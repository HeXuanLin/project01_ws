//1.包含头文件；
#include "ros/ros.h"
#include "plumbing_server_client/Addints.h"

int main(int argc, char *argv[])
{
    //优化实现，获取命令中输入的参数；
    if(argc != 3) //判断传入main的总元素个数是否小于3。第一个元素是客户端文件名，第二个是num1，第三个是num2；
    {
        ROS_INFO("Incorrect number of parameters");
        return 1; //结束；
    }
    //2.初始化ROS节点；
    ros::init(argc, argv, "client01");
    //3.创建节点句柄；
    ros::NodeHandle nh;
    //4.创建一个客户端对象；
    ros::ServiceClient client01 = nh.serviceClient<plumbing_server_client::Addints>("addints"); //serviceClient是封装好的STL模板函数，<>内需要功能包名下Addints；
    //5.提交请求并处理响应；
    //5-1.创建一个Addints对象，对象已封装；
    plumbing_server_client::Addints ai;
    //5-2.组织请求；
    ai.request.num1 = atoi(argv[1]); //从argv解析元素二，atoi()字符串转整形值；
    ai.request.num2 = atoi(argv[2]); //从argv解析元素三；
    //如果先启动客户端，未启动服务端，会导致请求异常。可以调用ROS相关函数，让客户端不抛异常，而是挂起客户端请求，等待服务端启动；
    //client01.waitForExistence(); 下面函数效果相同；
    ros::service::waitForService("addints");
    //5-3.处理响应；
    //客户端访问服务端，把ai对象提交了，ai对象封装了request和response，request封装了num1和num2，response封装了sum。提交完后返回结果，返回true则处理成功，false则处理失败。
    bool answer = client01.call(ai); 
    if (answer)
    {
        ROS_INFO("Get response.");
        //获取结果；
        ROS_INFO("The answer is: %d", ai.response.sum);
    }
    else
    {
        ROS_INFO("Faild response.");
    }
    return 0;
}