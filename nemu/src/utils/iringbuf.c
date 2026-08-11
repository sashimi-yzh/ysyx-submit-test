#include<stdio.h>
#include<string.h>
#include <stdbool.h> 
#include<utils/iringbuf.h>
#include <utils.h>
// 定义环形缓冲的大小
#ifndef IRINGBUF_SIZE
#define IRINGBUF_SIZE 16
#endif

// 定义单个环形缓冲单元的大小
#ifndef IRINGBUF_LINE_MAX
#define IRINGBUF_LINE_MAX 256
#endif

static char buf[IRINGBUF_SIZE][IRINGBUF_LINE_MAX];
static int head=0;
static int count=0;

void iringbuf_init(void){
  head=0;
  count=0;
  for(int i=0;i<IRINGBUF_SIZE;i++){
    buf[i][0]='\0';
  }
}

void iringbuf_push(const char *logline){
  if(logline==NULL) return;
  strncpy(buf[head],logline,IRINGBUF_LINE_MAX-1);
  buf[head][IRINGBUF_LINE_MAX-1]='\0';
  head=(head+1)%IRINGBUF_SIZE;
  if(count<IRINGBUF_SIZE) count++;
}

void iringbuf_dump(bool goodtrap) {
  if (count == 0) {
    puts("No instruction for running");
    return;
  }

  const char *c = goodtrap ? ANSI_FG_GREEN : ANSI_FG_RED;

  int last  = (head - 1 + IRINGBUF_SIZE) % IRINGBUF_SIZE;
  int start = (head - count + IRINGBUF_SIZE) % IRINGBUF_SIZE;

  printf("%s=================instruction ring buffer=================%s\n", ANSI_FG_BLUE, ANSI_NONE);
  for (int i = 0; i < count; i++) {
    int idx = (start + i) % IRINGBUF_SIZE;

    if (idx == last) {
      printf("%s--> %s%s\n", c, buf[idx], ANSI_NONE);
    } else {
      printf("%s    %s%s\n", c, buf[idx], ANSI_NONE);
    }
  }
  printf("%s=========================================================%s\n", ANSI_FG_BLUE, ANSI_NONE);
}

