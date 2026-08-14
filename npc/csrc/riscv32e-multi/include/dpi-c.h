#ifndef __DPIC_H__
#define __DPIC_H__

#include<common.h>

extern "C" int npc_regs(int addr);
extern "C" int npc_csrs(int addr);
extern "C" int npc_pc();
extern "C" int npc_inst();
extern "C" int npc_ifu_state();
extern "C" long long npc_clint();

extern "C" int npc_jump_addr();
extern "C" int npc_isRet();
extern "C" int npc_isCall();

int get_regs(int addr);
int get_pc();
int get_inst();
int get_ifu_state();
int get_csrs(int addr);
int get_jump_addr();
int get_isRet();
int get_isCall();
long get_clint();

#endif
