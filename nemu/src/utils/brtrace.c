#include "common.h"
#include "cpu/decode.h"
#include <stdint.h>
#include <stdio.h>

static FILE *fp = NULL;
static uint8_t last_type = 0b10;
static int last_taken = 0;
static uint32_t last_pc = -1;
static int write_pc = 1;
static uint32_t cnt = 0;

void init_brtrace(const char *filename) {
  if (!filename) return;
  Log("Branch trace is written to %s", filename);
  fp = fopen(filename, "wb");
  assert(fp);
}

static void write_last() {
  if (cnt == 0) return;
  uint8_t len;
  if (cnt == 1) len = 0;
  else if (cnt <= 255) len = 1;
  else if (cnt <= 65535) len = 2;
  else len = 3;

  uint8_t h = last_type | (last_taken << 2) | (write_pc << 3) | (len << 4);
  fwrite(&h, 1, 1, fp);
  if (write_pc) fwrite(&last_pc, 4, 1, fp);
  if (len) fwrite(&cnt, len + (len == 3), 1, fp);
}

void brtrace(Decode *s) {
  if (!fp) return;
  // inst
  uint8_t type;
  uint8_t opcode = (s->isa.inst.val >> 2) & ((1 << 5) - 1);
  switch (opcode) {
    case 0b11011: type = 0b11; break; // jal
    case 0b11001: type = 0b01; break; // jalr
    case 0b11000: type = 0b00; break; // branch
    default: return;
  }
  // direction
  int taken = s->dnpc != s->snpc;
  // pc
  uint32_t pc = s->pc;

  if (type == last_type && taken == last_taken && pc == last_pc) {
    ++cnt;
  } else {
    write_last();
    write_pc = pc != last_pc;

    cnt = 1;
    last_type = type;
    last_taken = taken;
    last_pc = pc;
  }
}

void finalize_brtrace() {
  write_last();
  if (fp) fclose(fp);
}

