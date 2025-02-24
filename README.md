# CYD Code Sample

This project demonstrates how to use the CYD, USB-C only variant with resistive touch. Labeled "ESP32-024" in the back. The project is developed using PlatformIO and Arduino. The simulator used is Wokwi.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)

## Introduction
This project aims to provide a simple and effective way to control a tft display using an ESP32 WROOM 32 microcontroller. It includes sample code and instructions to get started quickly. I used a CYD board with integreated 2.8inch display.

Coding might not seem like what the embedded workd does it but I'm a software engineer. I can't help using patterns and such. Ofcourse, my use cases are smaller and won't do anything that drains resourses for little gain.

## Features
- Interface with tft display
- Display text and graphics
- Easy-to-use API
- Simulator setup (Wokwi)

## Hardware Requirements
- CYD, USB-C only variant with resistive touch
    - Any CYD will do if you know the pin mappings
    - Any ESP32WROOM32 microcontroller connected to a tft driven with ST7789 will work too
    - Mine is likely [this one](https://github.com/rzeldent/platformio-espressif32-sunton/blob/main/esp32-2432S028Rv3.json)

## Software Requirements
- PlatformIO IDE
- Wokwi/Wokwi for vscode (Optional)
- Libraries
    - `tft_eSPI`
    - `XPT2046_Touchscreen`
        - Needed specify url for this library because platformio did not this library in their repository since alpha
    - `adafruit/Adafruit FT6206 Library``
        - Used only for simulator since Wokwi only support capacitive touch

## Installation
1. Clone the repository
2. Open the project in PlatformIO IDE
3. Install the required libraries

### Optional steps
- Use Aider
    - Rename `.aider.conf.yml.sample` to `.aider.conf.yml`
    - Add gemini (or other model) api key
- Install Wokwoi vscode extension to use Wokwi simulator
- For quick test, to see everything is connected right, try [this snippet](https://forum.arduino.cc/t/tzt-esp32-2-4-lcd-w-touchscreen/1270830/12)

## Usage
1. **Connect the hardware:**
    - Connect the ESP32 to the tft display via SPI according to pinout diagram.
        - For CYD everything is connected
2. **Update config:**
    - Open `config/device/tft_config.h` and make changes according to connection made previous step.
        - `config/sim/tft_config.h` in the case of simulator
3. **Compile:**
    - Select env.
        - Select between `device` and `sim` env from the switcher in vscode status bar
    - Build using PlatformIO
4. **Upload the code:**
    - Upload the code to the CYD using PlatformIO.
    - No action required for simulator.
5. **Run the project:**
    - Power on the board and the LCD and test should show up on the display.
    - For simulator, click on diagram.json in vscode. Press play.

## Project specific quarks
- ESP32WROOM32 board serial issue with tft_espi
    - tft_espi uses `Serial` for communincation. So does USB CDC. This leads to compile error. Could not solve it yet. For the moment, keeping `ARDUINO_USB_CDC_ON_BOOT` disabled. Any startup error can be seen in Wokwi terminal by launching the code in simulator.
- Wokwi simulator
    - Wokwi simulator does not support resistive touch, only capacitive touch. The solution I chose to use capacitive touch setup for simulator while device works with resistive touch. The touch controller is interface is used in code to abstract away the implementation details. The build system has two environtment and depending which environment it's being built for, appropriate touch controller is loaded. Checkout `TouchControllerDriver` in `lib` for more insight.
    - For reason unknown, using tft_espi and adafruit FT6206 capacitive touch library in same project when microcontroller is esp32-s3 makes Wokwi go to boot loop. So, the simulator is using generic esp32 which works. Hardware isn't too important for simulators. All we want to check is if our feature is working as expected. With the help of the abstracted code it was achieved and we can forget about the mismatch of device between real device and simulator.
- Display and Touch controller rotation axis mismatch
    - The `tft_espi` and `XPT2046_Touchscreen` has their own implementation of rotation. They both take numeric value but the origin point differs. For this project a landscape solution is necessary and it turns out given rotation value `1` to both makes their origin point of the coordinate system same but the axis are flipped. I simply switched the output from `XPT2046_Touchscreen` because I don't want to implement a proper rotation algorithm. Did a similar thing for the simulator touch controller as well.
