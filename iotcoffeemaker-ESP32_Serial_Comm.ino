#include <Hardwareserial.h>

Hardwareserial MySerial1(0);

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  MySerial1.begin(9600);
}
void loop() {
  
  if (MySerial1.available()) {
    Serial.println(MySerial1.read());
  
  }
}
