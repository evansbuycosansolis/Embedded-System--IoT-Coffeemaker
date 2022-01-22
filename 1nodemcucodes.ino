#include <SoftwareSerial.h>
SoftwareSerial s(D2,D3);
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "TouchPoint1"                                           
#define WIFI_PASSWORD "GTBIF@2017JAN0921"   
  
void setup() {
  // Initialize Serial port
  Serial.begin(115200);
  s.begin(115200);
  while (!Serial) continue;
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);


  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  
}
 
void loop() {

  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
 
  if (root == JsonObject::invalid())
  {
    return;
    
  }
  //Print the data in the serial monitor
  Serial.println("JSON received and parsed");
  root.prettyPrintTo(Serial);
  Serial.println("");
  Serial.print("Temperature ");
  float data1=root["temp"];
  Serial.println(data1);
 
  Serial.println("---------------------xxxxx--------------------");
 
 
}
