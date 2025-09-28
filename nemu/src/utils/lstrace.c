#include "common.h"
#include <stdio.h>

static FILE *fp = NULL;

static uint32_t last_addr = -1;
static uint32_t seq_cnt = 0;
static int last_len = -1, last_op = -1;

void init_lstrace(const char *filename) {
  if (!filename) return;
  Log("LoadStore trace is written to %s", filename);
  fp = fopen(filename, "wb");
  assert(fp);
}

static inline uint8_t len_w(int len) {
  switch (len) {
    case 1: return 0;
    case 2: return 1;
    case 4: return 2;
    case 8: return 3;
    default: assert(0);
  }
}

static void write_seq() {
  if (!seq_cnt) return;
  uint8_t l, h = last_op;

  h |= len_w(last_len) << 1;
  h |= 0b10 << 3;

  if (seq_cnt == 1) l = 0;
  else if (seq_cnt <= (1 << 8) - 1) l = 1;
  else if (seq_cnt <= (1 << 16) - 1) l = 2;
  else l = 3;
  h |= l << 5;

  fwrite(&h, 1, 1, fp);
  if (l) fwrite(&seq_cnt, l + (l == 3), 1, fp);

  seq_cnt = 0;
}

// op 0:read 1:write
void lstrace(uint32_t addr, int op, int len) {
  if (!fp) return;
  int off;
  *(uint32_t *)&off = addr - last_addr;
  if (off == last_len && len == last_len && op == last_op) {
    ++seq_cnt;
  } else {
    write_seq();
    uint8_t h = (len_w(len) << 1) | op;
    if (-32768 <= off && off < 32768) {
      if (-128 <= off && off < 128) {
        h |= 0b0101 << 3;
        fwrite(&h, 1, 1, fp);
        fwrite(&off, 1, 1, fp);
      } else {
        h |= 0b1001 << 3;
        fwrite(&h, 1, 1, fp);
        fwrite(&off, 2, 1, fp);
      }
    } else {
      h |= 0b1100 << 3;
      fwrite(&h, 1, 1, fp);
      fwrite(&addr, 4, 1, fp);
    }
  }
  last_addr = addr;
  last_op = op;
  last_len = len;
}

void finalize_lstrace() {
  write_seq();
  if (fp) fclose(fp);
}
