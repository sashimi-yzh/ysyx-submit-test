#include <am.h>
#include "npc.h"

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t temp = inl(KBD_ADDR);

  kbd->keydown = (temp & KEYDOWN_MASK);
  kbd->keycode = (temp & ~KEYDOWN_MASK);
}
