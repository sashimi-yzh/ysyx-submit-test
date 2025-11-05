#include <am.h>
#include <klib-macros.h>

#define PS2_BASE 0x10011000
#define PS2_KEY (*(volatile uint8_t*)(PS2_BASE))


//https://www.cnblogs.com/xiii/p/9182425.html
#define KEYCODE_A 0x1C
#define KEYCODE_B 0x32
#define KEYCODE_C 0x21
#define KEYCODE_D 0x23
#define KEYCODE_E 0x24
#define KEYCODE_F 0x2B
#define KEYCODE_G 0x34
#define KEYCODE_H 0x33
#define KEYCODE_I 0x43
#define KEYCODE_J 0x3B
#define KEYCODE_K 0x42
#define KEYCODE_L 0x4B
#define KEYCODE_M 0x3A
#define KEYCODE_N 0x31
#define KEYCODE_O 0x44
#define KEYCODE_P 0x4D
#define KEYCODE_Q 0x15
#define KEYCODE_R 0x2D
#define KEYCODE_S 0x1B
#define KEYCODE_T 0x2C
#define KEYCODE_U 0x3C
#define KEYCODE_V 0x2A
#define KEYCODE_W 0x1D
#define KEYCODE_X 0x22
#define KEYCODE_Y 0x35
#define KEYCODE_Z 0x1A
#define KEYCODE_0 0x45
#define KEYCODE_1 0x16
#define KEYCODE_2 0x1E
#define KEYCODE_3 0x26
#define KEYCODE_4 0x25
#define KEYCODE_5 0x2E
#define KEYCODE_6 0x36
#define KEYCODE_7 0x3D
#define KEYCODE_8 0x3E
#define KEYCODE_9 0x46
#define KEYCODE_GRAVE 0x0E
#define KEYCODE_MINUS 0x4E
#define KEYCODE_EQUALS 0x55
#define KEYCODE_BACKSLASH 0x5D
#define KEYCODE_BACKSPACE 0x66
#define KEYCODE_SPACE 0x29
#define KEYCODE_TAB 0x0D
#define KEYCODE_CAPS 0x58
#define KEYCODE_LSHIFT 0x12
#define KEYCODE_LCTRL 0x14
#define KEYCODE_LALT 0x11
#define KEYCODE_RSHIFT 0x59
#define KEYCODE_ENTER 0x5A
#define KEYCODE_ESC 0x76
#define KEYCODE_F1 0x05
#define KEYCODE_F2 0x06
#define KEYCODE_F3 0x04
#define KEYCODE_F4 0x0C
#define KEYCODE_F5 0x03
#define KEYCODE_F6 0x0B
#define KEYCODE_F7 0x83
#define KEYCODE_F8 0x0A
#define KEYCODE_F9 0x01
#define KEYCODE_F10 0x09
#define KEYCODE_F11 0x78
#define KEYCODE_F12 0x07
#define KEYCODE_SCROLL 0x7E
#define KEYCODE_LEFTBRACKET 0x54
#define KEYCODE_NUM 0x77
#define KEYCODE_KPSTAR 0x7C
#define KEYCODE_KPMINUS 0x7B
#define KEYCODE_KPPLUS 0x79
#define KEYCODE_KP 0x71
#define KEYCODE_KP0 0x70
#define KEYCODE_KP1 0x69
#define KEYCODE_KP2 0x72
#define KEYCODE_KP3 0x7A
#define KEYCODE_KP4 0x6B
#define KEYCODE_KP5 0x73
#define KEYCODE_KP6 0x74
#define KEYCODE_KP7 0x6C
#define KEYCODE_KP8 0x75
#define KEYCODE_KP9 0x7D
#define KEYCODE_RIGHTBRACKET 0x5B
#define KEYCODE_SEMICOLON 0x4C
#define KEYCODE_APOSTROPHE 0x52
#define KEYCODE_COMMA 0x41
#define KEYCODE_PERIOD 0x49 
#define KEYCODE_SLASH 0x4A


#define KEYCODE_LGUI 0x1F
#define KEYCODE_RCTRL 0x14
#define KEYCODE_RGUI 0x27
#define KEYCODE_RALT 0x11
#define KEYCODE_APPLICATION 0x2F
#define KEYCODE_INSERT 0x70
#define KEYCODE_HOME 0x6C
#define KEYCODE_PAGEUP 0x7D
#define KEYCODE_DELETE 0x71
#define KEYCODE_END 0x69
#define KEYCODE_PAGEDOWN 0x7A
#define KEYCODE_UP 0x75
#define KEYCODE_LEFT 0x6B
#define KEYCODE_DOWN 0x72
#define KEYCODE_RIGHT 0x74
#define KEYCODE_KPSLASH 0x4A
#define KEYCODE_KPENTER 0x5A


#define KEYCODE_PRNTSCRN  // 0xE0 0x12 0xE0 0x7C;  0xE0 0xF0 0x7C 0xE0 0xF0 0x12
#define KEYCODE_PAUSE     // 0xEl 0x14 0x77 0xE1 0xF0 0x14 0xF0 0x77


static uint8_t keymap_normal[256] = {};
static uint8_t keymap_extend[256] = {};

#define KEYCODE_NORMAL(_) \
_(A, 0x1C) _(B, 0x32) _(C, 0x21) _(D, 0x23) _(E, 0x24) _(F, 0x2B) _(G, 0x34) _(H, 0x33)     \
_(I, 0x43) _(J, 0x3B) _(K, 0x42) _(L, 0x4B) _(M, 0x3A) _(N, 0x31) _(O, 0x44) _(P, 0x4D)     \
_(Q, 0x15) _(R, 0x2D) _(S, 0x1B) _(T, 0x2C) _(U, 0x3C) _(V, 0x2A) _(W, 0x1D) _(X, 0x22)     \
_(Y, 0x35) _(Z, 0x1A) _(0, 0x45) _(1, 0x16) _(2, 0x1E) _(3, 0x26) _(4, 0x25) _(5, 0x2E)     \
_(6, 0x36) _(7, 0x3D) _(8, 0x3E) _(9, 0x46) _(GRAVE, 0x0E) _(MINUS, 0x4E) _(EQUALS, 0x55)    \
_(BACKSLASH, 0x5D) _(BACKSPACE, 0x66) _(SPACE, 0x29) _(TAB, 0x0D) _(CAPS, 0x58) _(LSHIFT, 0x12)  \
_(LCTRL, 0x14) _(LALT, 0x11) _(RSHIFT, 0x59) _(ENTER, 0x5A) _(ESC, 0x76) _(F1, 0x05)        \
_(F2, 0x06) _(F3, 0x04) _(F4, 0x0C) _(F5, 0x03) _(F6, 0x0B) _(F7, 0x83) _(F8, 0x0A)         \
_(F9, 0x01) _(F10, 0x09) _(F11, 0x78) _(F12, 0x07) _(SCROLL, 0x7E) _(LEFTBRACKET, 0x54)        \
_(NUM, 0x77) _(KPSTAR, 0x7C) _(KPMINUS, 0x7B) _(KPPLUS, 0x79) _(KP, 0x71) _(KP0, 0x70)      \
_(KP1, 0x69) _(KP2, 0x72) _(KP3, 0x7A) _(KP4, 0x6B) _(KP5, 0x73) _(KP6, 0x74) _(KP7, 0x6C)  \
_(KP8, 0x75) _(KP9, 0x7D) _(RIGHTBRACKET, 0x5B) _(SEMICOLON, 0x4C) _(APOSTROPHE, 0x52)           \
_(COMMA, 0x41) _(PERIOD, 0x49) _(SLASH, 0x4A) 

#define KEYMAP_NORMAL(k, c) keymap_normal[c] = AM_KEY_##k;


#define KEYCODE_EXTEND(_) \
_(LGUI, 0x1F) _(RCTRL, 0x14) _(RGUI, 0x27) _(RALT, 0x11) _(APPLICATION, 0x2F) _(INSERT, 0x70) \
_(HOME, 0x6C) _(PAGEUP, 0x7D) _(DELETE, 0x71) _(END, 0x69) _(PAGEDOWN, 0x7A) _(UP, 0x75) \
_(LEFT, 0x6B) _(DOWN, 0x72) _(RIGHT, 0x74) _(KPSLASH, 0x4A) _(KPENTER, 0x5A)   

#define KEYMAP_EXTEND(k, c) keymap_extend[c] = AM_KEY_##k;

// code_recursion: bit 0-7: key code; 
// bit 15: key status;       1: key up;        0: key down
// bit 14-13: key type; 00: normal key; extend key: 01;  special key: {10:PRINTSCRN, 11:PAUSE}
// ***** WARNING: 还不支持PRINTSCRN和PAUSE *****
// 首次传入的code_recursion应该是0
uint16_t keyScan(uint16_t code_recursion) {
  uint8_t code = PS2_KEY;
  if(code == 0) {
    return code_recursion;
  }
  if(code == 0xE0) { //暂时认为是extend key
    code_recursion = code_recursion | (0x01 << 13);
    return keyScan(code_recursion);
  }
  else if(code == 0xF0){  // 暂时认为是KEY UP
    code_recursion = code_recursion | (0x01 << 15);
    return keyScan(code_recursion);
  }
  else {
    code_recursion = code_recursion | code;
    return code_recursion;
  }
}

void __am_input_init() {
  KEYCODE_NORMAL(KEYMAP_NORMAL)
  KEYCODE_EXTEND(KEYMAP_EXTEND)
}

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint16_t code_recursion = 0;
  uint16_t code = keyScan(code_recursion);
  if(code == 0) {
    kbd->keydown = 0;
    kbd->keycode = AM_KEY_NONE;
    return;
  }
  if(code & (0x01 << 15))
    kbd->keydown = 0;
  else 
    kbd->keydown = 1;

  uint8_t key_type = (code >> 13) & 0x11;
  if(key_type == 0x00) {
    kbd->keycode = keymap_normal[code & 0xFF];
  }else if (key_type == 0x01) {
    kbd->keycode = keymap_extend[code & 0xFF];
  }
  else{
    panic("Not support yet");
    kbd->keycode = AM_KEY_NONE;
  }
}
