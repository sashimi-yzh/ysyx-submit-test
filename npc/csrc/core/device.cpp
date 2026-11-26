/***************************************************************************************
* NPC Device Management
* 设备管理模块实现
* 支持：串口、RTC 定时器、键盘（SDL2）、VGA 帧缓冲（SDL2）
***************************************************************************************/

#include "device.h"
#include <cstdio>
#include <cstring>
#include <sys/time.h>
#include <SDL2/SDL.h>

static uint64_t boot_time = 0;

static uint64_t get_time_us() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (uint64_t)tv.tv_sec * 1000000 + tv.tv_usec;
}

//  键盘 
#define KEYDOWN_MASK  0x8000
#define KEY_QUEUE_LEN 256

static uint32_t key_queue[KEY_QUEUE_LEN];
static int key_head = 0, key_tail = 0;

// SDL scancode → AM keycode 映射表（与 NEMU keyboard.c 保持一致）
#define AM_KEYS(_) \
  _(ESCAPE) _(F1) _(F2) _(F3) _(F4) _(F5) _(F6) _(F7) _(F8) _(F9) _(F10) _(F11) _(F12) \
  _(GRAVE) _(1) _(2) _(3) _(4) _(5) _(6) _(7) _(8) _(9) _(0) _(MINUS) _(EQUALS) _(BACKSPACE) \
  _(TAB) _(Q) _(W) _(E) _(R) _(T) _(Y) _(U) _(I) _(O) _(P) _(LEFTBRACKET) _(RIGHTBRACKET) _(BACKSLASH) \
  _(CAPSLOCK) _(A) _(S) _(D) _(F) _(G) _(H) _(J) _(K) _(L) _(SEMICOLON) _(APOSTROPHE) _(RETURN) \
  _(LSHIFT) _(Z) _(X) _(C) _(V) _(B) _(N) _(M) _(COMMA) _(PERIOD) _(SLASH) _(RSHIFT) \
  _(LCTRL) _(APPLICATION) _(LALT) _(SPACE) _(RALT) _(RCTRL) \
  _(UP) _(DOWN) _(LEFT) _(RIGHT) _(INSERT) _(DELETE) _(HOME) _(END) _(PAGEUP) _(PAGEDOWN)

#define AM_KEY_NAME(k) AM_KEY_##k,
enum {
    AM_KEY_NONE = 0,
    AM_KEYS(AM_KEY_NAME)
};

#define SDL_KEYMAP(k) keymap[SDL_SCANCODE_##k] = AM_KEY_##k;
static uint32_t keymap[512] = {};

static void init_keymap() {
    AM_KEYS(SDL_KEYMAP)
}

static void key_enqueue(uint32_t code) {
    int next = (key_tail + 1) % KEY_QUEUE_LEN;
    if (next != key_head) {   // 队列未满
        key_queue[key_tail] = code;
        key_tail = next;
    }
}

static uint32_t key_dequeue() {
    if (key_head == key_tail) return AM_KEY_NONE;
    uint32_t v = key_queue[key_head];
    key_head = (key_head + 1) % KEY_QUEUE_LEN;
    return v;
}

// VGA / SDL 
static SDL_Window   *g_window   = NULL;
static SDL_Renderer *g_renderer = NULL;
static SDL_Texture  *g_texture  = NULL;

// 帧缓冲（NPC 侧维护，游戏写入后 sync 时刷到 SDL）
static uint32_t g_fb[SCREEN_W * SCREEN_H];

static void init_sdl() {
    SDL_Init(SDL_INIT_VIDEO);
    g_window = SDL_CreateWindow("NPC Typing Game",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_W * 2, SCREEN_H * 2, 0);   // 2× 放大显示
    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
    g_texture  = SDL_CreateTexture(g_renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        SCREEN_W, SCREEN_H);
    SDL_RenderPresent(g_renderer);
}

static void sdl_update_screen() {
    SDL_UpdateTexture(g_texture, NULL, g_fb, SCREEN_W * sizeof(uint32_t));
    SDL_RenderClear(g_renderer);
    SDL_RenderCopy(g_renderer, g_texture, NULL, NULL);
    SDL_RenderPresent(g_renderer);
}


void init_device() {
    boot_time = get_time_us();
    memset(g_fb, 0, sizeof(g_fb));
#ifndef ENABLE_NVBOARD
    init_keymap();
#endif
}

void device_cleanup() {
#ifndef ENABLE_NVBOARD
    if (g_texture)  SDL_DestroyTexture(g_texture);
    if (g_renderer) SDL_DestroyRenderer(g_renderer);
    if (g_window)   SDL_DestroyWindow(g_window);
    SDL_Quit();
#endif
}

bool is_device_addr(uint32_t addr) {
    return addr == SERIAL_PORT  ||
           addr == RTC_ADDR_LO  ||
           addr == RTC_ADDR_HI  ||
           addr == KBD_ADDR     ||
           addr == VGACTL_ADDR  ||
           addr == VGASYNC_ADDR;
}

bool is_fb_addr(uint32_t addr) {
    return addr >= FB_ADDR && addr < FB_ADDR + FB_SIZE;
}

uint32_t device_read(uint32_t addr) {
    if (addr == RTC_ADDR_LO) {
        uint64_t us = get_time_us() - boot_time;
        return (uint32_t)(us & 0xFFFFFFFF);
    }
    if (addr == RTC_ADDR_HI) {
        uint64_t us = get_time_us() - boot_time;
        return (uint32_t)(us >> 32);
    }
    if (addr == KBD_ADDR) {
        return key_dequeue();
    }
    if (addr == VGACTL_ADDR) {
        // 高16位=宽，低16位=高
        return ((uint32_t)SCREEN_W << 16) | (uint32_t)SCREEN_H;
    }
    return 0;
}

void device_write(uint32_t addr, uint32_t data, uint8_t wmask) {
    if (addr == SERIAL_PORT) {
        putchar((char)(data & 0xFF));
        fflush(stdout);
        return;
    }
    if (addr == VGASYNC_ADDR && data) {
        // 写1触发刷屏
        sdl_update_screen();
        return;
    }
}

void fb_write(uint32_t addr, uint32_t data, uint8_t wmask) {
    // addr 是帧缓冲内的字节偏移（相对 FB_ADDR）
    uint32_t offset = (addr - FB_ADDR) / 4;  // 像素索引
    if (offset >= (uint32_t)(SCREEN_W * SCREEN_H)) return;

    uint32_t old = g_fb[offset];
    uint32_t result = old;
    if (wmask & 0x1) result = (result & ~0x000000FFu) | (data & 0x000000FFu);
    if (wmask & 0x2) result = (result & ~0x0000FF00u) | (data & 0x0000FF00u);
    if (wmask & 0x4) result = (result & ~0x00FF0000u) | (data & 0x00FF0000u);
    if (wmask & 0x8) result = (result & ~0xFF000000u) | (data & 0xFF000000u);
    g_fb[offset] = result;
}

void device_update() {
#ifndef ENABLE_NVBOARD
    // 原仿真环境（standalone）的 SDL 事件轮询
    // 每 1ms 才轮询一次 SDL 事件，避免每条指令都调用 SDL 拖慢仿真
    static uint64_t last_update = 0;
    uint64_t now = get_time_us();
    if (now - last_update < 1000) return;  
    last_update = now;

    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
        switch (ev.type) {
            case SDL_QUIT:
                key_enqueue(AM_KEY_ESCAPE | KEYDOWN_MASK);
                break;
            case SDL_KEYDOWN:
            case SDL_KEYUP: {
                uint32_t scancode = ev.key.keysym.scancode;
                if (scancode < 512 && keymap[scancode] != AM_KEY_NONE) {
                    uint32_t code = keymap[scancode];
                    if (ev.type == SDL_KEYDOWN) code |= KEYDOWN_MASK;
                    key_enqueue(code);
                }
                break;
            }
            default: break;
        }
    }
#endif
}
