/*
  ReadAnalogVoltage
  Leolvassa az A4 analóg bemenetre kapcsolt jel nagyságát, 
  átszámítja voltokra, s az eredményt kiirja a soros porton keresztül. 
  Kapcsoljuk egy potméter csúszkáját az A4 (P1_4) bemenetre, a potméter
  két végét pedig a földre (GND) és a tápfeszültségre (VCC)!
 
  Ez a mintaprogram szabadon felhasználható (public domain)
 */
 
void setup() {
  Serial.begin(9600);               // msp430g2231 esetén 4800 kell!
}

void loop() {
  int sensorValue = analogRead(A4); //Mérés az A4 bemeneten 
  // Átszámítjuk a 0 - 1023 közötti voltra (0 - 3.5V):
  float voltage = sensorValue * (3.5 / 1023.0);
  Serial.println(voltage,3);        //Kiíratjuk az eredményt
  delay(1000); 
}
