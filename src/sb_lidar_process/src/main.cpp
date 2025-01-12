#include "./sb_lidar_process.hpp"

using namespace sb_lidar_processing

ros::Publisher pub;

void callback(const sensor_msgs::PointCloud2 &msg){
    //add time-consuming processing here
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    //publishing
}

int main(int argc, char **argv){

    ros::init(argc, argv, "lidar_process_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("lidar3D", 5, callback) //1 is for Queuing the messages, have to make it higher in case processing takes longer time
    pub::nh.advertise<obsts>("obsts", 5);

    ros::AsyncSpinner   spinner(2); //Two threads for concurrent callbacks
    spinner.start();
    ros::waitForShutdown();
    return 0;
}
