/*
    发布方：订阅乌龟的位姿信息，转换成相对于窗体的坐标关系并发布。
    准备：
        1.话题/turtle1/pose
        2.消息/turtlesim/pose
    流程：
        1.包含头文件
        2.设置编码，初始化，NodeHandle
        3.创建订阅对象、订阅/turtle1/pose
        4.回调函数处理订阅的信息，将位姿信息转换成坐标相对关系并发布(关注)
        5.spin()
    结果：可使用rviz查看相对坐标位置关系
*/

#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"  //用于发布动态坐标关系
#include "geometry_msgs/TransformStamped.h" //用于组织发布数据
#include "tf2/LinearMath/Quaternion.h" //欧拉角转四元数

void dopose(const turtlesim::Pose::ConstPtr &pose)
{
    //核心：获取乌龟位姿信息，转换成坐标系相对关系，并发布
    //创建动态坐标关系发布对象
    static tf2_ros::TransformBroadcaster pub; //static让每次调用回调函数时用同一个pub对象
    //组织发布数据;
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = "turtle1";
    //坐标系偏移量设置;
    ts.transform.translation.x = pose->x; //乌龟坐标系相对于世界坐标系的x坐标
    ts.transform.translation.y = pose->y; //从订阅信息中取出乌龟的xy坐标
    ts.transform.translation.z = 0; //2D场景没有z坐标，通过rosmsg info turtlesim/Pose查看
    //坐标系四元数设置(位姿信息中没有四元数，但是有偏航角，已知乌龟为2D，没有翻滚与俯仰角，因此乌龟欧拉角为：0 0 theta，可转换为四元数)
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta); //从订阅信息中取出thata传入qtn
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();
    //发布数据;
    pub.sendTransform(ts);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "dynamic_pub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("turtle/pose", 100, dopose);
    ros::spin();    
    return 0;
}
