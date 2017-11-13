/*****************************************************************************
Arduino Library for Maxim DS1624 temperature sensor and memory

MIT License

Copyright (c) 2017 Alessio Leoncini, https://www.technologytourist.com

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

#include <DS1624.h>

// Sensor presents all address pins connected to ground
DS1624 ds1624(0x00);

void setup()
{  
  // Begin serial connection at 9600 baud
  Serial.begin(9600);
} 

void loop()
{
  float temperature;
  bool valid;
  
  // Get current temperature
  ds1624.GetTemperature(temperature, valid);

  // Print it
  Serial.println(temperature);

  // Wait a while
  delay(1000);
}
