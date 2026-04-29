#ifndef __PS2_KEYS_H__
#define __PS2_KEYS_H__

enum {
	// Control keys
	PS2_CODE_ESCAPE      = 0x76,
	PS2_CODE_TAB         = 0x0D,
	PS2_CODE_CAPSLOCK   = 0x58,
	PS2_CODE_RSHIFT      = 0x59,
	PS2_CODE_LSHIFT      = 0x12,
	PS2_CODE_LCTRL       = 0x14,
	PS2_CODE_LALT        = 0x11,
	PS2_CODE_SPACE       = 0x29,
	PS2_CODE_RETURN       = 0x5A,
	PS2_CODE_BACKSPACE   = 0x66,

	// Function keys
	PS2_CODE_F1          = 0x05,
	PS2_CODE_F2          = 0x06,
	PS2_CODE_F3          = 0x04,
	PS2_CODE_F4          = 0x0C,
	PS2_CODE_F5          = 0x03,
	PS2_CODE_F6          = 0x0B,
	PS2_CODE_F7          = 0x83,
	PS2_CODE_F8          = 0x0A,
	PS2_CODE_F9          = 0x01,
	PS2_CODE_F10         = 0x09,
	PS2_CODE_F11         = 0x78,
	PS2_CODE_F12         = 0x07,

	// Number keys
	PS2_CODE_1           = 0x16,
	PS2_CODE_2           = 0x1E,
	PS2_CODE_3           = 0x26,
	PS2_CODE_4           = 0x25,
	PS2_CODE_5           = 0x2E,
	PS2_CODE_6           = 0x36,
	PS2_CODE_7           = 0x3D,
	PS2_CODE_8           = 0x3E,
	PS2_CODE_9           = 0x46,
	PS2_CODE_0           = 0x45,
	PS2_CODE_MINUS       = 0x4E,
	PS2_CODE_EQUALS       = 0x55,
	PS2_CODE_GRAVE       = 0x0E,

	// Alphabet keys
	PS2_CODE_Q           = 0x15,
	PS2_CODE_W           = 0x1D,
	PS2_CODE_E           = 0x24,
	PS2_CODE_R           = 0x2D,
	PS2_CODE_T           = 0x2C,
	PS2_CODE_Y           = 0x35,
	PS2_CODE_U           = 0x3C,
	PS2_CODE_I           = 0x43,
	PS2_CODE_O           = 0x44,
	PS2_CODE_P           = 0x4D,
	PS2_CODE_A           = 0x1C,
	PS2_CODE_S           = 0x1B,
	PS2_CODE_D           = 0x23,
	PS2_CODE_F           = 0x2B,
	PS2_CODE_G           = 0x34,
	PS2_CODE_H           = 0x33,
	PS2_CODE_J           = 0x3B,
	PS2_CODE_K           = 0x42,
	PS2_CODE_L           = 0x4B,
	PS2_CODE_Z           = 0x1A,
	PS2_CODE_X           = 0x22,
	PS2_CODE_C           = 0x21,
	PS2_CODE_V           = 0x2A,
	PS2_CODE_B           = 0x32,
	PS2_CODE_N           = 0x31,
	PS2_CODE_M           = 0x3A,

	// Symbol keys
	PS2_CODE_LEFTBRACKET    = 0x54,
	PS2_CODE_RIGHTBRACKET    = 0x5B,
	PS2_CODE_BACKSLASH   = 0x5D,
	PS2_CODE_SEMICOLON   = 0x4C,
	PS2_CODE_APOSTROPHE  = 0x52,
	PS2_CODE_COMMA       = 0x41,
	PS2_CODE_PERIOD         = 0x49,
	PS2_CODE_SLASH       = 0x4A,

	// Keypad (non-E0 part)
	PS2_CODE_KP_0        = 0x70,
	PS2_CODE_KP_1        = 0x69,
	PS2_CODE_KP_2        = 0x72,
	PS2_CODE_KP_3        = 0x7A,
	PS2_CODE_KP_4        = 0x6B,
	PS2_CODE_KP_5        = 0x73,
	PS2_CODE_KP_6        = 0x74,
	PS2_CODE_KP_7        = 0x6C,
	PS2_CODE_KP_8        = 0x75,
	PS2_CODE_KP_9        = 0x7D,
	PS2_CODE_KP_DOT      = 0x71,
	PS2_CODE_KP_PLUS     = 0x79,
	PS2_CODE_KP_MINUS    = 0x7B,
	PS2_CODE_KP_MULTIPLY = 0x7C,

	// Lock keys
	PS2_CODE_NUM_LOCK    = 0x77,
	PS2_CODE_SCROLL_LOCK = 0x7E,

	// Extended keys
	PS2_CODE_RALT =0xE011,
	PS2_CODE_RCTRL=0xE014,
	PS2_CODE_APPLICATION=0xE02F,
	PS2_CODE_UP=0xE075,
	PS2_CODE_DOWN=0xE072,
	PS2_CODE_LEFT=0xE06B,
	PS2_CODE_RIGHT=0xE074,
	PS2_CODE_INSERT=0xE070,
	PS2_CODE_DELETE=0xE071,
	PS2_CODE_HOME=0xE06C,
	PS2_CODE_END=0xE069,
	PS2_CODE_PAGEUP=0xE07D,
	PS2_CODE_PAGEDOWN=0xE07A,

	PS2_EXCODE_END
};


#endif
