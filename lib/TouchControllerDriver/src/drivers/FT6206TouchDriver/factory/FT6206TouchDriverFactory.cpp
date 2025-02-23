#include "FT6206TouchDriverFactory.h"

std::unique_ptr<TouchDriverInterface> FT6206TouchDriverFactory::createTouchDriver(const PinConfig& pinConfig) {
    return std::make_unique<FT6206TouchDriver>(
        pinConfig.sdaPin,
        pinConfig.sclPin
    );
}
