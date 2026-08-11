#include <isa.h>
#include <npc/runtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "local-include/reg.h"
// regs name vector
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

enum { REGISTER_COUNT = 32 };
// change the regs name to index
static int register_index(const char *token) {
  if (token == NULL || *token == '\0') return -1;
  // whether out of bound
  if (token[0] == 'x' || token[0] == 'X') {
    char *end = NULL;
    long number = strtol(token + 1, &end, 10);
    if (*end == '\0' && number >= 0 && number < REGISTER_COUNT) return (int)number;
  }
  // compare from the second token (no $)
  for (int index = 0; index < REGISTER_COUNT; index++) {
    if (strcmp(token, regs[index] + 1) == 0) return index;
  }
  return -1;
}
// input reg name return reg value
word_t isa_reg_str2val(const char *name, bool *success) {
  if (success == NULL) return 0;
  *success = false;
  if (name == NULL) return 0;
  // name only
  const char *token = name + (name[0] == '$');
  if (strcmp(token, "pc") == 0 || strcmp(token, "PC") == 0) {
    *success = true;
    return cpu.pc;
  }
  // call register_index to get the real index
  int index = register_index(token);
  if (index < 0) return 0;
  *success = true;
  return cpu.gpr[index];
}
// show all the reg names and values
void isa_reg_display() {
  printf("[regs] pc=" FMT_WORD "\n", cpu.pc);
  for (int index = 0; index < REGISTER_COUNT; index++) {
    printf("x%02d/%-3s=" FMT_WORD, index, regs[index], cpu.gpr[index]);
    putchar((index + 1) % 4 == 0 ? '\n' : ' ');
  }
}
