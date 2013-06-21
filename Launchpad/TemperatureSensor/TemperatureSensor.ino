/*
   TemperatureSensor
   Hőmérés a beépített hőmérővel. A jobb feloldás érdekében
   a beépített 1.5 V-os referenciához képest mérünk, az eredményt
   Celsius fokokra átszámítjuk. A soros porton kiíratjuk az ADC-ből
   kapott nyers adatot és az átszámított eredményt is. A mérések 
   között egymásodperces szünetet tartunk. 
 */  
int val;                        //a konverzió eredménye
float temp;                     //a hőmérséklet értéke

void setup() {
  Serial.begin(9600);           //Soros kapcsolat 9600 bit/s
  analogReference(INTERNAL1V5); //1,5 V-os belső referencia 
  analogRead(TEMPSENSOR);       //a beépített hőmérő kiválasztása
}

void loop() {
  delay(1000);                  //egy kis várakozás   
  val = analogRead(TEMPSENSOR); //a hőmérő leolvasása
  Serial.print("adc:");         //a nyers adat kiírása
  Serial.print(val);
  temp = val*0.413-277.8;       //a hőmérséklet kiszámítása
  Serial.print("  temp:");      
  Serial.println(temp,1);       //a hőmérséklet kiírása
}

