//1.包含头文件；
#include "ros/ros.h"
#include "helloword/person.h" //ROS中的文本类型，消息载体；


int main(int argc, char *argv[])
{
    ROS_INFO("This is the publisher");
    //2.初始化ROS节点；
    ros::init(argc, argv, "talker");
    //3.创建节点句柄；
    ros::NodeHandle nh;
    //4.创建发布者对象；
    ros::Publisher talker = nh.advertise<helloword::person>("msg", 10); //<消息泛型类型>(“话题名称”，未发出消息的缓存区超出时移除队列中最早数据)
    //5.编写发布逻辑并发布数据；
    //5-1.创建被发布的消息，包括什么属性；
    helloword::person msg;
    msg.name = "Leo";
    msg.age = 18;
    msg.height = 177;
    //5-2.设置发布数据；
    ros::Rate rate(1);
    //5-3.循环发布数据；
    while(ros::ok())
    {
        msg.age += 1;
        //核心，数据发布;
        talker.publish(msg);
        ROS_INFO("The detail of person is %s, %d, %f", msg.name.c_str(), msg.age, msg.height);
        //休眠;
        rate.sleep();
        ros::spinOnce(); //官方建议，处理回调函数；  
    }
    return 0;
}
