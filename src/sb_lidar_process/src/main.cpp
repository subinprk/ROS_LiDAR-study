#include "./sb_lidar_process.hpp"

using namespace sb_lidar_processing

void callback(const sensor_msgs::PointCloud2 &msg){
    
}

int main(int argc, char **argv){

    ros::init(argc, argv, "lidar_process_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("lidar3D", 1, callback) //1 is for Queuing the messages, have to make it higher in case processing takes longer time

    return 0;
}
