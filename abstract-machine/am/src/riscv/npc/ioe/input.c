#include <am.h>
#include <riscv/riscv.h>
#include <npc.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
    uint16_t scancode = inw(KBD_ADDR);
    if(scancode & KEYDOWN_MASK){
        kbd -> keydown = 1;
        kbd -> keycode = (uint8_t)scancode;
    }
    else{
        kbd -> keydown = 0;
        kbd -> keycode = (uint8_t)scancode;
    }
}
