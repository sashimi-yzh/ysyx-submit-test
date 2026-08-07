#include <am.h>

#define PS2_BASE 0x10011000L
#define PS2_DATA (*(volatile uint8_t *)(PS2_BASE + 0))

#define AT_NORMAL_SCANCODE_A            0x1C
#define AT_NORMAL_SCANCODE_B            0x32
#define AT_NORMAL_SCANCODE_C            0x21
#define AT_NORMAL_SCANCODE_D            0x23
#define AT_NORMAL_SCANCODE_E            0x24
#define AT_NORMAL_SCANCODE_F            0x2B
#define AT_NORMAL_SCANCODE_G            0x34
#define AT_NORMAL_SCANCODE_H            0x33
#define AT_NORMAL_SCANCODE_I            0x43
#define AT_NORMAL_SCANCODE_J            0x3B
#define AT_NORMAL_SCANCODE_K            0x42
#define AT_NORMAL_SCANCODE_L            0x4B
#define AT_NORMAL_SCANCODE_M            0x3A
#define AT_NORMAL_SCANCODE_N            0x31
#define AT_NORMAL_SCANCODE_O            0x44
#define AT_NORMAL_SCANCODE_P            0x4D
#define AT_NORMAL_SCANCODE_Q            0x15
#define AT_NORMAL_SCANCODE_R            0x2D
#define AT_NORMAL_SCANCODE_S            0x1B
#define AT_NORMAL_SCANCODE_T            0x2C
#define AT_NORMAL_SCANCODE_U            0x3C
#define AT_NORMAL_SCANCODE_V            0x2A
#define AT_NORMAL_SCANCODE_W            0x1D
#define AT_NORMAL_SCANCODE_X            0x22
#define AT_NORMAL_SCANCODE_Y            0x35
#define AT_NORMAL_SCANCODE_Z            0x1A
#define AT_NORMAL_SCANCODE_0            0x45
#define AT_NORMAL_SCANCODE_1            0x16
#define AT_NORMAL_SCANCODE_2            0x1E
#define AT_NORMAL_SCANCODE_3            0x26
#define AT_NORMAL_SCANCODE_4            0x25
#define AT_NORMAL_SCANCODE_5            0x2E
#define AT_NORMAL_SCANCODE_6            0x36
#define AT_NORMAL_SCANCODE_7            0x3D
#define AT_NORMAL_SCANCODE_8            0x3E
#define AT_NORMAL_SCANCODE_9            0x46
#define AT_NORMAL_SCANCODE_GRAVE        0x0E
#define AT_NORMAL_SCANCODE_MINUS        0x4E
#define AT_NORMAL_SCANCODE_EQUALS       0x55
#define AT_NORMAL_SCANCODE_BACKSLASH    0x5D
#define AT_NORMAL_SCANCODE_BACKSPACE    0x66
#define AT_NORMAL_SCANCODE_SPACE        0x29
#define AT_NORMAL_SCANCODE_TAB          0x0D
#define AT_NORMAL_SCANCODE_CAPSLOCK     0x58
#define AT_NORMAL_SCANCODE_LSHIFT       0x12
#define AT_NORMAL_SCANCODE_LCTRL        0x14
#define AT_NORMAL_SCANCODE_LALT         0x11
#define AT_NORMAL_SCANCODE_RSHIFT       0x59
#define AT_NORMAL_SCANCODE_RETURN       0x5A
#define AT_NORMAL_SCANCODE_ESCAPE       0x76
#define AT_NORMAL_SCANCODE_F1           0x05
#define AT_NORMAL_SCANCODE_F2           0x06
#define AT_NORMAL_SCANCODE_F3           0x04
#define AT_NORMAL_SCANCODE_F4           0x0C
#define AT_NORMAL_SCANCODE_F5           0x03
#define AT_NORMAL_SCANCODE_F6           0x0B
#define AT_NORMAL_SCANCODE_F7           0x83
#define AT_NORMAL_SCANCODE_F8           0x0A
#define AT_NORMAL_SCANCODE_F9           0x01
#define AT_NORMAL_SCANCODE_F10          0x09
#define AT_NORMAL_SCANCODE_F11          0x78
#define AT_NORMAL_SCANCODE_F12          0x07
#define AT_NORMAL_SCANCODE_LEFTBRACKET  0x54
#define AT_NORMAL_SCANCODE_RIGHTBRACKET 0x5B
#define AT_NORMAL_SCANCODE_SEMICOLON    0x4C
#define AT_NORMAL_SCANCODE_APOSTROPHE   0x52
#define AT_NORMAL_SCANCODE_COMMA        0x41
#define AT_NORMAL_SCANCODE_PERIOD       0x49
#define AT_NORMAL_SCANCODE_SLASH        0x4A

#define AT_EXT_SCANCODE_INSERT       0x70
#define AT_EXT_SCANCODE_HOME         0x6C
#define AT_EXT_SCANCODE_PAGEUP       0x7D
#define AT_EXT_SCANCODE_DELETE       0x71
#define AT_EXT_SCANCODE_END          0x69
#define AT_EXT_SCANCODE_PAGEDOWN     0x7A
#define AT_EXT_SCANCODE_UP           0x75
#define AT_EXT_SCANCODE_LEFT         0x6B
#define AT_EXT_SCANCODE_DOWN         0x72
#define AT_EXT_SCANCODE_RIGHT        0x74
#define AT_EXT_SCANCODE_RCTRL        0x14
#define AT_EXT_SCANCODE_RALT         0x11
#define AT_EXT_SCANCODE_APPLICATION  0x2F

#define NORMAL_KEYMAP(f) \
  f(A) f(B) f(C) f(D) f(E) f(F) f(G) f(H) f(I) f(J) f(K) f(L) f(M) \
  f(N) f(O) f(P) f(Q) f(R) f(S) f(T) f(U) f(V) f(W) f(X) f(Y) f(Z) \
  f(0) f(1) f(2) f(3) f(4) f(5) f(6) f(7) f(8) f(9) \
  f(GRAVE) f(MINUS) f(EQUALS) f(BACKSLASH) f(BACKSPACE) f(SPACE) f(TAB) \
  f(CAPSLOCK) f(LSHIFT) f(LCTRL) f(LALT) f(RSHIFT) \
  f(RETURN) f(ESCAPE) \
  f(F1) f(F2) f(F3) f(F4) f(F5) f(F6) f(F7) f(F8) f(F9) f(F10) f(F11) f(F12) \
  f(LEFTBRACKET) f(RIGHTBRACKET) \
  f(SEMICOLON) f(APOSTROPHE) f(COMMA) f(PERIOD) f(SLASH)

#define EXT_KEYMAP(f) \
  f(INSERT) f(HOME) f(PAGEUP) f(DELETE) f(END) f(PAGEDOWN) \
  f(UP) f(LEFT) f(DOWN) f(RIGHT) \
  f(RCTRL) f(RALT) f(APPLICATION)

#define SET_KEYMAP_NORMAL(name) [AT_NORMAL_SCANCODE_##name] = AM_KEY_##name,
#define SET_KEYMAP_EXT(name)    [AT_EXT_SCANCODE_##name]    = AM_KEY_##name,
static uint8_t keymap[256]     = { NORMAL_KEYMAP(SET_KEYMAP_NORMAL) };
static uint8_t keymap_ext[256] = { EXT_KEYMAP(SET_KEYMAP_EXT) };

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  static bool extended = false;
  static bool released = false;

  kbd->keydown = false;
  kbd->keycode = AM_KEY_NONE;

  uint8_t sc = PS2_DATA;
  if (sc == 0) return;

  if (sc == 0xE0) {
    extended = true;
    return;
  }
  if (sc == 0xF0) {
    released = true;
    return;
  }

  kbd->keycode = extended ? keymap_ext[sc] : keymap[sc];
  kbd->keydown = !released;

  extended = false;
  released = false;
}
