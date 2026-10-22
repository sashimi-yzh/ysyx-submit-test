#include <am.h>
#include <riscv/riscv.h>


#define DEVICE_BASE 0xa0000000
#define KBD_ADDR        (DEVICE_BASE + 0x0000060)

#define KEYDOWN_MASK 0x8000
#define KEYCODE_MASK 0x7FFF

static uint32_t am_get_keycode (){
  uint32_t keycode = inl(KBD_ADDR);
  return keycode;
}

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t value = am_get_keycode();
  uint32_t raw_code = value & KEYCODE_MASK;

  kbd->keydown = (value & KEYDOWN_MASK) != 0;
  kbd->keycode = raw_code;

  if (kbd->keycode == 0) {
    kbd->keycode = AM_KEY_NONE;
  }
}
