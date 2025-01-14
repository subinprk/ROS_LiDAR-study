#include <drive_lidar/lidar.hpp>

using namespace sb_lidar_process;

ros::Publisher pub;

void callback(const sensor_msgs::PointCloud2 &msg){
    pcl::PCLPointCloud2 pcl_pc;
    pcl_conversions::toPCL(msg, pcl_pc);
    pcl::PointCloud<pcl::PointXYZ>::Ptr input_cloud;
    pcl::fromPCLPointCloud2(pcl_pc, *input_cloud);

    ROI(input_cloud);
    voxelGrid(input_cloud);

    //RANSAC

    //Euclidean Clustering

    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    //publish
}

int main(int argc, char **argv){
    ros::init(argc, argv, "lidar_process_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("lidar3D", 5, callback); //1 is for Queuing the messages, have to make it higher in case processing takes longer time
    pub = nh.advertise<obsts>("obsts", 5);

    ros::AsyncSpinner   spinner(2); //Two threads for concurrent callbacks
    spinner.start();
    ros::waitForShutdown();
    return 0;
}
