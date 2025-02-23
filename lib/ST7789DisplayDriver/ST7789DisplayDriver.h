#pragma once

#include "TFT_eSPI.h"

class ST7789DisplayDriver {
private:
    TFT_eSPI tftDisplay;

public:
    enum class Color : uint16_t {
        BLACK = TFT_BLACK,
        WHITE = TFT_WHITE,
    };

    ST7789DisplayDriver();
    void init();
    void setCursorPosition(int16_t x, int16_t y);
    void setFontSize(uint8_t font);
    void setTextColor(Color textColor);
    int16_t getScreenHeight();
    int16_t getScreenWidth();
    void drawCentreString(const char *string, int32_t dX, int32_t poY, uint8_t font);
    void printLine(const String& text);
};
