/*
    需求：使用rosbag想磁盘写入数据(话题 + 消息)
    流程：
        1.导包
        2.初始化
        3.创建rosbag对象
        4.打开文件流(write)
        5.写数据
        6.关闭文件流
*/

//1.导包
#include "ros/ros.h"
#include "rosbag/bag.h"
#include "std_msgs/String.h" //使用std_msgs下的Sting类型作为消息

int main(int argc, char *argv[])
{
    //2.初始化
    ros::init(argc, argv, "rosbag_write");
    ros::NodeHandle nh;
    //3.创建rosbag对象
    rosbag::Bag bag1;
    //4.打开文件流
    bag1.open("bag1.bag", rosbag::BagMode::Write);
    //5.创建消息
    std_msgs::String msg;
    msg.data = "hello";
    //6.写数据
    bag1.write("/1",ros::Time::now(), msg); //(话题名称，时间戳，消息)
    bag1.write("/2",ros::Time::now(), msg); 
    bag1.write("/3",ros::Time::now(), msg); 
    bag1.write("/4",ros::Time::now(), msg); 

    //7.关闭数据流
    bag1.close();
    
    return 0;
}
