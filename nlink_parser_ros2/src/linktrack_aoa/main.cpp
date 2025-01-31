#include "init.h"
#include "init_serial.h"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  std::cout<<sizeof(argv)<<" dfg " <<argv[1]<<'\n';
  serial::Serial serial;

  /*
    // todo: refactor, and maybe make a common class for all of these serial using nodes?
    node->declare_parameter("port_name", "/dev/ttyUWB");
    node->declare_parameter("baudrate", 921600);

    auto port_name = node->get_parameter("port_name").as_string();
    auto baudrate = node->get_parameter("baudrate").as_int();
  */
  initSerial(&serial, "/dev/ttyUWB", 921600);
  NProtocolExtracter protocol_extraction;

  auto aoaInit = std::make_shared<linktrack_aoa::Init>(&protocol_extraction, &serial);

  rclcpp::spin(aoaInit);

  rclcpp::shutdown();
  return EXIT_SUCCESS;
}
