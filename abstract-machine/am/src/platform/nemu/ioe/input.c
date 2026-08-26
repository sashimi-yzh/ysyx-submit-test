#include <am.h>
#include <nemu.h>
#include <klib.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  int code = inl(KBD_ADDR);
  //printf("CODE=%08x\n",code);
  kbd->keydown = (code & KEYDOWN_MASK)?true:false;
  kbd->keycode = code & 0xff;
  // kbd->keydown = (code!=AM_KEY_NONE)?true:false;
  // kbd->keycode = code;
}

void __am_uart_rx(AM_UART_RX_T *val)
{
  val->data = 0x00;
}