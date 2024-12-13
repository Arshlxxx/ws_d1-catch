#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "msg/ArmString_.hpp"

#define TOPIC "rt/arm_Command"

using namespace unitree::robot;
using namespace unitree::common;

void jointStateCallback(const sensor_msgs::JointState::ConstPtr& msg)
{
    // 检查消息的字段是否有效
    if (msg->name.size() != msg->position.size())
    {
        ROS_WARN("JointState message is inconsistent. Sizes of name and position arrays do not match.");
        return;
    }

    // 检查velocity和effort是否为空，如果为空则填充为零
    std::vector<double> velocity(msg->position.size(), 0.0);
    std::vector<double> effort(msg->position.size(), 0.0);

    if (!msg->velocity.empty())
    {
        velocity = msg->velocity;  // Use the provided velocity if available
    }

    if (!msg->effort.empty())
    {
        effort = msg->effort;  // Use the provided effort if available
    }

    // 打印所有关节的位置、速度和努力
    for (size_t i = 0; i < msg->name.size(); ++i)
    {
        ROS_INFO("Joint %s: Position = %f, Velocity = %f, Effort = %f",
                 msg->name[i].c_str(), 
                 msg->position[i], 
                 velocity[i], 
                 effort[i]);
    }

    // 初始化ChannelPublisher
    // ChannelPublisher<unitree_arm::msg::dds_::ArmString_> publisher(TOPIC);
    // publisher.InitChannel();

    // unitree_arm::msg::dds_::ArmString_ arm_msg;

    // 根据接收到的位置填充控制命令
    // arm_msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":2,\"data\":{\"mode\":1,"
    //                   "\"angle0\":" + std::to_string(msg->position[0]) + ","
    //                   "\"angle1\":" + std::to_string(msg->position[1]) + ","
    //                   "\"angle2\":" + std::to_string(msg->position[2]) + ","
    //                   "\"angle3\":" + std::to_string(msg->position[3]) + ","
    //                   "\"angle4\":" + std::to_string(msg->position[4]) + ","
    //                   "\"angle5\":" + std::to_string(msg->position[5]) + ","
    //                   "\"angle6\":0}}";  // Assuming 7th angle is not used, or set to 0

    // // 发布填充好的消息
    // publisher.Write(arm_msg);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "joint_state_subscriber");
    ros::NodeHandle nh;
    
    // ChannelPublisher<unitree_arm::msg::dds_::ArmString_> publisher(TOPIC);
    // publisher.InitChannel();
    // // 订阅 joint_state 话题
    ros::Subscriber sub = nh.subscribe("joint_states", 10, jointStateCallback);

    // 循环等待消息并处理回调
    ros::spin();

    return 0;
}
