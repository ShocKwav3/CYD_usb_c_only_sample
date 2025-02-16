#include "Arduino.h"
#include "ST7789DisplayDriver.h"
#include "XPT2046TouchDriver.h"

ST7789DisplayDriver display;
XPT2046TouchDriver touch = XPT2046TouchDriver(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS, XPT2046_IRQ, HSPI);

#define FONT_SIZE 2

void printTouchToSerial(int touchX, int touchY, int touchZ) {
    Serial.print("X = ");
    Serial.print(touchX);
    Serial.print(" | Y = ");
    Serial.print(touchY);
    Serial.print(" | Pressure = ");
    Serial.print(touchZ);
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

    touch.init();
}

void loop() {
    if (touch.isTirqTouched() && touch.isTouched()) {
        TS_Point point = touch.getPoint();
        int touchCoordinateX = map(point.y, 200, 3800, 1, display.getScreenHeight());
        int touchCoordinateY = map(point.x, 240, 3700, 1, display.getScreenWidth());
        int touchCoordinateZ = point.z;

        display.printLine(
            "X = " + String(touchCoordinateX)
            + " | Y = " + String(touchCoordinateY)
            + " | Pressure = " + String(touchCoordinateZ)
        );
        printTouchToSerial(touchCoordinateX, touchCoordinateY, touchCoordinateZ);
    }

    delay(100);
}
