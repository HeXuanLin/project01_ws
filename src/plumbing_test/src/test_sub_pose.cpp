//1.包含头文件；
#include "ros/ros.h"
#include "turtlesim/Pose.h"

/*
    需求：订阅乌龟的位姿信息，并输出到控制台
*/

void dopose(const turtlesim::Pose::ConstPtr &pose)
{
    ROS_INFO("Turtle pose: Position(%.2f, %.2f), Theta(%.2f), Linear_v(%.2f), Angular_v(%.2f)", pose->x, pose->y, pose->theta, pose->linear_velocity, pose->angular_velocity);
}

int main(int argc, char *argv[])
{
    //2.初始化ROS节点；
    ros::init(argc, argv, "turtle_pose");
    //3.创建节点句柄；
    ros::NodeHandle nh;
    //4.创建发布对象；
    ros::Subscriber sub = nh.subscribe("/turtle1/pose", 100, dopose);
    ros::spin();
    return 0;
}

