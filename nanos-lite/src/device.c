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

size_t serial_write(const void *buf, size_t offset, size_t len) {
  for (int i = 0; i < len; i ++) {
    io_write(AM_UART_TX, ((const char *)buf)[i]);
  }
  return len;
} 

size_t events_read(void *buf, size_t offset, size_t len) {
  return 0;
}

size_t dispinfo_read(void *buf, size_t offset, size_t len) {
  AM_GPU_CONFIG_T config = io_read(AM_GPU_CONFIG);
  char buffer[64];
  int str_len = sprintf(buffer,"WIDTH : %d\nHEIGHT: %d\n",config.width,config.height);
  // Log("dispinfo_read: %s",buf);
  int i = 0;
  for(; i < len && i <= str_len; i++) {
    ((char *)buf)[i] = buffer[i];
  }
  return i;
}

size_t fb_write(const void *buf, size_t offset, size_t len) {
  AM_GPU_CONFIG_T config = io_read(AM_GPU_CONFIG);
  int x = offset % config.width;
  int y = offset / config.width;
  io_write(AM_GPU_FBDRAW, x, y, (uint32_t*)buf, len, 1, true);
  // printf("fb_write: x=%d, y=%d, len=%d\n", x, y, len);
  return len;
}

void init_device() {
  Log("Initializing devices...");
  ioe_init();
}
