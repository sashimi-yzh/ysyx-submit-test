/***************************************************************************************
* NPC Performance Counter
* 性能计数器: 接收 RTL 通过 DPI-C 上报的性能事件, 在仿真结束时打印性能报告.
* 注意: 事件编号必须与 npc/vsrc/top.v 中 PERF_* localparam 保持一致.
***************************************************************************************/

#ifndef __PERF_H__
#define __PERF_H__

#include <cstdint>

enum PerfEventId {
    PERF_COMMIT       = 0,   // 提交(动态)指令数
    PERF_IF_FETCH     = 1,   // IFU 取到指令
    PERF_IF_STALL_BUS = 2,   // IFU 等 ICache 接收请求
    PERF_IF_STALL_MEM = 3,   // IFU 等 ICache 返回指令
    PERF_LD_DONE      = 4,   // LSU 取到数据 (load 完成)
    PERF_ST_DONE      = 5,   // LSU 完成 store
    PERF_LD_WAIT      = 6,   // load 等待数据周期数 (统计平均访存延迟)
    PERF_ALU          = 7,   // 计算类指令 (R型/I型算术逻辑)
    PERF_LOAD         = 8,   // load 类指令
    PERF_STORE        = 9,   // store 类指令
    PERF_BRANCH       = 10,  // 分支指令
    PERF_JUMP         = 11,  // 跳转指令
    PERF_UPPER        = 12,  // lui/auipc
    PERF_CSR          = 13,  // CSR 指令
    PERF_ECALL        = 14,  // ecall
    PERF_MRET         = 15,  // mret
    PERF_EBREAK       = 16,  // ebreak
    PERF_IC_ACCESS    = 17,  // ICache 取指请求数
    PERF_IC_HIT       = 18,  // ICache 命中数
    PERF_IC_MISS      = 19,  // ICache 缺失数
    PERF_IC_REFILL    = 20,  // ICache 缺失时发起的总线 AR 数
    PERF_IC_BYPASS_AR = 21,  // ICache 非缓存旁路发起的总线 AR 数
    PERF_LSU_AR       = 22,  // LSU 发起的总线 AR 数
    PERF_IF_BYPASS    = 23,  // 非缓存地址直连取指数
    PERF_BRANCH_TAKEN = 24,  // 条件分支 taken
    PERF_BRANCH_NOT_TAKEN = 25, // 条件分支 not taken
    PERF_JAL          = 26,  // jal
    PERF_JALR         = 27,  // jalr
    PERF_LD_BYTE      = 28,  // load byte
    PERF_LD_HALF      = 29,  // load half
    PERF_LD_WORD      = 30,  // load word
    PERF_ST_BYTE      = 31,  // store byte
    PERF_ST_HALF      = 32,  // store half
    PERF_ST_WORD      = 33,  // store word
    PERF_BUS_AR       = 34,  // 总线 AR 握手数
    PERF_BUS_R        = 35,  // 总线 R 握手数
    PERF_BUS_AW       = 36,  // 总线 AW 握手数
    PERF_BUS_W        = 37,  // 总线 W 握手数
    PERF_BUS_B        = 38,  // 总线 B 握手数
    PERF_BUS_AR_STALL = 39,  // AR 有效但未 ready 的周期数
    PERF_IC_COMPULSORY = 40, // ICache 强制缺失 (目标块原先无效)
    PERF_IC_REPLACE   = 41,  // ICache 替换缺失 (目标块原先有效)
    PERF_ALU_R        = 42,  // R 型 ALU 指令
    PERF_ALU_I        = 43,  // I 型 ALU 指令
    PERF_CSRRW        = 44,  // csrrw
    PERF_CSRRS        = 45,  // csrrs
    PERF_ST_WAIT      = 46,  // store 等待完成周期数 (统计平均 store 延迟)
    PERF_FENCE_I      = 47,  // fence.i
    PERF_EVENT_COUNT
};

void perf_report();
void perf_log_open(const char *path);
void perf_log_close();

#ifdef __cplusplus
extern "C" {
#endif
int perf_delay_acc_step();
#ifdef __cplusplus
}
#endif

#endif
