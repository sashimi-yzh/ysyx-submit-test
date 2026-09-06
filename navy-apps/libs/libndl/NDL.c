#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "sys/time.h"
#include "sys/stat.h"

#include "assert.h"

static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;

uint32_t NDL_GetTicks() {
  struct timeval tv;
  struct timezone tz;

  int res = gettimeofday(&tv, &tz);
  return tv.tv_usec / 1000;
}

int NDL_PollEvent(char *buf, int len) {
  int fd = open("/dev/events", 0, 0);
  int res =  read(fd, buf, len);
  close(fd);

  return res;
}

static size_t canvas_width = 0;
static size_t canvas_height = 0;
static size_t canvas_x = 0;
static size_t canvas_y = 0;
void NDL_OpenCanvas(int *w, int *h) {
  int fd = open("/proc/dispinfo", 0, 0);
  char buf[128];
  int readn = read(fd, buf, sizeof(buf));
  close(fd);
  if(readn == 0) {
    *w = 0; *h = 0; return ;
  }
  int max_height, max_width;

  sscanf(buf, "WIDTH : %d\nHEIGHT:%d", &max_width, &max_height);
  if(*w == 0) *w = max_width;
  if(*h == 0) *h = max_height;

  assert(*w <= max_width);
  assert(*h <= max_height);

  canvas_width = *w;
  canvas_height = *h;
  return ;
}

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) {
  int fd_info = open("/proc/dispinfo", 0, 0);
  char buf[128];
  int readn = read(fd_info, buf, sizeof(buf));
  while(readn == 0) {
    readn = read(fd_info, buf, sizeof(buf));
  }
  close(fd_info);
  int max_height, max_width;
  sscanf(buf, "WIDTH : %d\nHEIGHT:%d", &max_width, &max_height);

  int frame_buffer_x = canvas_x + x;
  int frame_buffer_y = canvas_y + y;

  if(h == 0) h = max_height;
  if(w == 0) w = max_width;

  int fd_fb = open("/dev/fb", 0, 0);
  for(int i = 0; i < h; i++) {
    lseek(fd_fb, sizeof(uint32_t) * ((frame_buffer_y + i) * max_width + frame_buffer_x), SEEK_SET);
    write(fd_fb, (pixels + i * w), sizeof(uint32_t) * w);
  }
  close(fd_fb);
}

void NDL_OpenAudio(int freq, int channels, int samples) {
}

void NDL_CloseAudio() {
}

int NDL_PlayAudio(void *buf, int len) {
  return 0;
}

int NDL_QueryAudio() {
  return 0;
}

int NDL_Init(uint32_t flags) {
  if (getenv("NWM_APP")) {
    evtdev = 3;
  }
  return 0;
}

void NDL_Quit() {
}
