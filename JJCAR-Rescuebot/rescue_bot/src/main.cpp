#include <thread>
#include <string>

#include "ros/ros.h"

#include "rescue_bot.h"

int main(int argc, char **argv)
{
    // float x = 0;
    // float y = 0;
    // float th = 0;

    // // Command line argument parser
    // for (int i = 0; i < argc; i++)
    // {
    //     std::string val = argv[i];

    //     if (val == "-x")
    //     {
    //         x = std::stof(argv[i + 1]);
    //     }
    //     else if (val == "-y")
    //     {
    //         y = std::stof(argv[i + 1]);
    //     }
    //     else if (val == "-th")
    //     {
    //         th = std::stof(argv[i + 1]);
    //     }
    // }

    std::cout << "STARTED" << std::endl;

    ros::init(argc, argv, "rescue_bot");

    ros::NodeHandle nh;

    std::shared_ptr<RescueBot> rescueBot(new RescueBot(nh));
    // dogController->sendCommand(x, y, th);

    ros::spin();

    ros::shutdown();

    return 0;
}