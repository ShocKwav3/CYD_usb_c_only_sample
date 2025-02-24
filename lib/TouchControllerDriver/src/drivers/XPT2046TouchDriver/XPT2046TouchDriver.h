#pragma once

#include "SPI.h"
#include "../../interfaces/TouchDriverInterface.h"

//forward declaration due to third party library name conflict
//See TouchControllerDriver dir readme for details
class XPT2046_Touchscreen;
class XPT2046TouchDriver : public TouchDriverInterface {
private:
    SPIClass touchscreenSPI;
    XPT2046_Touchscreen* touchscreen;

    uint32_t displayWidth;
    uint32_t displayHeight;

public:
    XPT2046TouchDriver(
        uint8_t clk,
        uint8_t miso,
        uint8_t mosi,
        uint8_t cs,
        uint8_t irq,
        uint8_t spiBus,
        uint32_t dWidth,
        uint32_t dHeight
    );
    void init() override;
    void setRotation(uint8_t rotation) override;
    bool isTouched() override;
    Point getTouchedPoint() override;
};
