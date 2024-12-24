#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <std_msgs/Float32MultiArray.h> // 订阅的消息类型
#include <std_msgs/Int32.h>


// 用于存储从话题中接收到的 apple_position 数据
float apple_position[3] = {0.0, 0.0, 0.0}; // x, y, z
// 记录 reach 和 catch 标志位
int reach_flag = 0; // 0 表示未到达，1 表示已到达
int catch_flag = 0; // 0 表示未抓取，1 表示已抓取

// 订阅的回调函数，用于更新 apple_position 变量
void applePositionCallback(const std_msgs::Float32MultiArray::ConstPtr& msg) 
{
    if (msg->data.size() >= 3)  // 确保有足够的3个数据 x, y, z
    {
        apple_position[0] = msg->data[0];
        apple_position[1] = msg->data[1];
        apple_position[2] = msg->data[2];
        ROS_INFO("Received apple_position: x=%.6f, y=%.6f, z=%.6f", 
                  apple_position[0], apple_position[1], apple_position[2]);
    }
    else
    {
        ROS_WARN("Received data is too short! Length: %lu", msg->data.size());
    }
}

// 订阅 reach 话题的回调函数
void reachCallback(const std_msgs::Int32::ConstPtr& msg) 
{
    reach_flag = msg->data;
    ROS_INFO("Received reach_flag: %d", reach_flag);
}

// 订阅 catch 话题的回调函数
void catchCallback(const std_msgs::Int32::ConstPtr& msg) 
{
    catch_flag = msg->data;
    ROS_INFO("Received catch_flag: %d", catch_flag);
}

int main(int argc, char **argv)
{
    // 初始化节点
    ros::init(argc, argv, "moveit_fk_demo");
    // 创建节点句柄
    ros::NodeHandle nh;
    // 多线程
    ros::AsyncSpinner spinner(2); // 使用2个线程以同时订阅和控制MoveIt
    spinner.start();

    // 订阅话题 "/apple_3d_position"，回调函数为 applePositionCallback
    ros::Subscriber sub = nh.subscribe("/apple_3d_position", 10, applePositionCallback);

    // subscrib the topic reach and catch
    ros::Subscriber sub_reach = nh.subscribe("/reach", 10, reachCallback);
    ros::Subscriber sub_catch = nh.subscribe("/catch", 10, catchCallback);

    ros::Publisher reach_pub = nh.advertise<std_msgs::Int32>("/reach", 10);


    // 初始化需要使用 move group 控制的机械臂中的 arm group
    moveit::planning_interface::MoveGroupInterface arm("arm");

    // 获取终端link的名称
    std::string end_effector_link = arm.getEndEffectorLink();
    std::cout << "End Effector Link: " << end_effector_link << std::endl;

    // 设置目标位置所使用的参考坐标系
    std::string reference_frame = "base_link";
    arm.setPoseReferenceFrame(reference_frame);

    // 当运动规划失败后，允许重新规划
    arm.allowReplanning(true);

    // 设置位置和姿态的允许误差
    arm.setGoalPositionTolerance(0.001);
    arm.setGoalOrientationTolerance(0.01);

    // 设置允许的最大速度和加速度
    arm.setMaxAccelerationScalingFactor(0.2);
    arm.setMaxVelocityScalingFactor(0.2);

    // 控制机械臂先回到初始化位置
    arm.setNamedTarget("reset");
    arm.move();
    sleep(1); 

    while (ros::ok())
    {
        if (reach_flag == 0 && catch_flag == 0) 
        {
                    
            // 设置机器人终端的目标位置
            geometry_msgs::Pose target_pose;
            // 设置目标位置和姿态，假设这里是根据 apple_position 来设置的
            target_pose.orientation.x = 0.5;
            target_pose.orientation.y = 0.5;
            target_pose.orientation.z = 0.5;
            target_pose.orientation.w = 0.5;
            // 使用从 apple_position 话题中接收到的位置信息
            target_pose.position.x = apple_position[0] + 0.02;
            target_pose.position.y = apple_position[1] - 0.02;
            target_pose.position.z = apple_position[2] - 0.05;
            // target_pose.position.y = apple_position[1] + 0.02;
            // target_pose.position.z = apple_position[2] + 0.03;

            std::cout << "x: " << target_pose.position.x << std::endl;

            // 设置机器臂当前的状态作为运动初始状态
            arm.setStartStateToCurrentState();
            // 将目标位姿写入
            arm.setPoseTarget(target_pose);

            // 进行运动规划，计算机器人移动到目标的运动轨迹
            moveit::planning_interface::MoveGroupInterface::Plan plan;
            moveit::planning_interface::MoveItErrorCode success = arm.plan(plan);

            // 输出规划成功与否的信息
            ROS_INFO("Plan (pose goal) %s", success ? "SUCCESS" : "FAILED");

            // 让机械臂按照规划的轨迹开始运动
            if(success)
            arm.execute(plan);
            sleep(5);
            //--------------------------------------------------------
            std_msgs::Int32 reach_msg;
            reach_msg.data = 1;  // 设置 reach_flag 值为 1
            reach_pub.publish(reach_msg);  // 发布到 /reach 话题
            ROS_INFO("Published reach_flag: 1");
        }
        if (reach_flag == 1 && catch_flag == 1)
        {
            // 控制机械臂回到初始化位置
            arm.setNamedTarget("reset");
            arm.move();
            sleep(1);

            // std_msgs::Int32 catch_msg;
            // catch_msg.data = 2;  // 设置 catch_flag 值为 1
            // catch_pub.publish(catch_msg);  // 发布到 /catch 话题
            // ROS_INFO("Published catch_flag: 2");
        }
    }
    ros::shutdown(); 

    return 0;
}
