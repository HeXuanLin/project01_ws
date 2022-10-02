/*
    问题：现有一机器人模型，核心构成包含主体与雷达，各对应一坐标系，坐标系的原点分别位于主体与雷达的物理中心。
    已知雷达原点相对于主体原点位移关系如下: x 0.2 y0.0 z0.5。当前雷达检测到一障碍物，
    在雷达坐标系中障碍物的坐标为 (2.0 3.0 5.0),请问，该障碍物相对于主体的坐标是多少？
*/

//1.包含头文件；
#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

int main(int argc, char *argv[])
{
    //2.发布两个坐标系的相对关系；
    ros::init(argc, argv, "static_boardcaster");
    ros::NodeHandle nh;
    //3.创建发布对象，发布方NodeHandle非必须；
    tf2_ros::StaticTransformBroadcaster pub;
    //4.组织被发布的消息；
    geometry_msgs::TransformStamped tf;
    tf.header.seq = 100; //
    tf.header.stamp = ros::Time::now(); //获取当前时间戳；
    tf.header.frame_id = "base"; //被参考的基座坐标系；
    tf.child_frame_id = "lidar"; //雷达相对基座坐标系；
    //相对位移；
    tf.transform.translation.x = 0.2;
    tf.transform.translation.y = 0.0;
    tf.transform.translation.z = 0.5;
    //需要根据欧拉角转换；
    tf2::Quaternion qtn; //创建四元数对象；
    //向该对象设置欧拉角，这个对象可以将欧拉角转换为四元数；
    qtn.setRPY(0,0,0);   //欧拉角单位是弧度；
    tf.transform.rotation.x = qtn.getX();
    tf.transform.rotation.y = qtn.getY();
    tf.transform.rotation.z = qtn.getZ();
    tf.transform.rotation.w = qtn.getW();
    //5.发布数据；
    pub.sendTransform(tf);
    ros::spin();
    return 0;
}