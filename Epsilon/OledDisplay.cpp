// Author: [Eunous]
// Creation Date: [11/13/23]
// Description: Implementation file for OledDisplay, providing functions to display various information on an OLED screen.
// The use of this code is solely the responsibility of the user.


#include "OledDisplay.h"

#define SCREEN_WIDTH 128  // OLED width, in pixels
#define SCREEN_HEIGHT 64  // OLED height, in pixels

// Create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

// Function to display a Rickroll image on the OLED screen
void Display::displayRickRoll() {
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize OLED with I2C address 0x3C
  oled.clearDisplay();                      // Clear the OLED display
  oled.drawBitmap(0, 0, rickroll, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);  // Draw the Rickroll image
  oled.display();                           // Display the content on the OLED screen
  delay(1000);                              // Pause for 1 second
}

// Function to display Wi-Fi scan information on the OLED screen
void Display::displayWifiScan(int deviceFound, int nbScan) {
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize OLED with I2C address 0x3C
  oled.clearDisplay();                      // Clear the OLED display
  oled.setTextColor(WHITE);                 // Set text color to white
  oled.setTextSize(1);                      // Set text size to 1
  oled.setCursor(0, 0);
  oled.print("EPSILON\n");                   // Display "EPSILON"
  oled.setCursor(0, 10);
  oled.print("Device Found: ");
  oled.print(deviceFound);                   // Display the number of devices found
  oled.print("\nScan Number: ");
  oled.print(nbScan);                        // Display the scan number
  oled.display();                            // Display the content on the OLED screen
}

// Function to display BLE scan information on the OLED screen
void Display::displayBLEScan(int deviceFound, int nbScan) {
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize OLED with I2C address 0x3C
  oled.clearDisplay();                      // Clear the OLED display
  oled.setTextSize(1);                      // Set text size to 1
  oled.setTextColor(WHITE);                 // Set text color to white
  oled.setCursor(0, 0);
  oled.print("EPSILON");
  oled.setCursor(0, 10);
  oled.println("Nb BLE found:");             // Display "Nb BLE found"
  oled.print(deviceFound);                   // Display the number of BLE devices found
  oled.println("Nb Scan: ");
  oled.print(nbScan);                        // Display the scan number
  oled.display();                            // Display the content on the OLED screen
}

// Function to display beacon information on the OLED screen
void Display::displayBeacon(int deviceFound, int nbScan) {
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize OLED with I2C address 0x3C
  oled.clearDisplay();                      // Clear the OLED display
  oled.setTextSize(1);                      // Set text size to 1
  oled.setTextColor(WHITE);                 // Set text color to white
  oled.setCursor(0, 0);
  oled.print("EPSILON");
  oled.setCursor(0, 10);
  oled.print("\nNb Beacon found:");         // Display "Nb Beacon found"
  oled.print(deviceFound);                   // Display the number of beacons found
  oled.print("\nNb Scan: ");
  oled.print(nbScan);                        // Display the scan number
  oled.display();                            // Display the content on the OLED screen
}
