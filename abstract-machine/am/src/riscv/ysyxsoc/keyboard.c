#include <am.h>
#include <klib-macros.h>
#include <ysyxsoc.h>
#include <riscv/riscv.h>

#define KBD_ADDR 0x10011000
static bool break_pending = false;
static bool ext_pending = false;

// 1. 标准按键查表 (没有 0xE0 前缀的按键)
static const int am_key_lut[256] = {
    [0x76] = AM_KEY_ESCAPE,
    [0x05] = AM_KEY_F1, [0x06] = AM_KEY_F2, [0x04] = AM_KEY_F3, [0x0C] = AM_KEY_F4,
    [0x03] = AM_KEY_F5, [0x0B] = AM_KEY_F6, [0x83] = AM_KEY_F7, [0x0A] = AM_KEY_F8,
    [0x01] = AM_KEY_F9, [0x09] = AM_KEY_F10, [0x78] = AM_KEY_F11, [0x07] = AM_KEY_F12,
    
    [0x0E] = AM_KEY_GRAVE, [0x16] = AM_KEY_1, [0x1E] = AM_KEY_2, [0x26] = AM_KEY_3,
    [0x25] = AM_KEY_4, [0x2E] = AM_KEY_5, [0x36] = AM_KEY_6, [0x3D] = AM_KEY_7,
    [0x3E] = AM_KEY_8, [0x46] = AM_KEY_9, [0x45] = AM_KEY_0, 
    [0x4E] = AM_KEY_MINUS, [0x55] = AM_KEY_EQUALS, [0x66] = AM_KEY_BACKSPACE,
    
    [0x0D] = AM_KEY_TAB, [0x15] = AM_KEY_Q, [0x1D] = AM_KEY_W, [0x24] = AM_KEY_E,
    [0x2D] = AM_KEY_R, [0x2C] = AM_KEY_T, [0x35] = AM_KEY_Y, [0x3C] = AM_KEY_U,
    [0x43] = AM_KEY_I, [0x44] = AM_KEY_O, [0x4D] = AM_KEY_P, 
    [0x54] = AM_KEY_LEFTBRACKET, [0x5B] = AM_KEY_RIGHTBRACKET, [0x5D] = AM_KEY_BACKSLASH,
    
    [0x58] = AM_KEY_CAPSLOCK, [0x1C] = AM_KEY_A, [0x1B] = AM_KEY_S, [0x23] = AM_KEY_D,
    [0x2B] = AM_KEY_F, [0x34] = AM_KEY_G, [0x33] = AM_KEY_H, [0x3B] = AM_KEY_J,
    [0x42] = AM_KEY_K, [0x4B] = AM_KEY_L, [0x4C] = AM_KEY_SEMICOLON, [0x52] = AM_KEY_APOSTROPHE,
    [0x5A] = AM_KEY_RETURN,
    
    [0x12] = AM_KEY_LSHIFT, [0x1A] = AM_KEY_Z, [0x22] = AM_KEY_X, [0x21] = AM_KEY_C,
    [0x2A] = AM_KEY_V, [0x32] = AM_KEY_B, [0x31] = AM_KEY_N, [0x3A] = AM_KEY_M,
    [0x41] = AM_KEY_COMMA, [0x49] = AM_KEY_PERIOD, [0x4A] = AM_KEY_SLASH, 
    [0x59] = AM_KEY_RSHIFT,
    
    [0x14] = AM_KEY_LCTRL, [0x11] = AM_KEY_LALT, [0x29] = AM_KEY_SPACE
};

// 2. 扩展按键查表 (带有 0xE0 前缀的按键)
static const int am_ext_key_lut[256] = {
    [0x11] = AM_KEY_RALT,
    [0x14] = AM_KEY_RCTRL,
    [0x75] = AM_KEY_UP,
    [0x72] = AM_KEY_DOWN,
    [0x6B] = AM_KEY_LEFT,
    [0x74] = AM_KEY_RIGHT,
    [0x70] = AM_KEY_INSERT,
    [0x71] = AM_KEY_DELETE,
    [0x6C] = AM_KEY_HOME,
    [0x69] = AM_KEY_END,
    [0x7D] = AM_KEY_PAGEUP,
    [0x7A] = AM_KEY_PAGEDOWN,
    [0x2F] = AM_KEY_APPLICATION, // 菜单键(Menu)，标准 Set 2 为 0xE0 0x2F
    [0x4A] = AM_KEY_SLASH,       // 小键盘的 /
    [0x5A] = AM_KEY_RETURN       // 小键盘的 Enter 
};

static int scancode_to_amkey(uint8_t code, bool is_ext) {
    if (is_ext) {
        return am_ext_key_lut[code] ? am_ext_key_lut[code] : AM_KEY_NONE;
    } else {
        return am_key_lut[code] ? am_key_lut[code] : AM_KEY_NONE;
    }
}

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd)
{
    uint8_t code = inb(KBD_ADDR);

    // 1. 无效按键
    if (code == 0)
    {
        kbd->keydown = false;
        kbd->keycode = AM_KEY_NONE;
        return;
    }

    // 2. 识别扩展码前缀 (0xE0)
    if (code == 0xE0)
    {
        ext_pending = true;
        kbd->keydown = false;
        kbd->keycode = AM_KEY_NONE;
        return;
    }

    // 3. 识别断码前缀 (0xF0)
    if (code == 0xF0)
    {
        break_pending = true;
        kbd->keydown = false;
        kbd->keycode = AM_KEY_NONE;
        return;
    }

    // 4. 解析真实按键
    int am_key = scancode_to_amkey(code, ext_pending);

    // 状态机重置：一旦解析完真实按键，重置扩展位
    ext_pending = false;

    // 5. 判断是松开(keyup)还是按下(keydown)
    if (break_pending)
    {
        kbd->keydown = false;
        kbd->keycode = am_key;
        break_pending = false; // 重置断码位
    }
    else
    {
        kbd->keydown = true;
        kbd->keycode = am_key;
    }
}