#include <am.h>
#include <nemu.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

static int buf_size;
static uintptr_t buf;
static int buf_p;

void __am_audio_init() {
  buf_size = inl(AUDIO_SBUF_SIZE_ADDR);
  buf = AUDIO_SBUF_ADDR;
  buf_p = 0;
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->bufsize = buf_size;
  cfg->present = true;
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
  int audio_left = ctl->buf.end - ctl->buf.start;
  uint8_t *p = ctl->buf.start;
  while (audio_left > 0) {
    int nplay = buf_size - io_read(AM_AUDIO_STATUS).count;
    if (!nplay) continue;
    while (audio_left > 0 && nplay > 0) {
      // write aligned 4 bytes at a time
      uintptr_t addr = buf + buf_p;
      int len = 0;
      if (audio_left >= 4 && nplay >= 4 && !(addr & 0b11)) {
        outl(addr, *(uint32_t *)p);
        len = 4;
      } else {
        outb(addr, *p);
        len = 1;
      }
      p += len;
      audio_left -= len;
      nplay -= len;
      buf_p = (buf_p + len) % buf_size;
    }
  }
}
