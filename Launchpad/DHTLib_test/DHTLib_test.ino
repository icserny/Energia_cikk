/*
 * DHTLib_test.ino
 * DHT22 hőmérséklet és relatív páratartalom szenzor próba
 *
 * Szerző: Rob Tillaart (01/04/2011)
 * Módosítás: Cserny István 2013.
 */
 
#include <dht.h>
dht DHT;

#define DHT22_PIN P1_6

void setup()
{
  Serial.begin(9600);
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}

void loop() {
  delay(2000);
  // READ DATA
  Serial.print("DHT22, \t");
  int chk = DHT.read22(DHT22_PIN);
  switch (chk)   {
    case DHTLIB_OK:  
                Serial.print("OK,\t");
                break;
    case DHTLIB_ERROR_CHECKSUM:
                Serial.print("Checksum error,\t");
                break;
    case DHTLIB_ERROR_TIMEOUT:
                Serial.print("Time out error,\t");
                break;
    default:
                Serial.print("Unknown error,\t");
                break;
  }
  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);  
}

