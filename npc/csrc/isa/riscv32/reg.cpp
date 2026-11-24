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

#include <isa.h>
#include <stdint.h>
#include "local-include/reg.h"
#include "dpi.h"

#ifdef CONFIG_DIFFTEST
extern "C" bool difftest_is_skip();
#endif

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

const char *csr_names[] = {
  "mstatus", "mtvec", "mepc", "mcause"
};

int ext_get_gpr_npc(int index) {
  setup_scope("cpu.regfile");
  int value = get_gpr_npc(index);
  return value;
}

extern "C" void get_npc_gpr_regs(CPU_state *npc) {
  setup_scope("cpu.regfile");
  for (uint8_t i = 0; i < sizeof(npc->gpr)/sizeof(npc->gpr[0]); i++) {
    npc->gpr[i] = get_gpr_npc(i);
  }
#ifdef CONFIG_DIFFTEST
  if (difftest_is_skip()) {
    setup_scope("cpu");
    npc->pc = get_npc();
    return;
  }
#endif
  setup_scope("cpu");
  npc->pc = get_pc();
}

extern "C" void isa_reg_display() {
  int i;

  setup_scope("cpu.regfile");
  for (i = 0; i < sizeof(regs)/sizeof(regs[0]); i++) {
    printf("Index.%d reg %-4s value 0x%08x\t", i, regs[i], get_gpr_npc(i));
    if (i % 4 == 0)
      printf("\n");
  }
  for (i = 0; i < sizeof(csr_names)/sizeof(csr_names[0]); i++) {
    printf("Index.%d reg %-4s value 0x%08x\t", i, csr_names[i], get_csr_npc(i));
    if (i % 4 == 0)
      printf("\n");
  }
  setup_scope("cpu");
  printf("reg %-4s value 0x%08x\n", "pc", get_pc());
}

extern "C" word_t isa_reg_str2val(const char *s, bool *success) {
  int i;

  setup_scope("cpu.regfile");
  *success = false;
  // the 1st reg is $0, we handle it here
  if (!strcmp(s, "0")) {
    *success = true;
    return get_gpr_npc(0);
  }

  if (!strcmp(s, "pc")) {
    setup_scope("cpu");
    *success = true;
    return get_pc();
  }

  setup_scope("cpu.regfile");
  for (i = 0; i < sizeof(regs)/sizeof(regs[0]); i++) {
   if (!strcmp(regs[i], s)) {
      *success = true;
      return get_gpr_npc(i);
    }
  }

  Log("Not a valid reg name: %s\n", s);
  return 0;
}


#ifdef CONFIG_PERF
extern "C" uint64_t g_running_cycles;

extern "C" void perf_cnt_display() {
  setup_scope("cpu");
  uint64_t lsu_cnt = get_lsu_cnt();
  uint64_t idu_calc_cnt = get_idu_calc_cnt();
  uint64_t idu_mem_cnt = get_idu_mem_cnt();
  uint64_t idu_csr_cnt = get_idu_csr_cnt();
  uint64_t idu_br_cnt = get_idu_br_cnt();
  uint64_t idu_cnt = get_idu_cnt();
  uint64_t ifu_cnt = get_ifu_cnt();
  uint64_t exu_cnt = get_exu_cnt();
  uint64_t redirect_cnt = get_redirect_cnt();
  uint64_t exu_redirect_cnt = get_exu_redirect_cnt();
  uint64_t branch_redirect_cnt = get_branch_redirect_cnt();
  uint64_t jump_redirect_cnt = get_jump_redirect_cnt();
  uint64_t jal_redirect_cnt = get_jal_redirect_cnt();
  uint64_t jalr_redirect_cnt = get_jalr_redirect_cnt();
  uint64_t wbu_redirect_cnt = get_wbu_redirect_cnt();
  uint64_t redirect_cycles = get_redirect_cycles();
  uint64_t exu_redirect_cycles = get_exu_redirect_cycles();
  uint64_t branch_redirect_cycles = get_branch_redirect_cycles();
  uint64_t jump_redirect_cycles = get_jump_redirect_cycles();
  uint64_t jal_redirect_cycles = get_jal_redirect_cycles();
  uint64_t jalr_redirect_cycles = get_jalr_redirect_cycles();
  uint64_t wbu_redirect_cycles = get_wbu_redirect_cycles();
  uint64_t ifu_cycles = get_ifu_cycles();
  uint64_t lsu_cycles = get_lsu_cycles();
  uint64_t hazard_event_cnt = get_hazard_event_cnt();
  uint64_t hazard_cycles = get_hazard_cycles();
  double total_cycle_percent = g_running_cycles == 0
                                   ? 0.0
                                   : 100.0 / (double)g_running_cycles;

  double calc_avg = (idu_calc_cnt == 0) ? 0.0 : (double)get_calc_cycles() / idu_calc_cnt;
  double mem_avg = (idu_mem_cnt == 0) ? 0.0 : (double)get_mem_cycles() / idu_mem_cnt;
  double csr_avg = (idu_csr_cnt == 0) ? 0.0 : (double)get_csr_cycles() / idu_csr_cnt;
  double br_avg = (idu_br_cnt == 0) ? 0.0 : (double)get_br_cycles() / idu_br_cnt;
  double ifu_avg = (ifu_cnt == 0) ? 0.0 : (double)ifu_cycles / ifu_cnt;
  double lsu_avg = (lsu_cnt == 0) ? 0.0 : (double)lsu_cycles / lsu_cnt;
  double redirect_avg = (redirect_cnt == 0) ? 0.0 : (double)redirect_cycles / redirect_cnt;
  double exu_redirect_avg = (exu_redirect_cnt == 0) ? 0.0 : (double)exu_redirect_cycles / exu_redirect_cnt;
  double jal_redirect_avg = (jal_redirect_cnt == 0) ? 0.0 : (double)jal_redirect_cycles / jal_redirect_cnt;
  double jalr_redirect_avg = (jalr_redirect_cnt == 0) ? 0.0 : (double)jalr_redirect_cycles / jalr_redirect_cnt;
  double wbu_redirect_avg = (wbu_redirect_cnt == 0) ? 0.0 : (double)wbu_redirect_cycles / wbu_redirect_cnt;

  setup_scope("cpu.my_icache");
  uint64_t ihit_cnt         = get_ihit_cnt();
  uint64_t imiss_cnt        = get_imiss_cnt();
  uint64_t ihit_lat_cycles  = get_ihit_lat_cycles();
  uint64_t imiss_lat_cycles = get_imiss_lat_cycles();

  uint64_t icache_access_cnt = ihit_cnt + imiss_cnt;
  double ihit_avg = (ihit_cnt == 0) ? 0.0 : (double)ihit_lat_cycles / ihit_cnt;
  double imiss_avg =
      (imiss_cnt == 0) ? 0.0 : (double)imiss_lat_cycles / imiss_cnt;
  double imiss_rate =
      (icache_access_cnt == 0) ? 0.0 : (double)imiss_cnt / icache_access_cnt;
  double amat =
      (icache_access_cnt == 0)
          ? 0.0
          : (double)(ihit_lat_cycles + imiss_lat_cycles) / icache_access_cnt;

  printf("+----------------------+----------------------+\n");
  printf("| %-20s | %20s |\n", "Metric", "Value");
  printf("+----------------------+----------------------+\n");
  printf("| %-20s | %20llu |\n", "lsu_cnt", (unsigned long long)lsu_cnt);
  printf("| %-20s | %20llu |\n", "idu_calc_cnt", (unsigned long long)idu_calc_cnt);
  printf("| %-20s | %20llu |\n", "idu_mem_cnt", (unsigned long long)idu_mem_cnt);
  printf("| %-20s | %20llu |\n", "idu_csr_cnt", (unsigned long long)idu_csr_cnt);
  printf("| %-20s | %20llu |\n", "idu_br_cnt", (unsigned long long)idu_br_cnt);
  printf("| %-20s | %20llu |\n", "idu_cnt", (unsigned long long)idu_cnt);
  printf("| %-20s | %20llu |\n", "ifu_cnt", (unsigned long long)ifu_cnt);
  printf("| %-20s | %20llu |\n", "exu_cnt", (unsigned long long)exu_cnt);
  printf("| %-20s | %20llu |\n", "redirect_cnt", (unsigned long long)redirect_cnt);
  printf("| %-20s | %20llu |\n", "exu_redirect_cnt", (unsigned long long)exu_redirect_cnt);
  printf("| %-20s | %20llu |\n", "branch_redirect_cnt", (unsigned long long)branch_redirect_cnt);
  printf("| %-20s | %20llu |\n", "jump_redirect_cnt", (unsigned long long)jump_redirect_cnt);
  printf("| %-20s | %20llu |\n", "jal_redirect_cnt", (unsigned long long)jal_redirect_cnt);
  printf("| %-20s | %20llu |\n", "jalr_redirect_cnt", (unsigned long long)jalr_redirect_cnt);
  printf("| %-20s | %20llu |\n", "wbu_redirect_cnt", (unsigned long long)wbu_redirect_cnt);
  printf("+----------------------+----------------------+\n");
  printf("| %-20s | %20s |\n", "Metric", "Value");
  printf("+----------------------+----------------------+\n");
  printf("| %-20s | %10llu (%6.2f%%) |\n", "redirect_cycles",
         (unsigned long long)redirect_cycles,
         redirect_cycles * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "exu_redr_cycles",
         (unsigned long long)exu_redirect_cycles,
         exu_redirect_cycles * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "branch_redr_cycles",
         (unsigned long long)branch_redirect_cycles,
         branch_redirect_cycles * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "jump_redr_cycles",
         (unsigned long long)jump_redirect_cycles,
         jump_redirect_cycles * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "jal_redr_cycles",
         (unsigned long long)jal_redirect_cycles,
         jal_redirect_cycles * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "jalr_redr_cycles",
         (unsigned long long)jalr_redirect_cycles,
         jalr_redirect_cycles * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "wbu_redr_cycles",
         (unsigned long long)wbu_redirect_cycles,
         wbu_redirect_cycles * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "ifu_cycles",
         (unsigned long long)ifu_cycles, ifu_cycles * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "lsu_cycles",
         (unsigned long long)lsu_cycles, lsu_cycles * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "hazard_event_cnt",
         (unsigned long long)hazard_event_cnt,
         hazard_event_cnt * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "hazard_cycles",
         (unsigned long long)hazard_cycles,
         hazard_cycles * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "ihit_cnt",
         (unsigned long long)ihit_cnt, ihit_cnt * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "imiss_cnt",
         (unsigned long long)imiss_cnt, imiss_cnt * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "ihit_lat_cycles",
         (unsigned long long)ihit_lat_cycles,
         ihit_lat_cycles * total_cycle_percent);
  printf("| %-20s | %10llu (%6.2f%%) |\n", "imiss_lat_cycles",
         (unsigned long long)imiss_lat_cycles,
         imiss_lat_cycles * total_cycle_percent);
  printf("+----------------------+----------------------+\n");
  printf("| %-20s | %20.2f |\n", "calc avg cycles", calc_avg);
  printf("| %-20s | %20.2f |\n", "mem avg cycles", mem_avg);
  printf("| %-20s | %20.2f |\n", "csr avg cycles", csr_avg);
  printf("| %-20s | %20.2f |\n", "br avg cycles", br_avg);
  printf("| %-20s | %20.2f |\n", "redirect avg cycles", redirect_avg);
  printf("| %-20s | %20.2f |\n", "exu_redr avg cycles", exu_redirect_avg);
  printf("| %-20s | %20.2f |\n", "jal_redr avg cycles", jal_redirect_avg);
  printf("| %-20s | %20.2f |\n", "jalr_redr avg cycles", jalr_redirect_avg);
  printf("| %-20s | %20.2f |\n", "wbu_redr avg cycles", wbu_redirect_avg);
  printf("| %-20s | %20.2f |\n", "ifu avg cycles", ifu_avg);
  printf("| %-20s | %20.2f |\n", "lsu avg cycles", lsu_avg);
  printf("| %-20s | %20.2f |\n", "ihit avg cycles", ihit_avg);
  printf("| %-20s | %20.2f |\n", "imiss avg cycles", imiss_avg);
  printf("| %-20s | %19.2f%% |\n", "imiss rate", imiss_rate * 100.0);
  printf("| %-20s | %20.2f |\n", "icache AMAT", amat);
  printf("+----------------------+----------------------+\n");
}
#endif
