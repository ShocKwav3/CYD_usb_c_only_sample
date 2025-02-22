#include "TouchControllerDriver.h"

// Initialize the static member outside the class
std::unique_ptr<TouchDriverInterface> TouchControllerDriver::instance = nullptr;

TouchDriverInterface& TouchControllerDriver::getInstance(const PinConfig& pinConfig) {
    if (!instance) {
        std::unique_ptr<TouchDriverFactoryInterface> factory = std::make_unique<TouchDriverFactory>();
        instance = factory->createTouchDriver(pinConfig); // Factory creates the driver
    }
    return *instance;
}
