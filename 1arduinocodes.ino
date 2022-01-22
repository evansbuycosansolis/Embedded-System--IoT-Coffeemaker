
#include <SoftwareSerial.h>
#include <ArduinoJson.h>


SoftwareSerial s(3,2);

void setup() {
   Serial.begin(115200);
   s.begin(115200);
 
}
StaticJsonBuffer<1000> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
void loop() {
  
 
  root["temp"] = ("5.0");
  
   
if(s.available()>0)
{
 root.printTo(s);
}
}


