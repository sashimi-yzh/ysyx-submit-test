#include <am.h>
#include <riscv/riscv.h>
#include "soc.h"
#include <stdio.h>

#define SCANCODE(key, scancode) [scancode] = AM_KEY_##key

static const int LUT[256] = {
    SCANCODE(GRAVE, 0x0E),
    SCANCODE(1, 0x16),
    SCANCODE(2, 0x1E),
    SCANCODE(3, 0x26),
    SCANCODE(4, 0x25),
    SCANCODE(5, 0x2E),
    SCANCODE(6, 0x36),
    SCANCODE(7, 0x3D),
    SCANCODE(8, 0x3E),
    SCANCODE(9, 0x46),
    SCANCODE(0, 0x45),
    SCANCODE(MINUS, 0x4E),
    SCANCODE(EQUALS, 0x55),
    SCANCODE(A, 0x1C),
    SCANCODE(B, 0x32),
    SCANCODE(C, 0x21),
    SCANCODE(D, 0x23),
    SCANCODE(E, 0x24),
    SCANCODE(F, 0x2B),
    SCANCODE(G, 0x34),
    SCANCODE(H, 0x33),
    SCANCODE(I, 0x43),
    SCANCODE(J, 0x3B),
    SCANCODE(K, 0x42),
    SCANCODE(L, 0x4B),
    SCANCODE(M, 0x3A),
    SCANCODE(N, 0x31),
    SCANCODE(O, 0x44),
    SCANCODE(P, 0x4D),
    SCANCODE(Q, 0x15),
    SCANCODE(R, 0x2D),
    SCANCODE(S, 0x1B),
    SCANCODE(T, 0x2C),
    SCANCODE(U, 0x3C),
    SCANCODE(V, 0x2A),
    SCANCODE(W, 0x1D),
    SCANCODE(X, 0x22),
    SCANCODE(Y, 0x35),
    SCANCODE(Z, 0x1A),
    SCANCODE(LEFTBRACKET, 0x54),
    SCANCODE(RIGHTBRACKET, 0x5B),
    SCANCODE(BACKSLASH, 0x5D),
    SCANCODE(SEMICOLON, 0x4C),
    SCANCODE(APOSTROPHE, 0x52),
    SCANCODE(RETURN, 0x5A),
    SCANCODE(COMMA, 0x41),
    SCANCODE(PERIOD, 0x49),
    SCANCODE(SLASH, 0x4A),
    SCANCODE(BACKSPACE, 0x66),
    SCANCODE(TAB, 0x0D),
    SCANCODE(CAPSLOCK, 0x58),
    SCANCODE(LSHIFT, 0x12),
    SCANCODE(LCTRL, 0x14),
    SCANCODE(LALT, 0x11),
    SCANCODE(SPACE, 0x29),
    SCANCODE(RSHIFT, 0x59),
    SCANCODE(ESCAPE, 0x76),
    SCANCODE(F1, 0x05),
    SCANCODE(F2, 0x06),
    SCANCODE(F3, 0x04),
    SCANCODE(F4, 0x0C),
    SCANCODE(F5, 0x03),
    SCANCODE(F6, 0x0B),
    SCANCODE(F7, 0x83),
    SCANCODE(F8, 0x0A),
    SCANCODE(F9, 0x01),
    SCANCODE(F10, 0x09),
    SCANCODE(F11, 0x78),
    SCANCODE(F12, 0x07),
};

static const int LUT_EXTEND[256] = {
    SCANCODE(RALT, 0x11),
    SCANCODE(RCTRL, 0x14),
    SCANCODE(DELETE, 0x71),
    SCANCODE(END, 0x69),
    SCANCODE(HOME, 0x6C),
    SCANCODE(INSERT, 0x70),
    SCANCODE(PAGEDOWN, 0x7A),
    SCANCODE(PAGEUP, 0x7D),
    SCANCODE(DOWN, 0x72),
    SCANCODE(LEFT, 0x6B),
    SCANCODE(RIGHT, 0x74),
    SCANCODE(UP, 0x75),
};

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t next_after_f0;
  uint32_t kbd_out = inl(KBD_ADDR) ;
  bool extend = false;
  if((kbd_out & 0xFF) == 0xE0){
    extend = true;
    kbd_out = inl(KBD_ADDR) ;
  }
  if((kbd_out & 0xFF) == 0xF0){
    next_after_f0 = inl(KBD_ADDR);
    kbd_out = (kbd_out << 8) | next_after_f0;
  }
  kbd->keydown = ((((kbd_out >> 8) & 0xFF) == 0xF0) ? false : true);
  kbd->keycode = extend ? LUT_EXTEND[kbd_out & 0x00FF] : LUT[kbd_out & 0x00FF];
}

void __am_uart_rx(AM_UART_RX_T *rx) {
  if (!(inb(UART_REG_LSR) & 0x01)) {
    rx->data = 0xff;
  }
  else{
    uint8_t rx_data = inb(SERIAL_PORT);
    if(rx_data){
      rx->data = rx_data;
    }
    else{
      rx->data = 0xff;
    }
  }
  
}