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

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <dlfcn.h>
#include <capstone/capstone.h>
#include <assert.h>

#include "tpdef.h"
#include "util.h"

typedef cs_err (*pcs_open)(cs_arch arch, cs_mode mode, csh *handle);
typedef size_t (*pcs_disasm)(csh handle, const uint8_t *code,
  size_t code_size, uint64_t address, size_t count, cs_insn **insn);
typedef void (*pcs_free)(cs_insn *insn, size_t count);

static pcs_disasm cs_disasm_dl = nullptr;
static pcs_free cs_free_dl = nullptr;

static csh handle;

void init_disasm()
{
  char path[512];
  const char *npc_home = getenv("NPC_HOME");
  assert(npc_home);
  
  snprintf(path, sizeof(path), "%s/libcapstone.so.5", npc_home);

  void *dl_handle = dlopen(path, RTLD_LAZY);
  assert(dl_handle);

  pcs_open cs_open_dl= nullptr;
  cs_open_dl = (pcs_open)dlsym(dl_handle, "cs_open");
  assert(cs_open_dl);

  cs_disasm_dl = (pcs_disasm)dlsym(dl_handle, "cs_disasm");
  assert(cs_disasm_dl);

  cs_free_dl = (pcs_free)dlsym(dl_handle, "cs_free");
  assert(cs_free_dl);

  cs_arch arch = CS_ARCH_RISCV;
  cs_mode mode = CS_MODE_RISCV32;
	int ret = cs_open_dl(arch, mode, &handle);
  assert(ret == CS_ERR_OK);
}


void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) 
{
	cs_insn *insn;
	size_t count = cs_disasm_dl(handle, code, nbyte, pc, 0, &insn);
  if (count != 1) 
  {
    printf(ANSI_FMT("disassemble failed >: pc = %08x;  inst = %08x;\n", ANSI_FG_RED), (uint32_t)pc, *((uint32_t*)code));
    finalize(5);
  }
  
  int ret = snprintf(str, size, "%s", insn->mnemonic);
  if (insn->op_str[0] != '\0')
    snprintf(str + ret, size - ret, "\t%s", insn->op_str);
  
  cs_free_dl(insn, count);
}
