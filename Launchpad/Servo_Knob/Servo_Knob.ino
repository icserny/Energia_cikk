// Szervó vezérlése potenciométerrel 
// Szerző: Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;                       // Szervó objektum példányosítása
int potpin = 4;                      // A potmétert az A4 (P1.4) lábra kötjük
int val;                             // Változó az analóg feszültség beolvasásához
 
void setup() { 
  myservo.attach(7);                 // A szervó vezérlése a 7. lábon (P1.5) történik 
} 
 
void loop() { 
  val = analogRead(potpin);          // a potméter állásának beolvasása (0-1023) 
  val = map(val, 0, 1023, 0, 179);   // a kapott szám átskálázása a szervóhoz (0-180) 
  myservo.write(val);                // a szervó beállítása a fenti érték szerint 
  delay(100);                        // várunk, hogy a szervó beálljon  
} 
