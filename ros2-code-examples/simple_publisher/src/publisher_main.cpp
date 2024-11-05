#include "rclcpp/rclcpp.hpp"
#include "rmw/rmw.h"
#include "simple_publisher/simple_publisher_node.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<SimplePublisherNode> node = std::make_shared<SimplePublisherNode>();

   const char * implementation_id = rmw_get_implementation_identifier();
    std::cout << "Current RMW implementation: " << implementation_id << std::endl;

  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}
