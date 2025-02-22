#pragma once

#include "../interfaces/TouchDriverInterface.h"
#include "../interfaces/TouchDriverFactoryInterface.h"
#include "../drivers/XPT2046TouchDriver/factory/XPT2046TouchDriverFactory.h"

class TouchDriverFactory : public TouchDriverFactoryInterface {
    public:
        std::unique_ptr<TouchDriverInterface> createTouchDriver(const PinConfig& pinConfig) override;
        ~TouchDriverFactory() {}
};
