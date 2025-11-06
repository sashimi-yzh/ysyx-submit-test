#include <am.h>
#include <stdio.h>
#include "ysyxsoc.h"

// TODO：这里需要改，全部重写的改：首先建立映射表，然后根据按下状态和扫描码判断是否有按键按下
// 有E0的就前面加上一个1,表示这是扩展键盘
static int keymap[512] = {};

#define NPC_KEYS(f) \
  f(ESCAPE, 0x76) f(F1, 0x05) f(F2, 0x06) f(F3, 0x04) f(F4, 0x0C) f(F5, 0x03) f(F6, 0x0B) f(F7, 0x83) f(F8, 0x0A) f(F9, 0x01) f(F10, 0x09) f(F11, 0x78) f(F12, 0x07) \
  f(GRAVE, 0x0E) f(1, 0x16) f(2, 0x1E) f(3, 0x26) f(4, 0x25) f(5, 0x2E) f(6, 0x36) f(7, 0x3D) f(8, 0x3E) f(9, 0x46) f(0, 0x45) f(MINUS, 0x4E) f(EQUALS, 0x55) f(BACKSPACE, 0x66) \
  f(TAB, 0x0D) f(Q, 0x15) f(W, 0x1D) f(E, 0x24) f(R, 0x2D) f(T, 0x2C) f(Y, 0x35) f(U, 0x3C) f(I, 0x43) f(O, 0x44) f(P, 0x4D) f(LEFTBRACKET, 0x54) f(RIGHTBRACKET, 0x5B) f(BACKSLASH, 0x5D) \
  f(CAPSLOCK, 0x58) f(A, 0x1C) f(S, 0x1B) f(D, 0x23) f(F, 0x2B) f(G, 0x34) f(H, 0x33) f(J, 0x3B) f(K, 0x42) f(L, 0x4B) f(SEMICOLON, 0x4C) f(APOSTROPHE, 0x52) f(RETURN, 0x5A) \
  f(LSHIFT, 0x12) f(Z, 0x1A) f(X, 0x22) f(C, 0x21) f(V, 0x2A) f(B, 0x32) f(N, 0x31) f(M, 0x3A) f(COMMA, 0x41) f(PERIOD, 0x49) f(SLASH, 0x4A) f(RSHIFT, 0x59) \
  f(LCTRL, 0x14) f(APPLICATION, 0x11) f(LALT, 0x11) f(SPACE, 0x29) f(RALT, 0x111) f(RCTRL, 0x114) \
  f(UP, 0x175) f(DOWN, 0x172) f(LEFT, 0x16B) f(RIGHT, 0x174) f(INSERT, 0x170) f(DELETE, 0x171) f(HOME, 0x16C) f(END, 0x169) f(PAGEUP, 0x17D) f(PAGEDOWN, 0x17A)

// ##是一个连接符号，用于将宏参数与周围的记号拼接在一起。
// 相当于是使用宏定义写入数组
#define SCANCODE_KEYS_MAP(k, c) keymap[c] = AM_KEY_ ## k;

// 初始化数组
void __am_keymap_init() {
  NPC_KEYS(SCANCODE_KEYS_MAP)

}

uint16_t get_scan(uint16_t scan_code);

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint16_t scan_code = get_scan(0);
  if(scan_code == 0){
    kbd->keycode = AM_KEY_NONE;
  }

  if((scan_code >> 9) == 1)                     // 表示松开按键了
    kbd->keydown = 0;
  scan_code = scan_code & 0x1FF;
  kbd->keycode = keymap[scan_code];
  // printf("scan_code: %d,kbd->keycode: %d\n",scan_code,kbd->keycode);
}

uint16_t get_scan(uint16_t scan_code){
  uint8_t code = inb(PS2_BASE + 0x0);           // 读取ps/2的状态
  switch(code)
  {
    case 0xE0:
      scan_code |= (1 << 8);                    // 如果是扩展键盘，则在第八位加上一个1
      scan_code = get_scan(scan_code);
      break;
    case 0xF0:
      scan_code |= (1 << 9);                    // 用于判断是否为松开的事件
      scan_code = get_scan(scan_code);
      break;
    default:
      scan_code = (scan_code & 0xFF00) | code;  // 正式判断按键是什么
      break;
  }
  // if(code != 0 || scan_code != 0){
  //   printf("scan_code: %d,code: %d\n",scan_code,code);
  // }
  return scan_code;
}
