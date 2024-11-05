#ifndef __SIMPLE_PUBLISHER_NODE_HPP__
#define __SIMPLE_PUBLISHER_NODE_HPP__

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <sensor_msgs/msg/image.hpp>

class SimplePublisherNode : public rclcpp::Node
{

public:
    SimplePublisherNode(std::string name = "simple_publisher");

    void publish();

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _publisher;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr _publisher_image;
    rclcpp::TimerBase::SharedPtr _timer;
    int _count;
};

#endif // __SIMPLE_PUBLISHER_NODE_HPP__
