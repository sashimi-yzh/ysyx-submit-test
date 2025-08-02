#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
time_t start, end;

#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
#include <verilated.h>
#include <verilated_fst_c.h>

#include <readline/readline.h>
#include <readline/history.h>

#ifdef nvboard
#include <nvboard.h>
#endif


#include "sdb.h"
#include "memory.h"
#include "config.h"

#define NR_CMD (int)(sizeof(cmd_table) / sizeof(cmd_table[0]))

#ifdef ysyx_23060299_E_EXTENSION
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"
};
#else
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};
#endif

typedef struct {
  #ifdef ysyx_23060299_E_EXTENSION
  uint32_t gpr[16];
  #else
  uint32_t gpr[32];
  #endif
  uint32_t pc;
} riscv32_CPU_state;

extern  uint8_t     bash_mode   ;

#ifdef has_wave
extern  vluint64_t 	sim_time    ;
#endif


#ifdef ysyx_23060299_PO
vluint64_t 	clk_circle 	= 0;
vluint64_t  inst_num    = 0;
extern uint32_t idu_cal_cnt     ;
extern uint32_t idu_sw_cnt      ;
extern uint32_t idu_csr_cnt     ;
extern uint32_t idu_jump_cnt    ;
extern uint64_t ifu_sumCyc      ;
extern uint64_t lsu_sumCyc      ;
extern uint32_t lsu_times       ;
extern uint32_t icache_hit_cnt  ;
extern uint32_t icache_all_cnt  ;
#endif

#ifdef TIMEOUT_QUIT
vluint64_t 	timeout_circle_limit 	    = 0;
#define TIMEOUT_LIMIT 10000
#endif

extern  VysyxSoCFull *top 	  ;
extern  VerilatedFstC *m_trace  ;
extern  void (*ref_difftest_exec)(uint64_t n);
extern  void (*ref_difftest_regcpy)(void *dut, bool direction);
uint8_t		ebreak  =   0;

extern "C" void npc_trap(int code) {
  #ifdef ysyx_23060299_PO
    double  ipc = (double)inst_num / clk_circle ;
    printf("\033[1;35m" "\nThe IPC is %f\n" "Turn it off in config.h for more sim speed\n" "\033[0m", ipc);
    printf("\033[1;35m" "The inst_num is %ld\n""\033[0m", inst_num);
    printf("\033[1;35m" "The simulate circle is %ld\n""\033[0m", clk_circle);
    printf("\033[1;35m" "The idu_cal_cnt    is %d\n""\033[0m", idu_cal_cnt   );
    printf("\033[1;35m" "The idu_lw_cnt     is %d\n""\033[0m", lsu_times    );
    printf("\033[1;35m" "The idu_sw_cnt     is %d\n""\033[0m", idu_sw_cnt    );
    printf("\033[1;35m" "The idu_csr_cnt    is %d\n""\033[0m", idu_csr_cnt   );
    printf("\033[1;35m" "The idu_jump_cnt   is %d\n""\033[0m", idu_jump_cnt  );
    printf("\033[1;35m" "The Inst Fetch Average Cycle is %f\n""\033[0m", (double)ifu_sumCyc / icache_all_cnt  );
    printf("\033[1;35m" "The Load Average Cycle is %f\n""\033[0m", (double)lsu_sumCyc / lsu_times  );
    printf("\033[1;35m" "The ICACHE hit rate is %f%%\n""\033[0m", ((double)icache_hit_cnt / icache_all_cnt)  * 100);


    printf("\033[1;35m" "The icache_hit_cnt    is %d\n""\033[0m", icache_hit_cnt   );
    printf("\033[1;35m" "The icache_all_cnt   is %d\n""\033[0m", icache_all_cnt  );
    // printf time
    end = time(NULL);
    printf("程序运行时间：%ld 秒\n", (end - start));
  #endif
	if(code == 1) {
		printf("\33[1;32m" "HIT GOOD TRAP\n" "\33[0m");
	}
	else {
		printf("\33[1;31m" "HIT BAD TRAP\nInvalid Inst at PC=0x%08x\n", code);
	}
	ebreak		=	1;
}

extern "C" void check_access_fault(uint8_t resp, uint32_t pc) {
    resp = resp & 3 ;
    if(resp !=  0) {
      printf("check_access_fault\n");
      printf("fault PC = 0x%08x\n", pc);
      ebreak		=	1;
    }
}

void cpu_exec(uint64_t n) {
  uint8_t exec_times = 0;
  
  while(exec_times < n && (ebreak == 0)) {
    top->clock = 0;
    top->eval();

    #ifdef ysyx_23060299_PO
      if(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU__DOT__inst_commit) {
        inst_num++;
      }
      clk_circle++;
    #endif

    #ifdef TIMEOUT_QUIT
      if(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU__DOT__inst_commit) {
        timeout_circle_limit = 0;
      }
      timeout_circle_limit++;
      // printf("timeout_circle_limit = %ld\n", timeout_circle_limit);
      if(timeout_circle_limit == TIMEOUT_LIMIT)
      {
        printf("\33[1;31m" "Time out !!! \n");
        ebreak = 1;
      }
    #endif

    #ifdef has_wave
      // if(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc >= 0xa0000000  &&  top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc <=  0xa2000000)
      #ifdef SIMULATE_CIRCLE
      if(clk_circle > SIMULATE_CIRCLE)
      #endif
        m_trace->dump(sim_time++);
    #endif

    top->clock = 1;
    top->eval();


    #ifdef has_wave
      // if(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc >= 0xa0000000  &&  top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc <=  0xa2000000)
      #ifdef SIMULATE_CIRCLE
      if(clk_circle > SIMULATE_CIRCLE)
      #endif
        m_trace->dump(sim_time++);
    #endif

    #ifdef nvboard
      nvboard_update();
    #endif

    #ifdef  COMMIT_COUNTER
      if(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU__DOT__commit_counter ==  COMMIT_COUNTER) {
        printf("The clk_circle reach at the limit. \n");
        ebreak = 1;
      }
    #endif

    exec_times++;

#ifdef has_difftest
      if(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU__DOT__inst_commit) {

        // skip device
        if(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU__DOT__load_inst_diff && (
              (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__LSU__DOT__lsu_araddr >= 0x10000000  &&  top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__LSU__DOT__lsu_araddr <= 0x10000fff) //uart
          ||  (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__LSU__DOT__lsu_araddr >= 0x02000000  &&  top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__LSU__DOT__lsu_araddr <= 0x0200ffff) //clint
        )) {
          ref_difftest_exec(1);

          riscv32_CPU_state nemu;
          ref_difftest_regcpy(&nemu, 0);
          riscv32_CPU_state npc;
          npc.pc = nemu.pc;
        npc.gpr[0] = 0;
        #ifdef ysyx_23060299_E_EXTENSION
        for(uint8_t i = 1; i < 16; i++) {
        #else
        for(uint8_t i = 1; i < 32; i++) {
        #endif
          npc.gpr[i] = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__RegisterFile__DOT__reg_files[i - 1];
        }

          ref_difftest_regcpy(&npc, 1); //DIFFTEST_TO_REF

          return  ;
        }

        uint8_t i = 0;
        // diff exec once and compare
        ref_difftest_exec(1);

        riscv32_CPU_state nemu;
        ref_difftest_regcpy(&nemu, 0);

        // 对比寄存器
        #ifdef ysyx_23060299_E_EXTENSION
        for(i = 1; i < 16; i++) {
        #else
        for(i = 1; i < 32; i++) {
        #endif
          if (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__RegisterFile__DOT__reg_files[i - 1] != nemu.gpr[i]) {
            printf("\33[1;31m" "Diff info: %s Reg is not equal\n", regs[i]);
            printf("The npc %s Reg is 0x%08x\n",regs[i], top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__RegisterFile__DOT__reg_files[i - 1]);
            printf("The nemu %s Reg is 0x%08x\n",regs[i], nemu.gpr[i]);
            break;
          }
        }
        #ifdef ysyx_23060299_E_EXTENSION
        if(i != 16) {
        #else
        if(i != 32) {
        #endif
          ebreak		=	1;
          printf("ysyxsoc PC = 0x%08x\n", top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU__DOT__pc_commit);
          printf("nemu PC = 0x%08x\n", nemu.pc);
          printf("The simulate circle is %ld\n", clk_circle);
          break;
        }
      }
#endif

  }
}

static char *rl_gets()
{
  if(ebreak) {
      return NULL;
  }
  static char *line_read = NULL;

  if (line_read)
  {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read)
  {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_si(char *args)
{
  int step = 2;
  if (args == NULL)
    step = 1;
  else
    sscanf(args, "%d", &step);

  while (step != 0)
  {
    cpu_exec(1);
    if(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU__DOT__inst_commit)
      step--  ;
  }

  return 0;
}

void isa_reg_display() {
    uint8_t i;
    for(i = 0; i < 16; i++)
    {
      if(i == 0)
        printf("%s\t0x%08x\n", regs[i], 0);
      else
        printf("%s\t0x%08x\n", regs[i], top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__RegisterFile__DOT__reg_files[i - 1]);
	}
}

static int cmd_info(char *args)
{
  if (args == NULL)
    printf("No args. Please use 'r' or 'w' for the end\n");
  else if (*args == 'r')
    isa_reg_display();
//   else if (*args == 'w')
//     sdb_watchpoint_display();
  else
    printf("Unknown Command. Please use 'r' or 'w' for the end\n");
  return 0;
}

static int cmd_x(char *args)
{
  char *n = strtok(args, " ");
  char *mem_addr = strtok(NULL, "");
  int len;
  uint32_t addr;
  uint32_t value;
  sscanf(n, "%d", &len);
  sscanf(mem_addr, "%x", &addr);
  for (uint8_t i = 0; i < len; i++)
  {
    value = pmem_read(addr, 4);
    printf("0x%08x:\t0x%08x\n", addr, value);
    addr = addr + 4;
  }
  return 0;
}

static int cmd_q(char *args)
{
  return -1;
}

static struct
{
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    // {"help", "Display information about all supported commands", cmd_help},
    // {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit ysyx_23060299_NPC (Save Wave if have)", cmd_q},
    {"si", "Step the program for N circles", cmd_si},
    {"info", "Display the general registers or watch point", cmd_info},
    {"x", "Scan the momory like 'x len addr'", cmd_x}
    // {"p", "Type in the express like 'p express'", cmd_p},
    // {"d", "Delete the index of the watchpoint", cmd_d},
    // {"w", "Create a Watchpoint", cmd_w}

    /* TODO: Add more commands */

};

void sdb_mainloop()
{
  if(bash_mode) {
    // printf start timer
    start = time(NULL);
    while(ebreak == 0) {
      cpu_exec(1);
    }
  }
  for (char *str; ((str = rl_gets()) != NULL);)
  {
    
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL)
    {
      continue;
    }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end)
    {
      args = NULL;
    }

    int i;
    for (i = 0; i < NR_CMD; i++)
    {
      if (strcmp(cmd, cmd_table[i].name) == 0)
      {
        if (cmd_table[i].handler(args) < 0)
        {
          return;
        }
        break;
      }
    }

    if (i == NR_CMD)
    {
      printf("Unknown command '%s'\n", cmd);
    }
  }
}
