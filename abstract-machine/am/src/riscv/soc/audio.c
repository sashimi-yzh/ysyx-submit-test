#include "riscv/riscv.h"
#include <am.h>
#include <klib.h>
#include <soc.h>
#include <stdint.h>

#define AUDIO_FREQ_ADDR (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR (AUDIO_ADDR + 0x14)

void __am_audio_init() {}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
  cfg->present = cfg->bufsize > 0;
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  outl(AUDIO_FREQ_ADDR, ctrl->freq);
  outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
  outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
  outl(AUDIO_INIT_ADDR, 1);
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  static int last_pos = 0;
  int len = ctl->buf.end - ctl->buf.start;
  int bsize = inl(AUDIO_SBUF_SIZE_ADDR);
  while (bsize - inl(AUDIO_COUNT_ADDR) < len)
    ;
  void *cur_addr = ctl->buf.start;
  while (ctl->buf.end - cur_addr >= 4) {
    outl(AUDIO_SBUF_ADDR + last_pos, *(uint32_t *)cur_addr);
    cur_addr += 4;
    last_pos += 4;
    if (last_pos >= bsize)
      last_pos -= bsize;
  }

  while (ctl->buf.end - cur_addr >= 1) {
    outb(AUDIO_SBUF_ADDR + last_pos, *(uint8_t *)cur_addr);
    cur_addr++;
    last_pos++;
    if (last_pos == bsize)
      last_pos = 0;
  }

  int new_count = inl(AUDIO_COUNT_ADDR) + len;

  outl(AUDIO_COUNT_ADDR, new_count);
}