This is a library for the Adafruit 1.8" SPI display.
This library works with the Adafruit 1.8" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/358
as well as Adafruit raw 1.8" TFT display
  ----> http://www.adafruit.com/products/618
 
Check out the links above for our tutorials and wiring diagrams.
These displays use SPI to communicate, 4 or 5 pins are required
to interface (RST is optional).
Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.
MIT license, all text above must be included in any redistribution

To download. click the DOWNLOADS button in the top right corner, rename the uncompressed folder Adafruit_ST7735. Check that the Adafruit_ST7735 folder contains Adafruit_ST7735.cpp and Adafruit_ST7735.

Place the Adafruit_ST7735 library folder your <arduinosketchfolder>/libraries/ folder. You may need to create the libraries subfolder if its your first library. Restart the IDE

Also requires the Adafruit_GFX library for Arduino.

Ported to Energia/Stellaris by Stephen Crane, https://github.com/jscrane

Pin connections for Hardware SPI:
Vcc	-> VBUS (21)
BKL	-> GND (22)
Reset	-> RST (16)
RS	-> PA_6 (9)
MISO	-> PB_6, MISO(2) (14)
MOSI	-> PB_7, MOSI(2) (15)
SCL	-> PB_4, SCK(2) (7)
LCD_CS	-> PA_7 (10)
SD_CS	-> n/c
GND	-> GND (20)
