//hardwareseria: pins from stm32 TxRx to ESP32 RX2andTX2 for Serial2. no need to declare "HardwareSerial Serial2"

void setup() {
  Serial.begin(9600);
  Serial2.begin(115200);
  while (!Serial) {
  }
}

void loop() { 
  //for serial reading
  if (Serial2.available()) {
    Serial.write(Serial2.read());
  }
  //for serial writing (of commands, or anything)
    if (Serial.available()>0){
    Serial2.write(Serial.read());
  }
}
