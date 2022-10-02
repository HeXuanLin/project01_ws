#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    //用C++的方式设计不同类型的话题；
    ros::init(argc, argv, "nihao");

    // // 全局话题(根目录下)：话题名称要以“/”开头(也可以设置自己的命名空间)，这种情况下和节点(命名空间以及名称)没有关系，
    // ros::NodeHandle nh;
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/topic", 1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/topic", 1000);

    // // 相对话题(命名空间下)：非“/”开头，与节点名称平级，都在命名空间目录下
    // ros::NodeHandle nh;
    // ros::Publisher pub = nh.advertise<std_msgs::String>("topic", 1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/topic", 1000);

    //私有话题：需要创建特定NodeHandle，跟随节点名称(hello)目录后
    ros::NodeHandle nh("~");
    // ros::Publisher pub = nh.advertise<std_msgs::String>("topic", 1000);
    ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/topic", 1000);

    return 0;
}
