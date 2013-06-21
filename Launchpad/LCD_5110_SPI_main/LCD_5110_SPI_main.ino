/*
 * LCD_5110_SPI_main
 * Demóprogram a Nokia 5110 LCD kipróbálásához (hardveres SPI támogatással)
 * 
 * Szerző: Rei VILO, Jan 12, 2013
 *
 * Hardver követelmények:
 *  - Launchpad kártya MSP430G2553 mikrovezérlővel, vagy Stellaris LM4F Launchpad kártya
 *  - Nokia 5110 LCD kijelző
 *
 * Huzalozási vázlat:
 *
 * Nokia 5110                 MSP430   vagy  LM4F       
 * ----------------------------------------------
 * 1. VCC     tápfeszültség    VCC           VCC
 * 2. GND     közös pont       GND           GND 
 * 3. SCE     kiválasztó jel   P2.2          PA.7
 * 4. RST     RESET            P1.0          PB.5
 * 5. D/C     adat/parancs     P2.3          PA.2 
 * 6. DIN     MOSI adatvonal   P1.7          PB_7
 * 7. SCLK    SPI órajel       P1.5          PB.4
 * 8. LED     háttérvilágítás  P2.1          PA.6
 */

#include "Energia.h"
#include "SPI.h"
#include "LCD_5110_SPI.h"

#if defined(__MSP430G2553__)
  LCD_5110_SPI myScreen;

#elif defined(__LM4F120H5QR__)
  LCD_5110_SPI myScreen(PA_7,    // Chip Select
                        PA_2,    // Data/Command
                        PB_5,    // Reset
                        PA_6,    // Backlight
                        PUSH2);  // Push Button 2
#endif
boolean	backlight = false;
uint8_t k = 0;


// Add setup code
void setup() {
#if defined(__MSP430G2553__)
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV4);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);   
#elif defined(__LM4F120H5QR__)
    SPI.setModule(2);
    SPI.setClockDivider(SPI_CLOCK_DIV16); // max. frequency = 5 MHz!
#endif
    
    myScreen.begin();
    myScreen.setBacklight(backlight);
    myScreen.text(0, 0, "Hello!");    
    delay(1000);
    myScreen.clear();
    myScreen.text(0, 5, "Light off");
}

void loop() {
    if (myScreen.getButton()) {
        backlight = (backlight==0);
        myScreen.setFont(0);
        myScreen.text(0, 5, backlight ? "Light on " : "Light off");
        myScreen.setBacklight(backlight);
    }
    
    myScreen.setFont(1);
    if (k==0)   myScreen.text(0, 2, " MSP430");
    else if (k==8)   myScreen.text(0, 2, "  LM4F  ");
    
    myScreen.setFont(0);
    for (uint8_t i=0; i<14; i++) myScreen.text(i, 4, (i==k) ? "*" : " ");
    k ++;
    k %= 14;
    
    delay(200);
}
