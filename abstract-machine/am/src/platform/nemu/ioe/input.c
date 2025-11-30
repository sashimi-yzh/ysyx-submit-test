#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

int printf(const char *fmt, ...);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t k = inl(KBD_ADDR);
	if(k & KEYDOWN_MASK) kbd->keydown = true;
	else kbd->keydown = false;
	kbd->keycode = k & ~KEYDOWN_MASK;
}
