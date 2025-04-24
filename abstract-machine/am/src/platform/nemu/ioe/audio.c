#include <am.h>
#include <nemu.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

#ifndef __ICS_EXPORT
#include <klib.h>

static int sbuf_size = 0;
static int head = 0;

void __am_audio_init() {
  sbuf_size = inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = true;
  cfg->bufsize = sbuf_size;
}

static int audio_write(uint8_t *buf, int len) {
  uint32_t count = inl(AUDIO_COUNT_ADDR);
  uint8_t* const sbuf = (uint8_t *)AUDIO_SBUF_ADDR;
  int free = sbuf_size - count;
  int nwrite = len;
  if (free < len) nwrite = free;

  if (nwrite + head < sbuf_size) {
    memcpy(sbuf + head, buf, nwrite);
    head += nwrite;
  } else {
    int first_cpy_len = sbuf_size - head;
    memcpy(sbuf + head, buf, first_cpy_len);
    memcpy(sbuf, buf + first_cpy_len, nwrite - first_cpy_len);
    head = nwrite - first_cpy_len;
  }
  count += nwrite;
  outl(AUDIO_COUNT_ADDR, count);
  return nwrite;
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  outl(AUDIO_FREQ_ADDR, ctrl->freq);
  outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
  outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
  outl(AUDIO_INIT_ADDR, 1);
  head = 0;
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  int len = ctl->buf.end - ctl->buf.start;
  assert(len <= sbuf_size);
  while (sbuf_size - inl(AUDIO_COUNT_ADDR) < len);
  audio_write(ctl->buf.start, len);
}
#else
void __am_audio_init() {
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = false;
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = 0;
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
}
#endif
