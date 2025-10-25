#include <am.h>
#include <klib.h>
#include <stdbool.h>

#include "amdev.h"
#include "device.h"
#include "../../riscv.h"


static int base_code[256] = {
    [0x1C] = AM_KEY_A, // A
    [0x32] = AM_KEY_B, // B
    [0x21] = AM_KEY_C, // C
    [0x23] = AM_KEY_D, // D
    [0x24] = AM_KEY_E, // E
    [0x2B] = AM_KEY_F, // F
    [0x34] = AM_KEY_G, // G
    [0x33] = AM_KEY_H, // H
    [0x43] = AM_KEY_I, // I
    [0x3B] = AM_KEY_J, // J
    [0x42] = AM_KEY_K, // K
    [0x4B] = AM_KEY_L, // L
    [0x3A] = AM_KEY_M, // M
    [0x31] = AM_KEY_N, // N
    [0x44] = AM_KEY_O, // O
    [0x4D] = AM_KEY_P, // P
    [0x15] = AM_KEY_Q, // Q
    [0x2D] = AM_KEY_R, // R
    [0x1B] = AM_KEY_S, // S
    [0x2C] = AM_KEY_T, // T
    [0x3C] = AM_KEY_U, // U
    [0x2A] = AM_KEY_V, // V
    [0x1D] = AM_KEY_W, // W
    [0x22] = AM_KEY_X, // X
    [0x35] = AM_KEY_Y, // Y
    [0x1A] = AM_KEY_Z, // Z
    [0x45] = AM_KEY_0, // 0
    [0x16] = AM_KEY_1, // 1
    [0x1E] = AM_KEY_2, // 2
    [0x26] = AM_KEY_3, // 3
    [0x25] = AM_KEY_4, // 4
    [0x2E] = AM_KEY_5, // 5
    [0x36] = AM_KEY_6, // 6
    [0x3D] = AM_KEY_7, // 7
    [0x3E] = AM_KEY_8, // 8
    [0x46] = AM_KEY_9, // 9
    [0x76] = AM_KEY_ESCAPE,
    [0x05] = AM_KEY_F1,
    [0x06] = AM_KEY_F2, 
    [0x04] = AM_KEY_F3, 
    [0x0C] = AM_KEY_F4,
    [0x03] = AM_KEY_F5,
    [0x0B] = AM_KEY_F6,
    [0x83] = AM_KEY_F7,
    [0x0A] = AM_KEY_F8,
    [0x01] = AM_KEY_F9,
    [0x09] = AM_KEY_F10,
    [0x78] = AM_KEY_F11,
    [0x07] = AM_KEY_F12,
    [0x0e] = AM_KEY_GRAVE,
    [0x70] = AM_KEY_0,
    [0x69] = AM_KEY_1,
    [0x72] = AM_KEY_2, 
    [0x7A] = AM_KEY_3,
    [0x6B] = AM_KEY_4,
    [0x73] = AM_KEY_5,
    [0x74] = AM_KEY_6,
    [0x6C] = AM_KEY_7,
    [0x75] = AM_KEY_8,
    [0x7D] = AM_KEY_9,
    [0x0D] = AM_KEY_TAB,
    [0x58] = AM_KEY_CAPSLOCK,
    [0x12] = AM_KEY_LSHIFT,
    [0x14] = AM_KEY_LCTRL,
    [0x11] = AM_KEY_LALT,
    [0x29] = AM_KEY_SPACE,
    [0x4E] = AM_KEY_MINUS,
    [0X55] = AM_KEY_EQUALS,
    [0x66] = AM_KEY_BACKSPACE,
    [0x54] = AM_KEY_LEFTBRACKET,
    [0x5B] = AM_KEY_RIGHTBRACKET,
    [0x5D] = AM_KEY_BACKSLASH,
    [0x4C] = AM_KEY_SEMICOLON,
    [0x52] = AM_KEY_APOSTROPHE,
    [0x5A] = AM_KEY_RETURN,
    [0x41] = AM_KEY_COMMA,
    [0x49] = AM_KEY_PERIOD,
    [0x4A] = AM_KEY_SLASH,
    [0x59] = AM_KEY_RSHIFT,
};  

static int ext_code[256] = {
  [0x75] = AM_KEY_UP,
  [0x72] = AM_KEY_DOWN,
  [0x6B] = AM_KEY_LEFT,
  [0x74] = AM_KEY_RIGHT,
  [0x11] = AM_KEY_RALT,
  [0x14] = AM_KEY_RCTRL,
  [0x70] = AM_KEY_INSERT,
  [0x71] = AM_KEY_DELETE,
  [0x6C] = AM_KEY_HOME,
  [0x69] = AM_KEY_END,
  [0x7D] = AM_KEY_PAGEUP,
  [0x7A] = AM_KEY_PAGEDOWN
};


void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) 
{
  bool down = true;
  int code;

  uint8_t ps2code = inb(DEV_KEYBOARD);
  if (ps2code == 0)
  {
    down = false; code = 0;
  }
  else if (ps2code == 0xF0)
  {
    down = false;
    ps2code = inb(DEV_KEYBOARD);
    code = base_code[ps2code];
  }
  else if (ps2code == 0xE0) 
  {
    ps2code = inb(DEV_KEYBOARD);
    if (ps2code == 0xF0) ps2code = inb(DEV_KEYBOARD);
    code = ext_code[ps2code];
  }
  else
  {
    down = true;
    code = base_code[ps2code];
  }

  kbd->keydown = down;
  kbd->keycode = code;
}
