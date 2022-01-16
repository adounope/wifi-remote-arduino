#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(D8,D9,D4,D5,D6,D7);
const char* APSSID = "ESP8266";
const char* APPASS = "NOTESP8266";
WiFiServer server(80);
String header, headerGET, line, WiFiSSID, WiFiPASS;
int pos1,pos2,pos3,pos4,pos5,pos6;
int v1D,v1T,v1H,v2D,v2T,v2H,v3D,v3T,v3H,v1,v2,v3;
String valueString1,valueString2,valueString3;
bool launchConfigState=false;
bool testWifi();
void configHTML(void);
void controlHTML(void);
void WiFiEEPROMsave(void);
void scanWiFi(void);
int currentTime = millis();
int previousTime = 0; 
int timeoutTime = 2000;
String WiFiDetail;
WiFiClient client;
void setup() {
  lcd.begin(16, 2);
  Serial.begin(115200);
  Serial.println();
  Serial.println("Disconnecting current wifi connection");
  WiFi.disconnect();
  Serial.println();
  Serial.println("Starting up EEPROM");
  EEPROM.begin(512);
  delay(10);
  String EESSID;
  for(int i=0; i<32; ++i){
    EESSID += char(EEPROM.read(i));
  }
  String EEPASS;
  for (int i = 32; i < 96; ++i){
    EEPASS += char(EEPROM.read(i));
  }
  Serial.print("SSID:");
  Serial.print(EESSID);
  Serial.print("/////");
  Serial.print("PASS:");
  Serial.print(EEPASS);
  Serial.print("/////");
 // WiFi.begin(EESSID.c_str(), EEPASS.c_str());
  WiFi.begin(EESSID.c_str(), EEPASS.c_str());
  delay(10);
  if(testWifi()){
    Serial.println("Succesfully Connected!!!");
    server.begin();
    delay(10);
    Serial.println(WiFi.localIP());
    lcd.setCursor(0,1);
    lcd.print(WiFi.localIP());
  }
  else{
    IPAddress APip(192, 168, 86, 50); ////
    IPAddress gateway(192, 168, 1, 1);////
    IPAddress subnet(255, 255, 255, 0);////
    WiFi.softAPConfig(APip, gateway, subnet);////
    boolean result = WiFi.softAP(APSSID, APPASS);
    if(result==false){
      Serial.println("AP failed sucessfully");
    }
    else{
      Serial.println("AP is setup");
    }
    Serial.println("");
    Serial.print("SoftAP IP: ");
    Serial.println(WiFi.softAPIP());
    lcd.setCursor(0,1);
    lcd.print(WiFi.softAPIP());
    lcd.setCursor(15,1);
    lcd.print("A");
    server.begin();
    delay(10);
    Serial.println("Server started");
    Serial.println();
    Serial.println("Waiting.");
  }
}
