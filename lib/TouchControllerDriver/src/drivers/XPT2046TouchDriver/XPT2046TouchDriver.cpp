#include "XPT2046TouchDriver.h"

XPT2046TouchDriver::XPT2046TouchDriver(uint8_t clk, uint8_t miso, uint8_t mosi, uint8_t cs, uint8_t irq, uint8_t spiBus)
    : touchscreenSPI(SPIClass(spiBus)), touchscreen(XPT2046_Touchscreen(cs, irq)) {
    touchscreenSPI.begin(clk, miso, mosi, cs);
}

void XPT2046TouchDriver::init() {
    touchscreen.begin(touchscreenSPI);
    touchscreen.setRotation(1);
}

void XPT2046TouchDriver::setRotation(uint8_t rotation) {
    touchscreen.setRotation(rotation);
}

bool XPT2046TouchDriver::isTouched() {
    return touchscreen.touched() && touchscreen.tirqTouched();
}

Point XPT2046TouchDriver::getTouchedPoint() {
    TS_Point touchedPoint = touchscreen.getPoint();

    return Point(touchedPoint.x, touchedPoint.y, touchedPoint.z);
}
