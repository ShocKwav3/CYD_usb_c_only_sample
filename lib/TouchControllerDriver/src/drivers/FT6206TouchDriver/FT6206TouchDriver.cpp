#include "FT6206TouchDriver.h"
#include "Adafruit_FT6206.h"

FT6206TouchDriver::FT6206TouchDriver(
    uint8_t sda,
    uint8_t scl,
    uint32_t dWidth,
    uint32_t dHeight
) : displayWidth(dWidth),
    displayHeight(dHeight) {
    Wire.begin(sda, scl);
    touchscreen = new Adafruit_FT6206();
}

void FT6206TouchDriver::init() {
    bool hasTouchBegan = touchscreen->begin(40);

    if (!hasTouchBegan) {
        Serial.println("Error: Unable to initialize touch controller");

        return;
    }

    this->setRotation(1);
}

void FT6206TouchDriver::setRotation(uint8_t rotation) {
    touchRotation = rotation;
}

bool FT6206TouchDriver::isTouched() {
    return touchscreen->touched();
}

Point FT6206TouchDriver::getTouchedPoint() {
    TS_Point touchedPoint = touchscreen->getPoint();

    //Output swapped for rotation axis discrepancies between display and touch driver
    return Point(
        touchedPoint.y,
        displayWidth - touchedPoint.x,
        0
    );
}
