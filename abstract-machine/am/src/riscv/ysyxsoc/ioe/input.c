#include <am.h>
#include <riscv/ysyxsoc/ysyxsoc.h>

const int ps2_scancode_to_amkey[144] = {
    // 0x00 - 0x0F
    0, AM_KEY_F9, 0, AM_KEY_F5, 
    AM_KEY_F3, AM_KEY_F1, AM_KEY_F2, AM_KEY_F12,
    0, AM_KEY_F10, AM_KEY_F8, AM_KEY_F6, 
    AM_KEY_F4, AM_KEY_TAB, AM_KEY_GRAVE, 0,
    
    // 0x10 - 0x1F
    0, AM_KEY_LALT, AM_KEY_LSHIFT, 0,
    AM_KEY_LCTRL, AM_KEY_Q,    AM_KEY_1,    0,
    0, 0, AM_KEY_Z,    AM_KEY_S,
    AM_KEY_A,    AM_KEY_W,    AM_KEY_2,    0,
    
    // 0x20 - 0x2F
    0, AM_KEY_C,    AM_KEY_X,    AM_KEY_D,
    AM_KEY_E,    AM_KEY_4,    AM_KEY_3,    0,
    0, AM_KEY_SPACE,AM_KEY_V,    AM_KEY_F,
    AM_KEY_T,    AM_KEY_R,    AM_KEY_5,    0,
    
    // 0x30 - 0x3F
    0, AM_KEY_N,    AM_KEY_B,    AM_KEY_H,
    AM_KEY_G,    AM_KEY_Y,    AM_KEY_6,    0,
    0, 0, AM_KEY_M,    AM_KEY_J,
    AM_KEY_U,    AM_KEY_7,    AM_KEY_8,    0,
    
    // 0x40 - 0x4F
    0, AM_KEY_COMMA,AM_KEY_K,    AM_KEY_I,
    AM_KEY_O,    AM_KEY_0,    AM_KEY_9,    0,
    0, AM_KEY_PERIOD,AM_KEY_SLASH,AM_KEY_L,
    AM_KEY_SEMICOLON, AM_KEY_P, AM_KEY_MINUS, 0,
    
    // 0x50 - 0x5F
    0, 0, AM_KEY_APOSTROPHE, 0,
    AM_KEY_LEFTBRACKET, AM_KEY_EQUALS, 0, 0,
    AM_KEY_CAPSLOCK, AM_KEY_RSHIFT, AM_KEY_RETURN, AM_KEY_RIGHTBRACKET,
    0, AM_KEY_BACKSLASH, 0, 0,
    
    // 0x60 - 0x6F
    0, 0, 0, 0,
    0, 0, AM_KEY_BACKSPACE, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    
    // 0x70 - 0x7F
    0, 0, 0, 0,
    0, 0, AM_KEY_ESCAPE, 0,
    AM_KEY_F11, 0, 0, 0,
    0, 0, AM_KEY_F11, 0,
    // 0x80 - 0x8F
    0, 0, 0, AM_KEY_F7,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
   };

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  int keyname = 0;
  bool extend = false;
  keyname = inb(PS2_ADDR);
  if(keyname == 0xe0) {
    extend = true;
    keyname = inb(PS2_ADDR);
  }

  if(keyname == 0xf0) {
      keyname = inb(PS2_ADDR);
    if(keyname == 0xe0) {
      extend = true;
      keyname = inb(PS2_ADDR);
    }
      kbd->keydown = false;
  } else {
    kbd->keydown = true;
  }

  if(extend) {
    switch (keyname)
    {
    case 0x11: kbd->keycode = AM_KEY_RALT; break;
    case 0x14: kbd->keycode = AM_KEY_RCTRL; break;
    case 0x70: kbd->keycode = AM_KEY_INSERT; break;
    case 0x71: kbd->keycode = AM_KEY_DELETE; break;
    case 0x6c: kbd->keycode = AM_KEY_HOME; break;
    case 0x69: kbd->keycode = AM_KEY_END; break;
    case 0x7d: kbd->keycode = AM_KEY_PAGEUP; break;
    case 0x7a: kbd->keycode = AM_KEY_PAGEDOWN; break;
    case 0x75: kbd->keycode = AM_KEY_UP; break;
    case 0x72: kbd->keycode = AM_KEY_DOWN; break;
    case 0x6b: kbd->keycode = AM_KEY_LEFT; break;
    case 0x74: kbd->keycode = AM_KEY_RIGHT; break;
    default:
      break;
    }
  } else {
    kbd->keycode = ps2_scancode_to_amkey[keyname];
  }
}