#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Wire.begin(21, 22);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Fixed UI sample only: these values do not reflect live playback or connections.
  // Song
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("Dreams");

  // Artist
  display.setTextSize(1);
  display.setCursor(0, 19);
  display.println("Fleetwood Mac");

  // Volume
  display.setCursor(0, 35);
  display.print("VOL: 65%");

  // Playback
  display.setCursor(105, 35);
  display.print(">");

  // Bluetooth
  display.setCursor(0, 52);
  display.print("BT: ON");

  // Wi-Fi
  display.setCursor(68, 52);
  display.print("WiFi: ON");

  display.display();
}

void loop() {
}
