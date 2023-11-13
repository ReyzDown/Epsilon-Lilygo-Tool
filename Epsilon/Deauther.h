#ifndef DEAUTHER_H
#define DEAUTHER_H

// #include <WiFi.h>
// #include "esp_wifi.h"
#include <string.h>
#include <Arduino.h>
#include "esp_wifi.h"

typedef uint8_t MacAddr[6];

class Deauther {
public:
    esp_err_t deauth(const MacAddr ap, const MacAddr station,
        const MacAddr bssid, uint8_t channel);
    esp_err_t esp32_deauther_configure_wifi(uint8_t channel);
    void spam_task();
    esp_err_t raw(const uint8_t* packet, int32_t len, bool en_sys_seq);

private:
    esp_err_t change_channel(uint8_t channel) ;
    uint16_t seqnum;
    uint8_t buffer[200];

};
#endif
