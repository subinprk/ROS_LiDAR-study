### Making a LiDAR Sensor message processing package for automated driving system

1. setting up the sensor position in MORAI(drivng simulation program)
2. Calling data sensor data using velodyne API
3. Noise Filtering using Voxel Grid Filter, and in case that the processing speed too late, add downsampling.
4. Using RANSAC algorithem, detach the ground and the obstacles
5. Using Euclidean clustering, catching the center point of the obstacles

Currently working in catkin workspace, catkin_make to build the package
