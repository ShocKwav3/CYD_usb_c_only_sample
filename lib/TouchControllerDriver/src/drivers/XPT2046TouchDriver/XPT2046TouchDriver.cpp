#include "XPT2046TouchDriver.h"
#include "XPT2046_Touchscreen.h"

XPT2046TouchDriver::XPT2046TouchDriver(
    uint8_t clk,
    uint8_t miso,
    uint8_t mosi,
    uint8_t cs,
    uint8_t irq,
    uint8_t spiBus,
    uint32_t dWidth,
    uint32_t dHeight
) : touchscreenSPI(SPIClass(spiBus)),
    displayWidth(dWidth),
    displayHeight(dHeight) {
    touchscreenSPI.begin(clk, miso, mosi, cs);
    touchscreen = new XPT2046_Touchscreen(cs, irq);
}

void XPT2046TouchDriver::init() {
    touchscreen->begin(touchscreenSPI);
    touchscreen->setRotation(1);
}

void XPT2046TouchDriver::setRotation(uint8_t rotation) {
    touchscreen->setRotation(rotation);
}

bool XPT2046TouchDriver::isTouched() {
    return touchscreen->touched() && touchscreen->tirqTouched();
}

Point XPT2046TouchDriver::getTouchedPoint() {
    TS_Point touchedPoint = touchscreen->getPoint();

    //Output swapped for rotation axis discrepancies between display and touch driver
    return Point(
        map(touchedPoint.y, 250, 3850, 1, displayHeight),
        map(touchedPoint.x, 240, 3830, 1, displayWidth),
        touchedPoint.z
    );
}
