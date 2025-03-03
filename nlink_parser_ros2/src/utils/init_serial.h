#ifndef INITSERIAL_H
#define INITSERIAL_H
#include <serial/serial.h>
#include <yaml-cpp/yaml.h>

bool initSerial(serial::Serial *serial, const std::string& port_name, const uint32_t baudrate);
bool initSerial(serial::Serial *serial, char *param_file_path);

#endif // INITSERIAL_H
