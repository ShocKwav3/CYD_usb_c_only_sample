#pragma once

#include "memory"
#include "interfaces/TouchDriverInterface.h"
#include "interfaces/TouchDriverFactoryInterface.h"
#include "dto/PinConfig/PinConfig.h"
#include "factories/TouchDriverFactory.h"

class TouchControllerDriver {
    public:
        static TouchDriverInterface& getInstance(const PinConfig& pinConfig); // Returns a reference

    private:
        TouchControllerDriver() {} // Private constructor
        static std::unique_ptr<TouchDriverInterface> instance; // Static member
};
