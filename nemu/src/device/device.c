/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <common.h>
#include <utils.h>
#include <device/map.h>
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
void init_mrom(device_init_param_t *);
void init_sram(device_init_param_t *);
void init_flash(device_init_param_t *);
void init_sdram(device_init_param_t *);

void send_key(uint8_t, bool);
void vga_update_screen();

void device_update() {
  static uint64_t last = 0;
  uint64_t now = get_time();
  if (now - last < 1000000 / TIMER_HZ) {
    return;
  }
  last = now;

  IFDEF(CONFIG_HAS_VGA, vga_update_screen());

#if !defined(CONFIG_TARGET_AM) && defined (CONFIG_HAS_KEYBOARD)
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        nemu_state.state = NEMU_QUIT;
        break;
      // If a key was pressed
      case SDL_KEYDOWN:
      case SDL_KEYUP: {
        uint8_t k = event.key.keysym.scancode;
        bool is_keydown = (event.key.type == SDL_KEYDOWN);
        send_key(k, is_keydown);
        break;
      }
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

void device_load_img(IOMap *map, const char *path) {
  Assert(path, "path should not be NULL");
  Assert(map, "map should not be NULL");

  FILE *fp = fopen(path, "rb");
  Assert(fp, "Can not open '%s'", path);

  fseek(fp, 0, SEEK_END);
  long img_size = ftell(fp);

  Log("Load image to %s: %s, size = %ld", map->name, path, img_size);
  uintptr_t map_size = (uintptr_t)map->high - (uintptr_t)map->low + 1;
  Assert(img_size <= map_size, "size of map is not enough. At least %lu byte", img_size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(map->space, img_size, 1, fp);
  assert(ret == 1);

  fclose(fp);
}

void init_device(device_init_param_t *param) {
  IFDEF(CONFIG_TARGET_AM, ioe_init());
  init_map();

  IFDEF(CONFIG_HAS_SERIAL, init_serial());
  IFDEF(CONFIG_HAS_TIMER, init_timer());
  IFDEF(CONFIG_HAS_VGA, init_vga());
  IFDEF(CONFIG_HAS_KEYBOARD, init_i8042());
  IFDEF(CONFIG_HAS_AUDIO, init_audio());
  IFDEF(CONFIG_HAS_DISK, init_disk());
  IFDEF(CONFIG_HAS_SDCARD, init_sdcard());
  IFDEF(CONFIG_HAS_MROM, init_mrom(param));
  IFDEF(CONFIG_HAS_SRAM, init_sram(param));
  IFDEF(CONFIG_HAS_FLASH, init_flash(param));
  IFDEF(CONFIG_HAS_SDRAM, init_sdram(param));

  IFNDEF(CONFIG_TARGET_AM, init_alarm());
}
