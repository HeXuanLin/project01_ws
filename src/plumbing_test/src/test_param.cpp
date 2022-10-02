//1.包含头文件；
#include "ros/ros.h"
/*
    需求：修改参数服务器中turtlesim背景色相关参数

*/

int main(int argc, char *argv[])
{
    //2.初始化ROS节点；
    ros::init(argc, argv, "turtle_pose");
    //3.不一定要创建节点句柄(和后期API有关)
    // ros::NodeHandle nh;
    // nh.setParam("/turtle1/background_r", 0);
    //4.修改参数，调用ros::param不需要创建节点句柄
    ros::param::set("/turtle1/background_r", 255);
    ros::spin();
    return 0;
}