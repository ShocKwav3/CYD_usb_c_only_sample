#include "Arduino.h"
#include "ST7789DisplayDriver.h"
#include "TouchControllerDriver.h"
#include "../config/PinConfigDefaults.h"

#define FONT_SIZE 2

ST7789DisplayDriver display;
PinConfig pinConfig(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS, XPT2046_IRQ, HSPI, FT6202_SDA, FT6202_SCL);
TouchDriverInterface& touchControllerDriver = TouchControllerDriver::getInstance(pinConfig);

void printTouchToSerial(int touchX, int touchY, int pressureZ) {
    Serial.print("X = ");
    Serial.print(touchX);
    Serial.print(" | Y = ");
    Serial.print(touchY);
    Serial.print(" | Pressure = ");
    Serial.print(pressureZ);
    Serial.println();
}

void setup() {
    Serial.begin(460800);

    display.init();
    display.setTextColor(ST7789DisplayDriver::Color::WHITE);

    int centerCoordinateX = display.getScreenWidth() / 2;
    int centerCoordinateY = display.getScreenHeight() / 2;

    display.drawCentreString("Hello, world!", centerCoordinateX, 30, FONT_SIZE);
    display.drawCentreString("Touch screen to test", centerCoordinateX, centerCoordinateY, FONT_SIZE);

    touchControllerDriver.init();

    delay(1000);
}

void loop() {
    if (touchControllerDriver.isTouched()) {
        Point point = touchControllerDriver.getTouchedPoint();
        int touchCoordinateX = map(point.coordinateX, 200, 3800, 1, display.getScreenHeight());
        int touchCoordinateY = map(point.coordinateY, 240, 3700, 1, display.getScreenWidth());
        int touchCoordinateZ = point.pressureZ;

        display.printLine(
            "X = " + String(touchCoordinateX)
            + " | Y = " + String(touchCoordinateY)
            + " | Pressure = " + String(touchCoordinateZ)
        );
        printTouchToSerial(touchCoordinateX, touchCoordinateY, touchCoordinateZ);
    }

    delay(100);
}

//we need to rename getTouchedPoint -> getRawTouchedPoint
//we need to have each drivers own mapping function
//we need to define and implement rotation for FT6206