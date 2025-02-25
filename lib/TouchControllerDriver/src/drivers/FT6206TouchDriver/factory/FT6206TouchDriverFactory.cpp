#include "FT6206TouchDriverFactory.h"

std::unique_ptr<TouchDriverInterface> FT6206TouchDriverFactory::createTouchDriver(
    const PinConfig& pinConfig,
    const DisplayConfig& displayConfig
) {
    return std::make_unique<FT6206TouchDriver>(
        pinConfig.sdaPin,
        pinConfig.sclPin,
        displayConfig.width,
        displayConfig.height
    );
}
