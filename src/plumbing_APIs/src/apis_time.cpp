//1.包含头文件；
#include "ros/ros.h"

void callback(const ros::TimerEvent &event)
{
    static int count = 0;
    count++;
    if(count>5)
    {
        ros::shutdown();
    }
    ROS_INFO("---------------");
    ROS_INFO("Funcion calling at: %.2f", event.current_real.toSec());
}


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "get_time");
    //2.初始化ROS节点。必须，否则会导致时间API调用失败(在NodeHandle时会初始化时间操作)；
    ros::NodeHandle nh;
    //3.获取当前时间，now函数会将now被调用时刻的时间封装并返回，参考值为1970年1月1日00:00:00。
    ros::Time current_time1 = ros::Time::now();
    ROS_INFO("Current time1: %.2f", current_time1.toSec());
    ROS_INFO("Current time1: %.d", current_time1.sec);

    //4.设置指定时刻；
    ros::Time t1(20.35);
    ROS_INFO("t1 = %.2f", t1.toSec());

    //5.让程序休眠5秒；
    ROS_INFO("Sleep start.");
    ros::Duration du1(3);
    du1.sleep();
    ROS_INFO("Sleep end.");
    
    //6.求程序运行到结束的时刻。
    //6-1.获取开始时刻；
    ros::Time start_time = ros::Time::now();
    ROS_INFO("Start time: %.2f", start_time.toSec());
    //6-2.模拟运行时间；
    ros::Duration du2(3);
    du2.sleep();
    //6-3.计算结束时刻(开始+持续时间)；
    ros::Time stop_time = start_time + du2;
    ROS_INFO("Stop time: %.2f", stop_time.toSec());
    //6-4.时刻之间不能相加，但可以相减；
    ros::Duration time_difference = stop_time - start_time;
    ROS_INFO("Time difference: %.2f", time_difference.toSec());
    //6-5.持续时间运算；
    ros::Duration du3 = du1 + du2;
    ros::Duration du4 = du1 - du2;
    ROS_INFO("du1 + du2 = %.2f", du3.toSec());
    ROS_INFO("du1 - du2 = %.2f", du4.toSec());

    //7.定时器(和ros::Rate类似)
    /*
        ros::Timer createTimer(ros::Duration period, 时间间隔(s)
        const ros::TimerCallback &callback,          回调函数(封装业务)
        bool oneshot = false,                        是否一次性回调
        bool autostart = true)                       自动启动
    */
    while(ros::ok())
    {
        ROS_INFO("---------------Timer---------------");
        ros::Timer timer = nh.createTimer(ros::Duration(1), callback, false);
        //8.如果计数器>10，则关闭节点；
        ros::spin();
    }
    return 0;
}
