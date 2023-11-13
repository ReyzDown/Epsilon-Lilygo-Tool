// Author: [Eunous]
// Creation Date: [11/13/23]
// Description: Implementation file for Wifi, defining functions for performing Wi-Fi scanning and related operations.
// The use of this code is solely the responsibility of the user.

#include "Wifi.h"

// Create an instance of the Display class for displaying Wi-Fi information
Display displayWifi;

// Function to perform Wi-Fi scanning
void WiFiScanner::Scan(int nbScan) {
    // Serial.println("Scan start");

    // WiFi.scanNetworks will return the number of networks found.
    int n = WiFi.scanNetworks();
    // Serial.println("Scan done");

    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        Serial.println("Nr | SSID                             | RSSI | CH |    Mac Address    | Encryption");
        for (int i = 0; i < n; ++i) {
            displayWifi(n, nbScan);
            // Print SSID and RSSI for each network found
            Serial.printf("%2d", i + 1);
            Serial.print(" | ");
            Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
            Serial.print(" | ");
            Serial.printf("%4d", WiFi.RSSI(i));
            Serial.print(" | ");
            Serial.printf("%2d", WiFi.channel(i));
            Serial.print(" | ");
            Serial.printf("%s | ", WiFi.BSSIDstr(i).c_str());
            switch (WiFi.encryptionType(i)) {
                case WIFI_AUTH_OPEN:
                    Serial.print("open");
                    break;
                case WIFI_AUTH_WEP:
                    Serial.print("WEP");
                    break;
                case WIFI_AUTH_WPA_PSK:
                    Serial.print("WPA");
                    break;
                case WIFI_AUTH_WPA2_PSK:
                    Serial.print("WPA2");
                    break;
                case WIFI_AUTH_WPA_WPA2_PSK:
                    Serial.print("WPA+WPA2");
                    break;
                case WIFI_AUTH_WPA2_ENTERPRISE:
                    Serial.print("WPA2-EAP");
                    break;
                case WIFI_AUTH_WPA3_PSK:
                    Serial.print("WPA3");
                    break;
                case WIFI_AUTH_WPA2_WPA3_PSK:
                    Serial.print("WPA2+WPA3");
                    break;
                case WIFI_AUTH_WAPI_PSK:
                    Serial.print("WAPI");
                    break;
                default:
                    Serial.print("unknown");
            }
            Serial.println();
            delay(10);
        }
    }
    Serial.println("");

    // Delete the scan result to free memory for code below.
    WiFi.scanDelete();

    // Wait a bit before scanning again.
    delay(5000);
}

// Function to disconnect from Wi-Fi
void WiFiScanner::Disconnect() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
}

// Array of lyrics for the "Never Gonna Give You Up" Rickroll
String never_gonna[] = {
    "We're no strangers to love",
    "You know the rules and so do I",
    "I just want to tell you how I'm feeling"
};

// Function to perform a Rickroll
void WiFiScanner::RickRoll() {
    displayWifi.displayRickRoll();
    size_t arraySize = sizeof(never_gonna) / sizeof(never_gonna[0]);
    size_t n = 0;
    while (n < arraySize) {
        WiFi.softAP(never_gonna[n].c_str());
        n++;
    }
}