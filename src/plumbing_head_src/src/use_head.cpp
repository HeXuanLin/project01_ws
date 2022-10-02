#include "ros/ros.h"
#include "plumbing_head_src/head.h"
//直接调用别人写的代码，主要麻烦在Cmake配置

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "hello");
    test01::hello nihao;
    nihao.function();
    return 0;
}
