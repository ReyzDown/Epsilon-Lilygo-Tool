
#ifndef OLEDDISPLAY_H
#define OLEDDISPLAY_H

// #include <WiFi.h>
// #include "esp_wifi.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "String.h"
#include "images.h"

class Display {
public:
    void displayWifiScan(int deviceFound, int nbScan);
    void displayBLEScan(int deviceFound, int nbScan);
    void displayBeacon(int deviceFound, int nbScan);
    void displayRickRoll();
};
#endif
