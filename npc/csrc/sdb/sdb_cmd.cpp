#include "npc.h"
#include "memory.h"
#include "util.h"

#include <cstdint>
#include <cstdio>
#include <iostream>
#include <cstring>

word_t expr(char* e, bool* success);


// continue
int cmd_c(char *args) 
{
  if (npc_stat == NPC_STOP) npc_stat = NPC_RUN;
  cpu_exec(-1);
  return 0;
}


// quit
int cmd_q(char *args) 
{
  finalize(0);
  return -1;
}


// Single step execution
int cmd_si(char* args)
{
  if (npc_stat == NPC_STOP) npc_stat = NPC_RUN;
  if (args == NULL)
    cpu_exec(1);
  else
  {
    int si_num = 0;
    if (sscanf(args, "%d", &si_num) == 1)
      cpu_exec((uint64_t)si_num);
    else
      printf("Please use \"si [N]\" to execute, N > 0.\n");
  }

  return 0;
}


// run and when pc change, stop it
uint64_t get_inst_num();

int cmd_n(char* args)
{
  if (npc_stat == NPC_STOP) npc_stat = NPC_RUN;

  uint64_t curnum = get_inst_num();
  while (get_inst_num() == curnum)
    cpu_exec(1);

  return 0; 
}


// print infomation
int cmd_info(char* args)
{
    void print_wp();

    bool exey = true;
    if (args == NULL || strlen(args) != 1)
    {
      exey = false;
      goto info_end;
    }
  
    if (*args == 'r')
      reg_print();
    else if (*args == 'w')
      print_wp();
    else
      exey = false;
  
info_end:
    if (!exey) 
    {
      printf("Please use command: \"info r\" or \"info w\".\n");
    }
    
    return 0;
}


int cmd_x(char* args)
{
    bool exey = true;
    char *str_end = args + strlen(args);
    char* arg_num = strtok(NULL, " ");
    char *arg_expr = arg_num + strlen(arg_num) + 1;
    
    if (arg_expr >= str_end) arg_expr = NULL;

    if (arg_num == NULL || arg_expr == NULL) 
    {
        exey = false;
        printf("Please use command: \"x [num] [expr]\".\n");
        return 0;
    }

    // 4 byte's num
    int x_num = 0;
    if (sscanf(arg_num, "%d", &x_num) == 0)
    {
        exey = false;
        printf("Please use command: \"x [num] [expr]\".\n");
        return 0;
    }
    
    // address  num
    bool success = false;
    paddr_t x_addr = expr(arg_expr, &success);
    if (!success)
    {
        printf("your expression have some error.\n");
        printf("Please use command: \"x [num] [expr]\".\n");
        return 0;
    }

    paddr_t endaddr = x_addr + (x_num - 1) * 4;
    if (likely(in_pmem(endaddr)))
    {
        printf("ADDR\t\tVALUE\n");
        while (x_num--)
        {
            word_t tmp = paddr_read(x_addr, 4);
            printf("0x%08x\t0x%08x\n", x_addr, tmp);
            x_addr += 4;
        }  
    }
    else 
    {
        printf("[0x%08x] Memory access out of bounds.\n", endaddr);
        return 0;
    }

    return 0;
}


int cmd_p(char* args)
{
    bool success = false;
    word_t ret = expr(args, &success);
    if (success)
      printf("answer: 0x%08x\n", ret);
    else
      printf("your expression have some error.\n");
  
    return 0;
}


// create watch point
int cmd_w(char* args)
{
  bool new_wp(const char* what, uint32_t value);
  
  bool success = false;
  word_t ret = expr(args, &success);

  if (success)
  {
    if (!new_wp(args, ret))
      printf("No more watchpoints available.\n");
  }
  else printf("your expression have some error.\n");

  return 0;
}


// delete watch point
int cmd_d(char* args)
{
  void free_wp(int num);

  int si_num = 0;
  if (args != nullptr && sscanf(args, "%d", &si_num) == 1)
    free_wp(si_num);
  else
    printf("Please use \"d [N]\" to execute, N is the number of wp.\n");

  return 0;
}


// start vcd wavefrom
int cmd_v(char* args)
{
  void start_v();
  start_v();
  return 0;
}


void pmc_init();
int cmd_csim(char* args)
{
  pmc_init();

  int cls = 4, bls = 2;
  if (args == nullptr || sscanf(args, "%d %d", &cls, &bls) != 2)
  {
    printf("Please use command: \"csim [cache sqrt num] [block ...]\".\n");
    return 0;
  }
  cachesim_run(cls, bls);

  pmc_init();
  return 0;
}