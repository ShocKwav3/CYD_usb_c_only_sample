#include "Arduino.h"
#include "ST7789DisplayDriver.h"
#include "TouchControllerDriver.h"
#include "../config/PinConfigDefaults.h"

#define FONT_SIZE 2

ST7789DisplayDriver display;
DisplayConfig displayConfig(TFT_WIDTH, TFT_HEIGHT);
PinConfig pinConfig(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS, XPT2046_IRQ, HSPI, FT6202_SDA, FT6202_SCL);
TouchDriverInterface& touchControllerDriver = TouchControllerDriver::getInstance(pinConfig, displayConfig);

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

    /*int centerCoordinateX = display.getScreenWidth() / 2;
    int centerCoordinateY = display.getScreenHeight() / 2;

    display.drawCentreString("Hello, world!", centerCoordinateX, 30, FONT_SIZE);
    display.drawCentreString("Touch screen to test", centerCoordinateX, centerCoordinateY, FONT_SIZE);*/

    display.setCursorPosition(15, 30);
    display.printLine("Hello, world!");
    display.printLine("Touch screen to test");

    touchControllerDriver.init();

    delay(1000);
}

void loop() {
    if (touchControllerDriver.isTouched()) {
        Point point = touchControllerDriver.getTouchedPoint();

        display.printLine(
            "X = " + String(point.coordinateX)
            + " | Y = " + String(point.coordinateY)
            + " | Pressure = " + String(point.pressureZ)
        );
        printTouchToSerial(point.coordinateX, point.coordinateY, point.pressureZ);
    }

    delay(100);
}
