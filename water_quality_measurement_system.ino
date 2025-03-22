#include <Arduino.h> 
#include <Wire.h> 
#include <EEPROM.h> 
#include <WiFi.h> 
#include <OneWire.h> 
#include <DallasTemperature.h> 
#include <Adafruit_ADS1015.h> 
#include <DFRobot_ESP_EC.h> 
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h> 
#define SCREEN_WIDTH 128 // OLED display width, in pixels 
#define SCREEN_HEIGHT 64 // OLED display height, in pixels 
// Declaration for an SSD1306 display connected to I2C (SDA, SCL)  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); 
#define ONE_WIRE_BUS 14          
// this is the gpio pin 13 on esp32. 
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire); 
DFRobot_ESP_EC ec; 
Adafruit_ADS1115 ads; 
Float voltage, ecValue, temperature = 25; 
String apiKey = “**************”;     //  Enter your Write API key from ThingSpeak 
Const char *ssid =  “**************”;     // replace with your wifi ssid and wpa2 key 
Const char *pass =  “**************”; 
Const char* server = “api.thingspeak.com”; 
WiFiClient client; 
Void setup() 
{ 
Serial.begin(115200); 
EEPROM.begin(32); 
//needed EEPROM.begin to store calibration k in eeprom 
Ec.begin(); 
Sensors.begin(); 
If (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  
// Address 0x3D for 128x64 
Serial.println(F(“SSD1306 allocation failed”)); 
For (;;); 
} 
Delay(2000); 
Display.clearDisplay(); 
Serial.println(“Connecting to “); 
Serial.println(ssid); 
WiFi.begin(ssid, pass); 
While (WiFi.status() != WL_CONNECTED) 
{ 
Delay(500); 
Serial.print(“.”); 
} 
Serial.println(“”); 
Serial.println(“WiFi connected”); 
} 
Void loop() 
{ 
Voltage = analogRead(A0); // A0 is the gpio 36 
Sensors.requestTemperatures(); 
Temperature = sensors.getTempCByIndex(0);  
// read your temperature sensor to execute temperature compensation 
ecValue = ec.readEC(voltage, temperature); 
// convert voltage to EC with temperature compensation 
Serial.print(“Temperature:”); 
Serial.print(temperature, 2); 
Serial.println(“ºC”); 
Serial.print(“EC:”); 
Serial.println(ecValue, 2); 
Display.setTextSize(2); 
Display.setTextColor(WHITE); 
Display.setCursor(0, 10); 
Display.print(“T:”); 
Display.print(temperature, 2); 
Display.drawCircle(85, 10, 2, WHITE); // put degree symbol ( ° ) 
Display.setCursor(90, 10); 
Display.print(“C”); 
Display.setCursor(0, 40); 
Display.print(“EC:”); 
Display.print(ecValue, 2); 
Display.display(); 
Delay(1500); 
Display.clearDisplay(); 
ec.calibration(voltage, temperature);  
// calibration process by Serail CMD 
If (client.connect(server, 80))   
//   “184.106.153.149” or api.thingspeak.com 
{ 
String postStr = apiKey; 
postStr += “&field1=”; 
postStr += String(temperature, 2); 
postStr += “&field2=”; 
postStr += String(ecValue, 2); 
postStr += “\r\n\r\n”; 
delay(500); 
client.print(“POST /update HTTP/1.1\n”); 
client.print(“Host: api.thingspeak.com\n”); 
client.print(“Connection: close\n”); 
client.print(“X-THINGSPEAKAPIKEY: “ + apiKey + “\n”); 
client.print(“Content-Type: application/x-www-form-urlencoded\n”); 
client.print(“Content-Length: “); 
client.print(postStr.length()); 
client.print(“\n\n”); 
client.print(postStr); 
delay(500); 
} 
client.stop(); 
}
