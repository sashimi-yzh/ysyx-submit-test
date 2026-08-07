/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
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

#include <capstone/capstone.h>
#include <common.h>
#include <dlfcn.h>

static size_t (*cs_disasm_dl)(csh handle, const uint8_t *code,
                              size_t code_size, uint64_t address, size_t count, cs_insn **insn);
static void (*cs_free_dl)(cs_insn *insn, size_t count);

static csh handle;

void init_disasm() {
  void *dl_handle;
  dl_handle = dlopen("tools/capstone/repo/libcapstone.so.5", RTLD_LAZY);
  assert(dl_handle);

  cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = NULL;
  cs_open_dl = dlsym(dl_handle, "cs_open");
  assert(cs_open_dl);

  cs_disasm_dl = dlsym(dl_handle, "cs_disasm");
  assert(cs_disasm_dl);

  cs_free_dl = dlsym(dl_handle, "cs_free");
  assert(cs_free_dl);

  cs_arch arch = MUXDEF(CONFIG_ISA_x86, CS_ARCH_X86,
                        MUXDEF(CONFIG_ISA_mips32, CS_ARCH_MIPS,
                               MUXDEF(CONFIG_ISA_riscv, CS_ARCH_RISCV,
                                      MUXDEF(CONFIG_ISA_loongarch32r, CS_ARCH_LOONGARCH, -1))));
  cs_mode mode = MUXDEF(CONFIG_ISA_x86, CS_MODE_32,
                        MUXDEF(CONFIG_ISA_mips32, CS_MODE_MIPS32,
                               MUXDEF(CONFIG_ISA_riscv, MUXDEF(CONFIG_ISA64, CS_MODE_RISCV64, CS_MODE_RISCV32) | CS_MODE_RISCVC,
                                      MUXDEF(CONFIG_ISA_loongarch32r, CS_MODE_LOONGARCH32, -1))));
  int ret = cs_open_dl(arch, mode, &handle);
  assert(ret == CS_ERR_OK);

#ifdef CONFIG_ISA_x86
  cs_err (*cs_option_dl)(csh handle, cs_opt_type type, size_t value) = NULL;
  cs_option_dl = dlsym(dl_handle, "cs_option");
  assert(cs_option_dl);

  ret = cs_option_dl(handle, CS_OPT_SYNTAX, CS_OPT_SYNTAX_ATT);
  assert(ret == CS_ERR_OK);
#endif
}

/**
 * @brief 将机器指令反汇编为汇编指令字符串
 *
 * 使用Capstone库将机器指令反汇编为汇编指令字符串，并将结果存储到给定的字符串中。
 *
 * @param str 存储反汇编结果的字符串指针
 * @param size 字符串str的最大容量
 * @param pc 程序计数器值
 * @param code 指向要反汇编的机器指令的指针
 * @param nbyte 要反汇编的机器指令的字节数
 */
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
  // 声明一个cs_insn类型的指针变量
  cs_insn *insn;
  // 使用Capstone库对二进制代码进行反汇编
  size_t count = cs_disasm_dl(handle, code, nbyte, pc, 0, &insn);
  // 断言反汇编结果的数量为1
  assert(count == 1);
  // 将反汇编得到的助记符写入字符串str中
  int ret = snprintf(str, size, "%s", insn->mnemonic);
  // 如果操作数不为空
  if (insn->op_str[0] != '\0') {
    // 将操作数写入字符串str中，紧跟在助记符之后
    snprintf(str + ret, size - ret, "\t%s", insn->op_str);
  }
  // 释放cs_insn结构体占用的内存
  cs_free_dl(insn, count);
}
