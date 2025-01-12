#include "sb_lidar_processing.hpp"

void    ransac(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud){
    pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers (new pcl::PointIndices);

    //Create the segmetation object
    pcl::SACSegmentation<pcl::PointXYZ> seg;
    seg.setModelType(pcl::SACMODEL_PLANE);
    seg.segMethodType(pcl::SAC_RANSAC);
    seg.setDistanceThreshold(0.01);

    seg.setInputCloud(input_cloud);
    seg.segment(*inliners, *coefficients);

    
    return ;
}