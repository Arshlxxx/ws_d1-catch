#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "msg/ArmString_.hpp"
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/Int32.h>

#define TOPIC "rt/arm_Command"

using namespace unitree::robot;
using namespace unitree::common;

std::vector<double> joint_positions;
int reach_flag = 0; // 0 表示未到达，1 表示已到达
int catch_flag = 0; // 0 表示未抓取，1 表示已抓取

ros::Publisher catch_pub;  // 声明全局发布者

void reachCallback(const std_msgs::Int32::ConstPtr& msg) 
{
    reach_flag = msg->data;
    ROS_INFO("Received reach_flag: %d", reach_flag);
}

void catchCallback(const std_msgs::Int32::ConstPtr& msg) 
{
    catch_flag = msg->data;
    ROS_INFO("Received catch_flag: %d", catch_flag);
}

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

    std::vector<double> velocity(msg->position.size(), 0.0);
    std::vector<double> effort(msg->position.size(), 0.0);

    joint_positions = msg->position;

    const double rad_to_deg = 57.2958;

    // 将弧度转化为角度
    for (size_t i = 0; i < joint_positions.size(); ++i) {
        joint_positions[i] *= rad_to_deg; // 每个值乘以转换因子
    }

    joint_positions[0] = -joint_positions[0];
    joint_positions[3] = -joint_positions[3];

    std::cout << "Joint positions in radians: ";
    for (double pos : joint_positions) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    unitree_arm::msg::dds_::ArmString_ arm_msg{};
    std_msgs::Int32 catch_msg;

    // if ((reach_flag == 0 || reach_flag == 1) && catch_flag == 0)
    if (reach_flag == 0)
    {
        arm_msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":2,\"data\":{\"mode\":1,\"angle0\":"
                            + std::to_string(joint_positions[0]) +",\"angle1\":"
                            + std::to_string(joint_positions[1]) +",\"angle2\":"
                            + std::to_string(joint_positions[2]) +",\"angle3\":"
                            + std::to_string(joint_positions[3]) +",\"angle4\":"
                            + std::to_string(joint_positions[4]) +",\"angle5\":"
                            + std::to_string(joint_positions[5]) +",\"angle6\":57}}"; 

        publisher.Write(arm_msg);
    }
    if (reach_flag == 1)
    {
        arm_msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":2,\"data\":{\"mode\":1,\"angle0\":"
                            + std::to_string(joint_positions[0]) +",\"angle1\":"
                            + std::to_string(joint_positions[1]) +",\"angle2\":"
                            + std::to_string(joint_positions[2]) +",\"angle3\":"
                            + std::to_string(joint_positions[3]) +",\"angle4\":"
                            + std::to_string(joint_positions[4]) +",\"angle5\":"
                            + std::to_string(joint_positions[5]) +",\"angle6\":45}}"; 

        publisher.Write(arm_msg);

        catch_msg.data = 1;  // 设置 catch_flag 值为 1
        catch_pub.publish(catch_msg);  // 发布到 /catch 话题
        ROS_INFO("Published catch_flag: 1");
    }

    if (!msg->velocity.empty())
    {
        velocity = msg->velocity;  // 使用提供的 velocity 数据
    }

    if (!msg->effort.empty())
    {
        effort = msg->effort;  // 使用提供的 effort 数据
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "joint_state_subscriber");
    ros::NodeHandle nh;

    // 在这里初始化 catch_pub 发布者
    catch_pub = nh.advertise<std_msgs::Int32>("catch", 1, true); // true 表示latch模式

    ros::Publisher reach_pub = nh.advertise<std_msgs::Int32>("reach", 1, true);  // 发布 reach 信息

    std_msgs::Int32 reach_msg;
    std_msgs::Int32 catch_msg;
    reach_msg.data = 0;
    catch_msg.data = 0;
    reach_pub.publish(reach_msg);
    catch_pub.publish(catch_msg);

    // 订阅 joint_states、reach 和 catch 话题
    ros::Subscriber sub = nh.subscribe("joint_states", 10, jointStateCallback);
    ros::Subscriber sub_reach = nh.subscribe("/reach", 10, reachCallback);
    ros::Subscriber sub_catch = nh.subscribe("/catch", 10, catchCallback);

    ros::Rate loop_rate(1);  // 设定循环频率为 1Hz
    while (ros::ok()) {
        // 处理 ROS 事件
        ros::spinOnce();

        // 按照设定的频率循环
        loop_rate.sleep();
    }

    return 0;
}
