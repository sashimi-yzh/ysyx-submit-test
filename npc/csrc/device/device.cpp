#include "map.h"

void device_init() {
  map_init();
  #ifdef __NPC__
  serial_init();
  rtc_init();
  #endif
}
