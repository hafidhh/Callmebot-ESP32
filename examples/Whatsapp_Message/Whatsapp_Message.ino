/**
 * @file Whatsapp_Message.ino
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief Example WhatsApp Messages
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/Callmebot-ESP32
 */

#include <WiFi.h>
#include <Callmebot_ESP32.h>

const char* ssid = "your_ssid";
const char* password = "your_password";
// Note :
// phoneNumber : Indonesia +62, Example: "+62897461238"
// apiKey : Follow instruction on https://www.callmebot.com/blog/free-api-whatsapp-messages/
String phoneNumber = "your_phonenumber";
String apiKey = "your_apiKey";
String messsage = "your_text_message";

void setup() {
	Serial.begin(115200);

	WiFi.begin(ssid, password);
	Serial.println("Connecting");
	while(WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.print("Connected to WiFi network with IP Address: ");
	Serial.println(WiFi.localIP());

	// Whatsapp Message
	Callmebot.whatsappMessage(phoneNumber, apiKey, messsage);
	Serial.println(Callmebot.debug());
}

void loop() {
	
}