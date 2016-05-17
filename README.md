# LiquidCrystal_SSD1306 [![Build Status](https://travis-ci.org/McNeight/LiquidCrystal_SSD1306.svg?branch=master)](https://travis-ci.org/McNeight/LiquidCrystal_SSD1306)

Developed by [Neil McNeight](https://github.com/McNeight) based on Arduino and other Open Source libraries.

## Description

Text only library for monochrome organic light-emitting diode (OLED) displays. For all Arduino boards.

This library allows an Arduino board to control OLED displays based on the SSD1306 (or a compatible) chipset, which is found on most OLED panels. The library works with an I2C interface, in addition to the reset control line.
It was originally designed to be a small library for ATtiny85-based boards (Trinket, Gemma, etc.) but it is compatible with all Arduino boards.

## Required Libraries

1. Either Wire or [TinyWireM](https://github.com/adafruit/TinyWireM)

## Installation

1. Change directory to your Arduino sketch directory
2. cd libraries
3. mkdir LiquidCrystal_SSD1306
4. cd LiquidCrystal_SSD1306
5. git clone https://github.com/McNeight/LiquidCrystal_SSD1306.git .
6. Start Arduino IDE.
7. LiquidCrystal_SSD1306 example is located at, File--->Example--->LiquidCrystal_SSD1306--->HelloWorld

## Compatibility

Tested with

1. [Adafruit Monochrome 0.96" 128x64 OLED graphic display](https://www.adafruit.com/products/326)
2. [Sabernetics Tech Electronics 0.84" OLED Display 96�16](http://sabernetics.com/store/0-84-oled-display-96x16/)
3. [SainSmart 0.69" I2C IIC Serial 96X16 White OLED Module](http://www.amazon.com/SainSmart-Serial-96X16-Module-Arduino/dp/B00MQLI09Y)

## History

DATE      VER   WHO   WHAT
06/20/15  1.6.0 NEM   Code cleanup and compatibility with Arduino 1.6.*

## Credits

Portions of code reused from

* [Arduino LiquidCrystal library](https://github.com/arduino/Arduino/tree/master/libraries/LiquidCrystal)
  * GNU Lesser General Public License (LGPL) version 2.1

```
Copyright (c) Arduino LLC. All right reserved.
This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later
version.
This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
License for more details.
You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the
Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
```

* [Adafruit SSD1306 library](https://github.com/adafruit/Adafruit_SSD1306)
  * "3-clause BSD license" or Modified BSD license

```
Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.
Scrolling code contributed by Michael Gregg
BSD license, check bsd-license-adafruit.txt for more information
All text above must be included in any redistribution
```

* [pocketmoon SSD1306NoBuffer library](https://github.com/pocketmoon/SSD1306NoBuffer)
  * No license given, and no copyright listed.
