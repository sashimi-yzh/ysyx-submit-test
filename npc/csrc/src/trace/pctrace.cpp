#include "trace.h"
#include <algorithm>
#include <cstdio>

static FILE *fp;

static uint32_t last_pc;
static int exec_cnt;

void init_pctrace(const char *filename) {
  if (!filename) return;
  Log("PC trace is written to %s", filename);
  fp = fopen(filename, "wb");
  assert(fp);
  last_pc = -1;
  exec_cnt = 0;
}

void pctrace(addr_t pc) {
  if (!fp) return;
  int off;
  *(uint32_t *)&off = pc - last_pc;
  if (off == 4) {
    exec_cnt++;
  } else {
    while (exec_cnt) {
      int d = std::min(16383, exec_cnt);
      exec_cnt -= d;
      uint16_t x = (d << 2) | 0b01;
      fwrite(&x, sizeof(x), 1, fp);
    }
    assert(exec_cnt == 0);
    if (-16384 <= off && off < 16384) {
      assert((off & 1) == 0);
      off >>= 1;
      uint16_t x = (off << 2) | 0b11;
      fwrite(&x, sizeof(x), 1, fp);
    } else {
      assert((pc & 1) == 0);
      fwrite(&pc, sizeof(uint32_t), 1, fp);
    }
  }
  last_pc = pc;
}

void finalize_pctrace() {
  if (exec_cnt) {
    while (exec_cnt) {
      int d = std::min(16383, exec_cnt);
      exec_cnt -= d;
      uint16_t x = (d << 2) | 0b01;
      fwrite(&x, sizeof(x), 1, fp);
    }
  }
  assert(exec_cnt == 0);
  if (fp) fclose(fp);
}