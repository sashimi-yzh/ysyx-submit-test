/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NPC is licensed under Mulan PSL v2.
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

#ifndef __ISA_H__
#define __ISA_H__

// Located at src/isa/$(GUEST_ISA)/include/isa-def.h
#include <isa-def.h>
#include <stdint.h>

// The macro `__GUEST_ISA__` is defined in $(CFLAGS).
// It will be expanded as "x86" or "mips32" ...
typedef concat(__GUEST_ISA__, _CPU_state) CPU_state;
typedef concat(__GUEST_ISA__, _ISADecodeInfo) ISADecodeInfo;

// monitor
extern unsigned char isa_logo[];
void init_isa();

// reg
extern CPU_state cpu;

// exec
struct Decode;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_PERF
uint64_t get_idu_cnt();
uint64_t get_idu_calc_cnt();
uint64_t get_idu_mem_cnt();
uint64_t get_idu_csr_cnt();
uint64_t get_idu_br_cnt();
uint64_t get_calc_cycles();
uint64_t get_mem_cycles();
uint64_t get_csr_cycles();
uint64_t get_br_cycles();
uint64_t get_ifu_cnt();
uint64_t get_exu_cnt();
uint64_t get_lsu_cnt();
uint64_t get_redirect_cnt();
uint64_t get_exu_redirect_cnt();
uint64_t get_branch_redirect_cnt();
uint64_t get_jump_redirect_cnt();
uint64_t get_jal_redirect_cnt();
uint64_t get_jalr_redirect_cnt();
uint64_t get_wbu_redirect_cnt();
uint64_t get_redirect_cycles();
uint64_t get_exu_redirect_cycles();
uint64_t get_branch_redirect_cycles();
uint64_t get_jump_redirect_cycles();
uint64_t get_jal_redirect_cycles();
uint64_t get_jalr_redirect_cycles();
uint64_t get_wbu_redirect_cycles();
uint64_t get_ihit_cnt();
uint64_t get_imiss_cnt();
uint64_t get_ihit_lat_cycles();
uint64_t get_imiss_lat_cycles();
uint64_t get_ifu_cycles();
uint64_t get_lsu_cycles();
uint64_t get_hazard_event_cnt();
uint64_t get_hazard_cycles();
void perf_cnt_display();
#endif

int get_gpr_npc(int index);
int get_csr_npc(int index);
int get_pc_npc();
void get_npc_gpr_regs(CPU_state *npc);
int ext_get_gpr_npc(int index);
void isa_reg_display();
word_t isa_reg_str2val(const char *name, bool *success);

void init_verilator_env (int argc, char *argv[]);
void deinit_verilator_env ();
int isa_exec_once(struct Decode *s);

#ifdef __cplusplus
}
#endif

// memory
enum { MMU_DIRECT, MMU_TRANSLATE, MMU_FAIL };
enum { MEM_TYPE_IFETCH, MEM_TYPE_READ, MEM_TYPE_WRITE };
enum { MEM_RET_OK, MEM_RET_FAIL, MEM_RET_CROSS_PAGE };
#ifndef isa_mmu_check
int isa_mmu_check(vaddr_t vaddr, int len, int type);
#endif
paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type);

// interrupt/exception
vaddr_t isa_raise_intr(word_t NO, vaddr_t epc);
#define INTR_EMPTY ((word_t)-1)
word_t isa_query_intr();

// difftest
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc);
void isa_difftest_attach();

#endif
