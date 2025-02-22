#include "TouchDriverFactory.h"

std::unique_ptr<TouchDriverInterface> TouchDriverFactory::createTouchDriver(const PinConfig& pinConfig) {
    #ifdef ENV_DEVICE
        return XPT2046TouchDriverFactory().createTouchDriver(pinConfig);
    #else
        #error "No touch controller defined. Define ENV_SIM or ENV_DEVICE."
    #endif
}
