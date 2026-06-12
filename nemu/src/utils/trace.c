#include <common.h>
#include <cpu/decode.h>
#include <device/map.h>

extern uint64_t g_nr_guest_inst;
extern bool g_print_step;

#ifdef CONFIG_BTRACE
void btrace(btrace_data_t btrace_data) {
  static FILE *bin = NULL;
  if (bin == NULL) {
    bin = fopen("btrace.bin", "w");
    assert(bin);
  }
  size_t ret = fwrite(&btrace_data, 1, sizeof(btrace_data_t), bin);
  assert(ret == sizeof(btrace_data_t));
}
#endif

#ifdef CONFIG_PCTRACE
void pctrace(Decode *s) {
  static FILE *bin = NULL;
  if (bin == NULL) {
    bin = fopen("pctrace.bin", "w");
    Assert(bin, "Can not open pctrace.bin");
  }
  unsigned long ret = fwrite(&s->pc, 1, sizeof(vaddr_t), bin);
  Assert(ret == sizeof(vaddr_t), "Write pctrace fail");
}
#endif

#ifdef CONFIG_MBINTRACE
void mbintrace(bool is_write, paddr_t addr, int len) {
  static FILE *bin = NULL;
  if (bin == NULL) {
    bin = fopen("mbintrace.bin", "w");
    Assert(bin, "Can not open mbintrace.bin");
  }
  unsigned long ret = fwrite(&addr, 1, sizeof(paddr_t), bin);
  Assert(ret == sizeof(paddr_t), "Write mbintrace fail");
}
#endif

#ifdef CONFIG_ITRACE
IFDEF(CONFIG_ITRACE, char iringbuf[16][128]);
IFDEF(CONFIG_ITRACE, unsigned int iringbuf_ptr = 0);

void iringbuf_display(void) {
  if (g_nr_guest_inst == 0) {
    return;
  }
  int len = LENGTH(iringbuf);
  int i = g_nr_guest_inst <= len ? 0 : (iringbuf_ptr + 1) % len;
  for (; i != iringbuf_ptr; i = (i + 1) % len) {
    printf("%s\n", iringbuf[i]);
  }
}
#endif

#ifdef CONFIG_ITRACE
void print_disassemble(Decode *s) {
  char *p = s->logbuf;
  p += snprintf(s->logbuf, sizeof(s->logbuf), 
      FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst;
#ifdef CONFIG_ISA_x86
  for (i = 0; i < ilen; i ++) {
#else
  for (i = ilen - 1; i >= 0; i --) {
#endif
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), inst, ilen);

  // Log
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", s->logbuf); }
#endif // CONFIG_ITRACE_COND
  if (g_print_step) { puts(s->logbuf); }
  memcpy(iringbuf + iringbuf_ptr, s->logbuf, LENGTH(s->logbuf));
  iringbuf_ptr = (iringbuf_ptr + 1) % LENGTH(iringbuf);
}
#endif

#ifdef CONFIG_MTRACE
void mtrace(bool is_write, paddr_t addr, int len, word_t data) {
#define MTRACE_MSG "Memory %s:  Addr="FMT_PADDR"  Len=%d  Data="FMT_WORD"\n", \
              is_write ? "write" : "read", addr, len, data 
#ifdef CONFIG_MTRACE_COND
  if (MTRACE_COND) {
    log_write(MTRACE_MSG);
  }
#endif
  extern bool g_print_step;
  if (g_print_step) {
    printf(MTRACE_MSG);
  }
}
#endif

#ifdef CONFIG_DTRACE
void dtrace(IOMap *map, bool is_write, paddr_t addr, int len, word_t data) {
#define DTRACE_MSG "Device %s %s:  Addr="FMT_PADDR"  Len=%d  Data="FMT_WORD"\n", \
              map->name, is_write ? "write" : "read", addr, len, data
#ifdef CONFIG_DTRACE_COND
  if (DTRACE_COND) {
    log_write(DTRACE_MSG);
  }
#endif
  extern bool g_print_step;
  if (g_print_step) {
    printf(DTRACE_MSG);
  }
}
#endif
