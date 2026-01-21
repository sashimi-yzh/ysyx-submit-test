#include "../../include/common.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"
};

uint32_t get_reg(int i)
{
  return SOC_GPR[i];
}

void printf_regs()
{
  printf(ANSI_FMT("npc的寄存器状态如下:\n", ANSI_FG_MAGENTA));
  for (size_t i = 0; i < REG_NUM; i++)
  {
    printf("%s : 0x%8x\n", regs[i], get_reg(i));
  }
  printf("pc : 0x%8x\n", SOC_NPC);
}

uint32_t reg_str2val(const char *s, bool *success)
{
  *success = true;
  for (int i = 0; i < REG_NUM; i++)
  {
    char reg[5] = "$";
    strcat(reg, regs[i]);
    if (!strcmp(reg, s))
    {
      return get_reg(i);
    }
  }
  const char *reg = "$pc";
  if (!strcmp(s, reg))
    return SOC_NPC;
  *success = false;
  return 0;
}

bool isa_difftest_checkregs(CPU_state *ref)
{
  if (ref->pc != SOC_NPC) {
    Log("PC值的difftest检查不通过, 发生在pc = 0x%8x, dut: 0x%8x, ref: 0x%8x", SOC_PC, SOC_NPC, ref->pc);
    return false;
  }
  for (size_t i = 0; i < REG_NUM; i++)
  {
    if (ref->gpr[i] != get_reg(i)) {
      Log("gpr值的difftest检查不通过, 发生在pc = 0x%8x, name = %s, dut: 0x%8x, ref: 0x%8x", SOC_PC, regs[i], get_reg(i), ref->gpr[i]);
      return false;
    }
  }

  return true;
}