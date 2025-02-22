#pragma once

#include "memory"
#include "TouchDriverInterface.h"

class TouchDriverFactoryInterface {
    public:
        virtual std::unique_ptr<TouchDriverInterface> createTouchDriver(const PinConfig& pinConfig) = 0;
        virtual ~TouchDriverFactoryInterface() {}
};
