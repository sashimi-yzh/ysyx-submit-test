#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
    /**/
  uint32_t code = inl(KBD_ADDR);
  kbd->keydown = (code & KEYDOWN_MASK ? true : false);
  if(kbd->keydown == 0)
    kbd->keycode = code;
  else
    kbd->keycode = code & ~KEYDOWN_MASK; //delete the state
  
  
}
