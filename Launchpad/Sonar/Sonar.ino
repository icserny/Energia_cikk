/*
 * Sonar
 * Ultrahangos távolságmérő HC-SR04 szenzorral
 *
 * Hardver követelmények:
 *  - Launchpad kártya MSP430G2553 vagy MSP430G2452 MCU-val
 *  - HC-SR04 ultrahangos szenzor, az alábbi bekötéssel
 *
 *  HC-SR04           Launchpad kártya
 * ----------------------------------------
 *  1. VCC            TP1 (+5V)
 *  2. Trigger        P2_5
 *  3. Echo           P2_4 (leosztva, vagy áramkorlátozással!)
 *  4. GND            GND
 *
 * Megjegyzések:
 * - A HC-SR04 modul +5V-os tápfeszültséget igényel, amit a TP1 pontról vehetünk.
 * - Az Echo jelet nem vezethetjük közvetlenül a P2_4 bemenetre, le kell osztanunk 
 *   azt 3,5 V-ra, vagy legalább egy áramkorlátozó ellenállást iktassunk be!
 *
 * A program eredetijének forrása:
 * http://arduinobasics.blogspot.hu/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 *
 */


#define echoPin P2_5       // Echo kimenet
#define trigPin P2_4       // Trigger bemenet

int maximumRange = 200;    // Legnagyobb távolság cm-ben
int minimumRange = 1;      // Minimális távolság cm-ben
long duration;             // Időtartam [us]
float distance;            // Távolság [cm]

void setup() {
  Serial.begin (9600);
  Serial.println("Sonar program");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW); 
  pinMode(RED_LED,OUTPUT);
  digitalWrite(RED_LED,HIGH);
}

void loop() {
  delay(1000);
  digitalWrite(RED_LED,HIGH);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2; // Kiszámoljuk a távolságot
  if (distance >= maximumRange || distance < minimumRange) {
    distance = -1.0;
  }  
  Serial.print(distance);  // A mért távolság kiíratása
  Serial.println(" cm");
  digitalWrite(RED_LED,LOW);  
}
