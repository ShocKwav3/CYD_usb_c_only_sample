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
