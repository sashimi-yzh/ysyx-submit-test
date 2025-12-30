#include <am.h>
#include <amdev.h>
#include <stdio.h>
//#include <stdint.h>

#define YSYXSOC_KBD 0x10011000//ysyxsoc里键盘地址空间0x1001_1000~0x1001_1007
#define KEYDOWN_MASK 0x8000
static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }

// 扫描码到抽象键码的映射（普通键）
static const uint8_t scan_to_key[256] = {
	[0x76] = AM_KEY_ESCAPE,
  	[0x05] = AM_KEY_F1,
  	[0x06] = AM_KEY_F2,
  	[0x04] = AM_KEY_F3,
  	[0x0C] = AM_KEY_F4,
  	[0x03] = AM_KEY_F5,
  	[0x0b] = AM_KEY_F6,
  	[0x83] = AM_KEY_F7,
  	[0x0a] = AM_KEY_F8,
  	[0x01] = AM_KEY_F9,
  	[0x09] = AM_KEY_F10,
  	[0x78] = AM_KEY_F11,
  	[0x07] = AM_KEY_F12,
 // 标准键扫描码映射
	[0x76] = AM_KEY_ESCAPE,
	[0x05] = AM_KEY_F1,
	[0x06] = AM_KEY_F2,
	[0x04] = AM_KEY_F3,
	[0x0C] = AM_KEY_F4,
	[0x03] = AM_KEY_F5,
	[0x0B] = AM_KEY_F6,
	[0x83] = AM_KEY_F7,
	[0x0A] = AM_KEY_F8,
	[0x01] = AM_KEY_F9,
	[0x09] = AM_KEY_F10,
	[0x78] = AM_KEY_F11,
	[0x07] = AM_KEY_F12,

	[0x0E] = AM_KEY_GRAVE,
	[0x16] = AM_KEY_1,
	[0x1E] = AM_KEY_2,
	[0x26] = AM_KEY_3,
	[0x25] = AM_KEY_4,
	[0x2E] = AM_KEY_5,
	[0x36] = AM_KEY_6,
	[0x3D] = AM_KEY_7,
	[0x3E] = AM_KEY_8,
	[0x46] = AM_KEY_9,
	[0x45] = AM_KEY_0,
	[0x4E] = AM_KEY_MINUS,
	[0x55] = AM_KEY_EQUALS,
	[0x66] = AM_KEY_BACKSPACE,

	[0x0D] = AM_KEY_TAB,
	[0x15] = AM_KEY_Q,
	[0x1D] = AM_KEY_W,
	[0x24] = AM_KEY_E,
	[0x2D] = AM_KEY_R,
	[0x2C] = AM_KEY_T,
	[0x35] = AM_KEY_Y,
	[0x3C] = AM_KEY_U,
	[0x43] = AM_KEY_I,
	[0x44] = AM_KEY_O,
	[0x4D] = AM_KEY_P,
	[0x54] = AM_KEY_LEFTBRACKET,
	[0x5B] = AM_KEY_RIGHTBRACKET,
	[0x5D] = AM_KEY_BACKSLASH,

	[0x58] = AM_KEY_CAPSLOCK,
	[0x1C] = AM_KEY_A,
	[0x1B] = AM_KEY_S,
	[0x23] = AM_KEY_D,
	[0x2B] = AM_KEY_F,
	[0x34] = AM_KEY_G,
	[0x33] = AM_KEY_H,
	[0x3B] = AM_KEY_J,
	[0x42] = AM_KEY_K,
	[0x4B] = AM_KEY_L,
	[0x4C] = AM_KEY_SEMICOLON,
	[0x52] = AM_KEY_APOSTROPHE,
	[0x5A] = AM_KEY_RETURN,

	[0x12] = AM_KEY_LSHIFT,
	[0x1A] = AM_KEY_Z,
	[0x22] = AM_KEY_X,
	[0x21] = AM_KEY_C,
	[0x2A] = AM_KEY_V,
	[0x32] = AM_KEY_B,
	[0x31] = AM_KEY_N,
	[0x3A] = AM_KEY_M,
	[0x41] = AM_KEY_COMMA,
	[0x49] = AM_KEY_PERIOD,
	[0x4A] = AM_KEY_SLASH,
	[0x59] = AM_KEY_RSHIFT,

	[0x14] = AM_KEY_LCTRL,
	[0x11] = AM_KEY_LALT,
	[0x29] = AM_KEY_SPACE,


};

// 扩展键扫描码映射（E0前缀的键）
static const uint8_t e0_scan_to_key[256] = {
// 扩展键扫描码 (E0前缀)
	[0x2F] = AM_KEY_APPLICATION,  // E0 2F
	[0x11] = AM_KEY_RALT,         // E0 11  
	[0x14] = AM_KEY_RCTRL,        // E0 14
	[0x75] = AM_KEY_UP,           // E0 75
	[0x72] = AM_KEY_DOWN,         // E0 72
	[0x6B] = AM_KEY_LEFT,         // E0 6B
	[0x74] = AM_KEY_RIGHT,        // E0 74
	[0x70] = AM_KEY_INSERT,       // E0 70
	[0x71] = AM_KEY_DELETE,       // E0 71
	[0x6C] = AM_KEY_HOME,         // E0 6C
	[0x69] = AM_KEY_END,          // E0 69
	[0x7D] = AM_KEY_PAGEUP,       // E0 7D
	[0x7A] = AM_KEY_PAGEDOWN,     // E0 7A
};
void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  // kbd->keydown = 0;
  // kbd->keycode = AM_KEY_NONE;

	uint16_t k = inl(YSYXSOC_KBD); 
  	kbd->keydown = (k & KEYDOWN_MASK ? true : false); 
  	uint16_t scan_code = k & ~KEYDOWN_MASK;
  	if( ( (k & 0xff00) == 0x6000) || ( (k & 0xff00) == 0xE000) ){
		kbd->keycode = e0_scan_to_key[scan_code & 0xff];
  	} else {
		kbd->keycode = scan_to_key[scan_code];
  	}
  
  	//if((k & 0xff) != 0) printf("[input]k=0x%x ", k & 0xff);

}

//nemu里的
// void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
//   //kbd->keydown = 0;
//   //kbd->keycode = AM_KEY_NONE;
//   int k = inl(KBD_ADDR); 
//   kbd->keydown = (k & KEYDOWN_MASK ? true : false); 
//   kbd->keycode = k & ~KEYDOWN_MASK; 
// }