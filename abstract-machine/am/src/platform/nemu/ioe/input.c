#include "riscv/riscv.h"
#include <am.h>
#include <klib.h>
#include <nemu.h>
#include <stdint.h>
#include <sys/types.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t signal = inl(KBD_ADDR);
  uint32_t code = signal & ~KEYDOWN_MASK;
  kbd->keydown = (bool)(signal & KEYDOWN_MASK);
  kbd->keycode = code;
}
