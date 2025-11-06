#include <common.h>
#include <circuit.h>

extern "C" void get_inst(int instruction){
	inst = instruction;
    // if(inst != 0){
    //     printf("inst is %x\n",inst);
    // }
}
extern "C" void get_pc(int pc_sim){
    prev_pc = pc_sim;
	pc = pc_sim;
    // if(pc != 0){
    //     printf("pc is %x\t",pc);
    // }
}
extern "C" void get_npc(int npc_sim){
	dnpc = npc_sim;
}
extern "C" void get_PCW(svBit PCW_sim){
	PCW = PCW_sim;
}
extern "C" void get_if_valid(svBit if_valid_sim){
    // printf("if_valid_dpi is %d\n",if_valid_sim);
	if_valid = if_valid_sim;
}
extern "C" void get_wb_ready(svBit wb_ready_sim){
	wb_ready = wb_ready_sim;
}

extern "C" void get_pc_w(int pc_w_sim){
    pc_w = pc_w_sim;
}
extern "C" void get_npc_w(int npc_w_sim){
    npc_w = npc_w_sim;
}

extern "C" void get_csr(int mstatus_sim, int mtvec_sim, int mcause_sim, int mepc_sim){
    mtvec   = mtvec_sim;
    mepc    = mepc_sim;
    mcause  = mcause_sim;
    mstatus =mstatus_sim;
}

// extern "C" void get_gpr(const svOpenArrayHandle rf){
//     // 获取数组指针
//     uint32_t *arr = (uint32_t *)svGetArrayPtr(rf);
//     if(arr == NULL){
//         assert(0);
//     }
//     for(int i = 0; i<REGNUM;i++){
//         printf("gpr[%d] is %x\n",i,arr[i]);
//     }
//     // 写入 gpr[0..31]
//     for (int i = 0; i < REGNUM; i++) {
//         gpr[i] = arr[i];
//     }
// }

// extern "C" void get_csr(const svOpenArrayHandle rf){
//     printf("a\n");
//     // 获取数组指针
//     uint32_t *arr = (uint32_t *)svGetArrayPtr(rf);
//     // 写入 csr[0..3]
//     for (int i = 0; i < 4; i++) {
//         csr[i] = arr[i];
//     }
// }