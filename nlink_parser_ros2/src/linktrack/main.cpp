#include "init.h"
#include "init_serial.h"
#include "protocol_extracter/nprotocol_extracter.h"

// int main(int argc, char **argv)
// {
  // ros::init(argc, argv, "linktrack_parser");
  // ros::NodeHandle nh;
  // serial::Serial serial;
  // initSerial(&serial);
  // NProtocolExtracter protocol_extraction;
  // linktrack::Init init(&protocol_extraction, &serial);
  // ros::Rate loop_rate(1000);
  // while (ros::ok())
  // {
    // auto available_bytes = serial.available();
    // std::string str_received;
    // if (available_bytes)
    // {
      // serial.read(str_received, available_bytes);
//       protocol_extraction.AddNewData(str_received);
//     }
//     ros::spinOnce();
//     loop_rate.sleep();
//   }
//   return EXIT_SUCCESS;
// }

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  // std::cout<<sizeof(argv)<<" dfg " <<argv[1]<<'\n';
  std::string port = "/dev/ttyUWB";
  if (argc == 2) {
    port = std::string(argv[1]);
    std::cout<< "Opening port: " << port << std::endl;
  } else {
    std::cout<< "No port selected, defaulting to: " << port << std::endl;
  }
  serial::Serial serial;
  initSerial(&serial, port, 921600);
  NProtocolExtracter protocol_extraction;
  auto aoaInit = std::make_shared<linktrack::Init>(&protocol_extraction, &serial);

  rclcpp::spin(aoaInit);

  rclcpp::shutdown();
  return EXIT_SUCCESS;
}
