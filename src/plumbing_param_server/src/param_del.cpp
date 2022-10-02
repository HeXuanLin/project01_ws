#include "ros/ros.h"

int main(int argc, char *argv[])
{
    //初始化ros节点；
    ros::init(argc, argv, "set_param_c");
    //创建ros节点句柄；
    ros::NodeHandle nh;

    //删除：NodeHandle
    bool del1 = nh.deleteParam("radius1");
    if(del1)
    {
        ROS_INFO("Delete success!");
    }
    else
    {
        ROS_INFO("Delete unsuccess.");
    }

    //删除：ros::param
    bool del2 = ros::param::del("radius2");
    if(del2)
    {
        ROS_INFO("Delete success!");
    }
    else
    {
        ROS_INFO("Delete unsuccess.");
    }

    return 0;
}