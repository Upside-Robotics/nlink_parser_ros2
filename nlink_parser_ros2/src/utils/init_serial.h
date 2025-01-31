#ifndef INITSERIAL_H
#define INITSERIAL_H
#include <serial/serial.h>

bool initSerial(serial::Serial *serial, std::string port, uint32_t baud_rate);

#endif // INITSERIAL_H
