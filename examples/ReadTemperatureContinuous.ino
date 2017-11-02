/*****************************************************************************
 * Usage example of:
 * Arduino Library for Maxim DS1624 temperature sensor and memory.
 * 
*****************************************************************************/

#include <DS1624.h>

// Sensor presents all address pins connected to ground, and it will work in 
// continuous temperature conversion mode.
DS1624 ds1624(false, false, false, true);

void setup()
{  
  // Begin serial connection at 9600 baud
  Serial.begin(9600);
} 

void loop()
{
  // Get current temperature
  float temperature = ds1624.GetTemperature();
  // Print it
  Serial.println(temperature);
  // Wait a while
  delay(1000);
}
