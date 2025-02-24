#pragma once

#include "memory"
#include "../../../interfaces/TouchDriverFactoryInterface.h"
#include "../XPT2046TouchDriver.h"

class XPT2046TouchDriverFactory : public TouchDriverFactoryInterface {
    public:
        std::unique_ptr<TouchDriverInterface> createTouchDriver(
            const PinConfig& pinConfig,
            const DisplayConfig& displayConfig
        ) override;
        ~XPT2046TouchDriverFactory() {}
};
