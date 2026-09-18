#include <common.h>
#include <npc.h>
#include <device/map.h>

void init_map();
void init_serial();
void init_timer();

void init_device() {
  init_map();

  IFDEF(CONFIG_HAS_SERIAL, init_serial());
  IFDEF(CONFIG_HAS_TIMER, init_timer());
}

void sdl_clear_event_queue() {
  /* NPC does not use SDL. Stub for compatibility with the debugger main loop. */
}
