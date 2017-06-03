#include <Wire.h>

// begin SD card libraries
#include <BlockDriver.h>
#include <FreeStack.h>
#include <MinimumSerial.h>
#include <SdFat.h>
#include <SdFatConfig.h>
#include <SysCall.h>
// end SD card libraries

#include "Bmp180.h" // RCR header

File file; // file object
//SdFatSdio sd_card; // MicroSD card

namespace rcr {
namespace level1payload {

void setup() {
  // Start serial communication.
  Serial.begin(9600); // in bits/second
}

void printBmpData(void) {

  Serial.print("Temperature = ");
  Serial.print(bmp_data.temperature);
  Serial.println(" °C");

  Serial.print("Ambient pressure = ");
  Serial.print(bmp_data.ambient_pressure);
  Serial.println(" Pa");

  Serial.print("Pressure altitude = ");
  Serial.print(bmp_data.pressure_altitude);
  Serial.println(" meters");
  Serial.println();
}

void loop() {
  printBmpData();
  delay(1000);
}

} // namespace level1_payload
} // namespace rcr
