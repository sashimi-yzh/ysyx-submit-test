#include <am.h>

#define DEVICE_BASE 0xa0000000
#define KBD_ADDR (DEVICE_BASE + 0x0000060)
#define KEYDOWN_MASK 0x8000

static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t keycode = inl(KBD_ADDR);
  kbd->keydown = keycode & KEYDOWN_MASK;
  kbd->keycode = keycode & (~KEYDOWN_MASK);
}
