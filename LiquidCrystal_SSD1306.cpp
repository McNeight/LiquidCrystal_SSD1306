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


#ifdef __AVR_ATtiny85__
#include "TinyWireM.h"
#define Wire TinyWireM
#else
#include <Wire.h>
#endif

#include "LiquidCrystal_SSD1306.h"

#define USING_EEPROM_FONT

// ATtiny25/45/85 Datasheet
#if defined(USING_EEPROM_FONT)
// Section 5.3
// "The ATtiny25/45/85 contains 128/256/512 bytes of data EEPROM memory.
//  It is organized as a separate data space, in which single bytes can
//  be read and written."
#include <avr/eeprom.h>
const uint8_t eeprom_font[] EEMEM = {
#else
// Section 5.1
// The ATtiny25/45/85 contains 2/4/8K bytes On-chip In-System Reprogrammable
// Flash memory for program storage.
// Since all AVR instructions are 16 or 32 bits wide, the Flash is organized
// as 1024/2048/4096 x 16.
#include <avr/pgmspace.h>
const uint8_t flash_font[] PROGMEM = {
#endif
  // Abbreviated ASCII 5x7 font from
  // SSD1306NoBuffer/SSD1306_NoBuffer/LCD_font_5x7.h
  0x00, 0x00, 0x4f, 0x00, 0x00, // !
  0x00, 0x03, 0x00, 0x03, 0x00, // "
  0x14, 0x3e, 0x14, 0x3e, 0x14, // #
  0x24, 0x2a, 0x7f, 0x2a, 0x12, // $
  0x63, 0x13, 0x08, 0x64, 0x63, // %
  0x36, 0x49, 0x55, 0x22, 0x50, // &
  0x00, 0x00, 0x07, 0x00, 0x00, // '
  0x00, 0x1c, 0x22, 0x41, 0x00, // (
  0x00, 0x41, 0x22, 0x1c, 0x00, // )
  0x0a, 0x04, 0x1f, 0x04, 0x0a, // *
  0x04, 0x04, 0x1f, 0x04, 0x04, // +
  0x50, 0x30, 0x00, 0x00, 0x00, // ,
  0x08, 0x08, 0x08, 0x08, 0x08, // -
  0x60, 0x60, 0x00, 0x00, 0x00, // .
  0x00, 0x60, 0x1c, 0x03, 0x00, // /
  0x3e, 0x41, 0x49, 0x41, 0x3e, // 0
  0x00, 0x02, 0x7f, 0x00, 0x00, // 1
  0x46, 0x61, 0x51, 0x49, 0x46, // 2
  0x21, 0x49, 0x4d, 0x4b, 0x31, // 3
  0x18, 0x14, 0x12, 0x7f, 0x10, // 4
  0x4f, 0x49, 0x49, 0x49, 0x31, // 5
  0x3e, 0x51, 0x49, 0x49, 0x32, // 6
  0x01, 0x01, 0x71, 0x0d, 0x03, // 7
  0x36, 0x49, 0x49, 0x49, 0x36, // 8
  0x26, 0x49, 0x49, 0x49, 0x3e, // 9
  0x00, 0x33, 0x33, 0x00, 0x00, // :
  0x00, 0x53, 0x33, 0x00, 0x00, // ;
  0x00, 0x08, 0x14, 0x22, 0x41, // <
  0x14, 0x14, 0x14, 0x14, 0x14, // =
  0x41, 0x22, 0x14, 0x08, 0x00, // >
  0x06, 0x01, 0x51, 0x09, 0x06, // ?
  0x3e, 0x41, 0x49, 0x15, 0x1e, // @
  0x78, 0x16, 0x11, 0x16, 0x78, // A
  0x7f, 0x49, 0x49, 0x49, 0x36, // B
  0x3e, 0x41, 0x41, 0x41, 0x22, // C
  0x7f, 0x41, 0x41, 0x41, 0x3e, // D
  0x7f, 0x49, 0x49, 0x49, 0x49, // E
  0x7f, 0x09, 0x09, 0x09, 0x09, // F
  0x3e, 0x41, 0x41, 0x49, 0x7b, // G
  0x7f, 0x08, 0x08, 0x08, 0x7f, // H
  0x00, 0x00, 0x7f, 0x00, 0x00, // I
  0x38, 0x40, 0x40, 0x41, 0x3f, // J
  0x7f, 0x08, 0x08, 0x14, 0x63, // K
  0x7f, 0x40, 0x40, 0x40, 0x40, // L
  0x7f, 0x06, 0x18, 0x06, 0x7f, // M
  0x7f, 0x06, 0x18, 0x60, 0x7f, // N
  0x3e, 0x41, 0x41, 0x41, 0x3e, // O
  0x7f, 0x09, 0x09, 0x09, 0x06, // P
  0x3e, 0x41, 0x51, 0x21, 0x5e, // Q
  0x7f, 0x09, 0x19, 0x29, 0x46, // R
  0x26, 0x49, 0x49, 0x49, 0x32, // S
  0x01, 0x01, 0x7f, 0x01, 0x01, // T
  0x3f, 0x40, 0x40, 0x40, 0x7f, // U
  0x0f, 0x30, 0x40, 0x30, 0x0f, // V
  0x1f, 0x60, 0x1c, 0x60, 0x1f, // W
  0x63, 0x14, 0x08, 0x14, 0x63, // X
  0x03, 0x04, 0x78, 0x04, 0x03, // Y
  0x61, 0x51, 0x49, 0x45, 0x43, // Z
  0x00, 0x7f, 0x41, 0x00, 0x00, // [
  0x03, 0x1c, 0x60, 0x00, 0x00, // / other way around
  0x00, 0x41, 0x7f, 0x00, 0x00, // ]
  0x0c, 0x02, 0x01, 0x02, 0x0c, // ^
  0x40, 0x40, 0x40, 0x40, 0x40, // _
  0x00, 0x01, 0x02, 0x04, 0x00, // `
  0x20, 0x54, 0x54, 0x54, 0x78, // a
  0x7f, 0x48, 0x44, 0x44, 0x38, // b
  0x38, 0x44, 0x44, 0x44, 0x44, // c
  0x38, 0x44, 0x44, 0x48, 0x7f, // d
  0x38, 0x54, 0x54, 0x54, 0x18, // e
  0x08, 0x7e, 0x09, 0x09, 0x00, // f
  0x0c, 0x52, 0x52, 0x54, 0x3e, // g
  0x7f, 0x08, 0x04, 0x04, 0x78, // h
  0x00, 0x00, 0x7d, 0x00, 0x00, // i
  0x00, 0x40, 0x3d, 0x00, 0x00, // j
  0x7f, 0x10, 0x28, 0x44, 0x00, // k
  0x00, 0x00, 0x3f, 0x40, 0x00, // l
  0x7c, 0x04, 0x18, 0x04, 0x78, // m
  0x7c, 0x08, 0x04, 0x04, 0x78, // n
  0x38, 0x44, 0x44, 0x44, 0x38, // o
  0x7f, 0x12, 0x11, 0x11, 0x0e, // p
  0x0e, 0x11, 0x11, 0x12, 0x7f, // q
  0x00, 0x7c, 0x08, 0x04, 0x04, // r
  0x48, 0x54, 0x54, 0x54, 0x24, // s
  0x04, 0x3e, 0x44, 0x44, 0x00, // t
  0x3c, 0x40, 0x40, 0x20, 0x7c, // u
  0x1c, 0x20, 0x40, 0x20, 0x1c, // v
  0x1c, 0x60, 0x18, 0x60, 0x1c, // w
  0x44, 0x28, 0x10, 0x28, 0x44, // x
  0x46, 0x28, 0x10, 0x08, 0x06, // y
  0x44, 0x64, 0x54, 0x4c, 0x44, // z
  0x00, 0x08, 0x77, 0x41, 0x00, // {
  0x00, 0x00, 0x7f, 0x00, 0x00, // |
  0x00, 0x41, 0x77, 0x08, 0x00, // }
  0x10, 0x08, 0x18, 0x10, 0x08  // ~
};

// initializer for I2C - we only indicate the reset pin!
LiquidCrystal_SSD1306::LiquidCrystal_SSD1306(uint8_t vccstate, uint8_t i2caddr, uint8_t reset)
{
  _width    = SSD1306_LCDWIDTH;
  _height   = SSD1306_LCDHEIGHT;
  _vccstate = vccstate;
  _i2caddr  = i2caddr;
  _reset    = reset;
  rotation  = 0;
  _y        = _x = 0;
  _r        = _c = 0;
  wrap      = false;
}


void LiquidCrystal_SSD1306::begin(uint8_t cols, uint8_t rows)
{
  _cols = cols;
  _rows = rows;

  // I2C Init
  Wire.begin();

  if (_reset)
  {
    // Setup reset pin direction (used by both SPI and I2C)
    pinMode(_reset, OUTPUT);
    digitalWrite(_reset, HIGH);
    // VDD (3.3V) goes high at start, lets just chill for a ms
    delay(1);
    // bring reset low
    digitalWrite(_reset, LOW);
    // wait 10ms
    delay(10);
    // bring out of reset
    digitalWrite(_reset, HIGH);
  }

  // Software Configuration
  // 1 Set MUX Ratio: A8h, 3Fh
  // 2 Set Display Offset: D3h, 00h
  // 3 Set Display Start Line: 40h
  // 4 Set Segment re-map: A0h/A1h
  // 5 Set COM Output Scan Direction: C0h/C8h
  // 6 Set COM Pins hardware configuration: DAh, 02
  // 7 Set Contrast Control: 81h, 7Fh
  // 8 Disable Entire Display On: A4h
  // 9 Set Normal Display: A6h
  // A Set Osc Frequency: D5h, 80h
  // B Enable charge pump regulator: 8Dh, 14h
  // C Display On: AFh

  // Combined initialization sequence
  noDisplay();                    // 0xAE
  ssd1306_command(SSD1306_MEMORYMODE);                    // 0x20
  ssd1306_command(0x00);                                  // 0x0 act like ks0108
  //ssd1306_command(0x00); // Horizontal Addressing Mode
  //ssd1306_command(0x01); // Vertical Addressing Mode
  //ssd1306_command(0x02); // Page Addressing Mode n10

  // 1 Set MUX Ratio: A8h, 3Fh
  ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
#if defined SSD1306_128_64
  // Init sequence for 128x64 OLED module
  ssd1306_command(0x3F);
#elif defined SSD1306_128_32
  // Init sequence for 128x32 OLED module
  ssd1306_command(0x1F);
#elif defined SSD1306_96_16
  // Init sequence for 96x16 OLED module
  ssd1306_command(0x0F);
#else
#error Display size not defined
#endif
  // 2 Set Display Offset: D3h, 00h
  ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
  ssd1306_command(0x0);                                   // no offset
  // 3 Set Display Start Line: 40h
  ssd1306_command(SSD1306_SETSTARTLINE | 0x0);            // line #0
  // 4 Set Segment re-map: A0h/A1h
  ssd1306_command(SSD1306_SEGREMAP | 0x1);
  // 5 Set COM Output Scan Direction: C0h/C8h
  ssd1306_command(SSD1306_COMSCANDEC);
#if defined SSD1306_128_64
  // 6 Set COM Pins hardware configuration: DAh, 02
  ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
  ssd1306_command(0x12);
  // 7 Set Contrast Control: 81h, 7Fh
  ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
  if (_vccstate == SSD1306_EXTERNALVCC)
  {
    ssd1306_command(0x9F);
  }
  else
  {
    ssd1306_command(0xCF);
  }
#elif defined SSD1306_128_32
  // 6 Set COM Pins hardware configuration: DAh, 02
  ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
  ssd1306_command(0x02);
  // 7 Set Contrast Control: 81h, 7Fh
  ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
  ssd1306_command(0x8F);
#elif defined SSD1306_96_16
  // 6 Set COM Pins hardware configuration: DAh, 02
  ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
  ssd1306_command(0x02);	//ada x12
  // 7 Set Contrast Control: 81h, 7Fh
  ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
  if (_vccstate == SSD1306_EXTERNALVCC)
  {
    ssd1306_command(0x10);
  }
  else
  {
    ssd1306_command(0xAF);
  }
#else
#error Display size not defined
#endif
  //
  ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xD9
  if (_vccstate == SSD1306_EXTERNALVCC)
  {
    ssd1306_command(0x22);
  }
  else
  {
    ssd1306_command(0xF1);
  }
  //
  ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
  ssd1306_command(0x40);
  // 8 Disable Entire Display On: A4h
  ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
  // 9 Set Normal Display: A6h
  ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6
  // A Set Osc Frequency: D5h, 80h
  ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
  ssd1306_command(0x80);                                  // the suggested ratio 0x80
  // B Enable charge pump regulator: 8Dh, 14h
  ssd1306_command(SSD1306_CHARGEPUMP);                    // 0x8D
  if (_vccstate == SSD1306_EXTERNALVCC)
  {
    ssd1306_command(0x10);
  }
  else
  {
    ssd1306_command(0x14);
  }
  // C Display On: AFh
  display(); //--turn on oled panel
  //if (!_reset)
  //{
  clear();
  //}
}


// clear everything
void LiquidCrystal_SSD1306::clear(bool inverted)
{
  ssd1306_command(SSD1306_COLUMNADDR);                    // 0x21
  ssd1306_command(0);   // Column start address (0 = reset)
  ssd1306_command(SSD1306_LCDWIDTH - 1); // Column end address (127 = reset)

  ssd1306_command(SSD1306_PAGEADDR);                      // 0x22
  ssd1306_command(0); // Page start address (0 = reset)
#if SSD1306_LCDHEIGHT == 64
  ssd1306_command(7); // Page end address
#endif
#if SSD1306_LCDHEIGHT == 32
  ssd1306_command(3); // Page end address
#endif
#if SSD1306_LCDHEIGHT == 16
  ssd1306_command(1); // Page end address
#endif

  /* Go to the start of the screen */
  ssd1306_command(SSD1306_SETPAGESTART);
  //ssd1306_command(SSD1306_SETSTARTLINE);
  ssd1306_command(SSD1306_SETLOWCOLUMN);
  ssd1306_command(SSD1306_SETHIGHCOLUMN);

  for (uint16_t i = 0; i < (SSD1306_LCDWIDTH * SSD1306_LCDHEIGHT / 8); ++i)
  {
    ssd1306_data(0x00);
  }

  invert(inverted);
  setCursor(0, 0);
}

void LiquidCrystal_SSD1306::home()
{
  setCursor(0, 0);
}

void LiquidCrystal_SSD1306::setCursor(uint8_t col, uint8_t row)
{
  if ((col < _cols) && (row < _rows))
  {
    _c = col;
    _r = row;
    _x = _c * (SSD1306_FONT_WIDTH + 1); // +1 for space between characters
    _y = _r * SSD1306_FONT_HEIGHT;

    ssd1306_command(SSD1306_SETPAGESTART | (_r));
    //ssd1306_command(SSD1306_SETSTARTLINE | (_r));
    ssd1306_command(SSD1306_SETLOWCOLUMN | (_x & 0x0F));
    ssd1306_command(SSD1306_SETHIGHCOLUMN | ((_x & 0xF0) >> 4));
  }
}

// Turn the display on/off (quickly)
void LiquidCrystal_SSD1306::noDisplay()
{
  ssd1306_command(SSD1306_DISPLAYOFF);
}
void LiquidCrystal_SSD1306::display()
{
  ssd1306_command(SSD1306_DISPLAYON);
}

// Turns the underline cursor on/off
void LiquidCrystal_SSD1306::noCursor()
{
  ssd1306_command(SSD1306_NOOP);
}
void LiquidCrystal_SSD1306::cursor()
{
  ssd1306_command(SSD1306_NOOP);
}

// Turn on and off the blinking cursor
void LiquidCrystal_SSD1306::noBlink()
{
  ssd1306_command(SSD1306_NOOP);
}
void LiquidCrystal_SSD1306::blink()
{
  ssd1306_command(SSD1306_NOOP);
}

// Turn on and off the backlight
void LiquidCrystal_SSD1306::setBacklight(uint8_t status)
{
  ssd1306_command(SSD1306_NOOP);
}

// These commands scroll the display without changing the RAM
void LiquidCrystal_SSD1306::scrollDisplayLeft(void)
{
  ssd1306_command(SSD1306_NOOP);
}
void LiquidCrystal_SSD1306::scrollDisplayRight(void)
{
  ssd1306_command(SSD1306_NOOP);
}

inline size_t LiquidCrystal_SSD1306::write(uint8_t value)
{
  if (value == '\n')
  {
    _y += SSD1306_FONT_HEIGHT;
    _r++;
    _x = _c = 0;
  }
  else if (value == '\r')
  {
    _x = _c = 0;
  }
  else
  {
    // drawChar(value, true); // Inverted
    drawChar(value);

    if (wrap && (_x > (_width - (SSD1306_FONT_WIDTH + 1))))
    {
      _y += SSD1306_FONT_HEIGHT;
      _r++;
      _x = _c = 0;
    }
  }
  return 1; // assume success
}

void LiquidCrystal_SSD1306::invert(bool i)
{
  if (i)
  {
    ssd1306_command(SSD1306_INVERTDISPLAY);
  }
  else
  {
    ssd1306_command(SSD1306_NORMALDISPLAY);
  }
}

// Dim the display
// dim = true: display is dimmed
// dim = false: display is normal
void LiquidCrystal_SSD1306::dim(boolean dim)
{
  uint8_t contrast;

  if (dim)
  {
    contrast = 0; // Dimmed display
  }
  else
  {
    if (_vccstate == SSD1306_EXTERNALVCC)
    {
      contrast = 0x9F;
    }
    else
    {
      contrast = 0xCF;
    }
  }
  // the range of contrast to too small to be really useful
  // it is useful to dim the display
  ssd1306_command(SSD1306_SETCONTRAST);
  ssd1306_command(contrast);
}

// startscrollright
// Activate a right handed scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F)
void LiquidCrystal_SSD1306::startscrollright(uint8_t start, uint8_t stop)
{
  ssd1306_command(SSD1306_RIGHT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(0X00);
  ssd1306_command(stop);
  ssd1306_command(0X00);
  ssd1306_command(0XFF);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}

// startscrollleft
// Activate a right handed scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F)
void LiquidCrystal_SSD1306::startscrollleft(uint8_t start, uint8_t stop)
{
  ssd1306_command(SSD1306_LEFT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(0X00);
  ssd1306_command(stop);
  ssd1306_command(0X00);
  ssd1306_command(0XFF);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}

// startscrolldiagright
// Activate a diagonal scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F)
void LiquidCrystal_SSD1306::startscrolldiagright(uint8_t start, uint8_t stop)
{
  ssd1306_command(SSD1306_SET_VERTICAL_SCROLL_AREA);
  ssd1306_command(0X00);
  ssd1306_command(SSD1306_LCDHEIGHT);
  ssd1306_command(SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(0X00);
  ssd1306_command(stop);
  ssd1306_command(0X01);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}

// startscrolldiagleft
// Activate a diagonal scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F)
void LiquidCrystal_SSD1306::startscrolldiagleft(uint8_t start, uint8_t stop)
{
  ssd1306_command(SSD1306_SET_VERTICAL_SCROLL_AREA);
  ssd1306_command(0X00);
  ssd1306_command(SSD1306_LCDHEIGHT);
  ssd1306_command(SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(0X00);
  ssd1306_command(stop);
  ssd1306_command(0X01);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}

void LiquidCrystal_SSD1306::stopscroll(void)
{
  ssd1306_command(SSD1306_DEACTIVATE_SCROLL);
}

// Draw a character
void LiquidCrystal_SSD1306::drawChar(unsigned char c, bool inverted)
{

  if ((_x > (_width - SSD1306_FONT_WIDTH))    || // Clip right
      (_y > (_height - SSD1306_FONT_HEIGHT))  || // Clip bottom
      (_x < 0)                                || // Clip left
      (_y < 0))                                  // Clip top
    return;

  if (c == 0x20) // Space
  {
    _x += SSD1306_FONT_WIDTH + 1;
    return;
  }

  ssd1306_command(SSD1306_SETPAGESTART | (_y / SSD1306_FONT_HEIGHT));
  //ssd1306_command(SSD1306_SETSTARTLINE | (_y / SSD1306_FONT_HEIGHT));
  ssd1306_command(SSD1306_SETLOWCOLUMN | (_x & 0x0F));
  ssd1306_command(SSD1306_SETHIGHCOLUMN | ((_x & 0xF0) >> 4));


  // top half

  for (uint8_t i = 0; i < 5; ++i)
  {
#if defined(USING_EEPROM_FONT)
    /* For reading a byte from the font table we need to read it from EEPROM */
    uint8_t b = eeprom_read_byte(&eeprom_font[((c - 0x21) * 5) + i]);
    //uint8_t b = eeprom_read_byte(&eeprom_font[(c * 5) + i]);
    //uint8_t b = pgm_read_byte(&eeprom_font[((c - 0x20) * 5) + i]);
    //uint8_t b = EEPROM.read(((c - 0x20) * 5) + i);
#else
    uint8_t b = pgm_read_byte(&flash_font[((c - 0x21) * 5) + i]);
#endif
    if (inverted)
    {
      b ^= 0xFF;
    }
    ssd1306_data(b);
  }

  // Spacing between characters
  if (inverted)
  {
    ssd1306_data(0xFF);
  }
  else
  {
    ssd1306_data(0x00);
  }

  _x += SSD1306_FONT_WIDTH + 1;
  // if ((_x > _width - SSD1306_FONT_WIDTH) && (_y >= _height - SSD1306_FONT_HEIGHT))
  // {
  // _x = 0;
  // _y = _height - SSD1306_FONT_HEIGHT;
  // }
  // else
  // {
  // if (_x > _width - 10)
  // {
  // _x = 0;
  // _y += SSD1306_FONT_HEIGHT;
  // }
  // if (_y > _height - SSD1306_FONT_HEIGHT)
  // {
  // _y = _height - SSD1306_FONT_HEIGHT;
  // }
  // }

}

void LiquidCrystal_SSD1306::setTextWrap(boolean w)
{
  wrap = w;
}

uint8_t LiquidCrystal_SSD1306::getRotation(void)
{
  return rotation;
}

// Call this function after clearing the screen and before writing text
void LiquidCrystal_SSD1306::setRotation(uint8_t x)
{
  rotation = (x & 3);
  switch (rotation)
  {
    case 0: // Normal
      _width  = SSD1306_LCDWIDTH;
      _height = SSD1306_LCDHEIGHT;
      ssd1306_command(SSD1306_SEGREMAP | 0x1);
      ssd1306_command(SSD1306_COMSCANDEC);
      break;
    case 2: // Upside Down
      // Not accurate for 96x16 display
      // Lines should begin at x = 32 instead of x = 0
      _width  = SSD1306_LCDWIDTH;
      _height = SSD1306_LCDHEIGHT;
      ssd1306_command(SSD1306_SEGREMAP);
      ssd1306_command(SSD1306_COMSCANINC);
      break;
    case 1:
    case 3:
      _width  = SSD1306_LCDHEIGHT;
      _height = SSD1306_LCDWIDTH;
      break;
  }
}

// Return the size of the display (per current rotation)
uint8_t LiquidCrystal_SSD1306::width(void)
{
  return _width;
}

uint8_t LiquidCrystal_SSD1306::height(void)
{
  return _height;
}

void LiquidCrystal_SSD1306::ssd1306_command(uint8_t c)
{
  // I2C
  Wire.beginTransmission(_i2caddr);
  Wire.write(0x00); // Co = 0, D/C = 0
  Wire.write(c);
  Wire.endTransmission();
}

void LiquidCrystal_SSD1306::ssd1306_data(uint8_t d)
{
  // I2C
  Wire.beginTransmission(_i2caddr);
  Wire.write(0x40); // Co = 0, D/C = 1
  Wire.write(d);
  Wire.endTransmission();
}
