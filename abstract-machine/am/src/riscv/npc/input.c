#include <npc.h>

uint8_t key_code_get(uint8_t key_data, uint8_t e0_flag)
{
    uint8_t key_code = 0;
    if(!e0_flag) {
        switch(key_data) {
            case 0x76: key_code = AM_KEY_ESCAPE; break;
            case 0x05: key_code = AM_KEY_F1; break;
            case 0x06: key_code = AM_KEY_F2; break;
            case 0x04: key_code = AM_KEY_F3; break;
            case 0x0C: key_code = AM_KEY_F4; break;
            case 0x03: key_code = AM_KEY_F5; break;
            case 0x0B: key_code = AM_KEY_F6; break;
            case 0x83: key_code = AM_KEY_F7; break;
            case 0x0A: key_code = AM_KEY_F8; break;
            case 0x01: key_code = AM_KEY_F9; break;
            case 0x09: key_code = AM_KEY_F10; break;
            case 0x78: key_code = AM_KEY_F11; break;
            case 0x07: key_code = AM_KEY_F12; break;
            case 0x0E: key_code = AM_KEY_GRAVE; break;
            case 0x16: key_code = AM_KEY_1; break;
            case 0x1E: key_code = AM_KEY_2; break;
            case 0x26: key_code = AM_KEY_3; break;
            case 0x25: key_code = AM_KEY_4; break;
            case 0x2E: key_code = AM_KEY_5; break;
            case 0x36: key_code = AM_KEY_6; break;
            case 0x3D: key_code = AM_KEY_7; break;
            case 0x3E: key_code = AM_KEY_8; break;
            case 0x46: key_code = AM_KEY_9; break;
            case 0x45: key_code = AM_KEY_0; break;
            case 0x4E: key_code = AM_KEY_MINUS; break;
            case 0x55: key_code = AM_KEY_EQUALS; break;
            case 0x66: key_code = AM_KEY_BACKSPACE; break;
            case 0x0D: key_code = AM_KEY_TAB; break;
            case 0x15: key_code = AM_KEY_Q; break;
            case 0x1D: key_code = AM_KEY_W; break;
            case 0x24: key_code = AM_KEY_E; break;
            case 0x2D: key_code = AM_KEY_R; break;
            case 0x2C: key_code = AM_KEY_T; break;
            case 0x35: key_code = AM_KEY_Y; break;
            case 0x3C: key_code = AM_KEY_U; break;
            case 0x43: key_code = AM_KEY_I; break;
            case 0x44: key_code = AM_KEY_O; break;
            case 0x4D: key_code = AM_KEY_P; break;
            case 0x54: key_code = AM_KEY_LEFTBRACKET; break;
            case 0x5B: key_code = AM_KEY_RIGHTBRACKET; break;
            case 0x5D: key_code = AM_KEY_BACKSLASH; break;
            case 0x58: key_code = AM_KEY_CAPSLOCK; break;
            case 0x1C: key_code = AM_KEY_A; break;
            case 0x1B: key_code = AM_KEY_S; break;
            case 0x23: key_code = AM_KEY_D; break;
            case 0x2B: key_code = AM_KEY_F; break;
            case 0x34: key_code = AM_KEY_G; break;
            case 0x33: key_code = AM_KEY_H; break;
            case 0x3B: key_code = AM_KEY_J; break;
            case 0x42: key_code = AM_KEY_K; break;
            case 0x4B: key_code = AM_KEY_L; break;
            case 0x4C: key_code = AM_KEY_SEMICOLON; break;
            case 0x52: key_code = AM_KEY_APOSTROPHE; break;
            case 0x5A: key_code = AM_KEY_RETURN; break;
            case 0x12: key_code = AM_KEY_LSHIFT; break;
            case 0x1A: key_code = AM_KEY_Z; break;
            case 0x22: key_code = AM_KEY_X; break;
            case 0x21: key_code = AM_KEY_C; break;
            case 0x2A: key_code = AM_KEY_V; break;
            case 0x32: key_code = AM_KEY_B; break;
            case 0x31: key_code = AM_KEY_N; break;
            case 0x3A: key_code = AM_KEY_M; break;
            case 0x41: key_code = AM_KEY_COMMA; break;
            case 0x49: key_code = AM_KEY_PERIOD; break;
            case 0x4A: key_code = AM_KEY_SLASH; break;
            case 0x59: key_code = AM_KEY_RSHIFT; break;
            case 0x14: key_code = AM_KEY_LCTRL; break;
            // case : key_code = AM_KEY_APPLICATION; break;
            case 0x11: key_code = AM_KEY_LALT; break;
            case 0x29: key_code = AM_KEY_SPACE; break;
            case 0xE0: 
                switch(inb(KBD_PORT)) {
                    case 0x11: key_code = AM_KEY_RALT; break;
                    case 0x14: key_code = AM_KEY_RCTRL; break;
                    case 0x75: key_code = AM_KEY_UP; break;
                    case 0x72: key_code = AM_KEY_DOWN; break;
                    case 0x6B: key_code = AM_KEY_LEFT; break;
                    case 0x74: key_code = AM_KEY_RIGHT; break;
                    case 0x70: key_code = AM_KEY_INSERT; break;
                    case 0x71: key_code = AM_KEY_DELETE; break;
                    case 0x6C: key_code = AM_KEY_HOME; break;
                    case 0x69: key_code = AM_KEY_END; break;
                    case 0x7D: key_code = AM_KEY_PAGEUP; break;
                    case 0x7A: key_code = AM_KEY_PAGEDOWN; break;
                    default: key_code = AM_KEY_NONE; break;
                }
                break;
            default: key_code = AM_KEY_NONE; break;
        }
    } else {
        switch(key_data) {
            case 0x11: key_code = AM_KEY_RALT; break;
            case 0x14: key_code = AM_KEY_RCTRL; break;
            case 0x75: key_code = AM_KEY_UP; break;
            case 0x72: key_code = AM_KEY_DOWN; break;
            case 0x6B: key_code = AM_KEY_LEFT; break;
            case 0x74: key_code = AM_KEY_RIGHT; break;
            case 0x70: key_code = AM_KEY_INSERT; break;
            case 0x71: key_code = AM_KEY_DELETE; break;
            case 0x6C: key_code = AM_KEY_HOME; break;
            case 0x69: key_code = AM_KEY_END; break;
            case 0x7D: key_code = AM_KEY_PAGEUP; break;
            case 0x7A: key_code = AM_KEY_PAGEDOWN; break;
            default: key_code = AM_KEY_NONE; break;
        }
    }

    return key_code;
}

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
    uint8_t key_data = inb(KBD_PORT);

    uint8_t e0_flag = 0;

    if(key_data == 0xF0) { // break code
        kbd->keydown = 0;
        key_data = inb(KBD_PORT);
        // printf("break code detected\n");
    } else if(key_data == 0xE0) {
        if((key_data = inb(KBD_PORT)) == 0xF0) {
            printf("e0 break code detected\n");
            kbd->keydown = 0;
            key_data = inb(KBD_PORT);
            e0_flag = 1;
        } else {
            kbd->keydown = 1;
            e0_flag = 1;
        }
    } else {
        kbd->keydown = 1;
    }

    uint8_t key_code = key_code_get(key_data, e0_flag);



    kbd->keycode = key_code;
}
