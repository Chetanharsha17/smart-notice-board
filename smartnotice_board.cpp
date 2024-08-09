#include <ESP8266WiFi.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#define DEBUG 0
#if DEBUG
#define PRINT(s, x) { Serial.print(F(s));
 Serial.print(x); }
#else
#define PRINT(s, x)
#endifMD_Parola P = MD_Parola(MD_MAX72XX::FC16_HW, 15, 8);
const char* ssid = "***********";
const char* password = "***********";
WiFiServer server(80);
uint8_t frameDelay = 25;
textEffect_t scrollEffect = PA_SCROLL_LEFT;
char curMessage[512], 
newMessage[512];
bool newMessageAvailable = false;
const char WebResponse[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
const char WebPage[] = "..."; // Your HTML here
uint8_t htoi(char c) {  c = toupper(c);  return (c >= '0' && c <= '9') ? (c - '0') : (c - 'A' + 0xa);}void getData(char *szMesg) {  // ... Your existing code for extracting data}

void getData(char *szMesg) {  // ... Your existing code for extracting data}
void handleWiFi() {  // ... Your existing code for handling WiFi requests}
void setup()
 {  Serial.begin(57600);  P.begin(); 
P.setIntensity(0);
 P.displayClear();
 P.displaySuspend(false); 
 P.displayScroll(curMessage, PA_LEFT, scrollEffect, frameDelay);
  curMessage[0] = newMessage[0] = '\0’; 
 WiFi.begin(ssid, password); 
 while (WiFi.status() != 
WL_CONNECTED) {    delay(500);  } 
 server.begin(); 
 sprintf(curMessage, "%03d:%03d:%03d:%03d", WiFi.localIP()[0], WiFi.localIP()[1], WiFi.localIP()[2], WiFi.localIP()[3]);}
void loop() 
{  handleWiFi(); 
 if (P.displayAnimate()) 
{    if (newMessageAvailable) {      strcpy(curMessage, newMessage);     
 newMessageAvailable = false;    }   
 P.displayReset();  
}
}

