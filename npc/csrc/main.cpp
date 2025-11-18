#include "difftest.h"
#include "disasm.h"
#include "exec.h"
#include "expr.h"
#include "ftrace.h"
#include "isa.h"
#include "nvboard.h"
#include "pmem.h"
#include "sdb.h"
#include "watchpoint.h"
#include <VysyxSoCFull.h>
#include <fstream>
#include <iostream>
#include <signal.h>
#include <vector>
#include <verilated_vcd_c.h>

using namespace std;

VerilatedVcdC *tfp = nullptr;
TOP_NAME top;

void nvboard_bind_all_pins(TOP_NAME *top);

int status = 0;
bool diff_test_on = false;

FILE *log_fp = nullptr;
extern FILE *ftrace_log;

bool close_wave = false;

void fflush_trace() {
  if (log_fp) {
    fflush(log_fp);
  }
  if (ftrace_log) {
    fflush(ftrace_log);
  }
#ifdef TRACE_WAVE
  close_wave = true;
#endif
}

void sigint_handler(int sig) {
  print_debug_info();
  print_performance_info();
#ifdef TRACE_WAVE
  close_wave = true;
#endif
}

void sigsegv_handler(int sig) {
  print_debug_info();
  print_performance_info();
  exit(-1);
}

int load_img(const string &filepath) {
  ifstream file(filepath, ios::binary);
  ASSERT(file.is_open(), "load img failed");
  file.seekg(0, ios::end);
  size_t size = file.tellg();
  file.seekg(0, ios::beg);
  file.read((char *)flash, size);
  file.close();
  cout << endl;
  cout << filepath << " size:" << size << endl;
  cout << endl;
  return size;
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  signal(SIGINT, sigint_handler);
  signal(SIGSEGV, sigsegv_handler);

  nvboard_bind_all_pins(&top);
  nvboard_init();

#ifdef TRACE_WAVE
  Verilated::traceEverOn(true);
  tfp = new VerilatedVcdC;
  top.trace(tfp, 99);
  tfp->open("waveform.vcd");
#endif

  // initial
  top.eval();

  string img;
  string ref_so;
  vector<string> elf_files;
  int size;
  for (int i = 0; i < argc; i++) {
    string tmp = argv[i];
    string option;
    int pos = 0;
    if (tmp[pos] != '-') {
      continue;
    }
    for (pos++; pos < tmp.length() && tmp[pos] != '='; pos++) {
      option.push_back(tmp[pos]);
    }
    if (option == "log") {
      log_fp = fopen(tmp.substr(pos + 1).c_str(), "w");
      ASSERT(log_fp, "open log file failed");
    } else if (option == "img") {
      img = tmp.substr(pos + 1);
      size = load_img(img);
    } else if (option == "diff_so") {
      ref_so = tmp.substr(pos + 1);
    } else if (option == "b") {
      sdb_set_batch_mode();
    } else if (option == "elf") {
      elf_files.push_back(tmp.substr(pos + 1));
    } else if (option == "ftrace-log") {
      ftrace_log = fopen(tmp.substr(pos + 1).c_str(), "w");
      ASSERT(ftrace_log, "open log file failed");
    }
  }
  // expr
  init_regex();
// disasm
#ifdef ITRACE
  init_disasm("riscv64-pc-linux-gnu");
#endif
  // init watchpoint
  init_wp_pool();

  reset();
  if (!ref_so.empty()) {
    init_difftest(ref_so.c_str(), size);
    diff_test_on = true;
  }
#ifdef FTRACE
  init_elf(elf_files);
#endif

  sdb_mainloop();
#ifdef TRACE_WAVE
  tfp->close();
#endif

  if (status || isa_reg_str2val("a0") != 0) {
    print_debug_info();
    print_total_insts_num();
    status = -1;
    cout << img << "\033[31m\tHIT BAD TRAP\033[0m" << endl;
  } else {
    cout << img << "\033[32m\tHIT GOOD TRAP\033[0m" << endl;
  }
#ifdef PRINT_PERFORMANCE_INFO
  print_performance_info();
#endif
  return status;
}