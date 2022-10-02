/*
    问题：现有一机器人模型，核心构成包含主体与雷达，各对应一坐标系，坐标系的原点分别位于主体与雷达的物理中心。
    已知雷达原点相对于主体原点位移关系如下: x 0.2 y0.0 z0.5。当前雷达检测到一障碍物，
    在雷达坐标系中障碍物的坐标为 (2.0 3.0 5.0),请问，该障碍物相对于主体的坐标是多少？

    订阅方(物体)：订阅发布的坐标系相对关系，传入一个坐标点，调用tf实现转换。
*/

//1.包含头文件，listener和buffer结合使用，listener将订阅到的数据传入buffer；
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"


int main(int argc, char *argv[])
{
    //2.初始化ROS节点；
    ros::init(argc, argv, "static_sub");
    //3.创建节点句柄，订阅方必须；
    ros::NodeHandle nh;
    //4.创建一个buffer；
    tf2_ros::Buffer buffer;
    //5.创建监听对象；
    tf2_ros::TransformListener listener(buffer);
    //6.组织坐标点数据，仅用于仿真，实际中障碍物坐标点应动态生成；
    geometry_msgs::PointStamped ps;
    ps.header.seq = 200; //
    ps.header.stamp = ros::Time::now(); //获取当前时间戳；
    ps.header.frame_id = "lidar"; //障碍物相对雷达坐标系；
    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;

    //7.添加try，保证订阅到坐标系相对关系再进行转换,防止抛异常，继续循环。
    //8.核心代码，调用tf内置实现，将ps坐标点转换成相对于lidar坐标系的base坐标系的坐标点;
    geometry_msgs::PointStamped ps_out;
    while(ros::ok())
    {
        ros::Rate rate(10); //转换频率；
        try
        {

            ps_out = buffer.transform(ps, "base"); //调用了buffer坐标点转换函数transform，参数1是被转换的坐标点，参数2是目标坐标系，返回值是一个新的坐标点。必须包含头文件5；
            ROS_INFO("ps_out:(%.2f, %.2f, %.2f), reference:%s", ps_out.point.x, ps_out.point.y, ps_out.point.z, ps_out.header.frame_id.c_str());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            ROS_INFO("Exception Message: %s", e.what());
        }
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}