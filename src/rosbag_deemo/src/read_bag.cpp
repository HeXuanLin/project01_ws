/*
    需求：使用rosbag想磁盘写入数据(话题 + 消息)
    流程：
        1.导包
        2.初始化
        3.创建rosbag对象
        4.打开文件流(read)
        5.读数据
        6.关闭文件流
*/

#include "ros/ros.h"
#include "rosbag/bag.h"
#include "rosbag/view.h"
#include "std_msgs/String.h" //使用std_msgs下的Sting类型作为消息

int main(int argc, char *argv[])
{
    //2.初始化;
    ros::init(argc, argv, "rosbag_write");
    ros::NodeHandle nh;
    //3.创建rosbag对象
    rosbag::Bag bag;
    //4.打开文件流;
    bag.open("bag1.bag", rosbag::BagMode::Read);
    //5.读数据(首先了解bag文件中有什么数据)
    //取出话题、时间戳、消息。可以先获取消息的集合，再迭代出消息的字段
    for (auto &&i : rosbag::View(bag))
    {
        //解析消息;
        std::string topic = i.getTopic();
        ros::Time time = i.getTime();
        std_msgs::StringPtr p = i.instantiate<std_msgs::String>();
        ROS_INFO("Messages, topic: %s, timestramp: %.2f, msgs: %s", topic.c_str(), time.toSec(), p->data.c_str());
    }
    bag.close();
    return 0;
}
