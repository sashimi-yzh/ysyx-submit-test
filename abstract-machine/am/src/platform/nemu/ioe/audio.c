#include "riscv/riscv.h"
#include <am.h>
#include <nemu.h>
#include <klib.h>
#include <stdint.h>
#include <stdio.h>
#define AUDIO_FREQ_ADDR (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR (AUDIO_ADDR + 0x14)
#define AUDIO_CLOCK_ADDR (AUDIO_ADDR + 0x18)
#define AUDIO_CLOCK_STATUS_ADDR (AUDIO_ADDR + 0x1C)
#define min(a, b) ((a) < (b) ? (a) : (b))
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
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  const int bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
  static uint32_t sbuf_wpos = 0;
  int avail = min(ctl->buf.end - ctl->buf.start, bufsize - inl(AUDIO_COUNT_ADDR));
  for (int i = 0; i < avail; i += 4) {
    outl(AUDIO_SBUF_ADDR + (sbuf_wpos + i) % bufsize, *(uint32_t *)(ctl->buf.start + i));
  }
  sbuf_wpos = (sbuf_wpos + avail) % bufsize;
  outl(AUDIO_COUNT_ADDR, inl(AUDIO_COUNT_ADDR) + avail);
}
