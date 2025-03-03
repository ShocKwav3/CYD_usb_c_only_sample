#include "TouchControllerDriver.h"

std::unique_ptr<TouchDriverInterface> TouchControllerDriver::instance = nullptr;

TouchDriverInterface& TouchControllerDriver::getInstance(const PinConfig& pinConfig, const DisplayConfig& displayConfig) {
    if (!instance) {
        #ifdef ENV_DEVICE
            instance = XPT2046TouchDriverFactory().createTouchDriver(pinConfig, displayConfig);
        #elif defined(ENV_SIM)
            instance = FT6206TouchDriverFactory().createTouchDriver(pinConfig, displayConfig);
        #else
            #error "No touch controller defined. Define ENV_SIM or ENV_DEVICE."
        #endif
    }

    return *instance;
}
