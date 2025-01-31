#include <sb_lidar_process/sb_lidar_process.hpp>
#include <pcl/common/centroid.h> //for center calculation

extern ros::Publisher cluster_pub;

void clustering(pcl::PointCloud<pcl::PointXYZ>::Ptr &input_cloud){
    
    if (!input_cloud || input_cloud->empty())
        return ;
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
    std::vector<pcl::PointIndices> cluster_indices;
    pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;

    tree->setInputCloud(input_cloud);
    ec.setClusterTolerance(0.02);
    ec.setMinClusterSize(100);
    ec.setMaxClusterSize(25000);
    ec.setSearchMethod(tree);
    ec.setInputCloud(input_cloud);
    ec.extract(cluster_indices);

    if (cluster_indices.empty()){
        std::cerr << "No clusters found" << std::endl;
        return ;
    }
    
            //debugging
    pcl::PointCloud<pcl::PointXYZ>::Ptr centroids(new pcl::PointCloud<pcl::PointXYZ>);
    std::vector<sb_lidar_process::obst> point_elem;
    int count = 0;
    for (const auto &indices: cluster_indices){
        Eigen::Vector4f centroid;
        pcl::compute3DCentroid(*input_cloud, indices.indices, centroid);
        centroids->push_back(pcl::PointXYZ(centroid[0], centroid[1], centroid[2]));
        sb_lidar_process::obst point;
        point.x = centroid[0];
        point.y = centroid[1];
        point.z = centroid[2];
        point_elem.push_back(point);
        count ++;
    }
            sensor_msgs::PointCloud2 output_msg;
            pcl::toROSMsg(*centroids, output_msg);
            output_msg.header.frame_id = "map";
            output_msg.header.stamp = ros::Time::now();
    sb_lidar_process::obsts msg;
    msg.count = count;
    msg.obst_vector = point_elem;
    cluster_pub.publish(output_msg);
}