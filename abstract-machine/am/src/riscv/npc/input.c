#include <am.h>
#include "../npc/include/npc.h"
#include "../riscv.h"

#define KEYDOWN_MASK 0x8000
void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  // kbd->keydown = 0;
  // kbd->keycode = AM_KEY_NONE;
  uint32_t kc = inl(KBD_ADDR);//从键盘设备读取32位数据
  kbd->keydown = kc & KEYDOWN_MASK ? true : false;
  kbd->keycode = kc & ~KEYDOWN_MASK;
  putch(kc);
}
