/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <common.h>

#include <btrace_pack.h>
#include <itrace_pack.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

void destroy_monitor();

extern bool isSoC;
extern itrace_pack_t g_itrace_pack;
extern itrace_pack_t g_mtrace_pack;
extern btrace_pack_t g_btrace_pack;
extern uint64_t g_nbranches;

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

  bool trace_inst_and_mem_pack = false;

  if (isSoC) {
    printf("exec is SoC\n");
    if (trace_inst_and_mem_pack) {
      g_itrace_pack = itrace_pack_create("itrace_pack.bin");
      g_mtrace_pack = itrace_pack_create("mtrace_pack.bin");
    }
  }
    g_btrace_pack = btrace_pack_create("btrace_pack.bin");

  /* Start engine. */
  engine_start();

#ifndef CONFIG_TARGET_AM
  destroy_monitor();
#endif

  if (isSoC) {
    if (trace_inst_and_mem_pack) {
      itrace_pack_close(g_itrace_pack);
      itrace_pack_close(g_mtrace_pack);
    }
  }
    btrace_pack_close(g_btrace_pack);

  printf("total branches: %lu\n", g_nbranches);

  return is_exit_status_bad();
}
