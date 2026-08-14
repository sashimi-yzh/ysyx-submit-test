#ifndef __DPIC_H__
#define __DPIC_H__

#include<common.h>

extern "C" int npc_regs(int addr);
extern "C" int npc_csrs(int addr);
extern "C" int npc_pc();
extern "C" int npc_npc();
extern "C" int npc_wbu_valid();
extern "C" int npc_inst();
extern "C" int npc_ebreak_inst();

extern "C" int npc_wbu_is_ret();
extern "C" int npc_wbu_is_call();

int get_regs(int addr);
int get_pc();
int get_npc();
int get_wbu_valid();
int get_inst();
int get_csrs(int addr);
int get_isRet();
int get_isCall();
int ebreak_inst();

#endif
