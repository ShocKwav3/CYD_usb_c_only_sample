#include "XPT2046TouchDriverFactory.h"

std::unique_ptr<TouchDriverInterface> XPT2046TouchDriverFactory::createTouchDriver(const PinConfig& pinConfig) {
    return std::make_unique<XPT2046TouchDriver>(
        pinConfig.clkPin,
        pinConfig.misoPin,
        pinConfig.mosiPin,
        pinConfig.csPin,
        pinConfig.irqPin,
        pinConfig.spiBusId
    );
}
