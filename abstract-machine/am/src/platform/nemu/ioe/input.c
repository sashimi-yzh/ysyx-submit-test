#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t kbd_reg = inl(KBD_ADDR);
  // if(kbd_reg & 0xff00 = 0x)
  kbd->keydown = kbd_reg & KEYDOWN_MASK;
  kbd->keycode = kbd_reg & 0xff;
}
