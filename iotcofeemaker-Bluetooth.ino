#include "BluetoothSerial.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

const int ledPin =  23;
const int oneWireBus = 32;  

BluetoothSerial SerialBT;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);


String message = "";
char incomingChar;
String temperatureString = "";


unsigned long previousMillis = 0;    // last time temperature was published
const long interval = 10000;         // interval at which to publish sensor readings

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("MorningAdam");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  unsigned long currentMillis = millis();
  // Send temperature readings
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    sensors.requestTemperatures(); 
    temperatureString = String(sensors.getTempCByIndex(0)) + "C  " +  String(sensors.getTempFByIndex(0)) + "F";
    SerialBT.println(temperatureString); 
  }

  if (SerialBT.available()){
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }
  

  // Check received message and control output accordingly  
  if (message =="ledon"){
    digitalWrite(ledPin, HIGH);
  }
  else if (message =="ledoff"){
    digitalWrite(ledPin, LOW);
  }
  delay(20);
}
