// Github :
// https://github.com/hafidhh
// https://github.com/hafidhh/Callmebot-ESP32

#ifndef Callmebot_ESP32_h
#define Callmebot_ESP32_h

#include "Arduino.h"

// WhatApp Message
void whatsappMessage(String phoneNumber, String apiKey, String message);

// Facebook Message
void facebookMessage(String apiKey, String message);

// Telegram Message
void telegramMessage(String username, String message);

// Telegram Message Group
void telegramGroup(String apiKey, String message);
void telegramGroup(String apiKey, String message, String html_format);

// Telegram Call
void telegramCall(String username, String message);
void telegramCall(String username, String message, String language);
void telegramCall(String username, String message, String language, String repeat);
void telegramCall(String username, String message, String language, String repeat, String textcarbon);
void telegramCall(String username, String message, String language, String repeat, String textcarbon, String timeout);

#endif