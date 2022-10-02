/*
    订阅方(物体)：订阅发布的坐标系相对关系，传入乌龟坐标点，调用tf转换为世界坐标系。
*/

//1.包含头文件，listener和buffer结合使用
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
    tf2_ros::TransformListener listener(buffer); //listener将订阅到的数据传入buffer；
    //6.创建要被转换的坐标点数据，仅用于仿真，实际中障碍物坐标点应动态生成；
    geometry_msgs::PointStamped ps;
    ps.header.seq = 200; //
    //动态坐标变换时buffer中有一堆值，它们的时间戳变动且有延迟。转换时ros会用点的时间戳和坐标关系的时间戳比对，时间戳错开过大ros将不进行转换，因此不能用now()，而是直接设置为0。
    ps.header.stamp = ros::Time(0.0);   //不添加时间戳关系；
    ps.header.frame_id = "turtle1";     //ps参考的坐标系；
    ps.point.x = 0;
    ps.point.y = 0;
    ps.point.z = 0;

    //7.添加try，保证订阅到坐标系相对关系再进行转换,防止抛异常，继续循环。
    //8.核心代码，调用tf内置实现，将ps坐标点转换成相对于lidar坐标系的base坐标系的坐标点;
    geometry_msgs::PointStamped ps_out;
    while(ros::ok())
    {
        ros::Rate rate(10); //转换频率；
        try
        {

            ps_out = buffer.transform(ps, "world"); //调用了buffer坐标点转换函数transform，参数1是被转换的坐标点，参数2是目标坐标系，返回值是一个新的坐标点。必须包含头文件5；
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