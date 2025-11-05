#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;

uint32_t NDL_GetTicks() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return t.tv_sec * 1000000 + t.tv_usec;
}

int NDL_PollEvent(char *buf, int len) {
  return 0;
}

int linestr2num(const char *s, int *num) {
  int i;
  *num = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
    *num = (*num) * 10 + (s[i] - '0');
  }
  return i;
}

void get_screen_size(int *w, int*h){
  char buf [64];
  int nread;
  int fd = open("/proc/dispinfo", 0, 0);
  nread = read(fd, buf, sizeof(buf) - 1);
  // printf("buf:%s\n", buf);
  buf[nread] = '\0'; 
  int i = 0;
  while (buf[i++] != '\0') { 
    if (buf[i] >= '0' && buf[i] <= '9') {
      i += linestr2num(&buf[i], w); 
      break;
    }
  }

  do{
    if (buf[i] >= '0' && buf[i] <= '9') {
      linestr2num(&buf[i], h);
      break;
    }
  }while (buf[i++] != '\0');

  close(fd);
}


void NDL_OpenCanvas(int *w, int *h) {

  int width, height;
  get_screen_size(&width, &height);
  if(*w > width || *h > height){
    printf("Not enough space for canvas, set to full screen\n");
    *w = width;
    *h = height;
  }
  if(*w == 0 || *h == 0){
    *w = width;
    *h = height;
  }
  screen_h = *h;
  screen_w = *w;


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
  }
}

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) {
  int fd = open("/dev/fb", 0 ,0);
  uint32_t *p = pixels;
  int width,height;
  get_screen_size(&width, &height);
  int base_x = (width - screen_w)/2;
  int base_y = (height - screen_h)/2;
   x = base_x + x;
   y = base_y + y;
  int offset = x + y * width;

  lseek(fd, offset, SEEK_SET);
  for(int i = 0; i < h; i ++){
    write(fd, p, w);
    lseek(fd, width - w, SEEK_CUR);
    p += w;
  }
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
