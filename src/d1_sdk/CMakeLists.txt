cmake_minimum_required(VERSION 3.5)
project(d1_sdk)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find catkin and required packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  std_msgs
)
catkin_package()
# Include directories for third-party libraries
include_directories(
  ${catkin_INCLUDE_DIRS}
  /usr/local/include/ddscxx
  /usr/local/include/iceoryx/v2.0.2
)

# Link third-party libraries
link_libraries(unitree_sdk2 ddsc ddscxx rt pthread)

# Add executables
add_executable(joint_angle_control src/joint_angle_control.cpp src/msg/ArmString_.cpp)
add_executable(multiple_joint_angle_control src/multiple_joint_angle_control.cpp src/msg/ArmString_.cpp)
add_executable(joint_enable_control src/joint_enable_control.cpp src/msg/ArmString_.cpp)
add_executable(arm_zero_control src/arm_zero_control.cpp src/msg/ArmString_.cpp)
add_executable(get_arm_joint_angle src/get_arm_joint_angle.cpp src/msg/ArmString_.cpp src/msg/PubServoInfo_.cpp)
add_executable(joint_state_subscriber src/joint_state_subscriber.cpp)
add_executable(multiple_joint_angle_control_policy1 src/multiple_joint_angle_control_policy1.cpp src/msg/ArmString_.cpp)

# Specify libraries to link against
target_link_libraries(joint_angle_control ${catkin_LIBRARIES})
target_link_libraries(multiple_joint_angle_control ${catkin_LIBRARIES})
target_link_libraries(joint_enable_control ${catkin_LIBRARIES})
target_link_libraries(arm_zero_control ${catkin_LIBRARIES})
target_link_libraries(get_arm_joint_angle ${catkin_LIBRARIES})
target_link_libraries(joint_state_subscriber ${catkin_LIBRARIES})
target_link_libraries(multiple_joint_angle_control_policy1 ${catkin_LIBRARIES})


# Install the executables (optional)
install(TARGETS
  joint_angle_control
  multiple_joint_angle_control
  joint_enable_control
  arm_zero_control
  get_arm_joint_angle
  joint_state_subscriber
  multiple_joint_angle_control_policy1
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)