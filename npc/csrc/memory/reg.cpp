#include <my_memory.h>
#include <svdpi.h>
#include <circuit.h>

word_t gpr[REGNUM];
word_t csr[4];

void isa_reg_display();
int cnt = 0;
const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

const char *SysReg[] = {
    "mstatus", "mtvec", "mepc", "mcause"
};

void get_reg(){
#ifdef CONFIG_SOC
    // 因为GPR中的寄存器改为了14个，所以直接访问能够得到的值也是那14个的，所以需要将0号寄存器单独进行赋值
    // 后面-1是因为GPR中没有0号寄存器，因此所有的寄存器对应CPU内部时都应该-1
    gpr[0] = 0;
    for(int i = 1;i < REGNUM; i++){
        gpr[i] = cpu->rootp -> ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_ID__DOT__GPR__DOT__rf[i-1];
    }
    // if(pc == 0xa0000114 && cnt == 100){
    //     printf("pc is %08x,inst is %#x\n",pc,inst);
    //     printf("ra = %08x\n",gpr[1]);
    //     npc_trap();
    // }
    // if(pc == 0xa0000114){
    //     cnt++;
    //     printf("pc is %08x,inst is %#x\n",pc,inst);
    // }
    // if(pc >= 0xa0000000){
    //     printf("pc is %08x,inst is %#x\n",pc,inst);
    // }
    csr[0] = mstatus;
    csr[1] = mtvec;
    csr[2] = mepc;
    csr[3] = mcause;
    //0:mstatus 1:mtvec 2:mepc 3:mcause
#else
    // 因为GPR中的寄存器改为了14个，所以直接访问能够得到的值也是那14个的，所以需要将0号寄存器单独进行赋值
    gpr[0] = 0;
    for(int i = 1;i < REGNUM; i++){
        gpr[i] = cpu->rootp -> ysyx_24100006__DOT__u_ID__DOT__GPR__DOT__rf[i-1];
    }
    csr[0] = mstatus;
    csr[1] = mtvec;
    csr[2] = mepc;
    csr[3] = mcause;
    //0:mstatus 1:mtvec 2:mepc 3:mcause
#endif
}

void isa_reg_display(){
    for(int i = 0;i < REGNUM;i++){
        printf("%s = " FMT_WORD "\n",regs[i],gpr[i]);
    }
    printf("dut-mstatus = %#x\n",csr[0]);
    printf("dut-mtvec = %#x\n",csr[1]);
    printf("dut-mepc = %#x\n",csr[2]);
    printf("dut-mcause = %#x\n",csr[3]);
}

word_t isa_reg_str2val(const char *s, bool *success){
    // get_reg();
    for(int i = 0;i < REGNUM;i++){  
        if(strcmp(regs[i],s) == 0){
            *success = true;
            return gpr[i];
        }
    }
    if(strcmp("pc",s) == 0){
        *success = true;
        return pc;
    }
    *success = false;
    return 0;
}