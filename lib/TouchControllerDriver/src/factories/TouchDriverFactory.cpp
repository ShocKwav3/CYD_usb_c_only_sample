#include "TouchDriverFactory.h"

std::unique_ptr<TouchDriverInterface> TouchDriverFactory::createTouchDriver(const PinConfig& pinConfig, const DisplayConfig& displayConfig) {
    #ifdef ENV_DEVICE
        return XPT2046TouchDriverFactory().createTouchDriver(pinConfig, displayConfig);
    #elif defined(ENV_SIM)
        return FT6206TouchDriverFactory().createTouchDriver(pinConfig, displayConfig);
    #else
        #error "No touch controller defined. Define ENV_SIM or ENV_DEVICE."
    #endif
}
