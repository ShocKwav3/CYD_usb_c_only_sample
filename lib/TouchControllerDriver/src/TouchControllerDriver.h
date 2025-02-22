#pragma once

#include "memory"
#include "interfaces/TouchDriverInterface.h"
#include "interfaces/TouchDriverFactoryInterface.h"
#include "dto/PinConfig/PinConfig.h"
#include "factories/TouchDriverFactory.h"

class TouchControllerDriver {
    public:
        static TouchDriverInterface& getInstance(const PinConfig& pinConfig);

    private:
        TouchControllerDriver() {}
        static std::unique_ptr<TouchDriverInterface> instance;
};
