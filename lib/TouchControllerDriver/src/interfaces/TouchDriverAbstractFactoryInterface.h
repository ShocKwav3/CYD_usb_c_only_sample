#pragma once

#include "memory"
#include "TouchDriverInterface.h"

class TouchDriverAbstractFactoryInterface {
    public:
        virtual std::unique_ptr<TouchDriverInterface> createTouchDriver(
            const PinConfig& pinConfig,
            const DisplayConfig& displayConfig
        ) = 0;
        virtual ~TouchDriverAbstractFactoryInterface() {}
};
