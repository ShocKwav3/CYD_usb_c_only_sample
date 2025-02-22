#pragma once

#include "cstdint"

class PinConfig {
    public:
        uint8_t clkPin;
        uint8_t misoPin;
        uint8_t mosiPin;
        uint8_t csPin;
        uint8_t irqPin;
        uint8_t spiBusId;
        PinConfig(uint8_t clkPin, uint8_t misoPin, uint8_t mosiPin, uint8_t csPin, uint8_t irqPin, uint8_t spiBusId);
};
