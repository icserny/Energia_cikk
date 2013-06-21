/*
  AnalogReadSerial
  Leolvassa az A4 analóg bemenetre kapcsolt jel nagyságát, 
  s az eredményt kiirja a soros porton keresztül. 
 
  Ez a mintaprogram szabadon felhasználható (public domain)
 */

void setup() {
  Serial.begin(9600); // msp430g2231 esetén 4800 kell!
}

void loop() {
  int sensorValue = analogRead(A4);
  Serial.println(sensorValue);
}
