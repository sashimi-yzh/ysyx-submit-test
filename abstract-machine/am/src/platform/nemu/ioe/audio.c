#include "riscv/riscv.h"
#include <am.h>
#include <nemu.h>
#include <stdbool.h>
#include <stdint.h>

#define AUDIO_FREQ_ADDR        (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR    (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR     (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR   (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR        (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR       (AUDIO_ADDR + 0x14)
#define AUDIO_TAIL_OFFSET_ADDR (AUDIO_ADDR + 0x18)
// #define AUDIO_LOCK_ADDR        (AUDIO_ADDR + 0x1c)

void __am_audio_init() {
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = true;
  cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  outl(AUDIO_FREQ_ADDR, ctrl->freq);
  outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
  outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
  outl(AUDIO_INIT_ADDR, 1u);
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  union {
    uint32_t u;
    int32_t s;
  } conv;
  uint32_t raw_data = inl(AUDIO_COUNT_ADDR);
  conv.u = raw_data;
  stat->count = conv.s;
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  static uint32_t sbuf_size = 0;
  if (sbuf_size == 0) {
    sbuf_size = inl(AUDIO_SBUF_SIZE_ADDR);
  }
  static uint32_t sbuf_tail = 0;
  uint8_t *start = (uint8_t *)ctl->buf.start;
  uint8_t *end = (uint8_t *)ctl->buf.end;
  while ((sbuf_size - inl(AUDIO_COUNT_ADDR)) < (end - start));
  // outl(AUDIO_LOCK_ADDR, 1u);
  while (start + 4 < end) {
    outl(AUDIO_SBUF_ADDR + sbuf_tail, *(uint32_t *)start);
    start += 4;
    sbuf_tail = (sbuf_tail + 4) % sbuf_size;
  }
  while (start < end) {
    outb(AUDIO_SBUF_ADDR + sbuf_tail, *start);
    start++;
    sbuf_tail = (sbuf_tail + 1) % sbuf_size;
  }
  outl(AUDIO_TAIL_OFFSET_ADDR, sbuf_tail);
  // outl(AUDIO_LOCK_ADDR, 0u);
}
