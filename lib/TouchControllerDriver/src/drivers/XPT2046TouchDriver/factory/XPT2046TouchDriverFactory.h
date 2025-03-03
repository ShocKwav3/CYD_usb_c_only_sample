#pragma once

#include "memory"
#include "../../../interfaces/TouchDriverAbstractFactoryInterface.h"
#include "../XPT2046TouchDriver.h"

class XPT2046TouchDriverFactory : public TouchDriverAbstractFactoryInterface {
    public:
        std::unique_ptr<TouchDriverInterface> createTouchDriver(
            const PinConfig& pinConfig,
            const DisplayConfig& displayConfig
        ) override;
        ~XPT2046TouchDriverFactory() {}
};
