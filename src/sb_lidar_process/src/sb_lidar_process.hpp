#ifndef SB_LIDAR_PROCESSING_SB_LIDAR_PROCESSING_HPP
# define SB_LIDAR_PROCESSING_SB_LIDAR_PROCESSING_HPP

//Mandatories
#include <ros/ros.h>

//C++ libraries
#include <vector>
#include <iostream>
#include <algorithm>

//threading
#include <thread>

//messages
#include <sensor_msgs/PointCloud2.h>
#include <sb_lidar_process/obsts.h>

//PointCloud2
#include <pcl/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

//ROI setting
#include <pcl/filters/passthrough.h>

//Downsampling
#include <pcl/filters/voxel_grid.h>


//roi_cpp
void ROI(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud);

//voxel_grid_cpp
void voxelGrid(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud);

#endif