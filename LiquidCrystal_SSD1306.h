/*
    Copyright © 2012-2015 Arduino LLC, Limor Fried/Ladyada, Michael Gregg,
    pocketmoon, Neil McNeight

    This file is part of LiquidCrystal_SSD1306.

    LiquidCrystal_SSD1306 is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 2.1 of the License, or
    (at your option) any later version.

    LiquidCrystal_SSD1306 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

-------------------------------------------------------------------------------
Change Log

DATE      VER   WHO   WHAT
06/20/15  1.6.0 NEM   Code cleanup and compatibility with Arduino 1.6.*
-------------------------------------------------------------------------------

 */


#ifndef LiquidCrystal_SSD1306_h
#define LiquidCrystal_SSD1306_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifdef __AVR_ATtiny85__
#include <TinyWireM.h>
#define Wire TinyWireM

#if ARDUINO >= 100
#define WIRE_WRITE TinyWireM.write
#else
#define WIRE_WRITE TinyWireM.send
#endif

#else
#include <Wire.h>
#endif

#define swap(a, b) { int8_t t = a; a = b; b = t; }

#define BLACK 0
#define WHITE 1
#define INVERSE 2

#define SSD1306_I2C_ADDRESS   0x3C	// 011110+SA0+RW - 0x3C or 0x3D
// Address for 96x16 is 0x3C
// Address for 128x32 is 0x3C
// Address for 128x64 is 0x3D (default) or 0x3C (if SA0 is grounded)

/*=========================================================================
    SSD1306 Displays
    -----------------------------------------------------------------------
    The driver is used in multiple displays (128x64, 128x32, etc.).
    Select the appropriate display below to create an appropriately
    sized framebuffer, etc.

    SSD1306_128_64  128x64 pixel display

    SSD1306_128_32  128x32 pixel display

    SSD1306_96_16

    -----------------------------------------------------------------------*/
//#define SSD1306_128_64
//#define SSD1306_128_32
#define SSD1306_96_16
/*=========================================================================*/

#if defined SSD1306_128_64 && defined SSD1306_128_32
#error "Only one SSD1306 display can be specified at once in SSD1306.h"
#endif
#if !defined SSD1306_128_64 && !defined SSD1306_128_32 && !defined SSD1306_96_16
#error "At least one SSD1306 display must be specified in SSD1306.h"
#endif

#if defined SSD1306_128_64
#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 64
#endif
#if defined SSD1306_128_32
#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 32
#endif
#if defined SSD1306_96_16
#define SSD1306_LCDWIDTH                  96
#define SSD1306_LCDHEIGHT                 16
#endif

#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A

//Set GDDRAM Page Start Address 0xB0 - OxB7
#define SSD1306_SETPAGESTART 0xB0

#define SSD1306_NOOP 0xE3

// Abbreviated ASCII 5x8 font
#if defined(USING_EEPROM_FONT)
extern const uint8_t eeprom_font[] EEMEM;
#else
extern const uint8_t flash_font[] PROGMEM;
#endif

#define SSD1306_FONT_WIDTH 5
#define SSD1306_FONT_HEIGHT 8

class LiquidCrystal_SSD1306 : public Print
{
  public:
    LiquidCrystal_SSD1306(uint8_t vccstate = SSD1306_SWITCHCAPVCC, uint8_t i2caddr = SSD1306_I2C_ADDRESS, uint8_t reset = 0);

    void init();

    void begin(uint8_t cols, uint8_t rows);

    void clear(bool inverted = false);
    void home();

    void noDisplay();
    void display();
    void noBlink();
    void blink();
    void noCursor();
    void cursor();
    void scrollDisplayLeft();
    void scrollDisplayRight();
    void leftToRight();
    void rightToLeft();
    void autoscroll();
    void noAutoscroll();

    // only if using backpack
    void setBacklight(uint8_t status);

    //    void createChar(uint8_t, uint8_t[]);
    void setCursor(uint8_t, uint8_t);
    virtual size_t write(uint8_t);
    //    void command(uint8_t);

    void invert(bool i);
    void dim(boolean dim);

    void startscrollright(uint8_t start, uint8_t stop);
    void startscrollleft(uint8_t start, uint8_t stop);

    void startscrolldiagright(uint8_t start, uint8_t stop);
    void startscrolldiagleft(uint8_t start, uint8_t stop);
    void stopscroll(void);


    // These MAY be overridden by the subclass to provide device-specific
    // optimized code.  Otherwise 'generic' versions are used.
    void
    drawChar(unsigned char c, bool inverted = false),
             setTextWrap(boolean w),
             setRotation(uint8_t r);

    using Print::write;

    uint8_t
    height(void),
           width(void),
           getRotation(void);

  protected:
    uint8_t
    rotation;
    boolean
    wrap; // If set, 'wrap' text at right edge of display

  private:
    uint8_t _i2caddr, _vccstate, _reset;
    uint8_t _width, _height, // Display w/h as modified by current rotation
            _x, _y, // pixel coordinates
            _rows, _cols, // Text w/h
            _r, _c; // character coordinates
    void ssd1306_command(uint8_t c);
    void ssd1306_data(uint8_t d);
};

#endif