#pragma once

#include "memory"
#include "../../../interfaces/TouchDriverFactoryInterface.h"
#include "../FT6206TouchDriver.h"

class FT6206TouchDriverFactory : public TouchDriverFactoryInterface {
    public:
        std::unique_ptr<TouchDriverInterface> createTouchDriver(
            const PinConfig& pinConfig,
            const DisplayConfig& displayConfig
        ) override;
        ~FT6206TouchDriverFactory() {}
};
