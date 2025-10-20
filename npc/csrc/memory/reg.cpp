#include "../include/common.h"
#include "../include/reg.h"
#include "../include/switch.h"

#ifdef CONFIG_YSYXSOC
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull.h"
extern VysyxSoCFull *top;
#define pc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc
#define diff_pc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__diff_pc
#define gpr top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__regs
#define mtvec top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mtvec
#define mepc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mepc
#define mstatus top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mstatus
#define mvendorid top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mvendorid
#define marchid top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__marchid
#else
#include "Vysyx_25020037_npc___024root.h"
#include "Vysyx_25020037_npc.h"
extern Vysyx_25020037_npc *top;
#define pc top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__pc
#define diff_pc top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__diff_pc
#define gpr top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__regs
#define mtvec top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__gpr_cpu__DOT__mtvec
#define mepc top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__gpr_cpu__DOT__mepc
#define mstatus top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__gpr_cpu__DOT__mstatus
#endif

void isa_reg_display(){
#ifdef CONFIG_DIFFTEST
    printf("pc\t\t0x%08x\n", diff_pc);
#else
    printf("pc\t\t0x%08x\n", pc);
#endif
    for(int reg = 0; reg < 16; reg++){
        printf("%s\t\t0x%08x\n", tempregs[reg], gpr[reg]);
    }
#ifdef CONFIG_PCSRS
    printf("mtvec\t\t0x%08x\n", mtvec);
    printf("mepc\t\t0x%08x\n", mepc);
    printf("mstatus\t\t0x%08x\n", mstatus);
    printf("mcause\t\t0x%08x\n", mcause);
    printf("mvendorid\t0x%08x\n", mvendorid);
    printf("marchid\t\t0x%08x\n", marchid);
#endif
}