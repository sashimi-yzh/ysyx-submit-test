#include <am.h>
#include <stdio.h>


#define UART_BASE 0x10000000L
#define UART_RX   0
#define UART_FIFO_CONTROL 2
#define UART_LSR 5

#define KEYDOWN_MASK 0x8000
#define KBD_ADDR1 0x10011000



uint8_t exchange(uint8_t num){
  switch(num) {
    case 0x76: return 1;
    case 0x05: return 2;
    case 0x06: return 3;
    case 0x04: return 4;
    case 0x0c: return 5;
    case 0x03: return 6;
    case 0x0b: return 7;
    case 0x83: return 8;
    case 0x0a: return 9;
    case 0x01: return 10;
    case 0x09: return 11;
    case 0x78: return 12;
    case 0x07: return 13;

    case 0x0e: return 14;
    case 0x16: return 15;
    case 0x1e: return 16;
    case 0x26: return 17;
    case 0x25: return 18;
    case 0x2e: return 19;
    case 0x36: return 20;
    case 0x3d: return 21;
    case 0x3e: return 22;
    case 0x46: return 23;
    case 0x45: return 24;
    case 0x4e: return 25;
    case 0x55: return 26;
    case 0x66: return 27;

    case 0x0d: return 28;
    case 0x15: return 29;
    case 0x1d: return 30;
    case 0x24: return 31;
    case 0x2d: return 32;
    case 0x2c: return 33;
    case 0x35: return 34;
    case 0x3c: return 35;
    case 0x43: return 36;
    case 0x44: return 37;
    case 0x4d: return 38;
    case 0x54: return 39;
    case 0x5b: return 40;
    case 0x5d: return 41;

    case 0x58: return 42;
    case 0x1c: return 43;
    case 0x1b: return 44;
    case 0x23: return 45;
    case 0x2b: return 46;
    case 0x34: return 47;
    case 0x33: return 48;
    case 0x3b: return 49;
    case 0x42: return 50;
    case 0x4b: return 51;
    case 0x4c: return 52;
    case 0x52: return 53;
    case 0x5a: return 54;

    case 0x12: return 55;
    case 0x1a: return 56;
    case 0x22: return 57;
    case 0x21: return 58;
    case 0x2a: return 59;
    case 0x32: return 60;
    case 0x31: return 61;
    case 0x3a: return 62;
    case 0x41: return 63;
    case 0x49: return 64;
    case 0x4a: return 65;
    case 0x59: return 66;
    default: return 0; 
  }
}

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint8_t k = *(volatile uint8_t *)(KBD_ADDR1);
  //printf("%x",k);
  kbd->keydown = (k!= 0xf0 ? true : false);
  kbd->keycode = exchange(k);
}

void __am_uart_rx(AM_UART_RX_T *uart) {
  //uint8_t a = inb(UART_BASE+UART_RX);
  char data_ready;
  data_ready = *(volatile uint8_t *)(UART_BASE + UART_LSR) & 0x01;
  if(data_ready == 1) {
    uart->data = *(volatile uint8_t *)(UART_BASE + UART_RX);
  }
  else {
    uart->data = 0xff;
  }
  //*(volatile uint8_t *)(UART_BASE + UART_FIFO_CONTROL) = (1 << 1);

}
