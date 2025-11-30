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
#include <SDL2/SDL.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();
void checkWatchPoint();
int iringbuf_push(char *data);
void iringbuf_display();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));	//Diff-test
	IFDEF(CONFIG_WATCHPOINT, checkWatchPoint());	//运行一次扫描所有监视点
}

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE
	char iringbuf[128];
  char *p = s->logbuf;
	char *irp = iringbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
	irp += snprintf(irp, sizeof(iringbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
		irp += snprintf(irp, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
	memset(irp, ' ', space_len);
  p += space_len;
	irp += space_len;

#ifndef CONFIG_ISA_loongarch32r
	void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
	disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
		  MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
	disassemble(irp, iringbuf + sizeof(iringbuf) - irp,
			MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
	strncat(iringbuf, " \n", 3);
  iringbuf_push(iringbuf);
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
	iringbuf[0] = '\0';
#endif
#endif
}

#ifdef CONFIG_MTRACE
char mtrace_buf[1024 * 1024 * 1024] = {0};	//2M
char *mtrace_p = mtrace_buf;
FILE *mtrace_log;
#endif
#ifdef CONFIG_DTRACE
char dtrace_buf[2 * 1024 * 1024] = {0};	//2M
char *dtrace_p = dtrace_buf;
FILE *dtrace_log;
#endif
#ifdef CONFIG_ETRACE
char etrace_buf[2 * 1024 * 1024] = {0}; //2M
char *etrace_p = etrace_buf;
FILE *etrace_log;
#endif

void cpu_show_ftrace();
void audio_callback(void* userdata, uint8_t *stream, int len);

static void execute(uint64_t n) {
  Decode s;
#if (CONFIG_MTRACE || CONFIG_DTRACE || CONFIG_ETRACE)
	const char *file_path = getenv("PWD");
	if (file_path == NULL) {
		perror("getenv failed");
	}
#endif
#ifdef CONFIG_MTRACE
	char mtrace_path[128] = {0};
	//mtracelog = fopen("build/nemu-mtrace-log.txt", "w");	//Mtrace
	snprintf(mtrace_path, 128, "%s/%s", file_path, "build/nemu-mtrace-log.txt");
	mtrace_log = fopen(mtrace_path, "w");
#endif
#ifdef CONFIG_DTRACE
	char dtrace_path[128] = {0};
	//dtrace_log = fopen("build/nemu-dtrace-log.txt", "w");	//Dtrace
	snprintf(dtrace_path, 128, "%s/%s", file_path, "build/nemu-dtrace-log.txt");
	dtrace_log = fopen(dtrace_path, "w");
#endif
#ifdef CONFIG_ETRACE
	char etrace_path[128] = {0};
	snprintf(etrace_path, 128, "%s/%s", file_path, "build/nemu-etrace-log.txt");
	etrace_log = fopen(etrace_path, "w");
#endif

  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }

//  iringbuf_display();  //  IRFtrace display
	#ifdef CONFIG_MTRACE
		fprintf(mtrace_log, "%s", mtrace_buf);	//Mtrace log
		fclose(mtrace_log);
	#endif
	#ifdef CONFIG_FTRACE
		cpu_show_ftrace();  //Ftrace display
  #endif
	#ifdef CONFIG_DTRACE
		fprintf(dtrace_log, "%s", dtrace_buf);	//Dtrace log
		fclose(dtrace_log);
	#endif
	#ifdef CONFIG_ETRACE
		fprintf(etrace_log, "%s", etrace_buf);	//Etrace log
		fclose(etrace_log);
	#endif
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
	iringbuf_display();
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
			if(nemu_state.halt_ret != 0) IFDEF(CONFIG_ITRACE, iringbuf_display());//IRingBuff
      // fall through
    case NEMU_QUIT: statistic();
  }
}
