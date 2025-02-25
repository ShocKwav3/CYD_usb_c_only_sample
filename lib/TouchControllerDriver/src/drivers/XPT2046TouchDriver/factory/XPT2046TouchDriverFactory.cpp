#include "XPT2046TouchDriverFactory.h"

std::unique_ptr<TouchDriverInterface> XPT2046TouchDriverFactory::createTouchDriver(
    const PinConfig& pinConfig,
    const DisplayConfig& displayConfig
) {
    return std::make_unique<XPT2046TouchDriver>(
        pinConfig.clkPin,
        pinConfig.misoPin,
        pinConfig.mosiPin,
        pinConfig.csPin,
        pinConfig.irqPin,
        pinConfig.spiBusId,
        displayConfig.width,
        displayConfig.height
    );
}
