#include <verilated.h>
#include <iostream>
#include <verilated_vcd_c.h>
//#include <nvboard.h>
#include <cstdlib>
#include <cstdint>
#include <iomanip> 
#include <fmt-def.h>
#include <color.h>
#include <reg.h>
#include <unistd.h>
#include <monitor.h>
#include <libgen.h> // 引入libgen库
#include <cpu/cpu.h>
#include <inst.h>
#include <verilator.h>



#include <signal.h>
#include <execinfo.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>

static void _bt_handler(int sig) {
  void* frames[128];
  int n = backtrace(frames, 128);
  const char* name =
      sig==SIGABRT? "SIGABRT" :
      sig==SIGSEGV? "SIGSEGV" :
      sig==SIGBUS ? "SIGBUS"  :
      sig==SIGILL ? "SIGILL"  : "SIG";
  fprintf(stderr, "\n===== %s detected; backtrace (%d frames) =====\n", name, n);
  backtrace_symbols_fd(frames, n, STDERR_FILENO);
  _exit(128 + sig); // 避免再次跑析构
}
static inline void install_bt_handler() {
  signal(SIGABRT, _bt_handler);
  signal(SIGSEGV, _bt_handler);
  signal(SIGBUS,  _bt_handler);
  signal(SIGILL,  _bt_handler);
}







extern  char img[131072];

bool stop = false;
uint64_t ret_val = 0;
extern uint32_t inst_num;

void engine_start();
int is_exit_status_bad();
void stop_sim();



int main(int argc, char **argv)
{
  install_bt_handler();
	Verilated::commandArgs(argc, argv);
	init_monitor(argc, argv);
	engine_start();
	stop_sim();
	return is_exit_status_bad();
}
