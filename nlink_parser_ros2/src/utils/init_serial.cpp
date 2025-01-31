#include "init_serial.h"
#include "rclcpp/rclcpp.hpp"
#include <iostream>
#include <fstream>
#include <string>
/*
void enumerate_ports() {
  auto devices_found = serial::list_ports();
  auto iter = devices_found.begin();
  while (iter != devices_found.end()) {
    serial::PortInfo device = *iter++;

    printf("(%s, %s, %s)\n", device.port.c_str(), device.description.c_str(),
           device.hardware_id.c_str());
  }
  std::string test;
  test.clear();
}
*/

bool initSerial(serial::Serial *serial, std::string port_name, uint32_t baudrate)
{
  try
  {
    serial->setPort(port_name);
    serial->setBaudrate(baudrate);
  
    std::cout<< "try to open serial port with port: " << port_name << " baud rate: "<< baudrate << std::endl;
    auto timeout = serial::Timeout::simpleTimeout(10);
    // without setTimeout,serial can not write any data
    // https://stackoverflow.com/questions/52048670/can-read-but-cannot-write-serial-ports-on-ubuntu-16-04/52051660?noredirect=1#comment91056825_52051660
    serial->setTimeout(timeout);
    serial->open();

    if (serial->isOpen())
    {
      std::cout<< "Serial port opened successfully."<<std::endl;
    }
    else
    {
      std::cout<< "Failed to open serial port, please check and retry."<<std::endl;
      exit(EXIT_FAILURE);
    }
      return true;
  }
  catch (const std::exception &e)
  {
    std::cout<< "Exception raised : "<<e.what()<<std::endl;
    exit(EXIT_FAILURE);
  }
}
