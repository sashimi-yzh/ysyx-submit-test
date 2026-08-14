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

// Input

#define AM_KEYS(_) \
  _(ESCAPE) _(F1) _(F2) _(F3) _(F4) _(F5) _(F6) _(F7) _(F8) _(F9) _(F10) _(F11) _(F12) \
  _(GRAVE) _(1) _(2) _(3) _(4) _(5) _(6) _(7) _(8) _(9) _(0) _(MINUS) _(EQUALS) _(BACKSPACE) \
  _(TAB) _(Q) _(W) _(E) _(R) _(T) _(Y) _(U) _(I) _(O) _(P) _(LEFTBRACKET) _(RIGHTBRACKET) _(BACKSLASH) \
  _(CAPSLOCK) _(A) _(S) _(D) _(F) _(G) _(H) _(J) _(K) _(L) _(SEMICOLON) _(APOSTROPHE) _(RETURN) \
  _(LSHIFT) _(Z) _(X) _(C) _(V) _(B) _(N) _(M) _(COMMA) _(PERIOD) _(SLASH) _(RSHIFT) \
  _(LCTRL) _(APPLICATION) _(LALT) _(SPACE) _(RALT) _(RCTRL) \
  _(UP) _(DOWN) _(LEFT) _(RIGHT) _(INSERT) _(DELETE) _(HOME) _(END) _(PAGEUP) _(PAGEDOWN)

#define AM_KEY_NAMES(key) AM_KEY_##key,
enum {
  AM_KEY_NONE = 0,
  AM_KEYS(AM_KEY_NAMES)
};

// PS2键盘扫描码枚举（通码，前缀SCANCODE_）
typedef enum {
    // 功能键区
    SCANCODE_ESCAPE    = 0x76,
    SCANCODE_F1        = 0x05,
    SCANCODE_F2        = 0x06,
    SCANCODE_F3        = 0x04,
    SCANCODE_F4        = 0x0C,
    SCANCODE_F5        = 0x03,
    SCANCODE_F6        = 0x0B,
    SCANCODE_F7        = 0x83,
    SCANCODE_F8        = 0x0A,
    SCANCODE_F9        = 0x01,
    SCANCODE_F10       = 0x09,
    SCANCODE_F11       = 0x78,
    SCANCODE_F12       = 0x07,

    // 数字行
    SCANCODE_GRAVE     = 0x0E,    // 反引号/波浪号
    SCANCODE_1         = 0x16,
    SCANCODE_2         = 0x1E,
    SCANCODE_3         = 0x26,
    SCANCODE_4         = 0x25,
    SCANCODE_5         = 0x2E,
    SCANCODE_6         = 0x36,
    SCANCODE_7         = 0x3D,
    SCANCODE_8         = 0x3E,
    SCANCODE_9         = 0x46,
    SCANCODE_0         = 0x45,
    SCANCODE_MINUS     = 0x4E,    // 减号/下划线
    SCANCODE_EQUALS    = 0x55,    // 等号/加号
    SCANCODE_BACKSPACE = 0x66,

    // QWERTY行
    SCANCODE_TAB           = 0x0D,
    SCANCODE_Q             = 0x15,
    SCANCODE_W             = 0x1D,
    SCANCODE_E             = 0x24,
    SCANCODE_R             = 0x2D,
    SCANCODE_T             = 0x2C,
    SCANCODE_Y             = 0x35,
    SCANCODE_U             = 0x3C,
    SCANCODE_I             = 0x43,
    SCANCODE_O             = 0x44,
    SCANCODE_P             = 0x4D,
    SCANCODE_LEFTBRACKET   = 0x54,  // [ / {
    SCANCODE_RIGHTBRACKET  = 0x5B,  // ] / }
    SCANCODE_BACKSLASH     = 0x5D,  // \ / |

    // ASDF行
    SCANCODE_CAPSLOCK      = 0x58,
    SCANCODE_A             = 0x1C,
    SCANCODE_S             = 0x1B,
    SCANCODE_D             = 0x23,
    SCANCODE_F             = 0x2B,
    SCANCODE_G             = 0x34,
    SCANCODE_H             = 0x33,
    SCANCODE_J             = 0x3B,
    SCANCODE_K             = 0x42,
    SCANCODE_L             = 0x4B,
    SCANCODE_SEMICOLON     = 0x4C,  // ; / :
    SCANCODE_APOSTROPHE    = 0x52,  // ' / "
    SCANCODE_RETURN        = 0x5A,  // 回车键

    // ZXCV行
    SCANCODE_LSHIFT        = 0x12,
    SCANCODE_Z             = 0x1A,
    SCANCODE_X             = 0x22,
    SCANCODE_C             = 0x21,
    SCANCODE_V             = 0x2A,
    SCANCODE_B             = 0x32,
    SCANCODE_N             = 0x31,
    SCANCODE_M             = 0x3A,
    SCANCODE_COMMA         = 0x41,  // , / <
    SCANCODE_PERIOD        = 0x49,  // . / >
    SCANCODE_SLASH         = 0x4A,  // / / ?
    SCANCODE_RSHIFT        = 0x59,

    // 控制键区
    SCANCODE_LCTRL         = 0x14,
    SCANCODE_APPLICATION   = 0x67,  // 菜单键
    SCANCODE_LALT          = 0x11,  // 左Alt
    SCANCODE_SPACE         = 0x29,  // 空格键
    SCANCODE_RALT          = 0x111,// 右Alt（扩展扫描码）
    SCANCODE_RCTRL         = 0x114,// 右Ctrl（扩展扫描码）

    // 方向/编辑键区
    SCANCODE_UP            = 0x175,// 上方向键
    SCANCODE_DOWN          = 0x172,// 下方向键
    SCANCODE_LEFT          = 0x16B,// 左方向键
    SCANCODE_RIGHT         = 0x174,// 右方向键
    SCANCODE_INSERT        = 0x170,// 插入
    SCANCODE_DELETE        = 0x171,// 删除
    SCANCODE_HOME          = 0x16C,// 主页
    SCANCODE_END           = 0x169,// 结束
    SCANCODE_PAGEUP        = 0x17D,// 上翻页
    SCANCODE_PAGEDOWN      = 0x17A // 下翻页
} PS2_ScanCode;

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
