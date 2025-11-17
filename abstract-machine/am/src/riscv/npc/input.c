#include <am.h>

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  kbd->keydown = 0;
  kbd->keycode = AM_KEY_NONE;
}

void __am_uart_rx(AM_UART_RX_T *rx) {
  rx->data = 0xff;
  // if (!(inb(UART_REG_LSR) & 0x01)) {
  //   rx->data = 0xff;
  // }
  // else{
  //   uint8_t rx_data = inb(SERIAL_PORT);
  //   if(rx_data){
  //     rx->data = rx_data;
  //   }
  //   else{
  //     rx->data = 0xff;
  //   }
  // }
  
}
