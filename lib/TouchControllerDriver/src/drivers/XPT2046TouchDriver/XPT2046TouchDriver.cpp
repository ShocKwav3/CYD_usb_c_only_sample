#include "XPT2046TouchDriver.h"

XPT2046TouchDriver::XPT2046TouchDriver(uint8_t clk, uint8_t miso, uint8_t mosi, uint8_t cs, uint8_t irq, uint8_t spiBus)
    : touchscreenSPI(SPIClass(spiBus)), touchscreen(XPT2046_Touchscreen(cs, irq)) {
        delay(100);
    touchscreenSPI.begin(clk, miso, mosi, cs);
}

void XPT2046TouchDriver::init() {
    delay(100);
    touchscreen.begin(touchscreenSPI);
    delay(100);
    touchscreen.setRotation(1);
}

void XPT2046TouchDriver::setRotation(uint8_t rotation) {
    touchscreen.setRotation(rotation);
}

bool XPT2046TouchDriver::isTouched() {
    Serial.println("isTouched");
    Serial.println(touchscreen.touched());
    Serial.println("isTirqTouched");
    Serial.println(touchscreen.tirqTouched());
    return false;
    //return touchscreen.touched() && touchscreen.tirqTouched();
}

Point XPT2046TouchDriver::getTouchedPoint() {
    TS_Point touchedPoint = touchscreen.getPoint();

    return Point(touchedPoint.x, touchedPoint.y, touchedPoint.z);
}
