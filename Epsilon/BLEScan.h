
#ifndef BLESCAN_H
#define BLESCAN_H

#include <Arduino.h> // Assurez-vous d'inclure la bibliothèque Arduino.h en premier.

#include <BLEDevice.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <BLEUUID.h>

#include "OledDisplay.h"

class BLEScanner {
public:
    void BLEsetUp();
    void bleScan(int nbScan);
};
#endif