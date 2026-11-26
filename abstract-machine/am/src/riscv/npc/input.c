#include <am.h>
#include "npc.h"

// 键盘寄存器地址（与 device.h 保持一致）
#define KBD_ADDR    0x10000060
#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t val = inl(KBD_ADDR);
  kbd->keydown = (val & KEYDOWN_MASK) != 0;
  kbd->keycode = val & ~KEYDOWN_MASK;
}
