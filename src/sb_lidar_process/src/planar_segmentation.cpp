#include <sb_lidar_process/sb_lidar_process.hpp>

void    ransac(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud){
    pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>),
                                        inlierPoints(new pcl::PointCloud<pcl::PointXYZ>);

    //Create the segmetation object
    pcl::SACSegmentation<pcl::PointXYZ> seg;
    seg.setModelType(pcl::SACMODEL_PLANE);
    seg.setMethodType(pcl::SAC_RANSAC);
    seg.setDistanceThreshold(0.01);

    seg.setInputCloud(input_cloud);
    seg.segment(*inliers, *coefficients);

    pcl::copyPointCloud<pcl::PointXYZ>(*cloud, *inliers, *inlierPoints);
    pcl::ExtractIndices<pcl::PointXYZ> extract;
    extract.setInputCloud(cloud);
    extract.setIndices(inliers);
    extract.setNegative(true);
    extract.filter(*input_cloud);
    //filter (PCLPointCloud2 &output);
    return ;
}