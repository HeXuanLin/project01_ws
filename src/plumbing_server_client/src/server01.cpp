//1.包含头文件
#include "ros/ros.h"
#include "plumbing_server_client/Addints.h"

//请求的处理结果可能成功，也可能失败，因此是bool类型
//请求对象和响应对象。类型是当前功能包下的，Addints下的，Request和Response类型。
//引用传递，传来的参数是原来结构体的别名，可以和正常结构体一样访问成员变量, 前面话题通信的是结构体指针，要用->来访问成员变量或函数。
bool donums(plumbing_server_client::Addints::Request &request, plumbing_server_client::Addints::Response &response) 
{
    //5.1处理请求
    int num1 = request.num1; //用变量接收提取的数据；
    int num2 = request.num2;
    ROS_INFO("Two numbers are: num1 = %d, num2 = %d", num1, num2);
    //5.2组织响应；
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("The sum is: sum = %d", sum);
    return true;
}

int main(int argc, char *argv[])
{
    //2.初始化ROS节点；
    ros::init(argc, argv, "server01");
    //3.创建节点句柄；
    ros::NodeHandle nh;
    //4.创建一个服务对象；
    ros::ServiceServer server01 = nh.advertiseService("addints", donums); //函数重载，选择合适的函数调用
    ROS_INFO("The server is running.");
    //5.处理请求并产生相应；
    //6.spin()；
    ros::spin();
    return 0;
}
