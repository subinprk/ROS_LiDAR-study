#include <sb_lidar_process/sb_lidar_process.hpp>

//sometimes the code has glitches

void    ransac(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud){
    pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
    pcl::PointCloud<pcl::PointXYZ>::Ptr inlierPoints(new pcl::PointCloud<pcl::PointXYZ>);

    // Create the segmentation object
    pcl::SACSegmentation<pcl::PointXYZ> seg;
    seg.setModelType(pcl::SACMODEL_PLANE);
    seg.setMethodType(pcl::SAC_RANSAC);
    seg.setDistanceThreshold(0.01);

    seg.setInputCloud(input_cloud);
    seg.segment(*inliers, *coefficients);

    if (inliers->indices.empty()) {
        std::cerr << "No inliers found!" << std::endl;
        return;
    }

    // Now copy the inliers from input_cloud directly
    pcl::copyPointCloud<pcl::PointXYZ>(*input_cloud, *inliers, *inlierPoints);

    // Extract the inliers from the input cloud and store them in a new cloud
    pcl::ExtractIndices<pcl::PointXYZ> extract;
    extract.setInputCloud(input_cloud);
    extract.setIndices(inliers);
    extract.setNegative(true);  // Remove the inliers from the input cloud
    extract.filter(*input_cloud);
}