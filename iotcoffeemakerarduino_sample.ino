#include <ArduinoJson.h>
#include <SoftwareSerial.h>

const byte rxPin = 1;
const byte txPin = 0;
SoftwareSerial s (rxPin, txPin);
 
void setup() {
s.begin(115200);
}
 
void loop() {
 StaticJsonBuffer<1000> jsonBuffer;
 JsonObject& root = jsonBuffer.createObject();
  root["data1"] = 100;
  root["data2"] = 200;
if(s.available()>0)
{
 root.printTo(s);
 Serial.print (s);
}
}
