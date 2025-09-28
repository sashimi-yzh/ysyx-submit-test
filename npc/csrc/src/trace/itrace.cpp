#include "trace.h"
#include "driver.h"

static const int buf_size = 128;

static char iringbuf[16][buf_size] = {0};
static int iringbuf_ptr = 0;

void itrace(addr_t pc, uint64_t inst, bool print) {
  char buf[buf_size];
  char *p = buf;
  p += snprintf(p, buf_size, FMT_ADDR ":", pc);
  const int ilen = 4;
  uint8_t *inst_p = (uint8_t *)&inst;
  for (int i = ilen - 1; i >= 0; --i) {
    p += snprintf(p, 4, " %02x", inst_p[i]);
  }
  for (int i = 0; i < 4; ++i) *p++ = ' ';

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, buf + buf_size - p, pc, inst_p, 4);

  IFDEF(ILOGALL, log_write("%s\n", buf));
  if (print) puts(buf);

  memcpy(iringbuf[iringbuf_ptr++], buf, buf_size);
  iringbuf_ptr &= 0xf;
}

void print_iringbuf() {
  puts("----- iringbuf -----");
  for (int i = 0; i < 16; ++i) {
    char *str = iringbuf[(iringbuf_ptr + i) & 0xf];
    if (*str) puts(str);
  }
  putchar('\n');
}
