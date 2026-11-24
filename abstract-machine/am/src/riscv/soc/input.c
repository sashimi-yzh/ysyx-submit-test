#include <am.h>
#include <npc.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {

  int code = inw(KBD_ADDR);  // 2byte value

  if (code & KEYDOWN_MASK) {
    kbd->keydown = true;
    kbd->keycode = code & ~KEYDOWN_MASK;
  } else {
    kbd->keydown = false;
    kbd->keycode = code & ~KEYDOWN_MASK;
  }
}
