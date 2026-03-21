/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <cpu/cpu.h>
#include <difftest-def.h>
#include <isa.h>
#include <memory/paddr.h>

typedef struct {
    word_t mstatus;
    word_t mcause;
    word_t mepc;
    word_t mtvec;
} CPU_DIFF_REF_CSR_STATE;
typedef struct {
    word_t gpr[16];
    word_t pc;
    CPU_DIFF_REF_CSR_STATE csr;
} CPU_DIFF_REF_STATE;

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction)
{
    if (direction == DIFFTEST_TO_REF) {
        // printf("difftest_memcpy to ref: addr=0x%08x, n=%lu\n", addr, n);
        memcpy(guest_to_host(addr), buf, n);
    } else {
        assert(0);
    }
}

__EXPORT void difftest_regcpy(void *dut, bool direction)
{
    if (direction == DIFFTEST_TO_REF) {
        // printf("difftest_regcpy to ref: pc=0x%08x, dutpc = 0x%08x\n", cpu.pc, ((CPU_DIFF_REF_STATE *)dut)->pc);
        cpu.pc = ((CPU_DIFF_REF_STATE *)dut)->pc;
        for (int i = 0; i < 16; i++) {
            cpu.gpr[i] = ((CPU_DIFF_REF_STATE *)dut)->gpr[i];
        }
        cpu.csr.mstatus = ((CPU_DIFF_REF_STATE *)dut)->csr.mstatus;
        cpu.csr.mcause = ((CPU_DIFF_REF_STATE *)dut)->csr.mcause;
        cpu.csr.mepc = ((CPU_DIFF_REF_STATE *)dut)->csr.mepc;
        cpu.csr.mtvec = ((CPU_DIFF_REF_STATE *)dut)->csr.mtvec;
    } else if (direction == DIFFTEST_TO_DUT) {
        // printf("difftest_regcpy to dut: pc=0x%08x\n", cpu.pc);
        ((CPU_DIFF_REF_STATE *)dut)->pc = cpu.pc;
        for (int i = 0; i < 16; i++) {
            ((CPU_DIFF_REF_STATE *)dut)->gpr[i] = cpu.gpr[i];
        }
        ((CPU_DIFF_REF_STATE *)dut)->csr.mstatus = cpu.csr.mstatus;
        ((CPU_DIFF_REF_STATE *)dut)->csr.mcause = cpu.csr.mcause;
        ((CPU_DIFF_REF_STATE *)dut)->csr.mepc = cpu.csr.mepc;
        ((CPU_DIFF_REF_STATE *)dut)->csr.mtvec = cpu.csr.mtvec;
        // printf("difftest_regcpy to dut done: pc=0x%08x, ref_cpu=0x%08x\n", ((CPU_DIFF_REF_STATE *)dut)->pc, cpu.pc);
    } else {
        assert(0);
    }
}

__EXPORT void difftest_exec(uint64_t n)
{
    cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO)
{
    assert(0);
}

__EXPORT void difftest_init(int port)
{
    void init_mem();
    init_mem();
    /* Perform ISA dependent initialization. */
    init_isa();
    // printf("cpu.pc = 0x%08x\n", cpu.pc);
}
