/*
 * RGB_ledblink
 * Bekapcsoljuk az RGB LED piros, a zöld és a kék alapszínt, ebben a sorrendben. 
 * Mindegyik szín egy-egy másodpercig világít, utána lekapcsoljuk.
 * Végül egy másodperre kikapcsolva hagyjuk az összes alapszínt.
 */

void setup() {                
  // Kimenetként inicialzáljuk a LED vezérlő lábakat
  pinMode(RED_LED, OUTPUT);     
  pinMode(BLUE_LED, OUTPUT);     
  pinMode(GREEN_LED, OUTPUT);       
}

void loop() {
  digitalWrite(RED_LED, HIGH);   // piros LED be
  delay(1000);                   // várunk 1 másodpercig
  digitalWrite(RED_LED, LOW);    // piros LED ki
  digitalWrite(GREEN_LED, HIGH); // zöld LED be
  delay(1000);                   // várunk 1 másodpercig
  digitalWrite(GREEN_LED, LOW);  // zöld LED ki
  digitalWrite(BLUE_LED, HIGH);  // kék LED be
  delay(1000);                   // várunk 1 másodpercig
  digitalWrite(BLUE_LED, LOW);   // kék LED ki
  delay(1000);                   // várunk 1 másodpercig  
}

