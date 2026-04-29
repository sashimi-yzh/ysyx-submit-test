#include "soc_devreg.h"
#include "ps2keys.h"
#include <am.h>
#include <stdint.h>

void __am_input_uart(AM_UART_RX_T *uart) {
  if (IS_UART_RECEIVE_READY())
    uart->data = *UART_RX;
  else
    uart->data = 0xff;
}

#define _REMAP_EXKEY(key) (((key)>0xff)?((key)-0xe000+256):(key))
#define _GEN_LUT_ITEM(key) [_REMAP_EXKEY(PS2_CODE_##key)] = AM_KEY_##key,
static const int _ps2amkey_lut[512] = {
	AM_KEYS(_GEN_LUT_ITEM)
};

static inline uint8_t _wait_code(){
	uint8_t code;
	do{
		code = *PS2_KEYINPUT;
	}while(code == 0);
	return code;
}

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint8_t code = *PS2_KEYINPUT;
  if (code == 0) {
    kbd->keydown = 0;
    kbd->keycode = AM_KEY_NONE;
    return;
  }
	bool is_extended = false;
	bool is_release = false;
  // extended key
  if (code == 0xe0) {
		is_extended = true;
		code = _wait_code();
  }

  // key release
  if (code == 0xf0) {
		is_release = true;
		code = _wait_code();
  }
	kbd->keydown = !is_release;
	kbd->keycode = _ps2amkey_lut[is_extended ? (code + 256) : code];
}
