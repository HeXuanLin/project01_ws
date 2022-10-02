//1.包含头文件；
#include "ros/ros.h"
#include "plumbing_head_src/head.h"

//2.声明namespace；
namespace test01
{
    void hello::function()
    {
        ROS_INFO("Function running success");
    };
}


int main(int argc, char *argv[])
{
    //3.初始化ROS节点；
    ros::init(argc, argv, "hello");
    //4.初始化节点句柄；
    ros::NodeHandle nh;
    //5.创建namespance为test01下的hello类的对象nihao；
    test01::hello nihao;
    //6.调用对象nihao的构造函数；
    nihao.function();   
    return 0;
}