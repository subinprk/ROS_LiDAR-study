#include "sb_lidar_process.hpp"

void ROI(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud){
    pcl::PassThrough<pcl::PointXYZ> xfilter;
    pcl::PassThrough<pcl::PointXYZ> yfilter;
    pcl::PassThrough<pcl::PointXYZ> zfilter;

    xfilter.setInputCloud(input_cloud);
    xfilter.setFilterFieldName("x");
    xfilter.setFilterLimits(0,10);//limit 지정하기
    xfilter.filter(input_cloud);

    yfilter.setInputCloud(input_cloud);
    yfilter.setFilterFieldName("y");
    yfilter.setFilterLimits(-10, 10);//limit 지정
    yfilter.filter(input_cloud);

    zfilter.setInputCloud(input_cloud);
    zfilter.setFilterFieldName("z");
    zfilter.setFilterLimits(0, 1.5); //limit 지정
    zfilter.filter(input_cloud);
}