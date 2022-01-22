#include <WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>


void setup() {
   
    Serial.begin(115200);
    WiFiManager wifiManager;
    wifiManager.autoConnect("Morning_Adam");
    Serial.println("Connected to the configured WiFi");
}

void loop() {
    // put your main code here, to run repeatedly:
    
}
