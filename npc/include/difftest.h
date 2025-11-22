#ifndef __DIFFTEST_H__
#define __DIFFTEST_H__


#include "common.h"
#include "debug.h"
#include "macro.h"
#include "utils.h"
#include "paddr.h"


enum{ DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

typedef struct{
  word_t mcause;//存放异常原因
  vaddr_t mepc;//存放触发异常的地址PC
  word_t mstatus;//存放当前状态
  word_t mtvec;//存放异常向量表地址
}riscv32_CSRs;

typedef struct {
    word_t gpr[32];
    vaddr_t pc;
    riscv32_CSRs csr;
}CPU_state;
void init_difftest(char *ref_so_file, long img_size, int port);
void update_cpu_state(CPU_state *cpu);
void difftest_skip_ref();
#endif