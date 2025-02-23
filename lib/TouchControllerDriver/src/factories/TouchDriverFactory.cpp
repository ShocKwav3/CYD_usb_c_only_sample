#include "TouchDriverFactory.h"

std::unique_ptr<TouchDriverInterface> TouchDriverFactory::createTouchDriver(const PinConfig& pinConfig) {
    #ifdef ENV_DEVICE
        return XPT2046TouchDriverFactory().createTouchDriver(pinConfig);
    #elif defined(ENV_SIM)
        return FT6206TouchDriverFactory().createTouchDriver(pinConfig);
    #else
        #error "No touch controller defined. Define ENV_SIM or ENV_DEVICE."
    #endif
}
