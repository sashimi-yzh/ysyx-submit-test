#include <am.h>
#include <amdev.h>
#include <klib.h>
#include <soc.h>
#include <stdint.h>
#include <sys/types.h>
/* PS/2 scancode (set 2) -> AM key mapping (single-byte makes) */
static const int ps2_scancode_to_am[256] = {
    [0x76] = AM_KEY_ESCAPE,
    [0x16] = AM_KEY_1,
    [0x1e] = AM_KEY_2,
    [0x26] = AM_KEY_3,
    [0x25] = AM_KEY_4,
    [0x2e] = AM_KEY_5,
    [0x36] = AM_KEY_6,
    [0x3d] = AM_KEY_7,
    [0x3e] = AM_KEY_8,
    [0x46] = AM_KEY_9,
    [0x45] = AM_KEY_0,
    [0x4e] = AM_KEY_MINUS,
    [0x55] = AM_KEY_EQUALS,
    [0x66] = AM_KEY_BACKSPACE,
    [0x0d] = AM_KEY_TAB,
    [0x15] = AM_KEY_Q,
    [0x1d] = AM_KEY_W,
    [0x24] = AM_KEY_E,
    [0x2d] = AM_KEY_R,
    [0x2c] = AM_KEY_T,
    [0x35] = AM_KEY_Y,
    [0x3c] = AM_KEY_U,
    [0x43] = AM_KEY_I,
    [0x44] = AM_KEY_O,
    [0x4d] = AM_KEY_P,
    [0x54] = AM_KEY_LEFTBRACKET,
    [0x5b] = AM_KEY_RIGHTBRACKET,
    [0x5a] = AM_KEY_RETURN,
    [0x14] = AM_KEY_LCTRL,
    [0x1c] = AM_KEY_A,
    [0x1b] = AM_KEY_S,
    [0x23] = AM_KEY_D,
    [0x2b] = AM_KEY_F,
    [0x34] = AM_KEY_G,
    [0x33] = AM_KEY_H,
    [0x3b] = AM_KEY_J,
    [0x42] = AM_KEY_K,
    [0x4b] = AM_KEY_L,
    [0x4c] = AM_KEY_SEMICOLON,
    [0x52] = AM_KEY_APOSTROPHE,
    [0x0e] = AM_KEY_GRAVE,
    [0x12] = AM_KEY_LSHIFT,
    [0x5d] = AM_KEY_BACKSLASH,
    [0x1a] = AM_KEY_Z,
    [0x22] = AM_KEY_X,
    [0x21] = AM_KEY_C,
    [0x2a] = AM_KEY_V,
    [0x32] = AM_KEY_B,
    [0x31] = AM_KEY_N,
    [0x3a] = AM_KEY_M,
    [0x41] = AM_KEY_COMMA,
    [0x49] = AM_KEY_PERIOD,
    [0x4a] = AM_KEY_SLASH,
    [0x59] = AM_KEY_RSHIFT,
    [0x11] = AM_KEY_LALT,
    [0x29] = AM_KEY_SPACE,
    [0x58] = AM_KEY_CAPSLOCK,

    [0x05] = AM_KEY_F1,
    [0x06] = AM_KEY_F2,
    [0x04] = AM_KEY_F3,
    [0x0c] = AM_KEY_F4,
    [0x03] = AM_KEY_F5,
    [0x0b] = AM_KEY_F6,
    [0x83] = AM_KEY_F7,
    [0x0a] = AM_KEY_F8,
    [0x01] = AM_KEY_F9,
    [0x09] = AM_KEY_F10,
    [0x78] = AM_KEY_F11,
    [0x07] = AM_KEY_F12,
};

/* Extended PS/2 scancode (E0 prefix) -> AM key mapping */
static const int ps2_scancode_e0_to_am[256] = {
    [0x1C] = AM_KEY_RETURN,                             /* keypad Enter */
    [0x1D] = AM_KEY_RCTRL,       [0x35] = AM_KEY_SLASH, /* keypad slash */
    [0x38] = AM_KEY_RALT,        [0x47] = AM_KEY_HOME,
    [0x48] = AM_KEY_UP,          [0x49] = AM_KEY_PAGEUP,
    [0x4B] = AM_KEY_LEFT,        [0x4D] = AM_KEY_RIGHT,
    [0x4F] = AM_KEY_END,         [0x50] = AM_KEY_DOWN,
    [0x51] = AM_KEY_PAGEDOWN,    [0x52] = AM_KEY_INSERT,
    [0x53] = AM_KEY_DELETE,      [0x5B] = AM_KEY_APPLICATION,
    [0x5C] = AM_KEY_APPLICATION, [0x5D] = AM_KEY_APPLICATION,
};

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  enum { ST_FRESH, ST_E0 };
  static uint8_t state = ST_FRESH;
  static bool is_keydown = true;
  static uint8_t discard_cnt = 0;
  uint8_t signal = inb(KBD_ADDR);
  if (signal == 0) {
    kbd->keycode = 0;
    kbd->keydown = false;
    return;
  }
  if (discard_cnt != 0) {
    discard_cnt--;
    kbd->keycode = 0;
    kbd->keydown = false;
    return;
  }
  if (signal == 0xf0) {
    kbd->keycode = 0;
    kbd->keydown = false;
    is_keydown = false;
    return;
  }
  switch (state) {
  case ST_FRESH:
    if (signal == 0xe0) {
      state = ST_E0;
      kbd->keycode = 0;
      kbd->keydown = false;
      return;
    } else if (signal == 0xe1) {
      /* pause/break (multi-byte) - leave as before */
      discard_cnt = 7;
      kbd->keycode = (0xe100) | signal;
      kbd->keydown = is_keydown;
      is_keydown = true;
      return;
    } else {
      int code = ps2_scancode_to_am[signal];
      if (code != AM_KEY_NONE) {
        kbd->keycode = code;
        kbd->keydown = is_keydown;
      } else {
        kbd->keycode = 0;
        kbd->keydown = false;
      }
      is_keydown = true;
      return;
    }
    break;
  case ST_E0:
  default:
    state = ST_FRESH;
    {
      int code = ps2_scancode_e0_to_am[signal];
      if (code != AM_KEY_NONE) {
        kbd->keycode = code;
        kbd->keydown = is_keydown;
      } else {
        kbd->keycode = 0;
        kbd->keydown = false;
      }
      is_keydown = true;
      return;
    }
    break;
  }
}
