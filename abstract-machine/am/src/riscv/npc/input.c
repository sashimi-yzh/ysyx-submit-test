#include <am.h>
#include "npc.h"
#include "../riscv.h"

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  kbd->keydown = 0;
  kbd->keycode = AM_KEY_NONE;
}

void __am_uart_input(AM_UART_RX_T *uart) {
  if (inb(UART_RX) != 0xff) uart->data = inb(UART_RX);
  else uart->data = 0xff;
}