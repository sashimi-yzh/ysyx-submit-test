#include <circuit.h>
#include <mem.h>
#include <utils.h>

uint32_t gpr[REGNUM];
uint32_t csr[4];

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"
};

void get_reg(){
    int i;
    for(i = 0; i < REAL_REGNUM; i++){
        gpr[i] = VGPR[i];
        gpr[i+16] = 0;
    }
    csr[0] = VCSR[0];
    csr[1] = VCSR[1];
    csr[2] = VCSR[2];
    csr[3] = VCSR[3];
}

void isa_reg_display() {
    for(int i = 0; i < REAL_REGNUM; i ++)
        printf("reg %s ---> 0x%x\n", regs[i], gpr[i]);
    printf("\n");
    printf("csr-mstatus   --->  0x%x\n", csr[0]);
    printf("csr-mtvec   --->  0x%x\n", csr[1]);
    printf("csr-mepc   --->  0x%x\n", csr[2]);
    printf("csr-mcause   --->  0x%x\n", csr[3]);
}

word_t isa_reg_str2val(const char *s, bool *success) {
    *success = false;
    for(int i = 0; i < REAL_REGNUM; i ++)
        if(strcmp(s, regs[i]) == 0){
            *success = true;
            return gpr[i];
        }
    printf("reg not found!\n");
    return 0;
}
