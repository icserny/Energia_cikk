/*
 * LCD_16x2
 * Mintapélda a LiquidCrystal programkönyvtár használatára
 * Bemutatja a 16x2 LCD ipari szabvány kijelző használatát.
 * A LiquidCrystal programkönyvtár minden olyan LCD kijelzővel
 * kompatibilis, amelyik a Hitachi HD44780 vagy azzal kompatibilis
 * vezérlő IC-t használ.
 *
 * Hardver követelmények:
 *  - Launchpad kártya MSP430G2553 vagy MSP430G2452 mikrovezérlővel
 *  - HD44780 kompatibilis 16x2 karakteres LCD kijelző
 *
 * Bekötési vázlat
 * LCD kivezetés      Launchpad
 * ---------------------------------
 * 01 - GND             GND, potméter
 * 02 - VCC             +5V, potméter
 * 03 - Kontraszt       GND vagy Pot csúszka
 * 04 - RS              Pin8 (P2.0)
 * 05 - R/W             GND
 * 06 - EN              Pin9 (P2.1)
 * 07 - DB0             GND vagy NC
 * 08 - DB1             GND vagy NC
 * 09 - DB2             GND vagy NC
 * 10 - DB3             GND vagy NC
 * 11 - DB4             Pin10 (P2.2)
 * 12 - DB5             Pin11 (P2.3)
 * 13 - DB6             Pin12 (P2.4)
 * 14 - DB7             Pin13 (P2.5)
 * 15 - LED anód        +5V
 * 16 - LED katód       GND
 *
 */

#include <LiquidCrystal.h>       //Becsatoljuk a programkönyvtárat

int i, k;
//Inicializáljuk a programkönyvtárat az alábbi lábkiosztással
LiquidCrystal lcd(P2_0, P2_1, P2_2, P2_3, P2_4, P2_5);

void setup() {
  lcd.begin(16, 2);              //Beállítjuk a sorok és oszlopok számát)
  lcd.print("<= 2 x 16 LCD =>"); //Kiírunk egy szöveget az első sorba
  for(i=0; i<16; i++) {
    k = (i * 7) & 0x0F;
    lcd.setCursor(k, 1);
    lcd.print(k,HEX);
    delay(100);  
  }  
  delay(2000);
  lcd.clear();                   //Képernyő törlése 
  lcd.print("Time since RESET"); 
}

void loop() {
  lcd.setCursor(0, 1);            
  lcd.print(millis()/1000);      //Kiíratjuk a Reset óta eltelt időt
}


