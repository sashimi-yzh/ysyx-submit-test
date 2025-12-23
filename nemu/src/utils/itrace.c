#include <common.h>
#include <utils.h>

#define MAX_IRINGBUF 64

typedef struct {
  word_t pc;
  word_t inst;
}ItraceNode;

ItraceNode iringbuf[MAX_IRINGBUF];
int p_cur = 0;
bool full = false;

void itrace_init(word_t pc, word_t inst) {
  iringbuf[p_cur].pc = pc;
  iringbuf[p_cur].inst = inst;
  p_cur = (p_cur + 1) % MAX_IRINGBUF;
  full = full || p_cur == 0;
}

void display_inst() {
  #ifdef CONFIG_ITRACE
  if (!full && !p_cur) return;

  int end = p_cur;
  int start = full ? p_cur : 0;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  char buf[128];
  char *p;
  printf("Most recently executed instructions\n");
  while((start = (start + 1) % MAX_IRINGBUF) != end){
    p = buf;
    p += sprintf(buf, "%s" FMT_WORD ": %08x ", ((start + 1) % MAX_IRINGBUF == end) ? " --> " : "     ", iringbuf[start].pc, iringbuf[start].inst);
    disassemble(p, buf + sizeof(buf) - p, iringbuf[start].pc, (uint8_t *)&iringbuf[start].inst, 4);

    if((start + 1) % MAX_IRINGBUF == end){
        if(is_exit_status_bad())
            printf(ANSI_FG_RED);
        else
            printf(ANSI_FG_GREEN);
    }
    puts(buf);
  }
  printf(ANSI_NONE);
  #endif
}