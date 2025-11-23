#include <am.h>
#include <nemu.h>
#include <stdio.h>
#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t kbd_out = inl(KBD_ADDR) ;
  kbd->keydown = (kbd_out & KEYDOWN_MASK ? true : false);
  kbd->keycode = kbd_out & ~KEYDOWN_MASK;
}

void __am_uart_rx(AM_UART_RX_T *rx) {
  rx->data = 0xff;
}
