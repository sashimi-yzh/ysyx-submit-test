#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <assert.h>

static int evtdev = -1;
static int fbdev = -1;
static int sbdev = -1;
static int screen_w = 0, screen_h = 0;
static int offset_x = 0, offset_y = 0;

uint32_t NDL_GetTicks() {
  struct timeval tv;
  assert(gettimeofday(&tv, NULL) == 0);
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int NDL_PollEvent(char *buf, int len) {
  int res = read(evtdev, buf, len);
  return res && buf[0] == 'k';
}

void NDL_OpenCanvas(int *w, int *h) {
  if (getenv("NWM_APP")) {
    int fbctl = 4;
    fbdev = 5;
    screen_w = *w; screen_h = *h;
    char buf[64];
    int len = sprintf(buf, "%d %d", screen_w, screen_h);
    // let NWM resize the window and create the frame buffer
    write(fbctl, buf, len);
    while (1) {
      // 3 = evtdev
      int nread = read(3, buf, sizeof(buf) - 1);
      if (nread <= 0) continue;
      buf[nread] = '\0';
      if (strcmp(buf, "mmap ok") == 0) break;
    }
    close(fbctl);
  } else {
    char buf[64];
    int fd = open("/proc/dispinfo", O_RDONLY);
    int res = read(fd, buf, sizeof(buf));
    close(fd);
    buf[res + 1] = '\0';

    char *p = strstr(buf, "WIDTH");
    p = strchr(p, ':');
    sscanf(p + 1, "%d", &screen_w);
    
    p = strstr(buf, "HEIGHT");
    p = strchr(p, ':');
    sscanf(p + 1, "%d", &screen_h);

    assert(*w <= screen_w && *h <= screen_h);
    if (*w || *h) {
      offset_x = (screen_w - *w) / 2;
      offset_y = (screen_h - *h) / 2;
    } else {
      *w = screen_w;
      *h = screen_h;
    }

    fbdev = open("/dev/fb", O_WRONLY);
  }
}

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) {
  x += offset_x; y += offset_y;
  for (int i = 0; i < h; ++i) {
    lseek(fbdev, ((y + i) * screen_w + x) * 4, SEEK_SET);
    assert(write(fbdev, pixels + w * i, w * 4) == w * 4);
  }
}

void NDL_OpenAudio(int freq, int channels, int samples) {
  int buf[3] = {freq, channels, samples};
  int fd = open("/dev/sbctl", O_WRONLY);
  assert(write(fd, buf, 12) == 12);
  close(fd);
  sbdev = open("/dev/sb", O_WRONLY);
}

void NDL_CloseAudio() {
  close(sbdev);
  sbdev = -1;
}

int NDL_PlayAudio(void *buf, int len) {
  int bytes_left = len;
  while (bytes_left) {
    assert(sbdev != -1);
    bytes_left -= write(sbdev, buf + len - bytes_left, bytes_left);
  }
  return 0;
}

int NDL_QueryAudio() {
  int res;
  char buf[20];
  int fd = open("/dev/sbctl", O_RDONLY);
  read(fd, buf, sizeof(buf));
  sscanf(buf, "%d", &res);
  close(fd);
  return res;
}

int NDL_Init(uint32_t flags) {
  if (getenv("NWM_APP")) {
    evtdev = 3;
  } else {
    evtdev = open("/dev/events", O_RDONLY);
  }
  return 0;
}

void NDL_Quit() {
  if (evtdev != -1) close(evtdev);
  if (fbdev != -1) close(fbdev);
  if (sbdev != -1) close(sbdev);
}
