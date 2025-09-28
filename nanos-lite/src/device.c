#include <common.h>
#include <device.h>

#if defined(MULTIPROGRAM) && !defined(TIME_SHARING)
# define MULTIPROGRAM_YIELD() yield()
#else
# define MULTIPROGRAM_YIELD()
#endif

#define NAME(key) \
  [AM_KEY_##key] = #key,

static const char *keyname[256] __attribute__((used)) = {
  [AM_KEY_NONE] = "NONE",
  AM_KEYS(NAME)
};

size_t serial_write(const void *buf, size_t offset, size_t len) {
  for (int i = 0; i < len; ++i) putch(((const char *)buf)[i]);
  return len;
}

size_t events_read(void *buf, size_t offset, size_t len) {
  AM_INPUT_KEYBRD_T kbd;
  ioe_read(AM_INPUT_KEYBRD, &kbd);
  if (!kbd.keycode) return 0;

  extern int current_process_sw;
  switch (kbd.keycode) {
    case AM_KEY_F1: current_process_sw = 1; return 0;
    case AM_KEY_F2: current_process_sw = 2; return 0;
    case AM_KEY_F3: current_process_sw = 3; return 0;
  }
  return snprintf((char *)buf, len, "k%c %s\n", kbd.keydown ? 'd' : 'u', keyname[kbd.keycode]);
}

size_t dispinfo_read(void *buf, size_t offset, size_t len) {
  AM_GPU_CONFIG_T cfg;
  ioe_read(AM_GPU_CONFIG, &cfg);

  return snprintf(buf, len, "WIDTH:%d\nHEIGHT:%d", cfg.width, cfg.height);
}

size_t fb_write(const void *buf, size_t offset, size_t len) {
  AM_GPU_MEMCPY_T ctl;
  ctl.size = len;
  ctl.dest = offset;
  ctl.src = (void *)buf;
  ioe_write(AM_GPU_MEMCPY, &ctl);
  return len;
}

size_t sb_write(const void *buf, size_t offset, size_t len) {
  AM_AUDIO_PLAY_T play;
  play.buf.start = (void *)buf;
  play.buf.end = (void *)buf + len;
  ioe_write(AM_AUDIO_PLAY, &play);
  return len;
}

size_t sbctl_read(void *buf, size_t offset, size_t len) {
  AM_AUDIO_CONFIG_T conf;
  ioe_read(AM_AUDIO_CONFIG, &conf);
  assert(conf.present);

  AM_AUDIO_STATUS_T stat;
  ioe_read(AM_AUDIO_STATUS, &stat);

  return sprintf(buf, "%d", conf.bufsize - stat.count);
}

size_t sbctl_write(const void *buf, size_t offset, size_t len) {
  assert(len == 12);
  AM_AUDIO_CTRL_T ctl;
  ctl.freq = *(int *)buf;
  ctl.channels = *(int *)(buf + 4);
  ctl.samples = *(int *)(buf + 8);
  ioe_write(AM_AUDIO_CTRL, &ctl);
  return 12;
}

void init_device() {
  Log("Initializing devices...");
  ioe_init();
}
