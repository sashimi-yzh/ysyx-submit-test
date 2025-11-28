/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NPC is licensed under Mulan PSL v2.
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

#include <dlfcn.h>
#include <isa.h>
#include <cpu/cpu.h>
#include <cpu/top.h>
#include <utils.h>
#include <npc.h>
#include <memory.h>
#include <cpu/top.h>
#include <cpu/difftest.h>

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

#ifdef CONFIG_DIFFTEST
extern CPU_state cpu;
typedef struct {
    word_t gpr[16];
    word_t pc;
    paddr_t mem_addr;
    word_t  mem_data;
    bool    mem_fcn;
    bool    mem_enable;
}diff_context;

bool mem_data_equal(uint32_t ref, uint32_t dut, uint32_t typ){
  // printf("hf  ref %x  dut %x  %d\n",((uint16_t)ref), ((uint16_t)dut),((uint16_t)ref) == ((uint16_t)dut));
  // printf("bit ref %x  dut %x %d\n",((uint8_t)ref), ((uint8_t)dut), ((uint8_t)ref) == ((uint8_t)dut));
  if (typ == MT_X ) return true;
  else if (typ == MT_W || typ == MT_WU) return ref == dut;
  else if (typ == MT_H || typ == MT_HU) return ((uint16_t)ref) == ((uint16_t)dut);
  else if (typ == MT_B || typ == MT_BU) return ((uint8_t)ref) == ((uint8_t)dut);

  return false;
}

bool isa_difftest_checkregs(diff_context *ref_r, vaddr_t pc) {
  if (ref_r->pc != cpu.pc ){
    printf("checkreg pc, ref %.8x, top %.8x \n",ref_r->pc,cpu.pc);
    return false;
  }
  for (int i=0;i<gpr_size;i++){
     if(ref_r->gpr[i]!=cpu.gpr[i]) {
        printf("checkreg x%d, ref %.8x, top %.8x \n",i,ref_r->gpr[i],cpu.gpr[i]);
        return false;
     }
  }  
  // mem_access_t mem = top_lsu_state();
  // if (ref_r->mem_addr != mem.addr ||
  //     !mem_data_equal(ref_r->mem_data,mem.data,mem.typ)  ){
  //       printf("mem_access_addr, ref %.8x, top %.8x \n",ref_r->mem_addr,mem.addr);
  //       printf("mem_access_data, ref %.8x, top %.8x \n",ref_r->mem_data,mem.data);
  //       return false;}      
  return true;
}

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;
// extern char* regs[];
// this is used to let ref skip instructions which
// can not produce consistent behavior with NPC

void difftest_skip_ref() {
  is_skip_ref = true;
  // If such an instruction is one of the instruction packing in QEMU
  // (see below), we end the process of catching up with QEMU's pc to
  // keep the consistent behavior in our best.
  // Note that this is still not perfect: if the packed instructions
  // already write some memory, and the incoming instruction in NPC
  // will load that memory, we will encounter false negative. But such
  // situation is infrequent.
  skip_dut_nr_inst = 0;
}

// this is used to deal with instruction packing in QEMU.
// Sometimes letting QEMU step once will execute multiple instructions.
// We should skip checking until NPC's pc catches up with QEMU's pc.
// The semantic is
//   Let REF run `nr_ref` instructions first.
//   We expect that DUT will catch up with REF within `nr_dut` instructions.
void difftest_skip_dut(int nr_ref, int nr_dut) {
  skip_dut_nr_inst += nr_dut;

  while (nr_ref -- > 0) {
    ref_difftest_exec(1);
  }
}

void memory_access_skip_ref(){
  mem_access_t lsu_state = top_lsu_state();
  IFDEF(CONFIG_HAS_UART,is_skip_ref = is_skip_ref || in_uart(lsu_state.addr) );
}

void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void *handle;
  printf("ref_so_file %s\n",ref_so_file);
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(paddr_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void*, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(CONFIG_MBASE, guest_to_host(CONFIG_MBASE), img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

void ref_reg_display(){
  diff_context ref_r;
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
  printf("ref register: \n");
    for (int i=0;i<gpr_size;i++){
        printf("%4s:%.8x",regs[i],ref_r.gpr[i]);
        (i%3==0)?printf("\n"):printf(" ");
    }
  printf("%4s:%.8x\n","pc",ref_r.pc);
}

static void checkregs(diff_context *ref, vaddr_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    isa_reg_display();
    ref_reg_display();
  }
}

void difftest_step(vaddr_t pc, vaddr_t pc_next) {
  diff_context ref_r;
 
  if (skip_dut_nr_inst > 0) { 
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    if (ref_r.pc == pc_next) {
      skip_dut_nr_inst = 0;
      checkregs(&ref_r, pc_next);
      return;
    }
    skip_dut_nr_inst --;
    if (skip_dut_nr_inst == 0)
      panic("can not catch up with ref.pc = " FMT_WORD " at pc = " FMT_WORD, ref_r.pc, pc);
    return;
  }
  memory_access_skip_ref();

  if (is_skip_ref) {
    // to skip the checking of an instruction, just copy the reg state to reference design
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
    is_skip_ref = false;
    return;
  }
  bool has_bubble = false;
  IFDEF(CONFIG_PIPELINE_PC,has_bubble=top_wb_inst()==0x00004033;);
  if (pc != 0x0 && pc_next != 0x0 &&pc_next != pc ) {
    ref_difftest_exec(1);
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    checkregs(&ref_r, pc);
  }
}

#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
#endif
