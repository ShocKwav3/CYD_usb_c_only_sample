#pragma once

#include "memory"
#include "interfaces/TouchDriverInterface.h"
#include "interfaces/TouchDriverAbstractFactoryInterface.h"
#include "dto/PinConfig/PinConfig.h"
#include "dto/DisplayConfig/DisplayConfig.h"
#include "drivers/XPT2046TouchDriver/factory/XPT2046TouchDriverFactory.h"
#include "drivers/FT6206TouchDriver/factory/FT6206TouchDriverFactory.h"

class TouchControllerDriver {
    public:
        static TouchDriverInterface& getInstance(const PinConfig& pinConfig, const DisplayConfig& displayConfig);

    private:
        TouchControllerDriver() {}
        static std::unique_ptr<TouchDriverInterface> instance;
};
