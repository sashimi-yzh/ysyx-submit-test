#ifndef _COMMON_H_
#define _COMMON_H_

#include "VysyxSoCFull.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "macro.h"//宏定义函数
#include "debug.h"//Assert\Log
#include "utils.h"//Log
#include "elf.h"//Ftrace

//Macro definition
typedef MUXDEF(CONFIG_ISA64, uint64_t, uint32_t) word_t;
typedef MUXDEF(CONFIG_ISA64, int64_t, int32_t)  sword_t;
#define FMT_WORD MUXDEF(CONFIG_ISA64, "0x%016" PRIx64, "0x%08" PRIx32)
typedef word_t vaddr_t;
typedef MUXDEF(PMEM64, uint64_t, uint32_t) paddr_t;
#define FMT_PADDR MUXDEF(PMEM64, "0x%016" PRIx64, "0x%08" PRIx32)
typedef uint16_t ioaddr_t;

//Config
//#define CONFIG_TARGET_AM 0//AM
//#define CONFIG_DEVICE 1//DEVICE Software
#define ITRACE_COND 1
#define CONFIG_TARGET_NATIVE_ELF 1

#define CONFIG_SIM_FAST 1

//#define CONFIG_DUMP_WAVE 1//是否保存波形（内存不足）
//#define CONFIG_DUMP_WAVE_SIM 1//只保存状态

//#define CONFIG_TRACE 1
	//#ifdef CONFIG_TRACE
		//#define CONFIG_ITRACE 1
			//#define CONFIG_ITRACE_COND 1
			//#define CONFIG_FTRACE 1
			//#define CONFIG_MTRACE 1 
		//#define CONFIG_WATCHPOINT 1
	//#endif
//#define CONFIG_DIFFTEST 1

#define CONFIG_MBASE 0x30000000//IM
#define CONFIG_MSIZE 0x10000000
#define CONFIG_PC_RESET_OFFSET 0 //reset pc offset
#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)
//#define CONFIG_MEM_RANDOM 1
#define CONFIG_TRACE_START 0
#define CONFIG_TRACE_END 10000


//main
void cpu_exec(int n);
void isa_parser_elf(char *filename);
typedef struct {
	vaddr_t mepc;
	word_t mstatus;
	word_t mcause;
	word_t mtvec;
} riscv32_CSRs;

typedef struct {
  word_t gpr[32];
  vaddr_t pc;
	riscv32_CSRs csr;
} CPU_state;

//Imemory
uint8_t* guest_to_host(paddr_t paddr);
paddr_t host_to_guest(uint8_t *haddr);
void init_mem();
int pmem_read(int raddr);
void pmem_write(int waddr, int wdata, char wmask);
word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);
//reg DPI-C
word_t gpr_regs_display(int raddr);//抓取reg  DPI-C in RF
void isa_regs_display();
word_t isa_reg_str2val(const char *s, bool *success);
void isa_gpr_push();
word_t csrs_display(int i);
//flash init_isa dpic
void init_isa();
uint8_t* flash_to_host(paddr_t paddr);
int c_flash_read(int addr);
//psram dpic
int c_psram_read(int addr);
void c_psram_write(int addr, int data, int8_t len);

//monitor
void init_monitor(int argc, char *argv[]);
//sdb//sdb.h
void init_sdb();
void sdb_mainloop();
void sdb_set_batch_mode();
void checkWatchPoint();

/***utils**/
//log.c
void init_log(const char *log_file);
bool log_enable();
//itrace/iringbuf
extern "C" void init_disasm(const char *triple);
extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
int iringbuf_init();
int iringbuf_push(char *data);
void iringbuf_display();
//difftest
void init_difftest(char *ref_so_file, long img_size, int port);
void difftest_step(vaddr_t pc, vaddr_t npc);
void difftest_skip_ref();

#endif
