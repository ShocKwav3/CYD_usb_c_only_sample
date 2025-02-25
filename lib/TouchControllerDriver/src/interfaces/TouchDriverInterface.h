#pragma once

#include "cstdint"
#include "../dto/PinConfig/PinConfig.h"
#include "../dto/Point/Point.h"
#include "../dto/DisplayConfig/DisplayConfig.h"

class TouchDriverInterface {
    public:
        virtual void init() = 0;
        virtual void setRotation(uint8_t rotation) = 0;
        virtual bool isTouched() = 0;
        virtual Point getTouchedPoint() = 0;
        virtual ~TouchDriverInterface() {}
};
