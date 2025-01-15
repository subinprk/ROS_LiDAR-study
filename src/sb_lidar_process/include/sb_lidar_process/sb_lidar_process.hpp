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
#include <pcl/filters/extract_indices.h>

//ROI
#include <pcl/filters/passthrough.h>

//Downsampling
#include <pcl/filters/voxel_grid.h>

//plane segmentation
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>

//Euclidean Clustering
#include <pcl/search/kdtree.h>
#include <pcl/segmentation/extract_clusters.h>
#include <iomanip> // for setw, setfill

//roi_cpp
void ROI(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud);

//voxel_grid_cpp
void voxelGrid(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud);

//planar_segmentation_cpp
void    ransac(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud);

//euclidean clustering
void clustering(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud);

#endif