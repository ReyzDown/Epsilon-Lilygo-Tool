
#ifndef WIFI_SCANNER_H
#define WIFI_SCANNER_H

#include <WiFi.h>
#include "OledDisplay.h"
#include "String.h"


class WiFiScanner {
public:
    void Scan(int nbScan);
    void Disconnect();
    void RickRoll();  

};
#endif