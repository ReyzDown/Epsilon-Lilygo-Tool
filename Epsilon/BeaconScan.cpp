// Author: [Eunous]
// Creation Date: [11/13/23]
// Description: Implementation file for BeaconScan, defining functions for beacon scanning operations.
// The use of this code is solely the responsibility of the user.

#include "BeaconScan.h"

// Global variables
int scanTimer = 5; // In seconds
BLEScan *pBeaconScan;
Display BeaconDisplay;

// Callback class for handling BLE advertised device data
class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
        // Handling of BLE advertised device data

        // Check if the device has a name and print it
        if (advertisedDevice.haveName()) {
            Serial.print("Device name: ");
            Serial.println(advertisedDevice.getName().c_str());
            Serial.println("");
        }

        // Check if the device has a Service UUID and print it
        if (advertisedDevice.haveServiceUUID()) {
            BLEUUID devUUID = advertisedDevice.getServiceUUID();
            Serial.print("Found ServiceUUID: ");
            Serial.println(devUUID.toString().c_str());
            Serial.println("");
        }

        // Check if the device has Manufacturer Data
        if (advertisedDevice.haveManufacturerData() == true) {
            std::string strManufacturerData = advertisedDevice.getManufacturerData();

            // Convert Manufacturer Data to a uint8_t array
            uint8_t cManufacturerData[100];
            strManufacturerData.copy((char *)cManufacturerData, strManufacturerData.length(), 0);

            // Check if the Manufacturer Data corresponds to an iBeacon
            if (strManufacturerData.length() == 25 && cManufacturerData[0] == 0x4C && cManufacturerData[1] == 0x00) {
                // Print information about the iBeacon
                Serial.println("Found an iBeacon!");
                BLEBeacon oBeacon = BLEBeacon();
                oBeacon.setData(strManufacturerData);
                Serial.printf("iBeacon Frame\n");
                Serial.printf("ID: %04X Major: %d Minor: %d UUID: %s Power: %d\n", oBeacon.getManufacturerId(), ENDIAN_CHANGE_U16(oBeacon.getMajor()), ENDIAN_CHANGE_U16(oBeacon.getMinor()), oBeacon.getProximityUUID().toString().c_str(), oBeacon.getSignalPower());
            } else {
                // Print information about other manufacturer's beacons
                Serial.println("Found another manufacturer's beacon!");
                Serial.printf("strManufacturerData: %d ", strManufacturerData.length());
                for (int i = 0; i < strManufacturerData.length(); i++) {
                    Serial.printf("[%X]", cManufacturerData[i]);
                }
                Serial.printf("\n");
            }
        }

        // Handle Eddystone beacons
        // ...
    }
};

// Function to set up Beacon scanning
void BeaconScanner::BeaconSetUp() {
    Serial.println("Scanning...");

    // Initialize BLE and create a new scan
    BLEDevice::init("");
    pBeaconScan = BLEDevice::getScan();
    
    // Set up callbacks for advertised devices
    pBeaconScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());

    // Configure scan parameters
    pBeaconScan->setActiveScan(true); // Active scan uses more power but gets results faster
    pBeaconScan->setInterval(100);
    pBeaconScan->setWindow(99); // Less or equal to setInterval value
}

// Function to perform Beacon scanning
void BeaconScanner::BeaconScan(int nbScan) {
    // Start BLE scan and get results
    BLEScanResults foundDevices = pBeaconScan->start(scanTimer, false);
    
    // Print the number of devices found
    Serial.print("Devices found: ");
    Serial.println(foundDevices.getCount());
    Serial.println("Scan done!");

    // Display beacon information on the OLED screen
    BeaconDisplay.displayBeacon(foundDevices.getCount(), nbScan);
    
    // Clear scan results to release memory
    pBeaconScan->clearResults();
    
    // Delay before the next scan
    delay(2000);
}
