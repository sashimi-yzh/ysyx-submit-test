#include "difftest.h"
#include "pmem.h"
#include <assert.h>
#include <dlfcn.h>

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n,
                            bool direction) = nullptr;
void (*ref_difftest_regcpy)(void *dut, void *pc, bool direction) = nullptr;
void (*ref_difftest_exec)(uint64_t n) = nullptr;
void (*ref_difftest_raise_intr)(uint64_t NO) = nullptr;

void init_difftest(const char *ref_so_file, int img_size) {
  assert(ref_so_file != nullptr);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  int *regs_num = (int *)dlsym(handle, "regs_num");
  assert(regs_num);
  *regs_num = REGS_NUM;

  ref_difftest_memcpy =
      (void (*)(paddr_t, void *, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy =
      (void (*)(void *, void *, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr =
      (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) =
      (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  ref_difftest_init(0);
  ref_difftest_memcpy(0x30000000, flash, img_size, DIFFTEST_TO_REF);
}