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
#include <mutex>
#include <queue>

//messages
#include <sensor_msgs/PointCloud2.h>
#include <sb_lidar_process::obsts.h>

//PointCloud2
#include <pcl/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

#endif