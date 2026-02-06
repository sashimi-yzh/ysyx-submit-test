#include <common.h>

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
static size_t screen_w = 0;
static size_t screen_h = 0;

size_t serial_write(const void *buf, size_t offset, size_t len) {
  for (size_t i = 0; i < len; ++i){
      putch(*((char *)buf + i));
    }
  return len;
}

size_t events_read(void *buf, size_t offset, size_t len) {
  AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
  size_t ret = 0 ;
  if( ev.keycode == AM_KEY_NONE )  {
    ret =  0;
  }
  else { 
    ret = snprintf(buf, len, "%s %s\n", ev.keydown?"kd":"ku", keyname[ev.keycode]);
  }
  return ret;
}


size_t dispinfo_read(void *buf, size_t offset, size_t len) {
  //AM_GPU_CONFIG_T config = io_read(AM_GPU_CONFIG);
  int width  = io_read(AM_GPU_CONFIG).width ;
  int height = io_read(AM_GPU_CONFIG).height;

  snprintf(buf, len, "width=%d, height=%d\n", width, height);
  return 0;
}

size_t fb_write(const void *buf, size_t offset, size_t len) {
  uint32_t *pixels = (uint32_t *)buf;

  size_t screen_offset = offset / 4u;
  size_t times = len / 4u;
  
  size_t start_x = screen_offset % screen_w;
  size_t start_y = screen_offset / screen_w;

  for(int i = 0; i < times; i++ ) {
    io_write(AM_GPU_FBDRAW, start_x, start_y, pixels, 1, 1, false);
    pixels ++ ;
    screen_offset ++ ;
    start_x = screen_offset % screen_w ;
    start_y = screen_offset / screen_w ;
  }

  io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true );
  return len;
}

void init_device() {
  Log("Initializing devices...");
  ioe_init();
  screen_w = io_read(AM_GPU_CONFIG).width;
  screen_h = io_read(AM_GPU_CONFIG).height;
}
