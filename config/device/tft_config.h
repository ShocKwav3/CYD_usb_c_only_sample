#pragma once

#define USER_SETUP_LOADED //Stops tft_eSPI from loading default user setup that replaces following macros

#define ST7789_DRIVER  // Full configuration option, define additional parameters below for this display

#define TFT_WIDTH 240  // ST7789 172 x 320
#define TFT_HEIGHT 320 // ST7789 240 x 320

#define TFT_RGB_ORDER TFT_BGR

// the following are also used in touch_config.h
#define TFT_MOSI 13
#define TFT_MISO 12
#define TFT_SCLK 14
#define TFT_CS   15  // Chip select control pin
#define TFT_DC   2  // Data Command control pin
#define TFT_RST  -1  // Reset pin (could connect to RST pin)
#define TOUCH_CS 33

#define TFT_BL 27  // LED back-light control pin
#define TFT_BACKLIGHT_ON HIGH  // Level to turn ON back-light (HIGH or LOW)
#define TFT_INVERSION_OFF

#define ESP32_DMA
#define USE_HSPI_PORT

#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
#define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
//#define LOAD_FONT8N // Font 8. Alternative to Font 8 above, slightly narrower, so 3 digits fit a 160 pixel TFT
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

#define SMOOTH_FONT

#define SPI_FREQUENCY 80000000
#define SPI_TOUCH_FREQUENCY  2500000