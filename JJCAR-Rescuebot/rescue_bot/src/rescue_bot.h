#ifndef RESCUEBOT_H
#define RESCUEBOT_H

#include "ros/ros.h"

#include <cmath>
#include <vector>
#include <mutex>
#include <thread>

#include "tf/transform_datatypes.h"
#include <tf2/LinearMath/Quaternion.h>

// ROS message types
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/PointStamped.h"
#include "nav_msgs/Odometry.h"

#include "dog_controller.h"

class RescueBot
{
    public:
        /**
         * @brief Default constructor for dog. Sets up internal variables,
         * subscribers, publishers and services.
         * 
         * @param[in] nh The ROS node handle, used to identify node instance
        */
        RescueBot(ros::NodeHandle nh);

        ~RescueBot();

        void setGoal(geometry_msgs::Point goal);

        void reachGoal();

        double distanceToGoal(geometry_msgs::PoseStamped origin,
                              geometry_msgs::PointStamped goal);

    private:
        // void poseCallback(geometry_msgs::PoseWithCovarianceStamped pose);
        void poseCallback(nav_msgs::Odometry pose);
        
        geometry_msgs::Point globalToLocal(geometry_msgs::Point point);

    private:
        ros::NodeHandle nh_;

        DogController* dogPtr_;

        ros::Subscriber poseSubscriber_;
        ros::Subscriber goalSubscriber_;

        std::thread controlThread_;

        geometry_msgs::Point currentGoal_;
        bool goalReached_;

        // geometry_msgs::PoseWithCovarianceStamped pose_;
        nav_msgs::Odometry pose_;
};

#endif // RESCUEBOT_H