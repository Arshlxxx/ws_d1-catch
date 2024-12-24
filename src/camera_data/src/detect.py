#!/usr/bin/env python3

import rospy
import pyrealsense2 as rs
import numpy as np
from ultralytics import YOLO
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import TransformStamped
import tf2_ros
import tf.transformations as tft
from scipy.spatial.transform import Rotation as R
import cv2
import math

# Global variable to store 4x4 transformation matrix
transform_matrix = None
apple_positions = []
# hand_eye_matrix = np.array([
#     [0.99920799, -0.02318005, -0.03234308, 0.06408225],
#     [0.01391821, 0.96505936, -0.26166146, -0.0176825],
#     [0.03727831, 0.26100406, 0.96461765, -0.04349952],
#     [0, 0, 0, 1]
# ])

# hand_eye_matrix[:3, :3] = np.identity(3)
# hand_eye_matrix = np.array([
#     [1.0, -0.0, -0.0, 0.065],
#     [0.0, 1.0, -0.0, -0.02],
#     [0.0, 0.0, 1.0, -0.045],
#     [0, 0, 0, 1]
# ])

# T_hc = np.array([
#     [0, 1, 0, 0.02],
#     [0, 0, 1, 0.045],
#     [1, 0, 0, -0.065],
#     [0, 0, 0, 1]
# ])

T_hc = np.array([
    [-0.08761895,  0.99613429,  0.00627619, 0.08636197],
    [ 0.44929099,  0.03389441,  0.89274228, -0.03210363],
    [ 0.88907847,  0.08104098, -0.45052396, -0.04985081],
    [ 0,          0,          0,          1        ]])

# T_hc = np.array([
#     [ 0.88907847,  0.08104098, -0.45052396, -0.04985081],
#     [-0.08761895,  0.99613429,  0.00627619, -0.08636197],
#     [ 0.44929099,  0.03389441,  0.89274228, -0.03210363],
#     [ 0,          0,          0,          1        ]])

# T_hc = np.array([
#     [0.01391821, 0.96505936, -0.26166146, 0.0176825],
#     [0.03727831, 0.26100406, 0.96461765, 0.04349952],
#     [0.99920799, -0.02318005, -0.03234308, -0.06408225],
#     [0, 0, 0, 1]
# ])
# T_hc = np.array([
#     [0.0, 1, -0.0, 0.0176825],
#     [0.0, 0.0, 1, 0.04349952],
#     [1, -0.0, -0.0, -0.06408225],
#     [0, 0, 0, 1]
# ])


# hand_eye_matrix = np.array( [[ 0.98544367,  0.15399075, -0.07202509,  0.08553192],
#  [-0.1580795,   0.98589468, -0.05497778,  0.00381211],
#  [ 0.06254308,  0.06556319,  0.99588645,  0.03424352],
#  [ 0.,          0.,          0.,          1.        ]])



def quaternion_to_euler(x, y, z, w):
    """
    Convert quaternion to Euler angles (roll, pitch, yaw).
    Args:
        x, y, z, w: Components of the quaternion.
    Returns:
        roll, pitch, yaw: Euler angles in radians.
    """
    r = R.from_quat([x, y, z, w])  # Note: The order is [x, y, z, w]
    roll, pitch, yaw = r.as_euler('xyz', degrees=False)  # Choose 'xyz' for the axis order
    return roll, pitch, yaw

# Function to fetch transform from base_link to Link6 and update the transform matrix
def fetch_transform():
    global transform_matrix
    global T_bc
    tf_buffer = tf2_ros.Buffer()
    tf_listener = tf2_ros.TransformListener(tf_buffer)
    try:
        transform_stamped = tf_buffer.lookup_transform("base_link", "Link6", rospy.Time(0), rospy.Duration(1.0))

        # Extract translation and rotation
        # translation = [transform_stamped.transform.translation.x,
        #                transform_stamped.transform.translation.y,
        #                transform_stamped.transform.translation.z]
        translation = [transform_stamped.transform.translation.x,
                transform_stamped.transform.translation.y,
                transform_stamped.transform.translation.z]
        rotation = [transform_stamped.transform.rotation.x,
                    transform_stamped.transform.rotation.y,
                    transform_stamped.transform.rotation.z,
                    transform_stamped.transform.rotation.w]
        
        print(rotation[0], rotation[1], rotation[2], rotation[3])
        
        # theta = math.atan2(translation[1], translation[0])
        
        # rotation_matrix_z = np.array([
        #                                 [np.cos(theta), -np.sin(theta), 0],
        #                                 [np.sin(theta), np.cos(theta), 0],
        #                                 [0, 0, 1]
        #                             ])
        
        # print(np.degrees(theta))

        # Build the 4x4 transformation matrix
        transform_matrix = np.eye(4)
        
        # transform_matrix[:3, :3] = np.linalg.inv(T_rotation_hand[:3, :3] @ tft.quaternion_matrix(rotation)[:3, :3])  # Rotation
        # print("det:", np.linalg.det(transform_matrix[:3, :3]))
        # transform_matrix[:3, :3] = rotation_matrix_z
        transform_matrix[:3, :3] = tft.quaternion_matrix(rotation)[:3, :3]
        transform_matrix[:3, 3] = translation  # Translation 
        T_bh = transform_matrix
        T_bc = T_bh @ T_hc
        
        # print(np.linalg.inv(transform_matrix) @ np.array([translation[0], translation[1], translation[2], 1]))
        # translation[1] = -translation[1]
        

        rospy.loginfo(f"Transform matrix updated:\n{T_bh}") # print

    except tf2_ros.TransformException as ex:
        rospy.logwarn(f"Failed to fetch transform: {ex}")
        transform_matrix = None

# 1️⃣ Initialize YOLOv8 model
model = YOLO('yolov8l.pt')  # Replace with your YOLOv8 model path

# 2️⃣ Initialize RealSense pipeline
pipeline = rs.pipeline()
config = rs.config()
config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
pipeline.start(config)

# 3️⃣ Align depth map to color image
align = rs.align(rs.stream.color)

# 4️⃣ Get camera intrinsics
profile = pipeline.get_active_profile()
depth_sensor = profile.get_device().first_depth_sensor()
depth_scale = depth_sensor.get_depth_scale()
intrinsics = profile.get_stream(rs.stream.color).as_video_stream_profile().get_intrinsics()
# print("Camera Intrinsics:", intrinsics)


# ROS node initialization
rospy.init_node('yolo_realsense_node', anonymous=True)
position_pub = rospy.Publisher('/apple_3d_position', Float32MultiArray, queue_size=10)

# Update transform every second
rospy.Timer(rospy.Duration(1.0), lambda event: fetch_transform())

try:
    rate = rospy.Rate(30)  # 30 Hz loop
    while not rospy.is_shutdown():
        # 5️⃣ Get aligned color and depth images
        frames = pipeline.wait_for_frames()
        aligned_frames = align.process(frames)
        depth_frame = aligned_frames.get_depth_frame()
        color_frame = aligned_frames.get_color_frame()
        
        if not depth_frame or not color_frame:
            continue

        depth_image = np.asanyarray(depth_frame.get_data())
        color_image = np.asanyarray(color_frame.get_data())

        # 6️⃣ Use YOLOv8 to detect objects
        results = model(color_image)
        
        for result in results:
            for box in result.boxes:
                cls = int(box.cls[0])  # Detected class
                conf = float(box.conf[0])  # Confidence
                if cls != 47 or conf < 0.5:  # Only detect apples (class 47)
                    continue

                x1, y1, x2, y2 = map(int, box.xyxy[0])
                cx, cy = (x1 + x2) // 2, (y1 + y2) // 2

                # 8️⃣ Get depth value (meters)
                if 0 <= cx < depth_image.shape[1] and 0 <= cy < depth_image.shape[0]:
                    depth_value = depth_frame.get_distance(cx, cy)
                else:
                    continue

                if depth_value == 0:
                    continue

                point_3d = rs.rs2_deproject_pixel_to_point(intrinsics, [cx, cy], depth_value)
                x, y, z = point_3d  # 3D coordinates
                print("x,y,z: ",x,y,z)
                x, y, z = z, -x, -y
                print("new x,y,z: ", x, y, z)
                
                cv2.circle(color_image, (int(cx), int(cy)), 5, (255, 0, 0), int(3), 6)
                cv2.imshow("result", color_image)
                cv2.waitKey(1)
                # Apply transformation matrix to the detected apple position
                if transform_matrix is not None:
                    # inverse_transform_matrix = invert_transform(transform_matrix)

                    # Step 1: Transform apple position from camera to robotic arm end-effector
                    apple_position_cam = np.array([x, y, z, 1]).T  # Homogeneous coordinates
                    
                    print("Tbc: \n", T_bc)
                    
                    apple_position = T_bc @ apple_position_cam
                    apple_positions.append(apple_position)
                    
                    print("pos_apple : \n", T_bc @ apple_position_cam)
                    
                    # invers_hand_eye_matrix = np.linalg.inv(hand_eye_matrix)
                    # apple_position_arm = np.dot(invers_hand_eye_matrix, apple_position_cam)  # Camera to end-effector
                    
                    # apple_position_arm_ture = np.dot(T_rotation_hand, apple_position_arm)

                    # Step 2: Transform apple position from end-effector to robot base
                    # invers_transform_matrix = invert_transform(transform_matrix)
                    
                    
                    # apple_position_base = np.dot(transform_matrix, apple_position_arm)  # End-effector to base
                    
                    # apple_position_base = [apple_position_arm[0] + transform_matrix[0,-1], apple_position_arm[1] + transform_matrix[1,-1], apple_position_arm[2] + transform_matrix[2,-1]]
                    # print("apple_position_base: ", apple_position_base)
                    # Step 3: Publish the transformed position in the base coordinate system
                    # position_pub.publish(Float32MultiArray(data=apple_position_base[:3]))

                    # Publish the transformed position
                    # position_pub.publish(Float32MultiArray(data=transformed_position[:3].tolist()))
                    # position_pub.publish(Float32MultiArray(data = apple_position[:3]))
                    # rospy.loginfo(f"Camera position: {apple_position_cam[:3]}")
                    # rospy.loginfo(f"End-effector position: {apple_position_arm[:3]}")
                    # rospy.loginfo(f"Base position: {apple_position_base[:3]}")

                else:
                    rospy.logwarn("Transform matrix is None, skipping position transformation.")
            if len(apple_positions) > 0:
                position_pub.publish(Float32MultiArray(data = apple_positions[-1][:3]))

        rate.sleep()

finally:
    pipeline.stop()
