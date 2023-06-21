/**
 * @file Callmebot_ESP32.h
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/Callmebot-ESP32
 */

#ifndef Callmebot_ESP32_h
#define Callmebot_ESP32_h

#include "Arduino.h"
#include "WiFi.h"
#include "certs.h"
#include "UrlEncode.h"
#include "HTTPClient.h"
#include "WiFiClientSecure.h"

class Callmebot_ESP32
{
private:
    const char* host = "https://api.callmebot.com";
    const uint16_t port = 443;
    bool httpStatus;
    int httpResponseCode;
    void clock();
    void callmebothttps(String url);
    String errorToString(int error);
public:
    void whatsappMessage(String phoneNumber, String apiKey, String message);
    void facebookMessage(String apiKey, String message);
    void telegramMessage(String username, String message);
    void telegramGroup(String apiKey, String message, bool html_format = false);
    void telegramCall(String username, String message, String language = "en-US-Neural2-J", unsigned long repeat = 2, String textcarbon = "yes", unsigned long timeout = 30);
    void telegramCallMp3(String username, String mp3link);
    String debug();
};

extern Callmebot_ESP32 Callmebot;

#endif