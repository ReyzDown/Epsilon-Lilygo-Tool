// Author: [Eunous]
// Creation Date: [11/13/23]
// Description: This program performs BLE scanning and displays the results on an OLED screen.
// The use of this code is solely the responsibility of the user.

#include "BLEScan.h"


Display DisplayBLE;

BLEScan* pBLEScan;
int scanTime = 5; 
class BLECallBacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      Serial.printf("Advertised Device: %s \n", advertisedDevice.toString().c_str());
    }
};

void BLEScanner::BLEsetUp(){

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan(); //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new BLECallBacks());
  pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);  // less or equal setInterval value
}

void BLEScanner::bleScan(int nbScan) {
  BLEScanResults foundBLE = pBLEScan->start(scanTime, false);
  Serial.print("Devices found: ");
  Serial.println(foundBLE.getCount());
  Serial.println("Scan done!");
  pBLEScan->clearResults();   
  DisplayBLE.displayBLEScan(foundBLE.getCount(), nbScan);
  delay(2000);  
}

