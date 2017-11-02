/*****************************************************************************
 * Arduino IDE Library for DS1624 temperature sensor from Maxim IC
 * 
*****************************************************************************/

#ifndef DS1624_Arduino_Library
#define DS1624_Arduino_Library

#include <Wire.h>

class DS1624
{
private:
  // Command codes
  const uint8_t START_CONVERSION = 0xEE;
  const uint8_t READ_TEMPERATURE = 0xAA;
  const uint8_t STOP_CONVERSION  = 0x22;
  const uint8_t ACCESS_MEM       = 0x17;
  const uint8_t ACCESS_CONFIG    = 0xAC;
  
  // Base sensor address 
  const uint8_t BASE_ADDRESS     = 0x48;
  
  // Stores the actual address
  uint8_t _address;
  
  // Stores the conversion mode
  bool _continuousConversion;
  
public:
  // Class constructor. Set the a2,a1,a0 bits according to the hardware 
  // connection of physical sensor pins.
  DS1624(bool a2, bool a1, bool a0, bool continuousConversion);
  
  // Gets temperature following the conversion mode defined by constructor.
  float GetTemperature();
  
  // Stops a continuous conversion.
  void StopConversion();
  
  // Restarts a continuous conversion after a manual stop.
  void StartConversion();
};

#endif //DS1624_Arduino_Library
