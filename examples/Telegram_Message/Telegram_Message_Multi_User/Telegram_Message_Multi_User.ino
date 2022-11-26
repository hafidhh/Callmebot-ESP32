// Example Telegram Message Multi
// Github :
// https://github.com/hafidhh
// https://github.com/hafidhh/Callmebot-ESP32

#include <WiFi.h>
#include <Callmebot_ESP32.h>

const char* ssid = "your_ssid";
const char* password = "your_password";

// Note :
// username : @username or phonenumber (Indonesia +62, Example: "+62897461238")
// You need to authorize CallMeBot to contact you using this link : https://api2.callmebot.com/txt/login.php. 
// Or alternatively, you can start the bot sending /start to @CallMeBot_txtbot.
String username1 = "@your_username1/phonenumber1";
String username2 = "@your_username2/phonenumber2";
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

  //Telegram Message
  String username = username1+"|"+username2;
  telegramMessage(username, messsage);
}

void loop() {
  
}