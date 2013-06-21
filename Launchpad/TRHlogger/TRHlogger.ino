/*  
  TRHlogger:   PC-based temperature and humidity logger
  Description: The DHT22 sensor is used to measure the ambient 
               temperature and relative humidity. The measured
               values are displayed on a PC and logged into an ASCII
               file through an application written using Processing.
  Board:       MSP430 Launchpad
  Reference:   http://embedded-lab.com/blog/?p=5453
  Modifications: I. Cserny
 */
#include "dht.h"
 
dht DHT;

#define DHT22_PIN   P1_6

void setup()   
{
  Serial.begin(9600); 
}

void loop()  
{
  delay(5000);
  int chk = DHT.read22(DHT22_PIN);
  if(chk==DHTLIB_OK) 
  {
    Serial.print(DHT.humidity,1);
    Serial.write(' ');
    Serial.println(DHT.temperature,1);
  }  
}


