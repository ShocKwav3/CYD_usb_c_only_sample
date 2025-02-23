#pragma once

#include "Wire.h"
#include "../../interfaces/TouchDriverInterface.h"

//forward declaration due to third party library name conflict
//See TouchControllerDriver dir readme for details
class Adafruit_FT6206;

class FT6206TouchDriver : public TouchDriverInterface {
private:
    Adafruit_FT6206* touchscreen;

public:
    FT6206TouchDriver(uint8_t sda, uint8_t scl);
    void init() override;
    void setRotation(uint8_t rotation) override;
    bool isTouched() override;
    Point getTouchedPoint() override;
};
