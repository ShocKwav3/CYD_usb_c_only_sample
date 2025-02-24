#pragma once

#include "../interfaces/TouchDriverInterface.h"
#include "../interfaces/TouchDriverFactoryInterface.h"
#include "../drivers/XPT2046TouchDriver/factory/XPT2046TouchDriverFactory.h"
#include "../drivers/FT6206TouchDriver/factory/FT6206TouchDriverFactory.h"

class TouchDriverFactory : public TouchDriverFactoryInterface {
    public:
        std::unique_ptr<TouchDriverInterface> createTouchDriver(
            const PinConfig& pinConfig,
            const DisplayConfig& displayConfig
        ) override;
        ~TouchDriverFactory() {}
};
