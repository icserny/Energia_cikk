/*
 * AccelReadSerial
 * Megméri a gyorsulásmérő analóg kimenő jeleit, 
 * s az eredményt kiirja a soros porton keresztül. 
 *
 * Hardverigény: MSP-EXP430FR5739 ("Fraunchpad") kártya
 */
int x,y,z;

void setup() {
  pinMode(PUSH1, INPUT_PULLUP);  // Nyomógomb bemenet felhúzása
  pinMode(PUSH2, INPUT_PULLUP);  // Nyomógomb bemenet felhúzása
  pinMode(ACC_ENABLE, OUTPUT);   // Gyorsulásmérő engedélyező láb
  digitalWrite(ACC_ENABLE,HIGH); // Gyorsulásmérő engedélyezés
  Serial.begin(9600); 
  Serial.println(" X    Y    Z");
  Serial.println("------------");
}

void loop() {
  x = analogRead(ACC_X);
  y = analogRead(ACC_Y);
  z = analogRead(ACC_Z);
  Serial.print(x);
  Serial.write(' ');
  Serial.print(y);
  Serial.write(' ');  
  Serial.println(z);  
  delay(500);
}
