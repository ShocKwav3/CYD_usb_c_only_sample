#include "ST7789DisplayDriver.h"

ST7789DisplayDriver::ST7789DisplayDriver() : tftDisplay(TFT_eSPI()) {}

void ST7789DisplayDriver::init() {
    tftDisplay.init();
    tftDisplay.setRotation(1); // Adjust orientation (1: Landscape, 0: Portrait, etc.)
    tftDisplay.fillScreen(static_cast<uint16_t>(Color::BLACK));
}

void ST7789DisplayDriver::setCursorPosition(int16_t x, int16_t y) {
    tftDisplay.setCursor(x, y);
}

void ST7789DisplayDriver::setFontSize(uint8_t fontSize) {
    tftDisplay.setTextFont(fontSize);
}

void ST7789DisplayDriver::setTextColor(Color textColor) {
    tftDisplay.setTextColor(static_cast<uint16_t>(textColor));
}

int16_t ST7789DisplayDriver::getScreenHeight() {
    return tftDisplay.height();
}

int16_t ST7789DisplayDriver::getScreenWidth() {
    return tftDisplay.width();
}

void ST7789DisplayDriver::drawCentreString(const char *string, int32_t dX, int32_t poY, uint8_t font) {
    tftDisplay.drawCentreString(string, dX, poY, font);
}

void ST7789DisplayDriver::printLine(const String& text) {
    tftDisplay.println(text);
}
