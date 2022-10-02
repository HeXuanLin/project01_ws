#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    //用C++的方式设计不同类型的参数；
    ros::init(argc, argv, "hello");
    ros::NodeHandle nh;

    // //全局参数(根目录下)：话题名称要以“/”开头(也可以设置自己的命名空间)，这种情况下和节点(命名空间以及名称)没有关系，
    // ros::param::set("/paramA", 100);
    // nh.setParam("/paramAa", 100);

    // //相对参数(命名空间下)：非“/”开头，与节点名称平级，都在命名空间目录下
    // ros::param::set("paramB", 100);
    // nh.setParam("paramBb", 100);

    // //私有参数：需要创建特定NodeHandle，跟随节点名称(hello)目录后
    ros::param::set("~paramC", 100);
    // ros::NodeHandle nh_private("~");
    // nh_private.setParam("paramC", 1000);
    return 0;
}