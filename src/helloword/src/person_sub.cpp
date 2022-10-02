//1.包含头文件；
#include "ros/ros.h"
#include "helloword/person.h"

//5.处理订阅到的数据；
//传入的消息是helloword功能包中的person类型，参数类型是它的常量智能指针(防止内部被修改)的引用，然后msg获取并操作订阅到的数据；
void domsg(const helloword::person::ConstPtr &msg) 
{
    ROS_INFO("Listener subscribes: %s, %d, %f", msg->name.c_str(), msg->age, msg->height);//指针通过->调用访问结构体中的数据，打印时需要C风格字符串；
}

int main(int argc, char *argv[])
{
    ROS_INFO("This is the subscriber");
    //2.初始化ROS节点；
    ros::init(argc, argv, "listener");
    //3.创建节点句柄；
    ros::NodeHandle nh;
    //4.创建订阅者对象；
    ros::Subscriber listerner = nh.subscribe("msg", 10, domsg);//<泛型类型自动推导可不写>("与发布方相同的话题"，缓冲区，回调函数用于处理订阅的数据)
    //6.spin()，回头执行回调函数；
    ros::spin();
    return 0;
}

