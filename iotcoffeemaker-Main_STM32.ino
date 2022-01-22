#include <OneWire.h>
#include <DallasTemperature.h>


// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);


void setup() {
 
  Serial.begin(9600);
  Serial.println("Digital Temperature // Serial Monitor Version");
  sensors.begin();
}


void loop() {
  sensors.requestTemperatures();  
  Serial.print("Temperature is: ");
  Serial.println(sensors.getTempCByIndex(0));
  delay(1000);
}
