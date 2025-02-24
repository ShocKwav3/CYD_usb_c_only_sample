#pragma once

#include "cstdint"

struct DisplayConfig {
    uint32_t width;
    uint32_t height;

    DisplayConfig(uint32_t w, uint32_t h);
};
