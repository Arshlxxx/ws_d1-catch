#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "msg/ArmString_.hpp"
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

#define TOPIC "rt/arm_Command"

using namespace unitree::robot;
using namespace unitree::common;

std::vector<double> joint_positions;

int move_flag = 0;

void jointStateCallback(const sensor_msgs::JointState::ConstPtr& msg)
{
    ChannelFactory::Instance()->Init(0);
    ChannelPublisher<unitree_arm::msg::dds_::ArmString_> publisher(TOPIC);
    publisher.InitChannel();

    // 检查消息的字段是否有效
    if (msg->name.size() != msg->position.size())
    {
        ROS_WARN("JointState message is inconsistent. Sizes of name and position arrays do not match.");
        return;
    }

    // 检查velocity和effort是否为空，如果为空则填充为零
    std::vector<double> velocity(msg->position.size(), 0.0);
    std::vector<double> effort(msg->position.size(), 0.0);

    joint_positions = msg->position;

    const double rad_to_deg = 57.2958;

    // Loop through each joint position and convert from radians to degrees
    for (size_t i = 0; i < joint_positions.size(); ++i) {
        joint_positions[i] *= rad_to_deg; // Multiply each entry by the conversion factor
    }

    joint_positions[0] = -joint_positions[0] + 9;
    joint_positions[3] = -joint_positions[3];


    std::cout << "Joint positions in radians: ";
    for (double pos : joint_positions) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    unitree_arm::msg::dds_::ArmString_ arm_msg{};
    arm_msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":2,\"data\":{\"mode\":1,\"angle0\":"
                            + std::to_string(joint_positions[0]) +",\"angle1\":"
                            + std::to_string(joint_positions[1]) +",\"angle2\":"
                            + std::to_string(joint_positions[2]) +",\"angle3\":"
                            + std::to_string(joint_positions[3]) +",\"angle4\":"
                            + std::to_string(joint_positions[4]) +",\"angle5\":"
                            + std::to_string(joint_positions[5]) +",\"angle6\":380}}"; 

                            

       
    publisher.Write(arm_msg);

    if (!msg->velocity.empty())
    {
        velocity = msg->velocity;  // Use the provided velocity if available
    }

    if (!msg->effort.empty())
    {
        effort = msg->effort;  // Use the provided effort if available
    }

    // // 打印所有关节的位置、速度和努力
    // for (size_t i = 0; i < msg->name.size(); ++i)
    // {
    //     ROS_INFO("Joint %s: Position = %f, Velocity = %f, Effort = %f",
    //              msg->name[i].c_str(), 
    //              msg->position[i], 
    //              velocity[i], 
    //              effort[i]);
    // }
}

int main(int argc, char** argv)
{
    // ChannelFactory::Instance()->Init(0);
    // ChannelPublisher<unitree_arm::msg::dds_::ArmString_> publisher(TOPIC);
    // publisher.InitChannel();

    ros::init(argc, argv, "joint_state_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("joint_states", 10, jointStateCallback);

    ros::Rate loop_rate(1);  // 设定循环频率为 1Hz
    while (ros::ok()) {
        

        // 处理 ROS 事件
        ros::spinOnce();

        // 按照设定的频率循环
        loop_rate.sleep();


        // unitree_arm::msg::dds_::ArmString_ arm_msg{};

                          
        // arm_msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":2,\"data\":{\"mode\":1,\"angle0\":15.6866,\"angle1\":28.0333,\"angle2\":-64.6494,\"angle3\":-24.7072,\"angle4\":38.7831,\"angle5\":19.2196,\"angle6\":50}}";
       
        // arm_msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":2,\"data\":{\"mode\":1,\"angle0\":"
        //                     + std::to_string(joint_positions[0]) +",\"angle1\":"
        //                     + std::to_string(joint_positions[1]) +",\"angle2\":"
        //                     + std::to_string(joint_positions[2]) +",\"angle3\":"
        //                     + std::to_string(joint_positions[3]) +",\"angle4\":"
        //                     + std::to_string(joint_positions[4]) +",\"angle5\":"
        //                     + std::to_string(joint_positions[5]) +",\"angle6\":50}}";

        // std::cout << "Formatted arm_msg data: " << joint_positions[0] << std::endl;
       
        // publisher.Write(arm_msg);
    }

    ros::spin();

    return 0;
}
