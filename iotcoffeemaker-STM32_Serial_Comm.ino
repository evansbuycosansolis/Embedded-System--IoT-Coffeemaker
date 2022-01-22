#include <OneWire.h>
#include <DallasTemperature.h>



#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);


void setup() {
 
  Serial.begin(9600);
Serial.println("Digital Temperature // Serial Monitor Version");
 sensors.begin();
}


void loop() {
sensors.requestTemperatures();  
  Serial.print("Hello");
Serial.println(sensors.getTempCByIndex(0));
  delay(1000);
}
