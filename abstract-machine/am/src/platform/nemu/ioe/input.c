#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  kbd->keycode = inl(KBD_ADDR);
  if((kbd->keycode & KEYDOWN_MASK) == KEYDOWN_MASK) {
    kbd->keycode &= ~KEYDOWN_MASK;
    kbd->keydown = true;
  } else {
    kbd->keydown = false;
  }
}
