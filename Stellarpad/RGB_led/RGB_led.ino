
/*
 * RGB LED
 * Fokozatos átmenet egyik véletlen színből a másikba
 * Forrás: http://arduino.cc/forum/index.php/topic,11293.0.html
 * Hardver követelmények: Stellaris Launcpad kártya
 */

float RGB1[3];
float RGB2[3];
float INC[3];
float SUM;
int red, green, blue;

void setup() { 
//--- Kiindulási színek generálása, véletlenszerűen  
  randomSeed(analogRead(0));
  for (int x=0; x<3; x++) {
    RGB1[x] = random(256);
    RGB2[x] = random(256); 
  } 
} 

void loop() { 
//--- Az 1. színből a 2. színbe történő átmenet lépéseinek meghatározása  
  for (int x=0; x<3; x++) {
    INC[x] = (RGB1[x] - RGB2[x]) / 256; 
  } 

  for (int s=0; s<256; s++) {
    red = int(RGB1[0]);
    green = int(RGB1[1]);
    blue = int(RGB1[2]);
//--- A közelítő szín kijelzése
    analogWrite (RED_LED, red);  
    analogWrite (GREEN_LED, green);   
    analogWrite (BLUE_LED, blue);     
    delay(20);   

    for (int x=0; x<3; x++) {
      RGB1[x] -= INC[x];   //Közelítünk a másik színhez    
    }

  }
//--- Új színt konstruálunk, véletlen számok generálásával 
  do {
    SUM = 0;
    for (int x=0; x<3; x++) {
      RGB2[x] = random(956)-700;
      RGB2[x] = constrain(RGB2[x], 0, 255); 
      SUM += RGB2[x];
    }
  } 
  while(SUM < 300);        //Nem engedjük túlságosan elsötétedni
}


