#include <am.h>
#include "ysyxsoc.h"

#define PS2_DATA_REG (*(volatile uint8_t *)(PS2_BASE + 0x0))

#define PS2_F0 0xF0   // break code 前缀
#define PS2_E0 0xE0   // extended 前缀

enum { ST_NORMAL = 0, ST_F0, ST_E0, ST_E0_F0 };
static int kbd_state = ST_NORMAL;

static int map_normal(uint8_t sc) {
  switch (sc) {
    case 0x76: return 1;   // ESCAPE
    case 0x05: return 2;   // F1
    case 0x06: return 3;   // F2
    case 0x04: return 4;   // F3
    case 0x0C: return 5;   // F4
    case 0x03: return 6;   // F5
    case 0x0B: return 7;   // F6
    case 0x83: return 8;   // F7
    case 0x0A: return 9;   // F8
    case 0x01: return 10;  // F9
    case 0x09: return 11;  // F10
    case 0x78: return 12;  // F11
    case 0x07: return 13;  // F12
    case 0x0E: return 14;  // GRAVE `
    case 0x16: return 15;  // 1
    case 0x1E: return 16;  // 2
    case 0x26: return 17;  // 3
    case 0x25: return 18;  // 4
    case 0x2E: return 19;  // 5
    case 0x36: return 20;  // 6
    case 0x3D: return 21;  // 7
    case 0x3E: return 22;  // 8
    case 0x46: return 23;  // 9
    case 0x45: return 24;  // 0
    case 0x4E: return 25;  // MINUS
    case 0x55: return 26;  // EQUALS
    case 0x66: return 27;  // BACKSPACE
    case 0x0D: return 28;  // TAB
    case 0x15: return 29;  // Q
    case 0x1D: return 30;  // W
    case 0x24: return 31;  // E
    case 0x2D: return 32;  // R
    case 0x2C: return 33;  // T
    case 0x35: return 34;  // Y
    case 0x3C: return 35;  // U
    case 0x43: return 36;  // I
    case 0x44: return 37;  // O
    case 0x4D: return 38;  // P
    case 0x54: return 39;  // LEFTBRACKET
    case 0x5B: return 40;  // RIGHTBRACKET
    case 0x5D: return 41;  // BACKSLASH
    case 0x58: return 42;  // CAPSLOCK
    case 0x1C: return 43;  // A
    case 0x1B: return 44;  // S
    case 0x23: return 45;  // D
    case 0x2B: return 46;  // F
    case 0x34: return 47;  // G
    case 0x33: return 48;  // H
    case 0x3B: return 49;  // J
    case 0x42: return 50;  // K
    case 0x4B: return 51;  // L
    case 0x4C: return 52;  // SEMICOLON
    case 0x52: return 53;  // APOSTROPHE
    case 0x5A: return 54;  // RETURN
    case 0x12: return 55;  // LSHIFT
    case 0x1A: return 56;  // Z
    case 0x22: return 57;  // X
    case 0x21: return 58;  // C
    case 0x2A: return 59;  // V
    case 0x32: return 60;  // B
    case 0x31: return 61;  // N
    case 0x3A: return 62;  // M
    case 0x41: return 63;  // COMMA
    case 0x49: return 64;  // PERIOD
    case 0x4A: return 65;  // SLASH
    case 0x59: return 66;  // RSHIFT
    case 0x14: return 67;  // LCTRL
    case 0x11: return 69;  // LALT
    case 0x29: return 70;  // SPACE
    default:   return 0;   
  }
}

static int map_extended(uint8_t sc) {
  switch (sc) {
    case 0x75: return 73;  // UP
    case 0x72: return 74;  // DOWN
    case 0x6B: return 75;  // LEFT
    case 0x74: return 76;  // RIGHT
    case 0x70: return 77;  // INSERT
    case 0x71: return 78;  // DELETE
    case 0x6C: return 79;  // HOME
    case 0x69: return 80;  // END
    case 0x7D: return 81;  // PAGEUP
    case 0x7A: return 82;  // PAGEDOWN
    case 0x2F: return 68;  // APPLICATION
    case 0x11: return 71;  // RALT
    case 0x14: return 72;  // RCTRL
    default:   return 0;
  }
}

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  
  kbd->keydown = false;
  kbd->keycode = AM_KEY_NONE;

  for (int i = 0; i < 16; i++) {
    uint8_t byte = PS2_DATA_REG;
    if (byte == 0) break;  // 无数据

    switch (kbd_state) {
      case ST_NORMAL:
        if (byte == PS2_E0) {
          kbd_state = ST_E0;
        } else if (byte == PS2_F0) {
          kbd_state = ST_F0;
        } else {
          int key = map_normal(byte);
          if (key) {
            kbd->keydown = true;
            kbd->keycode = key;
            kbd_state = ST_NORMAL;
            return;
          }
        }
        break;

      case ST_F0:  // 普通 break: 上一字节是 0xF0
        {
          int key = map_normal(byte);
          if (key) {
            kbd->keydown = false;
            kbd->keycode = key;
          }
          kbd_state = ST_NORMAL;
          if (key) return;
        }
        break;

      case ST_E0:  
        if (byte == PS2_F0) {
          kbd_state = ST_E0_F0;
        } else {
          int key = map_extended(byte);
          if (key) {
            kbd->keydown = true;
            kbd->keycode = key;
            kbd_state = ST_NORMAL;
            return;
          }
          kbd_state = ST_NORMAL;
        }
        break;

      case ST_E0_F0:  // 扩展 break: 0xE0, 0xF0 之后
        {
          int key = map_extended(byte);
          if (key) {
            kbd->keydown = false;
            kbd->keycode = key;
          }
          kbd_state = ST_NORMAL;
          if (key) return;
        }
        break;

      default:
        kbd_state = ST_NORMAL;
        break;
    }
  }
}
