#include <common.h>

#define IRINGBUF_LEN 16
int iringbuf_idx = 0;
char iringbuf[IRINGBUF_LEN][134];

void iringbuf_record(const char logbuf[128]) {
  memset(iringbuf[iringbuf_idx], ' ', 6);
  strncpy(iringbuf[iringbuf_idx] + 6, logbuf, 128);
  iringbuf_idx = (iringbuf_idx + 1) % IRINGBUF_LEN;
}

void iringbuf_display() {
#ifdef CONFIG_ITRACE_COND
  int i=0;
  int iringbuf_cur_idx = 0;
  if(iringbuf_idx == 0) {
    iringbuf_cur_idx = IRINGBUF_LEN - 1;
  }
  else {
    iringbuf_cur_idx = iringbuf_idx - 1;
  }
  
  printf("\nIRINGBUF:\n");
  iringbuf[iringbuf_cur_idx][2] = '-';
  iringbuf[iringbuf_cur_idx][3] = '-';
  iringbuf[iringbuf_cur_idx][4] = '>';
  for(; i < IRINGBUF_LEN; i ++) {
    printf("%2d: %s\n", i, iringbuf[i]);
  }
  printf("\n");
#endif
}