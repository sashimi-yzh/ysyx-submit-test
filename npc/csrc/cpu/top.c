
#include <cpu/cpu.h>
#ifdef CONFIG_NPC_VERILOG
#include <cpu/top.h>

Top* _top = NULL;
Top_rootp* _rootp =NULL;
Top* top() {
    if (!_top) {
        _top =  new Top{};
        _rootp = _top->rootp;
    }
    return _top;
}

void watch_top(){
    // if (!(top->ysyx_24100012_top__DOT__inst==WATCH_INST)) return;
    _top = top();
    if (!top) return;
    // if(top_pc()!=0x800013a0) return; // only watch when pc is 0x80000000
    printf(" io_halt %d ,pc %x,dnpc %x, inst: %.8x,func3 %d, imm %u, writedata: %x , writeCSR: %x,CSR: %d,alu_a: %x,alu_b: %x,aluout %x, a0 = %x,ra = %x,a%d = %x\n",
        _rootp->io_halt,
        top_pc(),
        top_dnpc(),
        _top->rootp->ysyx_24100012_top__DOT__inst,
        _top->rootp->ysyx_24100012_top__DOT__ALUSel,
        _top->rootp->ysyx_24100012_top__DOT__imm,
        _top->rootp->ysyx_24100012_top__DOT__writeData,
        _top->rootp->ysyx_24100012_top__DOT__AluOut,
        _top->rootp->ysyx_24100012_top__DOT__csrType,
        _top->rootp->ysyx_24100012_top__DOT__alu_a,
        _top->rootp->ysyx_24100012_top__DOT__alu_b,
        _top->rootp->ysyx_24100012_top__DOT__AluOut,
        top_gpr(10),
        top_gpr(1),
        14,
        top_gpr(14));
}

uint32_t top_gpr(int i) {
    if (!_top) return 0;
    if (i < 0 || i >= gpr_size) {
        printf("gpr index %d out of range\n", i);
        return 0;
    }
    return _rootp->ysyx_24100012_top__DOT__regfiles__DOT__reg_output_list[i];
}

uint32_t top_csr(int i) {
    if (!_top) return 0;
    if (i < 0 || i >= csr_size) {
        printf("csr index %d out of range\n", i);
        return 0;
    }
    return _rootp->ysyx_24100012_top__DOT__csrfiles__DOT__reg_output_list[i];
}

uint32_t top_pc() {
    if (!_top) return 0;
    return _rootp->ysyx_24100012_top__DOT__pc;
}

uint32_t top_halt(){
    if (!_top) return 0;
    return _rootp->io_halt;
}

uint32_t top_inst() {
    if (!_top) return 0;
    return _rootp->ysyx_24100012_top__DOT__inst;
}
uint32_t top_inst() {
    if (!_top) return 0;
    return _rootp->ysyx_24100012_top__DOT__inst;
}
uint32_t top_dnpc() {
    if (!_top) return 0;
    return _rootp->ysyx_24100012_top__DOT__ifu__DOT__PCIn;
}

void delete_top() {
    if (_top) {
        delete _top ;
    }
}
#endif