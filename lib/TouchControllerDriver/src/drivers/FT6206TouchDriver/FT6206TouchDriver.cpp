#include "FT6206TouchDriver.h"
#include "Adafruit_FT6206.h"

FT6206TouchDriver::FT6206TouchDriver(uint8_t sda, uint8_t scl) {
    Wire.begin(sda, scl);
    touchscreen = new Adafruit_FT6206();
}

void FT6206TouchDriver::init() {
    bool hasTouchBegan = touchscreen->begin(40);

    if (!hasTouchBegan) {
        Serial.println("Error: Unable to initialize touch controller");
    }
}

void FT6206TouchDriver::setRotation(uint8_t rotation) {}

bool FT6206TouchDriver::isTouched() {
    return touchscreen->touched();
}

Point FT6206TouchDriver::getTouchedPoint() {
    TS_Point touchedPoint = touchscreen->getPoint();

    return Point(touchedPoint.x, touchedPoint.y, 0);
}
