/*
  Blink
  Egy másodpercre bekapcsoljuk a piros LED-et, azután egy
  másodpercre lekapcsoljuk, s ezt ismételgetjük.

  Ez a mintaprogram szabadon felhasználható (public domain).
 */

void setup() {                
  // Digitális kimenetnek konfiguráljuk a piros LED-hez tartozó kivezetést
  pinMode(RED_LED, OUTPUT);     
}

void loop() {
  digitalWrite(RED_LED, HIGH);   // bekapcsoljuk a LED-et
  delay(1000);                   // várunk egy másodpercig
  digitalWrite(RED_LED, LOW);    // kikapcsoljuk a LED-et
  delay(1000);                   // várunk egy másodpercig
}
