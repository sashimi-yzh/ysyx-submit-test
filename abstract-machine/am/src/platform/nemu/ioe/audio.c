#include <am.h>
#include <nemu.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

uintptr_t tail = AUDIO_SBUF_ADDR;

void __am_audio_init() {
  tail = AUDIO_SBUF_ADDR;
  outl(AUDIO_INIT_ADDR,1);
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = true;
  cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  outl(AUDIO_FREQ_ADDR,ctrl->freq);
  outl(AUDIO_CHANNELS_ADDR,ctrl->channels);
  outl(AUDIO_SAMPLES_ADDR,ctrl->samples);
  outl(AUDIO_INIT_ADDR,1);
  tail = AUDIO_SBUF_ADDR;
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  size_t bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
  uint8_t *pos = ctl->buf.start;
  uint8_t *end = ctl->buf.end;
  size_t len = ctl->buf.end - ctl->buf.start;
  while(len > bufsize - inl(AUDIO_COUNT_ADDR));
  // size_t cnt = 0;
  while(pos != end){
    outb(tail,*pos);
    pos++;
    tail++;
    if (tail >= AUDIO_SBUF_ADDR+bufsize) tail = AUDIO_SBUF_ADDR;

  }
  outl(AUDIO_COUNT_ADDR,len);
}
