#include <am.h>
#include <riscv/riscv.h>
#include <ysyxsoc.h>
#include <klib.h>

//#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
	uint32_t scancode = inl(KBD_BASE);
	//注意只要最后8位=0,则视为没接收到键码,包括0xe000的情形
	kbd -> keycode = (scancode & 0x000000ff) ? (scancode & 0x0000ffff) : 0;
	kbd -> keydown = (bool)(scancode & 0xffff0000);
}
