#include "Device/Keyboard.h"
#include "Device/VGA.h"
#include "Monitor.h"
#include "spdlog/spdlog.h"
#include <Device/Device.h>
#include <SDL2/SDL_events.h>
#include <Simulate.h>
#include <stop_token>

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;
static SDL_Window *window = NULL;

static void VGA_init() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(VideoBase_t::ScreenWidth * 2,
                              VideoBase_t::ScreenHeight * 2, 0, &window,
                              &renderer);
  SDL_SetWindowTitle(window, "RISCV32E-NPC");
  texture = SDL_CreateTexture(
      renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC,
      VideoBase_t::ScreenWidth, VideoBase_t::ScreenHeight);
  SDL_RenderPresent(renderer);
}

static void keyboard_update() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
      {
        uint8_t k = event.key.keysym.scancode;
        bool is_keydown = (event.key.type == SDL_KEYDOWN);
        uint32_t wrapped = wrap_key_event(k, is_keydown);

        if (!Keyboard.kbd_buf->Push(wrapped))
          spdlog::warn("Key event {:#08x} ignored because the buffer is full",
                       wrapped);
      }
    } else if (event.type == SDL_QUIT) {
      quit.store(true);
    }
  }
}

static void vga_update() {
  uint8_t *ptr_vmem = reinterpret_cast<uint8_t *>(Video.front_ptr.load());
  SDL_UpdateTexture(texture, NULL, ptr_vmem,
                    VideoBase_t::ScreenWidth * sizeof(uint32_t));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}

void device_thread_work(std::stop_token stop_token,
                        std::promise<void> &device_inited_promise) {
  VGA_init();
  keyboard_init();

  device_inited_promise.set_value();

  using namespace std::chrono_literals;
  auto last_tick_vga = std::chrono::steady_clock::now();
  auto last_tick_kbd = std::chrono::steady_clock::now();
  while (!stop_token.stop_requested()) {
    auto cur_tick = std::chrono::steady_clock::now();
    if (Video.sync.load() && cur_tick - last_tick_vga >= 16.667ms) {
      last_tick_vga = cur_tick;
      vga_update();
      Video.sync.store(0);
    }

    if (cur_tick - last_tick_kbd >= 16.667ms) {
      last_tick_kbd = cur_tick;
      keyboard_update();
    }
  }
  if (texture)
    SDL_DestroyTexture(texture);
  if (renderer)
    SDL_DestroyRenderer(renderer);
  if (window)
    SDL_DestroyWindow(window);
}