# ESP32 Wi-Fi & Bluetooth Speaker

**Status: In development — individual component testing.**

A freshman engineering project exploring embedded programming, hardware integration, and user interface design through an ESP32-based stereo speaker. The goal is to support Bluetooth music playback and Wi-Fi internet radio, with an OLED interface and physical playback and volume controls.

The project is currently at the component-testing stage. This repository contains two standalone Arduino test sketches. An integrated main program has not been written yet.

## Current work

| Component | Current status |
| --- | --- |
| I²C communication | Scanner sketch provided for checking devices on GPIO 21 (SDA) and GPIO 22 (SCL). |
| OLED interface | Standalone 128×64 SSD1306 test sketch at address `0x3C`, using a fixed sample screen. |
| Integrated speaker firmware | Planned; not implemented. |

The OLED test shows `Dreams`, `Fleetwood Mac`, `VOL: 65%`, a playback symbol (`>`), `BT: ON`, and `WiFi: ON`. **All of these values are hard-coded placeholders.** They do not indicate active audio playback, real volume, or Bluetooth/Wi-Fi connections. The sketches are manual hardware checks, not automated tests.

## Planned features

- Stereo audio output from the ESP32 with suitable audio hardware.
- Bluetooth music playback.
- Wi-Fi internet radio.
- OLED updates for song, artist, volume, playback mode/state, and connection status, where supported by the audio source.
- Physical playback and volume controls.
- Integration of the individually tested components into one main program.
- Handling of long song and artist names on the small display.

These features remain development goals. Audio hardware, libraries, board compatibility, and integration details still need to be selected and tested. In particular, the chosen ESP32 variant must support the Bluetooth audio approach used later.

## Repository structure

```text
tests/
├── I2C_Scanner/
│   └── I2C_Scanner.ino
└── OLED_Test/
    └── OLED_Test.ino
```

Each sketch has its own matching folder so it can be opened independently in Arduino IDE.

## Hardware for current tests

- ESP32 development board with GPIO 21 and GPIO 22 available.
- 128×64 I²C SSD1306 OLED display configured for address `0x3C`.
- USB cable and jumper wires.

| OLED connection | ESP32 connection |
| --- | --- |
| SDA | GPIO 21 |
| SCL | GPIO 22 |
| GND | GND |
| VCC | Compatible supply for the specific OLED module |

Check the display module's supply requirements and keep I²C signal levels compatible with the ESP32's 3.3 V GPIO.

## Run the test sketches

1. Install Arduino IDE and the ESP32 board package. Select your board and USB port.
2. For the OLED test, install **Adafruit SSD1306** and **Adafruit GFX Library** through Library Manager, including any prompted dependencies. The scanner only uses `Wire` from the board package.
3. Open `tests/I2C_Scanner/I2C_Scanner.ino` and upload it. Open Serial Monitor at **115200 baud**. The sketch scans addresses 1–126 and reports responding devices. The OLED is expected at `0x3C`; use the scan to check the actual address.
4. Open `tests/OLED_Test/OLED_Test.ino` and upload it separately. The expected result is the fixed sample screen described above.

Uploading one sketch replaces the previously uploaded sketch. Neither sketch runs the complete speaker.

## Development approach

The immediate focus is verifying communication and display layout before connecting the audio and control systems. Future updates will document wiring, component choices, test observations, and integration progress as they are completed.

The initial OLED layout comes from the existing project test sketch; the scanner is reconstructed from the project's stated scan behavior. These repository copies have not been compiled or tested on hardware during repository preparation.
