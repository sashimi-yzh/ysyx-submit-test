#ifndef AM_IOE_DIAG_H__
#define AM_IOE_DIAG_H__

#include <am.h>
#include <amdev.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdbool.h>
#include <stdint.h>

static inline void diag_delay(uint32_t n) {
  for (volatile uint32_t i = 0; i < n; i++) {
  }
}

static inline uint32_t diag_rgb(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

static inline const char *diag_key_name(int key) {
  switch (key) {
    case AM_KEY_NONE: return "NONE";
#define KEY_NAME_CASE(k) case AM_KEY_##k: return #k;
    AM_KEYS(KEY_NAME_CASE)
#undef KEY_NAME_CASE
    default: return "UNKNOWN";
  }
}

static inline bool diag_poll_exit(void) {
  AM_INPUT_CONFIG_T icfg = io_read(AM_INPUT_CONFIG);
  if (!icfg.present) return false;

  for (int i = 0; i < 8; i++) {
    AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
    if (ev.keycode == AM_KEY_NONE) break;
    if (ev.keydown && ev.keycode == AM_KEY_ESCAPE) return true;
  }
  return false;
}

static inline void diag_print_rtc(AM_TIMER_RTC_T rtc) {
  printf("%04d-%02d-%02d %02d:%02d:%02d",
      rtc.year, rtc.month, rtc.day, rtc.hour, rtc.minute, rtc.second);
}

#endif
