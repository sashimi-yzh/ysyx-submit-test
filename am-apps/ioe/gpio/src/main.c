#include <ioe_diag.h>

#ifndef GPIO_PASSCODE
#define GPIO_PASSCODE 0xec73u
#endif

#define LED_PHASE_DELAY 10000u

static uint32_t pack_hex_nibbles(uint32_t x) {
  uint32_t v = 0;
  for (int i = 0; i < 8; i++) {
    uint32_t nib = (x >> (i * 4)) & 0xfu;
    v |= nib << (i * 4);
  }
  return v;
}

static uint32_t read_marchid(void) {
  uint32_t marchid = 0;
  asm volatile("csrr %0, marchid" : "=r"(marchid));
  return marchid;
}

int main(const char *args) {
  (void)args;
  ioe_init();

  AM_GPIO_CONFIG_T cfg = io_read(AM_GPIO_CONFIG);
  printf("[gpio][CONFIG] gpio.present=%d passcode=0x%04x\n",
      cfg.present, (unsigned)GPIO_PASSCODE);
  if (!cfg.present) {
    printf("[gpio][SKIP] GPIO AM device is not present on this platform\n");
    return 0;
  }

  printf("[gpio][PHASE led-seg-count] LED rotates; SEG counts; SW value is printed periodically\n");
  uint16_t led = 0x0001u;
  for (uint32_t step = 0; step < 64; step++) {
    io_write(AM_GPIO_LED, led);
    AM_GPIO_SW_T sw = io_read(AM_GPIO_SW);
    uint32_t seg = ((step & 0xffffu) << 16) | sw.value;
    io_write(AM_GPIO_SEG, seg);
    if ((step & 0x7u) == 0) {
      printf("[gpio][LED_SEG] step=%u led=0x%04x sw=0x%04x seg=0x%08x\n",
          step, led, sw.value, seg);
    }
    led = (uint16_t)((led << 1) | (led >> 15));
    diag_delay(LED_PHASE_DELAY);
  }

  printf("[gpio][PHASE seg-pattern] SEG cycles fixed patterns, LED=0xa55a\n");
  io_write(AM_GPIO_LED, 0xa55au);
  static const uint32_t patterns[] = {
    0x01234567u,
    0x89abcdefu,
    0x20260702u,
    0xdeadbeefu,
  };
  for (int i = 0; i < (int)LENGTH(patterns); i++) {
    io_write(AM_GPIO_SEG, patterns[i]);
    printf("[gpio][SEG_PATTERN] index=%d seg=0x%08x\n", i, patterns[i]);
    for (volatile uint32_t d = 0; d < 1200000u; d++) {
    }
  }

  uint32_t marchid = read_marchid();
  uint32_t seg_marchid = pack_hex_nibbles(marchid);
  printf("[gpio][PHASE seg-marchid] marchid=%u raw=0x%08x seg=0x%08x\n",
      marchid, marchid, seg_marchid);
  io_write(AM_GPIO_SEG, seg_marchid);

  printf("[gpio][PHASE sw-exit] set SW=0x%04x to exit; LED rotates from passcode\n",
      (unsigned)GPIO_PASSCODE);
  led = GPIO_PASSCODE;
  uint32_t polls = 0;
  while (1) {
    io_write(AM_GPIO_LED, led);
    AM_GPIO_SW_T sw = io_read(AM_GPIO_SW);
    uint32_t seg = ((polls & 0xffffu) << 16) | sw.value;
    io_write(AM_GPIO_SEG, seg);
    if (sw.value == (uint16_t)GPIO_PASSCODE) break;
    if ((polls++ & 0x3fu) == 0) {
      printf("[gpio][SW_SEG] waiting sw=0x%04x expected=0x%04x led=0x%04x seg=0x%08x\n",
          sw.value, (unsigned)GPIO_PASSCODE, led, seg);
    }
    led = (uint16_t)((led << 1) | (led >> 15));
    diag_delay(LED_PHASE_DELAY);
  }

  io_write(AM_GPIO_LED, 0xffffu);
  io_write(AM_GPIO_SEG, 0x0000ec73u);
  printf("[gpio][DONE] passcode matched; LED=0xffff SEG=0x0000ec73\n");
  return 0;
}
