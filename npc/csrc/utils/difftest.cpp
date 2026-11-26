/***************************************************************************************
* NPC DiffTest 实现
* 
* 实现 DiffTest 功能，与 NEMU 作为 REF 进行对比测试
***************************************************************************************/

#include "difftest.h"
#include "log.h"
#include "../core/npc.h"
#include "../core/memory.h"
#include "../core/reg.h"
#include <dlfcn.h>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>

#ifdef ENABLE_TRACE
#include "../trace/itrace.h"
#endif

// REF API 函数指针
void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;
void (*ref_difftest_init)(int port) = NULL;

// DiffTest 状态
static bool is_difftest_enabled = false;
static bool is_skip_ref = false;

// 初始化 DiffTest
void init_difftest(const char *ref_so_file, long img_size) {
  if (ref_so_file == NULL) {
    Log("DiffTest is disabled (no REF specified)");
    return;
  }
  
  // 加载动态库
  void *handle = dlopen(ref_so_file, RTLD_LAZY);
  if (!handle) {
    Log("ERROR: Cannot load REF shared object: %s", dlerror());
    printf("ERROR: Cannot load REF shared object: %s\n", dlerror());
    return;
  }
  
  // 解析符号
  ref_difftest_memcpy = (void (*)(uint32_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);
  
  ref_difftest_regcpy = (void (*)(void*, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);
  
  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);
  
  ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);
  
  ref_difftest_init = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);
  
  // 初始化 REF
  ref_difftest_init(1234);
  
  if (img_size < 0 || img_size > MAX_IMG_SIZE) {
    Log("ERROR: invalid image size for difftest: %ld (MAX_IMG_SIZE=%d)", img_size, MAX_IMG_SIZE);
    printf("ERROR: invalid image size for difftest: %ld (MAX_IMG_SIZE=%d)\n", img_size, MAX_IMG_SIZE);
    return;
  }

  uint32_t sync_size = (uint32_t)img_size;
#ifdef SOC_MODE
  ref_difftest_memcpy(FLASH_BASE, get_flash_buffer(), sync_size, DIFFTEST_TO_REF);
#else
  ref_difftest_memcpy(PMEM_BASE, get_pmem_buffer(), sync_size, DIFFTEST_TO_REF);
#endif

  // 同步寄存器
  DiffTestState dut_state;
  memset(&dut_state, 0, sizeof(dut_state));
  const int gpr_num = sizeof(dut_state.gpr) / sizeof(dut_state.gpr[0]);
  for (int i = 0; i < gpr_num; i++) {
    dut_state.gpr[i] = npc_get_reg(i);
  }
  dut_state.pc = npc_get_pc();
  ref_difftest_regcpy(&dut_state, DIFFTEST_TO_REF);
  
  is_difftest_enabled = true;
  
  Log("Differential testing: %s", "ON");
  Log("The result of every instruction will be compared with NEMU.");
  printf("\n");
  printf("========================================\n");
  printf("  DiffTest: ON\n");
  printf("  REF: %s\n", ref_so_file);
  printf("========================================\n");
  printf("\n");
}

// 跳过 REF 的执行 (extern "C": 供 ysyx_26020070.v 的 DPI-C 直接调用)
extern "C" void difftest_skip_ref() {
  if (!is_difftest_enabled) return;
  is_skip_ref = true;
}

// 检查单个寄存器
bool difftest_check_reg(const char *name, uint32_t pc, uint32_t ref, uint32_t dut) {
  if (ref != dut) {
    LogError("%s is different after executing instruction at pc = 0x%08x, "
             "right = 0x%08x, wrong = 0x%08x, diff = 0x%08x",
             name, pc, ref, dut, ref ^ dut);
    const char *red = log_color_enabled() ? ANSI_FG_RED : "";
    const char *reset = log_color_enabled() ? ANSI_NONE : "";
    printf("%s", red);
    printf("\n");
    printf("========================================\n");
    printf("  DiffTest Failed!\n");
    printf("========================================\n");
    printf("%s is different after executing instruction at pc = 0x%08x\n", name, pc);
    printf("  REF (right) = 0x%08x\n", ref);
    printf("  DUT (wrong) = 0x%08x\n", dut);
    printf("  diff        = 0x%08x\n", ref ^ dut);
    printf("========================================\n");
    printf("%s", reset);
    printf("\n");
    return false;
  }
  return true;
}

// 检查所有寄存器
static bool checkregs(DiffTestState *ref, uint32_t pc) {
  if (!difftest_check_reg("pc", pc, ref->pc, npc_get_pc())) {
    return false;
  }

  static const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  };

  for (int i = 0; i < 16; i++) {
    if (!difftest_check_reg(regs[i], pc, ref->gpr[i], npc_get_reg(i))) {
      return false;
    }
  }

  return true;
}

// DiffTest 单步执行
void difftest_step(uint32_t pc, uint32_t npc) {
  if (!is_difftest_enabled) return;
  
  DiffTestState ref_state;
  
  // 如果需要跳过 REF
  if (is_skip_ref) {
    // 将 DUT 的状态同步到 REF
    const int gpr_num = sizeof(ref_state.gpr) / sizeof(ref_state.gpr[0]);
    for (int i = 0; i < gpr_num; i++) {
      ref_state.gpr[i] = npc_get_reg(i);
    }
    ref_state.pc = npc_get_pc();
    ref_difftest_regcpy(&ref_state, DIFFTEST_TO_REF);
    is_skip_ref = false;
    return;
  }
  
  // 让 REF 执行一条指令
  ref_difftest_exec(1);
  
  // 获取 REF 的状态
  ref_difftest_regcpy(&ref_state, DIFFTEST_TO_DUT);
  
  // 对比寄存器
  if (!checkregs(&ref_state, pc)) {
    LogError("DiffTest failed at pc = 0x%08x", pc);
    const char *red = log_color_enabled() ? ANSI_FG_RED : "";
    const char *reset = log_color_enabled() ? ANSI_NONE : "";
    printf("%s\nDiffTest failed! Program aborted.%s\n", red, reset);
    npc_dump_snapshot();
    log_flush();
    exit(1);
  }
}

