#ifndef __AMDEV_H__
#define __AMDEV_H__

// **MAY SUBJECT TO CHANGE IN THE FUTURE**

#define AM_DEVREG(id, reg, perm, ...) \
  enum { AM_##reg = (id) }; \
  typedef struct { __VA_ARGS__; } AM_##reg##_T;

AM_DEVREG( 1, UART_CONFIG,  RD, bool present);
AM_DEVREG( 2, UART_TX,      WR, char data);
AM_DEVREG( 3, UART_RX,      RD, char data);
AM_DEVREG( 4, TIMER_CONFIG, RD, bool present, has_rtc);
AM_DEVREG( 5, TIMER_RTC,    RD, int year, month, day, hour, minute, second);
AM_DEVREG( 6, TIMER_UPTIME, RD, uint64_t us);
AM_DEVREG( 7, INPUT_CONFIG, RD, bool present);
AM_DEVREG( 8, INPUT_KEYBRD, RD, bool keydown; int keycode);
AM_DEVREG( 9, GPU_CONFIG,   RD, bool present, has_accel; int width, height, vmemsz);
AM_DEVREG(10, GPU_STATUS,   RD, bool ready);
AM_DEVREG(11, GPU_FBDRAW,   WR, int x, y; void *pixels; int w, h; bool sync);
AM_DEVREG(12, GPU_MEMCPY,   WR, uint32_t dest; void *src; int size);
AM_DEVREG(13, GPU_RENDER,   WR, uint32_t root);
AM_DEVREG(14, AUDIO_CONFIG, RD, bool present; int bufsize);
AM_DEVREG(15, AUDIO_CTRL,   WR, int freq, channels, samples);
AM_DEVREG(16, AUDIO_STATUS, RD, int count);
AM_DEVREG(17, AUDIO_PLAY,   WR, Area buf);
AM_DEVREG(18, DISK_CONFIG,  RD, bool present; int blksz, blkcnt);
AM_DEVREG(19, DISK_STATUS,  RD, bool ready);
AM_DEVREG(20, DISK_BLKIO,   WR, bool write; void *buf; int blkno, blkcnt);
AM_DEVREG(21, NET_CONFIG,   RD, bool present);
AM_DEVREG(22, NET_STATUS,   RD, int rx_len, tx_len);
AM_DEVREG(23, NET_TX,       WR, Area buf);
AM_DEVREG(24, NET_RX,       WR, Area buf);


//新增
AM_DEVREG(25, GPIO_LED_RD,	RD, uint16_t data);
AM_DEVREG(26, GPIO_LED_WR,  WR, uint16_t data);
AM_DEVREG(27, GPIO_SWITCH,  RD, uint16_t data);
AM_DEVREG(28, GPIO_SEG_RD,  RD, uint32_t data);
AM_DEVREG(29, GPIO_SEG_WR,  WR, uint32_t data);


// Input

#define AM_KEYS(_) \
  _(ESCAPE) _(F1) _(F2) _(F3) _(F4) _(F5) _(F6) _(F7) _(F8) _(F9) _(F10) _(F11) _(F12) \
  _(GRAVE) _(1) _(2) _(3) _(4) _(5) _(6) _(7) _(8) _(9) _(0) _(MINUS) _(EQUALS) _(BACKSPACE) \
  _(TAB) _(Q) _(W) _(E) _(R) _(T) _(Y) _(U) _(I) _(O) _(P) _(LEFTBRACKET) _(RIGHTBRACKET) _(BACKSLASH) \
  _(CAPSLOCK) _(A) _(S) _(D) _(F) _(G) _(H) _(J) _(K) _(L) _(SEMICOLON) _(APOSTROPHE) _(RETURN) \
  _(LSHIFT) _(Z) _(X) _(C) _(V) _(B) _(N) _(M) _(COMMA) _(PERIOD) _(SLASH) _(RSHIFT) \
  _(LCTRL) _(APPLICATION) _(LALT) _(SPACE) _(RALT) _(RCTRL) \
  _(UP) _(DOWN) _(LEFT) _(RIGHT) _(INSERT) _(DELETE) _(HOME) _(END) _(PAGEUP) _(PAGEDOWN)



/*#define AM_KEYS(_) \
	_(ESCAPE) = 0x76, _(F1) = 0x05,  _(F2) = 0x06, _(F3) = 0x04, _(F4) = 0x0c,  _(F5) = 0x03, \
	_(F6) = 0x0b, _(F7) = 0x83,  _(F8) = 0x0a, _(F9) = 0x01, _(F10) = 0x09, _(F11) = 0x78, _(F12) = 0x07, \
  	_(GRAVE) = 0x0e, _(1) = 0x16, _(2) = 0x1e, _(3) = 0x26, _(4) = 0x25, _(5) = 0x2e,  _(6) = 0x36, \
	_(7) = 0x3d, _(8) = 0x3e, _(9) = 0x46, _(0) = 0x45, _(MINUS) = 0x4e, _(EQUALS) = 0x55, _(BACKSPACE) = 0x66, \
	_(TAB) = 0x0d, _(Q) = 0x15, _(W) = 0x1d, _(E) = 0x24, _(R) = 0x2d, _(T) = 0x2c, _(Y) = 0x35, _(U) = 0x3c, \
	_(I) = 0x43, _(O) = 0x44, _(P) = 0x4d, _(LEFTBRACKET) = 0x54, _(RIGHTBRACKET) = 0x5b, _(BACKSLASH) = 0x5d, \
  	_(CAPSLOCK) = 0x58, _(A) = 0x1c, _(S) = 0x1b, _(D) = 0x23, _(F) = 0x2b, _(G) = 0x34, _(H) = 0x33, _(J) = 0x3b, \
	_(K) = 0x42, _(L) = 0x4b, _(SEMICOLON) = 0x4c, _(APOSTROPHE) = 0x52, _(RETURN) = 0x5a, \
  	_(LSHIFT) = 0x12, _(Z) = 0x1a, _(X) = 0x22, _(C) = 0x21, _(V) = 0x2a, _(B) = 0x32, _(N) = 0x31, _(M) = 0x3a, \
	_(COMMA) = 0x41, _(PERIOD) = 0x49, _(SLASH) = 0x4a, _(RSHIFT) = 0x59, \
  	_(LCTRL) = 0x14, _(APPLICATION) = 0x5e, _(LALT) = 0x11, _(SPACE) = 0x29, \
	_(RALT) = 0xe011, _(RCTRL) = 0xe014, _(UP) = 0xe075, _(DOWN) = 0xe072, _(LEFT) = 0xe06b, _(RIGHT) = 0xe074, \
	_(INSERT) = 0xe070, _(DELETE) = 0xe071, _(HOME) = 0xe06c, _(END) = 0xe069, _(PAGEUP) = 0xe07d, _(PAGEDOWN) = 0xe07a
*/

#define AM_KEY_NAMES(key) AM_KEY_##key,


//modify by Jason @ 2025.10.16
//用于SDL的scancode
//#if defined(__PLATFORM_NPC)||defined(__PLATFORM_NEMU)
//#endif

//用于ps2
#if defined(__PLATFORM_YSYXSOC)
enum {
	AM_KEY_NONE = 0, AM_KEY_ESCAPE = 0x76, AM_KEY_F1 = 0x05, AM_KEY_F2 = 0x06, AM_KEY_F3 = 0x04, AM_KEY_F4 = 0x0c,
  	AM_KEY_F5 = 0x03, AM_KEY_F6 = 0x0b, AM_KEY_F7 = 0x83, AM_KEY_F8 = 0x0a, AM_KEY_F9 = 0x01, AM_KEY_F10 = 0x09,
  	AM_KEY_F11 = 0x78, AM_KEY_F12 = 0x07, AM_KEY_GRAVE = 0x0e, AM_KEY_1 = 0x16, AM_KEY_2 = 0x1e, AM_KEY_3 = 0x26,
  	AM_KEY_4 = 0x25, AM_KEY_5 = 0x2e, AM_KEY_6 = 0x36, AM_KEY_7 = 0x3d, AM_KEY_8 = 0x3e, AM_KEY_9 = 0x46, AM_KEY_0 = 0x45,
  	AM_KEY_MINUS = 0x4e, AM_KEY_EQUALS = 0x55, AM_KEY_BACKSPACE = 0x66, AM_KEY_TAB = 0x0d, AM_KEY_Q = 0x15, AM_KEY_W = 0x1d,
  	AM_KEY_E = 0x24, AM_KEY_R = 0x2d, AM_KEY_T = 0x2c, AM_KEY_Y = 0x35, AM_KEY_U = 0x3c, AM_KEY_I = 0x43, AM_KEY_O = 0x44,
  	AM_KEY_P = 0x4d, AM_KEY_LEFTBRACKET = 0x54, AM_KEY_RIGHTBRACKET = 0x5b, AM_KEY_BACKSLASH = 0x5d, AM_KEY_CAPSLOCK = 0x58,
  	AM_KEY_A = 0x1c, AM_KEY_S = 0x1b, AM_KEY_D = 0x23, AM_KEY_F = 0x2b, AM_KEY_G = 0x34, AM_KEY_H = 0x33, AM_KEY_J = 0x3b,
  	AM_KEY_K = 0x42, AM_KEY_L = 0x4b, AM_KEY_SEMICOLON = 0x4c, AM_KEY_APOSTROPHE = 0x52, AM_KEY_RETURN = 0x5a,
 	AM_KEY_LSHIFT = 0x12, AM_KEY_Z = 0x1a, AM_KEY_X = 0x22, AM_KEY_C = 0x21, AM_KEY_V = 0x2a, AM_KEY_B = 0x32, AM_KEY_N = 0x31,
  	AM_KEY_M = 0x3a, AM_KEY_COMMA = 0x41, AM_KEY_PERIOD = 0x49, AM_KEY_SLASH = 0x4a, AM_KEY_RSHIFT = 0x59, AM_KEY_LCTRL = 0x14,
  	AM_KEY_APPLICATION = 0xe05e, // 假设这里使用了0xE05E作为APPLICATION键的扫描码
  	AM_KEY_LALT = 0x11, AM_KEY_SPACE = 0x29, 
	AM_KEY_RALT = 0xe011, AM_KEY_RCTRL = 0xe014, AM_KEY_UP = 0xe075, AM_KEY_DOWN = 0xe072, AM_KEY_LEFT = 0xe06b,
  	AM_KEY_RIGHT = 0xe074, AM_KEY_INSERT = 0xe070, AM_KEY_DELETE = 0xe071, AM_KEY_HOME = 0xe06c, AM_KEY_END = 0xe069,
  	AM_KEY_PAGEUP = 0xe07d, AM_KEY_PAGEDOWN = 0xe07a
};
#else//其他所有架构默认采用scancode
enum {
  AM_KEY_NONE = 0,
  AM_KEYS(AM_KEY_NAMES)
};
#endif



// GPU

#define AM_GPU_TEXTURE  1
#define AM_GPU_SUBTREE  2
#define AM_GPU_NULL     0xffffffff

typedef uint32_t gpuptr_t;

struct gpu_texturedesc {
  uint16_t w, h;
  gpuptr_t pixels;
} __attribute__((packed));

struct gpu_canvas {
  uint16_t type, w, h, x1, y1, w1, h1;
  gpuptr_t sibling;
  union {
    gpuptr_t child;
    struct gpu_texturedesc texture;
  };
} __attribute__((packed));

#endif
