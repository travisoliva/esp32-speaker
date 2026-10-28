#include <Wire.h>

// Standalone ESP32 hardware check: SDA = 21, SCL = 22.
void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  delay(1000);
  Serial.println("I2C scanner ready");
}

void loop() {
  int devicesFound = 0;
  Serial.println("Scanning I2C addresses 1-126...");

  for (uint8_t address = 1; address <= 126; address++) {
    Wire.beginTransmission(address);
    uint8_t error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      devicesFound++;
    }
  }

  if (devicesFound == 0) Serial.println("No I2C devices found");
  Serial.println("Scan complete\n");
  delay(5000);
}
