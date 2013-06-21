/*
  DigitalReadSerial
  Beolvassa az S2 nyomógomb állapotát és kiírja a soros vonalon keresztül. 
 
  Ez a mintaprogram szabadon felhasználható (public domain).
 */

void setup() {
  Serial.begin(9600);                   // msp430g2231 esetén 4800 kell!
  pinMode(PUSH2, INPUT_PULLUP);         // digitális bement belső felhúzással
}

void loop() {
  int sensorValue = digitalRead(PUSH2); //Nyomógomb állapota
  Serial.println(sensorValue);          //Kiírja a beolvasott értéket (1/0)  
}



