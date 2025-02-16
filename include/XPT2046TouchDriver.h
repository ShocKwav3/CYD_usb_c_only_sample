#pragma once

#include "SPI.h"
#include "XPT2046_Touchscreen.h"

class XPT2046TouchDriver {
private:
    SPIClass touchscreenSPI;
    XPT2046_Touchscreen touchscreen;

public:
    XPT2046TouchDriver(uint8_t clk, uint8_t miso, uint8_t mosi, uint8_t cs, uint8_t irq, uint8_t spiBus);
    void init();
    void setRotation(uint8_t rotation);
    bool isTouched();
    bool isTirqTouched();
    TS_Point getPoint();
};
