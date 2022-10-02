#include "ros/ros.h"

/*
    演示参数查询
    实现：
    在 roscpp 中提供了两套 API 实现参数操作
    ros::NodeHandle

        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached(键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
    
        ros::param::xxx
*/

int main(int argc, char *argv[])
{
    //初始化ros节点；
    ros::init(argc, argv, "set_param_c");
    //创建ros节点句柄；
    ros::NodeHandle nh;

    //1.param(键,默认值) 
    double r1 = nh.param("radius1", 0.5);
    ROS_INFO("r1 = %f", r1);

    //2.getParam(键,存储结果的变量)
    double r2 = 0.0;
    bool result1 = nh.getParam("radius2", r2);
    if(result1)
    {
        ROS_INFO("r2 = %f", r2);
    }
    else
    {
        ROS_INFO("Incorrect parameter input");
    }

    //3.getParamCached(键,存储结果的变量) 实现与gerParam相似，只是底层性能提升，一般测试看不出区别。
    double r3 = 0.0;
    bool result2 = nh.getParamCached("radius1", r3);
    if(result2)
    {
        ROS_INFO("r3 = %f", r3);
    }
    else
    {
        ROS_INFO("Incorrect parameter input");
    }

    //4. getParamNames(std::vector<std::string>) 不想包含头文件直接用vector和string时要加std::，这里是字符串容器。
    std::vector<std::string> names;
    nh.getParamNames(names); //将param装入name容器中，再遍历；
    for(auto &&i : names)
    {
        ROS_INFO("Parameters are: %s", i.c_str()); //遍历打印类似于C语言printf，所以要用C风格
    }

    //5.hasParam(键)
    bool result3 = nh.hasParam("xxxxxxx");
    bool result4 = nh.hasParam("radius1");
    ROS_INFO("If xxxxxxx exist? %d", result3);
    ROS_INFO("If radius1 exist? %d", result4);

    //6.searchParam(参数1，参数2)
    std::string result5;
    nh.searchParam("radius1", result5);
    ROS_INFO("result = %s", result5.c_str());
    return 0;
}