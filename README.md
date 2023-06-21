# Callmebot ESP32 Library
[![arduino-library-badge](https://www.ardu-badge.com/badge/Callmebot%20ESP32.svg?)](https://www.ardu-badge.com/Callmebot%20ESP32)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/hafidh/library/Callmebot%20ESP32.svg)](https://registry.platformio.org/libraries/hafidh/Callmebot%20ESP32)
[![GitHub release](https://img.shields.io/github/release/hafidhh/Callmebot-ESP32.svg)](https://github.com/hafidhh/Callmebot-ESP32/releases)
[![License](https://img.shields.io/github/license/hafidhh/Callmebot-ESP32.svg?)](https://github.com/hafidhh/Callmebot-ESP32/blob/master/LICENSE.md)
   
## 🚀 Description
CallMeBot Library for ESP32   

## 🔥 Features
* **Whatsapp Message**
* **Facebook Message**
* **Telegram Call**
* **Telegram Call Mp3 play**
* **Telegram Message**
* **Telegram Group Message**

## ✨ Tested Device
* **NodeMCU ESP32**

## 💻 Usage
### initialization
```cpp
#include <Callmebot_ESP32.h>
```
### WhatsApps Massage
Send Whatapps message  
To get apiKey follow the instruction on https://www.callmebot.com/blog/free-api-whatsapp-messages/  
param :
* phoneNumber : Indonesia +62, Example: "+62897461238"
* apiKey : "apiKey".
* message : "textmessage"
```cpp
Callmebot.whatsappMessage("phoneNumber", "apiKey", "message");
```

### Facebook Message
Send Facebook message  
To get apiKey follow the instruction on https://www.callmebot.com/blog/free-api-facebook-messenger/  
param :
* apiKey : "apiKey"
* message : "textmessage"
```cpp
Callmebot.facebookMessage("apiKey", "message");
```

### Telegram Call
You need to authorize CallMeBot to contact you using this [link](https://api2.callmebot.com/txt/login.php). Or alternatively, you can start the bot sending /start to @CallMeBot_txtbot.  
param :
* username : username/phone.  
username : @username, exmaple : "@rambo"   
phone : Indonesia +62, Example : "+62897461238"
* message : "textmessage".
* language : default = en-US-Neural2-J.  
if you want to change the voice, you can get voice name on https://cloud.google.com/text-to-speech/docs/voices
* repeat : default = 2.
* textcarbon : default "yes".  
yes: To always send a copy of the text message together with the call (default).  
no: To do not send a copy of the message as a Text Message.  
missed: To only send a Text Message if the call is missed or rejected.  
only: To only send a text message (only available on dedicated bots).
* timeout : default = 30.
```cpp
Callmebot.telegramCall("@username", "message");
```

### Telegram Call Mp3
You need to authorize CallMeBot to contact you using this [link](https://api2.callmebot.com/txt/login.php). Or alternatively, you can start the bot sending /start to @CallMeBot_txtbot.  
param :
* username : username/phone.  
username : @username, exmaple : "@rambo"   
phone : Indonesia +62, Example : "+62897461238"
* mp3link : mp3 file link. Example : "https://www.learningcontainer.com/wp-content/uploads/2020/02/Kalimba.mp3"
```cpp
Callmebot.telegramCall("@username", "mp3link");
```

### Telegram Message
You need to authorize CallMeBot to contact you using this [link](https://api2.callmebot.com/txt/login.php). Or alternatively, you can start the bot sending /start to @CallMeBot_txtbot.  
param :
* username : username/phone.  
username : @username, exmaple : "@rambo"   
phone : Indonesia +62, Example : "+62897461238"
* message : "textmessage"
```cpp
Callmebot.telegramMessage("@username", "message");
```
```cpp
String username = "@username1"+"|"+"@username2";
Callmebot.telegramMessage(username, "messsage");
```

### Telegram Group Message
To get apiKey follow the instruction on https://www.callmebot.com/blog/telegram-group-messages-api-easy/  
param :
* apiKey : "apiKey".
* message "textmessage".
* html_format : bold text.  
default = false.  
true if you want bold text. 
```cpp
Callmebot.telegramGroup("apiKey", "message");
```

## 🛡️ License
This project is licensed under the MIT License - see the [`LICENSE`](LICENSE.md) file for details.

## 🙏 Support
We all need support and motivation. Please give this project a ⭐️ to encourage and show that you liked it. Don't forget to leave a star ⭐️ before you move away.

If you found the project helpful, consider supporting us with a coffee.

<a href="https://github.com/sponsors/hafidhh">
    <img src="https://img.shields.io/badge/sponsor-30363D?style=for-the-badge&logo=GitHub-Sponsors&logoColor=#EA4AAA">
</a>
<a href="https://www.buymeacoffee.com/hafidh">
    <img src="https://img.shields.io/badge/Buy%20Me%20a%20Coffee-ffdd00?style=for-the-badge&logo=buy-me-a-coffee&logoColor=black">
</a>

## ✨ Link
<a href="https://www.callmebot.com/">
    <img 
    src="https://www.callmebot.com/wp-content/uploads/2019/10/Logo-Negro_x1.png"
    alt="CallMeBot"
    title="CallMeBot"
    style="height : 40px">
</a>
