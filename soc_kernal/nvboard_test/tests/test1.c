#include "am.h"
#include "amdev.h"
#include <klib.h>
#include <soc.h>
#include <stdint.h>

#define LED_GPIO 0x10002000
#define SWITCH_GPIO 0x10002004
#define DIGIT_GPIO 0x10002008

const uint8_t hex_2_digit_ctrl[16] = {0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49,
                                      0x41, 0x1F, 0x01, 0x09, 0x11, 0xC1,
                                      0x63, 0x85, 0x61, 0x71};

int main() {
  uint32_t marchid;
  asm volatile("csrr %0, marchid" : "=r"(marchid));
  for (int i = 0; i < 8; i++) {
    *(volatile uint8_t *)(DIGIT_GPIO + i) = hex_2_digit_ctrl[marchid % 10];
    marchid /= 10;
  }
  AM_UART_RX_T rx;
  ioe_read(AM_UART_RX, &rx);
  uint32_t x = rx.data - '0';
  ioe_read(AM_UART_RX, &rx);
  x = x * 10 + rx.data - '0';
  ioe_read(AM_UART_RX, &rx);
  x = x * 10 + rx.data - '0';
  printf("%u + ", x);

  ioe_read(AM_UART_RX, &rx);
  uint32_t y = rx.data - '0';
  ioe_read(AM_UART_RX, &rx);
  y = y * 10 + rx.data - '0';
  ioe_read(AM_UART_RX, &rx);
  y = y * 10 + rx.data - '0';
  printf("%u = %u\n", y, x + y);
  uint16_t p = 0;

loop:
  if (*(volatile uint16_t *)SWITCH_GPIO == 0x8002) {
    *(volatile uint16_t *)LED_GPIO = (1 << p);
    p = (p + 1) % 16;
  }
  AM_INPUT_KEYBRD_T input_kbd;

  for (volatile int j = 0; j < 256; j++) {
    ioe_read(AM_INPUT_KEYBRD, &input_kbd);
    if (input_kbd.keycode != 0) {
      if (input_kbd.keydown)
        printf("DOWN %02x\n", input_kbd.keycode);
      else
        printf("UP   %02x\n", input_kbd.keycode);
    }
  }

  goto loop;
  return 0;
}
