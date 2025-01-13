#include <sb_lidar_process/sb_lidar_process.hpp>

void voxelGrid(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud){
    pcl::VoxelGrid<pcl::PointXYZ> down;

    down.setInputCloud(input_cloud);
    down.setLeafSize(0.01f, 0.01f, 0.01f);

    return ;
}