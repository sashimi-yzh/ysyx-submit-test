/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include "isa.h"
#include <elf.h>
#include "/home/jx/ysyx-workbench/nemu/src/monitor/sdb/watchpoint.h"
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
/////////////////解析elf///////////

typedef struct {
    char name[64];
    paddr_t addr;      //the function head address
    Elf32_Xword size;
} Symbol;

Symbol *symbol = NULL;  //dynamic allocate memory  or direct allocate memory (Symbol symbol[NUM])
int func_num = 0;
void parse_elf(const char *elf_file)
{
    
    if(elf_file == NULL) return;
    
    FILE *fp;
    fp = fopen(elf_file, "rb");
    
    if(fp == NULL)
    {
        printf("failed to open the elf file!\n");
        exit(0);
    }
	
    Elf32_Ehdr edhr;
	//读取elf头
    if(fread(&edhr, sizeof(Elf32_Ehdr), 1, fp) <= 0)
    {
        printf("fail to read the elf_head!\n");
        exit(0);
    }

    
    
    fseek(fp, edhr.e_shoff, SEEK_SET);

    Elf32_Shdr shdr;
    char *string_table = NULL;
    //寻找字符串表
    for(int i = 0; i < edhr.e_shnum; i++)
    {
        if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0)
        {
            printf("fail to read the shdr\n");
            exit(0);
        }
        
        if(shdr.sh_type == SHT_STRTAB)
        {
          
            string_table = malloc(shdr.sh_size);
            fseek(fp, shdr.sh_offset, SEEK_SET);
            if(fread(string_table, shdr.sh_size, 1, fp) <= 0)
            {
                printf("fail to read the strtab\n");
                exit(0);
            }
        }
    }
    
    //寻找符号表
    fseek(fp, edhr.e_shoff, SEEK_SET);
    
    for(int i = 0; i < edhr.e_shnum; i++)
    {
        if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0)
        {
            printf("fail to read the shdr\n");
            exit(0);
        }

        if(shdr.sh_type == SHT_SYMTAB)
        {
            fseek(fp, shdr.sh_offset, SEEK_SET);

            Elf32_Sym sym;

            size_t sym_count = shdr.sh_size / shdr.sh_entsize;
            symbol = malloc(sizeof(Symbol) * sym_count);
	     
            for(size_t j = 0; j < sym_count; j++)
            {
                if(fread(&sym, sizeof(Elf32_Sym), 1, fp) <= 0)
                {
                    printf("fail to read the symtab\n");
                    exit(0);
                }

                if(ELF32_ST_TYPE(sym.st_info) == STT_FUNC)
                {
                    const char *name = string_table + sym.st_name;
                    strncpy(symbol[func_num].name, name, sizeof(symbol[func_num].name) - 1);
                    symbol[func_num].addr = sym.st_value;
                    symbol[func_num].size = sym.st_size;
                    func_num++;
                }
            }
        }
    }
    fclose(fp);
    free(string_table);
}
int depth = 0;
void call(word_t pc , word_t dnpc){
	 
	int i = 0;
	for ( ;i<func_num;i++){
		if(dnpc >= symbol[i].addr && dnpc < symbol[i].addr + symbol[i].size) break;
	}
	printf("0x%08x:",pc);
	for(int j=0;j<depth;j++)printf(" ");
	depth++;
	
	printf("call [%s@0x%08x]\n",symbol[i].name,dnpc);
}
void ret(word_t pc ){
	
	int i = 0;
	for ( ;i<func_num;i++){
		if(pc >= symbol[i].addr && pc < symbol[i].addr + symbol[i].size) break;
	}
	printf("0x%08x:",pc);
	for(int j=0;j<depth;j++)printf(" ");
	depth--;
	
	printf("ret [%s@0x%08x]\n",symbol[i].name,pc);
}	
//////////////////////

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 3
#define MAX_INSTRUCTIONS 3
CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;


void device_update();


static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
  
   #ifdef CONFIG_WATCHPOINT
    for (int i = 0; i < NR_WP; i++) { 
        if (wp_pool[i].flag) { 
            bool success = false; 
            bool division_by_zero = false; 
            uint32_t tmp = expr(wp_pool[i].expr, &success,&division_by_zero);
            if (success) {
                if (tmp != wp_pool[i].old_value) { 
                    wp_pool[i].new_value = tmp;
                    nemu_state.state = NEMU_STOP; 
                    printf("watchpoint NO.%d have changed\n",i); 
                    printf("watchpoint's value from %u change to %u\n",wp_pool[i].old_value,wp_pool[i].new_value);
                    return; 
                } 
            } else { 
                printf("expr error.\n"); 
                assert(0); 
            } 
        } 
    } 
#endif
}

//环形缓冲区
///////////start///////////
typedef struct {
    char instructions[MAX_INSTRUCTIONS][100];  
    int head;  
    int tail;  
} InstructionRingBuffer;

void init_iringbuf(InstructionRingBuffer *iringbuf) {
    iringbuf->head = 0;
    iringbuf->tail = 0;
    memset(iringbuf->instructions, 0, sizeof(iringbuf->instructions));
}

void write_iringbuf(InstructionRingBuffer *iringbuf, const char *instruction) {
    
    strcpy(iringbuf->instructions[iringbuf->head], instruction);
    iringbuf->head = (iringbuf->head + 1) % MAX_INSTRUCTIONS;

    
    if (iringbuf->head == iringbuf->tail) {
        iringbuf->tail = (iringbuf->tail + 1) % MAX_INSTRUCTIONS;
    }
}

void print_iringbuf(InstructionRingBuffer *iringbuf ) {

    int i = iringbuf->tail;
    
    while (i != iringbuf->head) {
        printf("instructions : %s\n", iringbuf->instructions[i]);
        i = (i + 1) % MAX_INSTRUCTIONS;
    }
   

}

////////////end//////////////////
InstructionRingBuffer iringbuf;
//  static FILE *trace_fd = NULL;


//  void init_bincache(const char *cache_bin) {
//    trace_fd = stdout;
//    if (cache_bin != NULL) {
//      FILE *fp = fopen(cache_bin, "wb");
//      Assert(fp, "Can not open '%s'", cache_bin);
//      trace_fd = fp;
//    }
//    Log("cache bin is written to %s", cache_bin ? cache_bin : "stdout");
//  }
static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;

  isa_exec_once(s);
  cpu.pc = s->dnpc;
  
  // if(s->B_type){
  //   uint32_t pc32 = (uint32_t)pc;
  //   fwrite(&pc32, sizeof(pc32), 1, trace_fd);
  //   fwrite(&s->branchpc, sizeof(pc32), 1, trace_fd);
  //   fwrite(&s->dnpc, sizeof(s->dnpc), 1, trace_fd);
  // }
   //写入 PC 地址（32位）
   
 
#ifdef CONFIG_IRINGBUF
  char logbuf[256] = {0};  // 创建一个临时日志缓冲区
  char *pp = logbuf;
  pp += snprintf(pp, sizeof(logbuf) - (pp - logbuf), FMT_WORD ":", s->pc);
  int ilenp = s->snpc - s->pc;
  int ip;
  uint8_t *instp = (uint8_t *)&s->isa.inst.val;
  for (ip = ilenp - 1; ip >= 0; ip--) {
      pp += snprintf(pp, 4, " %02x", instp[ip]);
  }
  int ilen_maxp = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_lenp = ilen_maxp - ilenp;
  if (space_lenp < 0) space_lenp = 0;
  space_lenp = space_lenp * 3 + 1;
  memset(pp, ' ', space_lenp);
  pp += space_lenp;
   
        
#ifndef CONFIG_ISA_loongarch32r

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(pp, s->logbuf + sizeof(s->logbuf) - pp,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilenp);
      
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
  write_iringbuf(&iringbuf, logbuf);
#endif
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
   
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;
#ifndef CONFIG_ISA_loongarch32r


  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
      
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
#endif
}

static void execute(uint64_t n) {
  Decode s;
  
  for (;n > 0; n --) {
   
    exec_once(&s, cpu.pc);
   
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
        
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;
  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
      if(nemu_state.halt_ret != 0){
      	print_iringbuf(&iringbuf);  
      	} 
    case NEMU_QUIT: statistic();
  }
}
