/*
 Fade
 Ebben a mintapéldában azt mutatjuk meg, hogy hogyan
 lehet a zöld LED fényerejét változtatni az analogWrite() 
 függvény segítségével.
 
 Ez a mintaprogram szabadon felhasználható (public domain).
 
 */
int brightness = 0;    // ilyen fényesen világítson a LED (0-255)
int fadeAmount = 5;    // ekkora legyen a fényerősség változása

void setup()  { 
  // a zöld LED-hez tartozó kivezetést digitális kimenetnek állítjuk
  pinMode(GREEN_LED, OUTPUT);
} 

void loop()  { 
  // a zöld LED fényerejének beállítása:
  analogWrite(GREEN_LED, brightness);    
  // változtassuk meg a fényerőt a következő ciklushoz:
  brightness = brightness + fadeAmount;
  // fordítsuk meg a fényerősségváltoztatás irányát a határoknál: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // várunk 30 miliszekundumot, hogy  a változás érvényesüljön    
  delay(30);                            
}
