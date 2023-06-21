/**
 * @file Callmebot_ESP32.cpp
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/Callmebot-ESP32
 */

#include "Callmebot_ESP32.h"

Callmebot_ESP32 Callmebot;

/**
 * converts error code to String
 * @param error int
 * @return String
 */
String Callmebot_ESP32::errorToString(int error)
{
    switch(error) {
    case HTTPC_ERROR_CONNECTION_REFUSED:
        return F("connection refused");
    case HTTPC_ERROR_SEND_HEADER_FAILED:
        return F("send header failed");
    case HTTPC_ERROR_SEND_PAYLOAD_FAILED:
        return F("send payload failed");
    case HTTPC_ERROR_NOT_CONNECTED:
        return F("not connected");
    case HTTPC_ERROR_CONNECTION_LOST:
        return F("connection lost");
    case HTTPC_ERROR_NO_STREAM:
        return F("no stream");
    case HTTPC_ERROR_NO_HTTP_SERVER:
        return F("no HTTP server");
    case HTTPC_ERROR_TOO_LESS_RAM:
        return F("too less ram");
    case HTTPC_ERROR_ENCODING:
        return F("Transfer-Encoding not supported");
    case HTTPC_ERROR_STREAM_WRITE:
        return F("Stream write error");
    case HTTPC_ERROR_READ_TIMEOUT:
        return F("read Timeout");
    default:
        return String();
    }
}

/**
 * @brief set clock (NTP)
 * 
 */
void Callmebot_ESP32::clock()
{
	// Set time via NTP, as required for x.509 validation
	configTime(0, 0, "pool.ntp.org", "time.nist.gov");
	time_t now = time(nullptr);
	while (now < 8 * 3600 * 2) {
		delay(500);
		now = time(nullptr);
	}
	struct tm timeinfo;
	gmtime_r(&now, &timeinfo);
}

void Callmebot_ESP32::callmebothttps(String url)
{
	WiFiClientSecure client;
	client.setCACert(cert_ISRG_Root_X1);
	HTTPClient https;

	this->httpStatus = https.begin(client, host+url);

	if (this->httpStatus)
	{
		// start connection and send HTTP header
		this->httpResponseCode = https.GET();
		https.end();
	}
	
}

/**
 * CallMeBot WhatsApp Messages.
 * @param phoneNumber Indonesia +62, Example: "+62897461238".
 * @param apiKey "apiKey", to get apiKey : https://www.callmebot.com/blog/free-api-whatsapp-messages/.
 * @param message "textmessage".
 */
void Callmebot_ESP32::whatsappMessage(String phoneNumber, String apiKey, String message)
{
	String url = "/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
	
	this->callmebothttps(url);
}

/**
 * CallMeBot Facebook Messages.
 * @param apiKey "apiKey", to get apiKey : https://www.callmebot.com/blog/free-api-facebook-messenger/.
 * @param message "textmessage".
 */
void Callmebot_ESP32::facebookMessage(String apiKey, String message)
{
	String url = "/facebook/send.php?apikey=" + apiKey + "&text=" + urlEncode(message);

	this->callmebothttps(url);
}

/**
 * CallMeBot WhatsApp Messages.
 * @param username username/phone. phone: Indonesia +62, Example: "+62897461238".
 * @param message "textmessage".
 */
void Callmebot_ESP32::telegramMessage(String username, String message)
{
	String url = "/text.php?user=" + username + "&text=" + urlEncode(message);

	this->callmebothttps(url);
}

/**
 * @brief CallMeBot Telegram Group Messages.
 * 
 * @param apiKey "apiKey", to get apiKey : https://www.callmebot.com/blog/telegram-group-messages-api-easy/.
 * @param message "textmessage".
 * @param html_format true/false. default = false. true if you want bold text.
 */
void Callmebot_ESP32::telegramGroup(String apiKey, String message, bool html_format)
{
	String html = "no";
	
	if (html_format == true)
	{
		html = "yes";
	}

	String url = "/telegram/group.php?apikey=" + apiKey + "&text=" + urlEncode(message) + "&html=" + html;
	
	this->callmebothttps(url);
}

/**
 * @brief CallMeBot Telegram Call.
 * 
 * @param username username/phone. phone: Indonesia +62, Example: "+62897461238".
 * @param message "textmessage".
 * @param language default = en-US-Neural2-J. if you want to change the voice, you can get voice name on https://cloud.google.com/text-to-speech/docs/voices
 * @param repeat default = 2.
 * @param textcarbon default "yes".
 * yes: To always send a copy of the text message together with the call (default).
 * no: To do not send a copy of the message as a Text Message.
 * missed: To only send a Text Message if the call is missed or rejected.
 * only: To only send a text message (only available on dedicated bots).
 * @param timeout default = 30.
 */
void Callmebot_ESP32::telegramCall(String username, String message, String language, unsigned long repeat, String textcarbon, unsigned long timeout)
{
	String url = "/start.php?user=" + username + "&text=" + urlEncode(message) + "&lang=" + language + "&rpt=" + String(repeat) + "&cc=" + textcarbon + "&timeout=" + String(timeout);
	
	this->callmebothttps(url);
}

/**
 * @brief play mp3 on telegram call
 * 
 * @param username username/phone. phone: Indonesia +62, Example: "+62897461238".
 * @param mp3link mp3 file link.
 */
void Callmebot_ESP32::telegramCallMp3(String username, String mp3link)
{
	String url = "/start.php?user=" + username + "&file=" + urlEncode(mp3link);

	this->callmebothttps(url);
}

/**
 * @brief show debug
 * 
 * @return httpResponse
 */
String Callmebot_ESP32::debug()
{
	String Response;
	if (this->httpStatus==true)
	{
		// httpResponseCode will be negative on error
		if (this->httpResponseCode > 0)
		{
			if (this->httpResponseCode == HTTP_CODE_OK)
			{
				Response = "Call/Message Request sent successfully";
			}
			else
			{
				Response = "Call/Message Request failed\n";
				Response += "[HTTPS] GET... code: ";
				Response += String(this->httpResponseCode);
			}
		}
		else
		{
			Response = "[HTTPS] GET... failed, error: ";
			Response += this->errorToString(httpResponseCode).c_str();
		}
	}
	else
	{
		Response = "[HTTPS] Unable to connect\n";
		Response += "Check your connection";
	}
	return Response;
}