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
  for (size_t i = 0; i < REG_NUM; i++)
  {
    if (ref->gpr[i] != get_reg(i))
      return false;
  }
  if (ref->pc != SOC_NPC)
    return false;
  return true;
}