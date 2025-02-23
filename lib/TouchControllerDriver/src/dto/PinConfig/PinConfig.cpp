#include "PinConfig.h"

PinConfig::PinConfig(uint8_t clkPin, uint8_t misoPin, uint8_t mosiPin, uint8_t csPin, uint8_t irqPin, uint8_t spiBusId, uint8_t sdaPin, uint8_t sclPin)
    : clkPin(clkPin), misoPin(misoPin), mosiPin(mosiPin), csPin(csPin), irqPin(irqPin), spiBusId(spiBusId), sdaPin(sdaPin), sclPin(sclPin) {}
