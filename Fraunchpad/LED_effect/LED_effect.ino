/*
 * LED_effect
 * Fényeffektus a Fraunchpad kártya gyári demójából átvéve,
 * melyben a P3 és PJ portokon található 4-4 LED-et villogtatjuk.
 *
 * Hardverigény: MSP-EXP430FR5739 ("Fraunchpad") kártya
 */

#include "Energia.h"

void StartUpSequence(void) 
{
  unsigned char flag=4,up=1,counter = 0; 
  unsigned char LED_ArrayPJ[] = { 0x01,0x02,0x04,0x08 };
  unsigned char LED_ArrayP3[] = { 0x80,0x40,0x20,0x10 };

  while (counter <10) 
  {    
    counter++;
    PJOUT &= ~(BIT0 +BIT1+BIT2+BIT3);
    P3OUT &= ~(BIT4 +BIT5+BIT6+BIT7);    
    if(up)        // from the outside - in
    {
      while(flag)
      {
        P3OUT = LED_ArrayP3[flag-1];
        PJOUT = LED_ArrayPJ[flag-1];
        delay(31);               
        flag--;
      }
      up=0;
    }
    else
    {  // from the inside - out
      while(flag<4)
      {
        P3OUT = LED_ArrayP3[flag];
        PJOUT = LED_ArrayPJ[flag];
        delay(31);        
        flag++;
      }
      up = 1;
    }
  }
  // Exit Loop, Clear LEDs
  PJOUT &= ~(BIT0 +BIT1+BIT2+BIT3);
  P3OUT &= ~(BIT4 +BIT5+BIT6+BIT7);    
}

void  setup() {
  PJDIR |= 0x0F;      // PJ alsó félbájt kimenet legyen
  P3DIR |= 0xF0;      // P3 felső félbájt kimenet legyen    
}  

void loop() {
  StartUpSequence();  // Fényefekktus meghívása
  delay(1000);        // Egymásodperces szünet
}  

