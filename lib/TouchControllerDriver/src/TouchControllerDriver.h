#pragma once

#include "memory"
#include "interfaces/TouchDriverInterface.h"
#include "interfaces/TouchDriverFactoryInterface.h"
#include "dto/PinConfig/PinConfig.h"
#include "dto/DisplayConfig/DisplayConfig.h"
#include "factories/TouchDriverFactory.h"

class TouchControllerDriver {
    public:
        static TouchDriverInterface& getInstance(const PinConfig& pinConfig, const DisplayConfig& displayConfig);

    private:
        TouchControllerDriver() {}
        static std::unique_ptr<TouchDriverInterface> instance;
};
