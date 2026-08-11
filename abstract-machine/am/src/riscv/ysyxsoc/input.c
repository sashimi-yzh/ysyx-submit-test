#include <am.h>
#include "include/npc.h"

static bool extended_prefix = false;
static bool release_prefix = false;

static int decode_set2_scancode(uint8_t code, bool prefix_e0) {
  if (prefix_e0) {
    switch (code) {
      case 0x11: return AM_KEY_RALT;
      case 0x14: return AM_KEY_RCTRL;
      case 0x2f: return AM_KEY_APPLICATION;
      case 0x70: return AM_KEY_INSERT;
      case 0x71: return AM_KEY_DELETE;
      case 0x6c: return AM_KEY_HOME;
      case 0x69: return AM_KEY_END;
      case 0x7d: return AM_KEY_PAGEUP;
      case 0x7a: return AM_KEY_PAGEDOWN;
      case 0x75: return AM_KEY_UP;
      case 0x72: return AM_KEY_DOWN;
      case 0x6b: return AM_KEY_LEFT;
      case 0x74: return AM_KEY_RIGHT;
      default:   return AM_KEY_NONE;
    }
  } else {
    switch (code) {
      case 0x76: return AM_KEY_ESCAPE;
      case 0x05: return AM_KEY_F1;
      case 0x06: return AM_KEY_F2;
      case 0x04: return AM_KEY_F3;
      case 0x0c: return AM_KEY_F4;
      case 0x03: return AM_KEY_F5;
      case 0x0b: return AM_KEY_F6;
      case 0x83: return AM_KEY_F7;
      case 0x0a: return AM_KEY_F8;
      case 0x01: return AM_KEY_F9;
      case 0x09: return AM_KEY_F10;
      case 0x78: return AM_KEY_F11;
      case 0x07: return AM_KEY_F12;
      case 0x0e: return AM_KEY_GRAVE;
      case 0x16: return AM_KEY_1;
      case 0x1e: return AM_KEY_2;
      case 0x26: return AM_KEY_3;
      case 0x25: return AM_KEY_4;
      case 0x2e: return AM_KEY_5;
      case 0x36: return AM_KEY_6;
      case 0x3d: return AM_KEY_7;
      case 0x3e: return AM_KEY_8;
      case 0x46: return AM_KEY_9;
      case 0x45: return AM_KEY_0;
      case 0x4e: return AM_KEY_MINUS;
      case 0x55: return AM_KEY_EQUALS;
      case 0x66: return AM_KEY_BACKSPACE;
      case 0x0d: return AM_KEY_TAB;
      case 0x15: return AM_KEY_Q;
      case 0x1d: return AM_KEY_W;
      case 0x24: return AM_KEY_E;
      case 0x2d: return AM_KEY_R;
      case 0x2c: return AM_KEY_T;
      case 0x35: return AM_KEY_Y;
      case 0x3c: return AM_KEY_U;
      case 0x43: return AM_KEY_I;
      case 0x44: return AM_KEY_O;
      case 0x4d: return AM_KEY_P;
      case 0x54: return AM_KEY_LEFTBRACKET;
      case 0x5b: return AM_KEY_RIGHTBRACKET;
      case 0x5d: return AM_KEY_BACKSLASH;
      case 0x58: return AM_KEY_CAPSLOCK;
      case 0x1c: return AM_KEY_A;
      case 0x1b: return AM_KEY_S;
      case 0x23: return AM_KEY_D;
      case 0x2b: return AM_KEY_F;
      case 0x34: return AM_KEY_G;
      case 0x33: return AM_KEY_H;
      case 0x3b: return AM_KEY_J;
      case 0x42: return AM_KEY_K;
      case 0x4b: return AM_KEY_L;
      case 0x4c: return AM_KEY_SEMICOLON;
      case 0x52: return AM_KEY_APOSTROPHE;
      case 0x5a: return AM_KEY_RETURN;
      case 0x12: return AM_KEY_LSHIFT;
      case 0x1a: return AM_KEY_Z;
      case 0x22: return AM_KEY_X;
      case 0x21: return AM_KEY_C;
      case 0x2a: return AM_KEY_V;
      case 0x32: return AM_KEY_B;
      case 0x31: return AM_KEY_N;
      case 0x3a: return AM_KEY_M;
      case 0x41: return AM_KEY_COMMA;
      case 0x49: return AM_KEY_PERIOD;
      case 0x4a: return AM_KEY_SLASH;
      case 0x59: return AM_KEY_RSHIFT;
      case 0x14: return AM_KEY_LCTRL;
      case 0x11: return AM_KEY_LALT;
      case 0x29: return AM_KEY_SPACE;
      default:   return AM_KEY_NONE;
    }
  }
}

void __am_input_keybrd(AM_INPUT_KEYBRD_T *keyboard) {
  keyboard->keydown = false;
  keyboard->keycode = AM_KEY_NONE;
  for (int attempt = 0; attempt < 8; attempt++) {
    uint8_t scan_code = (uint8_t)(inl(YSYXSOC_KEYBOARD_DATA_ADDR) & 0xffu);
    if (scan_code == 0x00u) {
      return;
    }
    if (scan_code == 0xe0u) {
      extended_prefix = true;
      continue;
    }
    if (scan_code == 0xf0u) {
      release_prefix = true;
      continue;
    }
    int keycode = decode_set2_scancode(scan_code, extended_prefix);
    extended_prefix = false;
    if (keycode == AM_KEY_NONE) {
      release_prefix = false;
      continue;
    }
    keyboard->keycode = keycode;
    keyboard->keydown = !release_prefix;
    release_prefix = false;
    return;
  }
}
