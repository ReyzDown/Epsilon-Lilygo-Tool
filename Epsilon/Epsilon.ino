
#include "Wifi.h"
#include "BLEScan.h"
#include "BeaconScan.h"

// Create instances of the BeaconScanner, BLEScanner, and WiFiScanner classes
BeaconScanner BS;
BLEScanner BLES;
WiFiScanner Wifi;
int count = 1;

void setup() {
  Serial.begin(115200);
  Wifi.Disconnect();  // Disconnect from Wi-Fi
  BS.BeaconSetUp();   // Set up Beacon scanning
  BLES.BLEsetUp();     // Set up BLE scanning
}

void loop() {
  Wifi.Scan(count);      // Perform Wi-Fi scanning
  Wifi.RickRoll();       // Execute a Rickroll
  BS.BeaconScan(count);  // Perform Beacon scanning
  BLES.bleScan(count);   // Perform BLE scanning

  count++;  // Increment the scan count
}
