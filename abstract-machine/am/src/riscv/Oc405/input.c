#include <am.h>
#include <klib-macros.h>
#include <klib.h>

#define KBD_BASE_ADDR  0x10011000
#define KBD_SCAN_CODE (*(volatile uint32_t *)(KBD_BASE_ADDR + 0x00))

uint8_t keybrd_translate(uint16_t code);

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint16_t  code  = (KBD_SCAN_CODE <<  8) & 0xFF00;
  if(code == 0) {
    kbd->keycode  = 0;
  } else if(code == 0xf000) {
    code  = (KBD_SCAN_CODE <<  8) & 0xFF00;
    kbd->keycode  = keybrd_translate(code);
    kbd->keydown  = 0;
  } else {
    code = code  | KBD_SCAN_CODE ;
    if((code & 0x00FF) == 0) {
      kbd->keycode  = keybrd_translate(code);
      kbd->keydown  = 1;
    } else if((code & 0x00FF) == 0xf0) {
      code = (code & 0xFF00)  | KBD_SCAN_CODE ;
      kbd->keycode  = keybrd_translate(code);
      kbd->keydown  = 0;
    } else {
      kbd->keycode  = keybrd_translate(code);
      kbd->keydown  = 1;
    }
  }
}

uint8_t keybrd_translate(uint16_t code) {
  uint8_t key_num ;
  switch (code)
  {
    // first line
    case 0x7600: key_num = 1; break;
    case 0x0500: key_num = 2; break;
    case 0x0600: key_num = 3; break;
    case 0x0400: key_num = 4; break;
    case 0x0C00: key_num = 5; break;
    case 0x0300: key_num = 6; break;
    case 0x0b00: key_num = 7; break;
    case 0x8300: key_num = 8; break;
    case 0x0a00: key_num = 9; break;
    case 0x0100: key_num = 10; break;
    case 0x0900: key_num = 11; break;
    case 0x7800: key_num = 12; break;
    case 0x0700: key_num = 13; break;

    // sec line
    case 0x0e00: key_num = 14; break;
    case 0x1600: key_num = 15; break;
    case 0x1e00: key_num = 16; break;
    case 0x2600: key_num = 17; break;
    case 0x2500: key_num = 18; break;
    case 0x2e00: key_num = 19; break;
    case 0x3600: key_num = 20; break;
    case 0x3d00: key_num = 21; break;
    case 0x3e00: key_num = 22; break;
    case 0x4600: key_num = 23; break;
    case 0x4500: key_num = 24; break;
    case 0x4e00: key_num = 25; break;
    case 0x5500: key_num = 26; break;
    case 0x6600: key_num = 27; break;

    // third line
    case 0x0d00: key_num = 28; break;
    case 0x1500: key_num = 29; break;
    case 0x1d00: key_num = 30; break;
    case 0x2400: key_num = 31; break;
    case 0x2d00: key_num = 32; break;
    case 0x2c00: key_num = 33; break;
    case 0x3500: key_num = 34; break;
    case 0x3c00: key_num = 35; break;
    case 0x4300: key_num = 36; break;
    case 0x4400: key_num = 37; break;
    case 0x4d00: key_num = 38; break;
    case 0x5400: key_num = 39; break;
    case 0x5b00: key_num = 40; break;
    case 0x5d00: key_num = 41; break;

    // fourth line
    case 0x5800: key_num = 42; break;
    case 0x1c00: key_num = 43; break;
    case 0x1b00: key_num = 44; break;
    case 0x2300: key_num = 45; break;
    case 0x2b00: key_num = 46; break;
    case 0x3400: key_num = 47; break;
    case 0x3300: key_num = 48; break;
    case 0x3b00: key_num = 49; break;
    case 0x4200: key_num = 50; break;
    case 0x4b00: key_num = 51; break;
    case 0x4c00: key_num = 52; break;
    case 0x5200: key_num = 53; break;
    case 0x5a00: key_num = 54; break;

    // fifth line
    case 0x1200: key_num = 55; break;
    case 0x1a00: key_num = 56; break;
    case 0x2200: key_num = 57; break;
    case 0x2100: key_num = 58; break;
    case 0x2a00: key_num = 59; break;
    case 0x3200: key_num = 60; break;
    case 0x3100: key_num = 61; break;
    case 0x3a00: key_num = 62; break;
    case 0x4100: key_num = 63; break;
    case 0x4900: key_num = 64; break;
    case 0x4a00: key_num = 65; break;
    case 0x5900: key_num = 66; break;

    // sixth line
    case 0x1400: key_num = 67; break;
    //case 0x5900: key_num = 68; break; windows home key 
    case 0x1100: key_num = 69; break;
    case 0x2900: key_num = 70; break;
    case 0xe011: key_num = 71; break;
    case 0xe014: key_num = 72; break;

    // extend
    case 0xe075: key_num = 73; break;
    case 0xe072: key_num = 74; break;
    case 0xe06b: key_num = 75; break;
    case 0xe074: key_num = 76; break;
    case 0xe070: key_num = 77; break;
    case 0xe071: key_num = 78; break;
    case 0xe06c: key_num = 79; break;
    case 0xe069: key_num = 80; break;
    case 0xe07d: key_num = 81; break;
    case 0xe07a: key_num = 82; break;

    default: key_num = 0; break;
  }
  return key_num;
};
