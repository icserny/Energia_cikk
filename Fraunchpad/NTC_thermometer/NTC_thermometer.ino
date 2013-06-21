/*
 * FraunchPad NTC hőmérő
 * Egyszerű mintaprogram a beépített NTC hőmérő használatához
 * szerző: Rei Vilo, embedxcode.weebly.com
 */
#include "Energia.h"
#include "FraunchPad_NTC.h"       // Az NTC könyvtár becsatolása

int32_t temperature;
NTC_FR myNTC;

//Decimális kiíratás egy tizedesre
void printX10(int32_t i) { 
  if (i<0) {
    Serial.print("-");
    i = -i;
  }
  Serial.print(i/10, DEC);
  Serial.print(".");
  Serial.print(i%10, DEC);
}


void setup() {
  pinMode(PUSH1, INPUT_PULLUP);  // Nyomógomb bemenet felhúzása
  pinMode(PUSH2, INPUT_PULLUP);  // Nyomógomb bemenet felhúzása
  myNTC.begin();                 // Az NTC osztójának bekapcsolása 
  Serial.begin(9600);
  Serial.println(myNTC.WhoAmI());
  Serial.println("press PUSH2 to exit serial");
  delay(500); 
}

void loop() {
  myNTC.get();
  Serial.print("Temperature = ");
  myNTC.celsiusX10(temperature);
  printX10(temperature);
  Serial.print(" oC\t");
  
  myNTC.fahrenheitX10(temperature);
  printX10(temperature);
  Serial.println(" oF");
  delay(1000);
  
  if (digitalRead(PUSH2)==LOW) {
    Serial.print("exit... ");
    Serial.end();
    Serial.println("end");
    while(true); // endless loop
  }
}
