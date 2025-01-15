#include <sb_lidar_process/sb_lidar_process.hpp>

//sometimes the code has glitches
extern ros::Publisher ransac_pub;

void    ransac(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud){
    static int count;

    pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
    pcl::PointCloud<pcl::PointXYZ>::Ptr inlierPoints(new pcl::PointCloud<pcl::PointXYZ>);

    // Create the segmentation object
    pcl::SACSegmentation<pcl::PointXYZ> seg;
    seg.setModelType(pcl::SACMODEL_PLANE);
    seg.setMethodType(pcl::SAC_RANSAC);
    seg.setDistanceThreshold(0.01);
    // seg.setMaxIterations(100);
    // seg.setProbability(0.95);

    seg.setInputCloud(input_cloud);
    seg.segment(*inliers, *coefficients);

    if (inliers->indices.empty()) {
        count ++;
        std::cerr << "No inliers found! frame: " << count << std::endl;
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

    sensor_msgs::PointCloud2    tmp;
    pcl::toROSMsg((*input_cloud), tmp);
    tmp.header.frame_id = "map";
    tmp.header.stamp = ros::Time::now();
    ransac_pub.publish(tmp);
}