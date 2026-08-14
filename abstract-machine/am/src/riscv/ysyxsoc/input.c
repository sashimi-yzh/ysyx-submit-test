#include <am.h>
#include <klib.h>
#define UART_RX_BASE 0x10000000
#define PS2_BASE 0x10011000
#define KEYDOWN_MASK 0x100

#define KEYMAP_SINGLE(k) do { \
  if ((SCANCODE_##k) <= 0x1FF) keymap_single[SCANCODE_##k] = AM_KEY_##k; \
} while(0);
static uint32_t keymap_single[512] = {};
void __am_keyboard_init(){
  AM_KEYS(KEYMAP_SINGLE)
}

static uint32_t keydown_next_state = 0; // f0: 断码，E0: 拓展，非零: 通码

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint8_t kbd_reg = *(volatile uint8_t *)PS2_BASE;
  uint8_t scancode = kbd_reg;
  // if(scancode != 0) printf("scancode: 0x%08x\n", scancode);
  if(scancode == 0xf0) {
    keydown_next_state = keydown_next_state | 0b1;
    kbd->keycode = 0;
  }
  else if(scancode == 0xe0) {
    keydown_next_state = keydown_next_state | 0b10;
    kbd->keycode = 0;
  }
  else {
    if(keydown_next_state & 0b10) {
      kbd->keycode = keymap_single[0x100 | scancode];
    }
    else {
      kbd->keycode = keymap_single[scancode];
    }
    
    if(keydown_next_state & 0b1) {
      kbd->keydown = 0;
      keydown_next_state = 0;
    }
    else {
      kbd->keydown = 1;
    }
  }
}

void __am_uart_rx(AM_UART_RX_T *rx) {
  if(*(volatile uint8_t *)(UART_RX_BASE + 5) & 0x1){
    rx->data = *(volatile uint8_t *)UART_RX_BASE;
  }
  else rx->data = 0xff;
}
