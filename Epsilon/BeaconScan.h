
#ifndef BEACONSCAN_H
#define BEACONSCAN_H

#include <Arduino.h> // Assurez-vous d'inclure la bibliothèque Arduino.h en premier.

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <BLEEddystoneURL.h>
#include <BLEEddystoneTLM.h>
#include <BLEBeacon.h>

#include "OledDisplay.h"

class BeaconScanner {
public:
    void BeaconSetUp();
    void BeaconScan(int nbScan);
};
#endif