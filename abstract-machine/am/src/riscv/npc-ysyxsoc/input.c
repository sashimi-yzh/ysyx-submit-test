#include <am.h>
#include "npc.h"

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t code_raw = inl(KBD_ADDR);
  kbd->keydown = (code_raw & KEYDOWN_MASK) != 0;
  kbd->keycode = code_raw & ~KEYDOWN_MASK;
}
