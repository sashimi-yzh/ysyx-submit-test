#ifndef __RISCV_CSR_H__
#define __RISCV_CSR_H__

#include <common.h>
typedef struct {
  word_t value;
  word_t wpri_mask;
  uint16_t addr;
  char name[16];
} riscv_csr;

extern riscv_csr csrs[6];

#endif
// warl
// wlrl