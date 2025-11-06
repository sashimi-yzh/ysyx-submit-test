
#include <common.h>
#include <utils.h>
#include <device.h>
#include <vga.h>
#include <keyboard.h>
#include <map.h>

#define TIMER_HZ 60

void init_i8042();

void send_key(uint8_t, bool);
void update_vga();

void device_update() {
  static uint64_t last = 0;
  uint64_t now = get_time();
  if (now - last < 1000000 / TIMER_HZ) {
    return;
  }
  last = now;

  IFDEF(CONFIG_VGA, update_vga());

  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    // printf("11\n");
    switch (event.type) {
      case SDL_QUIT:
        printf("KEY_BOARD exit\n");
        exit(0);
        break;
      #ifdef CONFIG_KEYBOARD
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

}

void init_device() {

  init_map();
  #ifdef CONFIG_KEYBOARD
    init_keymap();
  #endif
  #ifdef CONFIG_VGA
    init_vga();
  #endif
  // printf("\n\n\n\n\n\n\n\n\ninit device\n\n\n\n\n\n\n\n\n");
  printf("init device\n");

}
