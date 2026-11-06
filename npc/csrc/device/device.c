#include <common.h>
#include <utils.h>
#include <device/alarm.h>
#ifndef CONFIG_TARGET_AM
#include <SDL2/SDL.h>
#endif

void init_map();
void init_serial();
void init_timer();
void init_vga();
void init_i8042();
void init_audio();
void init_disk();
void init_sdcard();
void init_alarm();

void send_key(uint8_t, bool);
void vga_update_screen();


void device_update() {
  static uint64_t last = 0;
  uint64_t now = get_time();
  if (now - last < 1000000 / TIMER_HZ) {
    return;
  }
  last = now;
  #if CONFIG_HAS_VGA
  vga_update_screen();
  #endif

#if CONFIG_HAS_AUDIO
  // 添加音频更新处理
  extern void audio_update(void);
  audio_update();
#endif

#ifndef CONFIG_TARGET_AM
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        npc_state.state = NPC_QUIT;
        break;
#if CONFIG_HAS_KEYBOARD
      // If a key was pressed
      case SDL_KEYDOWN:
      case SDL_KEYUP: {
        uint8_t k = event.key.keysym.scancode;
        bool is_keydown = (event.key.type == SDL_KEYDOWN);
        send_key(k, is_keydown);
        break;
      }
#endif
      default: break;
    }
  }
#endif
}

void sdl_clear_event_queue() {
#ifndef CONFIG_TARGET_AM
  SDL_Event event;
  while (SDL_PollEvent(&event));
#endif
}

void init_device() {
  IFDEF(CONFIG_TARGET_AM, ioe_init());
  init_map();

  #if CONFIG_HAS_SERIAL 
    init_serial(); 
  #endif
  #if CONFIG_HAS_TIMER
    init_timer();
  #endif
  #if CONFIG_HAS_VGA
    init_vga();
  #endif
  #if CONFIG_HAS_KEYBOARD
    init_i8042();
  #endif
  #if CONFIG_HAS_AUDIO
    init_audio();
  #endif
  #if CONFIG_HAS_DISK
    init_disk();
  #endif
  #if CONFIG_HAS_SDCARD
    init_sdcard();
  #endif

  IFNDEF(CONFIG_TARGET_AM, init_alarm());
}
