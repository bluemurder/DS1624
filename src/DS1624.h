/*****************************************************************************
Arduino Library for Maxim DS1624 temperature sensor and memory

MIT License

Copyright (c) 2017 Alessio Leoncini

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*****************************************************************************/

#ifndef DS1624_Arduino_Library
#define DS1624_Arduino_Library

#include <stdint.h>

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
  // Default constructor. Use address pins a2,a1,a0 connected to ground,
  // continuous temperature conversion and I2C master default pins
  DS1624();
  
  // Class constructor. Set the a2,a1,a0 bits according to the hardware 
  // connection of physical sensor pins, and set continuous temperature 
  // conversion or one-shot conversion mode.
  DS1624(bool a2, bool a1, bool a0, bool continuousConversion);
  
  // Gets temperature following the conversion mode defined by constructor.
  float GetTemperature();
  
  // Stops a continuous conversion.
  void StopConversion();
  
  // Restarts a continuous conversion after a manual stop.
  void StartConversion();
};

#endif //DS1624_Arduino_Library
