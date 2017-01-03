LICENSING
=========

The licensing of this library is a bit of a pain, as it draws from
so many other open source projects. As code gets merged, cleaned up,
refactored, and then expanded upon, it can be hard to determine who
wrote which line. Attempting to maintain every single copyright header
was bulky and of questionable value. 

So, along with the acknowledgements in the README.md file, I've attempted
to list here the multiple sources that this code was pulled from, the authors
or contributors, and the license that was chosen by them.

I've chosen to license my contributions to this library under the LGPL 2.1.
After reading http://www.gnu.org/licenses/why-not-lgpl.html and considering
the argument against using the LGPL, I'm using it for three reasons:

1. Compatibility with the LGPL 2.1 license used for Arduino's core libraries
2. Plenty of free and non-free OLED libraries already exist, meaning that it
    does not "give free software any particular advantage"
3. Section 7 explicitly details how to properly credit source that is combined
    with other source in a library

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
  * Derived from work by Kalle Hyvönen, http://www.dgkelectronics.com

* [Hyvok SSD1306-display-driver-for-Arduino library](https://github.com/Hyvok/SSD1306-display-driver-for-Arduino)
  * No license given, and no copyright listed.
  * Documented by Kalle Hyvönen at http://www.dgkelectronics.com/library-for-controlling-ssd1306-based-oled-displays/
