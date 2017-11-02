/*****************************************************************************
 * Arduino Library for Maxim DS1624 temperature sensor and memory
 * 
*****************************************************************************/

#include "DS1624.h"
#include <Arduino.h>
#include <Wire.h>

DS1624::DS1624(bool a2, bool a1, bool a0, bool continuousConversion)
{
  // Base address least significant bits will be a2, a1, a0 respectively 
  _address = BASE_ADDRESS | (a2 << 2) | (a1 << 1) | a0;
  
  // Save conversion mode
  _continuousConversion = continuousConversion;
  
  // Start I2C communication on default SCK, SDA ports
  Wire.begin();
  
  //  Configure sensor
  Wire.beginTransmission(_address);
  Wire.write(ACCESS_CONFIG);
  Wire.write(0x00 | _continuousConversion);
  Wire.endTransmission();
    
  // Minimum time needed to store the configuration is 10ms
  // Here wait for 20ms
  delay(20);
  
  if(_continuousConversion)
  {
    StartConversion();
  }
}

void DS1624::StartConversion()
{
  Wire.beginTransmission(_address);
  Wire.write(START_CONVERSION);
  Wire.endTransmission();
}

void DS1624::StopConversion()
{
  Wire.beginTransmission(_address);
  Wire.write(STOP_CONVERSION);
  Wire.endTransmission();
}

float DS1624::GetTemperature()
{
  uint16_t temperature = 0;
  
  if(!_continuousConversion)
  {
    // Start conversion
    StartConversion();
    
    // Wait for conversion done
    uint8_t configRegister = 0x00;
    do
    {
      // Read configuration register. The most significant bit turns to 1
      // when conversion done
      Wire.beginTransmission(_address);
      Wire.write(ACCESS_CONFIG);
      Wire.requestFrom(_address, 1, true);
      
      // Wait for data sent from sensor
      while(!Wire.available());
      
      // Check DONE bit
      configRegister = Wire.read();
    }while(!(configRegister & 0x80));
  }
  
  // Request to read last converted temperature value
  Wire.beginTransmission(_address);
  Wire.write(READ_TEMPERATURE);
  Wire.requestFrom(_address, 2, true);

  // Wait for data sent from sensor
  while(!Wire.available());
  
  // Read most significant word
  temperature = Wire.read() << 8;
  
  // Wait for data sent from sensor
  while(!Wire.available());
  
  // Read least significant word
  temperature |= Wire.read();

  // Convert to float and handle negative numbers
  temperature >>= 4;
  return (float)((temperature & 0x800 ? (temperature & 0x7ff) - 0x800 : temperature) / 16.0);
}
