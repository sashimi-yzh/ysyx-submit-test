#include "klib.h"
#include <am.h>
#include <nemu.h>
#include <stdint.h>

// clang-format off
#define MIN(x, y) ((x) < (y)) ? (x) : (y)
static int wfd = 0;

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

void __am_audio_init() {
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->bufsize = *(int*)AUDIO_SBUF_SIZE_ADDR;
  if(cfg->bufsize == 0)
    cfg->present = false;
  else
    cfg->present = true;
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  *(int*)AUDIO_FREQ_ADDR = ctrl->freq;
  *(int*)AUDIO_SAMPLES_ADDR = ctrl->samples;
  *(int*)AUDIO_CHANNELS_ADDR = ctrl->channels;
  *(int*)AUDIO_INIT_ADDR = 1;
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = *(int*)AUDIO_COUNT_ADDR;
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  int buflen = *(int*)AUDIO_SBUF_SIZE_ADDR;
  int writelen = (int)(ctl->buf.end) - (int)(ctl->buf.start);
  int nwrite = 0;
  uint8_t *src = (uint8_t*)ctl->buf.start;
  uint8_t *dst = (uint8_t*)AUDIO_SBUF_ADDR;
  while(nwrite < writelen){
    int i = 0;
    for(;i<writelen;i++){
        dst[wfd] = src[i];
        wfd = (wfd + 1) % buflen;
    }
    nwrite += i;
  }
  *(int*)AUDIO_COUNT_ADDR = *(int*)AUDIO_COUNT_ADDR + writelen;
}

// clang-format on
