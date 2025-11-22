#include "../include/common.h"
#include "../include/utils.h"
#include "../include/debug.h"
#include "../include/macro.h"
#include "../include/conf.h"
#include "../include/paddr.h"
#include "../include/difftest.h"
#include "../include/watchpoint.h"
#include "svdpi.h"
#include "verilated_vcd_c.h"

#ifdef YSYXSOC
#include "VysyxSoCFull.h"
#include "VysyxSoCFull__Dpi.h"
#include "../obj_dir/VysyxSoCFull___024root.h"
extern VysyxSoCFull *top;
#else
#include "Vysyx_25010030_npc.h"
#include "Vysyx_25010030_npc__Dpi.h"
#include "../obj_dir/Vysyx_25010030_npc___024root.h"
extern Vysyx_25010030_npc *top;
#endif

#ifdef NVBOARD
#include <nvboard.h>
#endif
/********extern functions or variables********/

extern void single_cycle(void);
// extern NPCState npc_state;
extern VerilatedVcdC *tfp;
// extern vluint64_t main_time;
extern void die();
extern word_t expr(char *e);

// #ifdef CONFIG_ITRACE 
extern void append_iringbuf(char *s);
extern void display_iringbuf(void);
// #endif

#ifdef CONFIG_DIFFTEST
extern void difftest_step(vaddr_t pc, vaddr_t npc);
extern void difftest_skip_ref();
// extern void update_cpu_state(CPU_state *cpu);
// extern void (*ref_difftest_regcpy)(void *dut, bool direction);
#endif

// extern vluint64_t main_time;
int run_time = 0;
#define start_time 10
bool once = false;
/*********************************************/

/*********** FUNC_TRACE ***********/
#define MAX_FTRACE_SIZE 1000

typedef struct {
  uint32_t addr;  // 函数地址
  uint32_t size;  // 函数大小
  char name[64];  // 函数名
} func_symbol_t;
extern int func_count;
extern func_symbol_t func_table[];

typedef struct{
  vaddr_t pc;//函数调用地址
  const char *name;//函数名
  vaddr_t back;//返回地址
}ftrace_info;

static ftrace_info ftrace[MAX_FTRACE_SIZE];
static int ftrace_size=0;//当前调用栈深度

typedef struct {
  const char *name;
  uint64_t call_count;
} func_call_stats_t;

static func_call_stats_t func_call_stats[MAX_FTRACE_SIZE];
static int func_call_stats_size = 0;

void ftrace_call(vaddr_t pc,const char *name,vaddr_t back,vaddr_t dnpc){
  if(ftrace_size>=MAX_FTRACE_SIZE){
    printf("Call stack overflow!\n");
    return;
  }

  // 查找或创建函数调用统计记录
  int index = -1;
  for (int i = 0; i < func_call_stats_size; i++) {
    if (strcmp(func_call_stats[i].name, name) == 0) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    index = func_call_stats_size++;
    func_call_stats[index].name = name;
    func_call_stats[index].call_count = 0;
  }
  // 增加调用次数
  func_call_stats[index].call_count++;
  
  // 输出调用信息
  printf("0x%x: ",pc);
  for(int i=0;i<ftrace_size;i++){
    printf(" | "); // 缩进
  }
  printf("call [%s @ 0x%08x]\n",name,dnpc);
  // printf("call [0x%x]\n",back);
  // 压栈
  ftrace[ftrace_size].pc=pc;
  ftrace[ftrace_size].name=name;
  ftrace[ftrace_size].back=back;
  ftrace_size++;
}

void ftrace_ret(vaddr_t pc,const char *name){
  if(ftrace_size <= 0){
    printf("Call stack underflow!\n");
    return;
  }

  ftrace_size--;
  // 输出返回信息
  printf("0x%x: ",pc);
  for (int i = 0; i < ftrace_size; i++) {
    printf(" | "); // 缩进
  }
  printf("ret  [%s]\n", name);
}

const char *get_func_name(vaddr_t addr){
  for(int i=0;i<func_count;i++){
    if(addr>=func_table[i].addr && addr<func_table[i].addr+func_table[i].size){// 检查给出的地址是否落在区间[Value, Value + Size)内
      return func_table[i].name;
    }
  }
  return "???"; // 未知函数
}

#ifdef CONFIG_FTRACE
static void ftrace_handle() {
    // 获取当前流水线级信号
    #ifdef YSYXSOC
    uint32_t pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__id_ex_pc;
    uint32_t instr = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__id_ex_inst;
    uint32_t opcode = instr & 0x7F;
    uint32_t target = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ex_flush_pc;
    #else
    uint32_t pc = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__IF_ID_pc;
    uint32_t instr = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__IF_ID_inst;
    uint32_t opcode = instr & 0x7F;
    uint32_t target = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__ex_flush_pc;
    #endif

    // 计算真实跳转目标
    if (opcode == 0x6F) { // JAL
        // uint32_t target = pc + imm;
        const char* name = get_func_name(target);
        ftrace_call(pc, name, pc + 4, target);
    }
    else if (opcode == 0x67) { // JALR
        // uint32_t target = (rs1_val + imm) & ~0x1;
        // if (target != pc + 4) { // 排除简单的寄存器操作
        //     const char* name = get_func_name(target);
        //     ftrace_call(pc, name, pc + 4, target);
        // }
        
        // 处理ret指令（JALR x0, x1, 0）
        if ((instr & 0xFFFFF07F) == 0x00008067) {//通过掩码提取指令的x1（rs1）和x0(rd)，0(imm)
            if (ftrace_size > 0) {
                ftrace_ret(pc, ftrace[ftrace_size-1].name);
            }
        }
    }
}
#endif

/*********** FTRACE END ***********/

#define MAX_INST_TO_PRINT 20
static uint64_t g_nr_guest_inst = 0;
static bool g_print_step = false;
IFDEF(CONFIG_ITRACE,char logbuf[128]);

static struct {
    word_t pc;
    word_t next_pc;
    word_t inst;
    word_t ninst;
} PCSet = {0, 0, 0, 0};

//==================================== 统计与性能计数 =============================//
uint64_t R_inst, I_inst, J_inst, B_inst, L_inst, S_inst, CSR_inst;
uint64_t ifu_get;
uint64_t lsu_get;
uint64_t exu_done;
uint64_t cycle_sum;
double lsu_ratio=0, ifu_ratio=0, exu_ratio=0;
uint64_t icache_total_access = 0;
uint64_t icache_hit = 0;
uint64_t icache_miss = 0;
static void statistic() {
    Log("total guest instructions = %lu", g_nr_guest_inst);
    uint64_t total = g_nr_guest_inst;
    printf("\033[33mIPC = %lf\033[0m\n", (double)g_nr_guest_inst / cycle_sum);
    printf("\033[33m平均每条指令执行周期: %lf\033[0m\n", (double)cycle_sum / g_nr_guest_inst);
    // printf("+----------------+------------+-----------+\n");
    // printf("| 指令类型       | 数量       | 占比 (%%)  |\n");
    // printf("+----------------+------------+-----------+\n");
    // printf("| R 类型         | %10" PRIu64 " | %7.2f %% |\n", R_inst, total ? (double)R_inst / total * 100 : 0.0);
    // printf("| I 类型         | %10" PRIu64 " | %7.2f %% |\n", I_inst, total ? (double)I_inst / total * 100 : 0.0);
    // printf("| J 类型         | %10" PRIu64 " | %7.2f %% |\n", J_inst, total ? (double)J_inst / total * 100 : 0.0);
    // printf("| L 类型         | %10" PRIu64 " | %7.2f %% |\n", L_inst, total ? (double)L_inst / total * 100 : 0.0);
    // printf("| S 类型         | %10" PRIu64 " | %7.2f %% |\n", S_inst, total ? (double)S_inst / total * 100 : 0.0);
    // printf("| B 类型         | %10" PRIu64 " | %7.2f %% |\n", B_inst, total ? (double)B_inst / total * 100 : 0.0);
    // printf("| CSR 类型       | %10" PRIu64 " | %7.2f %% |\n", CSR_inst, total ? (double)CSR_inst / total * 100 : 0.0);
    // printf("+----------------+------------+-----------+\n");
    // printf("| 总指令数       | %10" PRIu64 " | %7.2f %% |\n", (R_inst + I_inst + J_inst + L_inst + S_inst + B_inst + CSR_inst), (double)(R_inst + I_inst + J_inst + L_inst + S_inst + B_inst + CSR_inst) / total * 100);
    // printf("+----------------+------------+-----------+\n");
    // printf("+--------------------------+------------+-----------+\n");
    // printf("| iCache 统计信息          | 数量       | 占比 (%%)  |\n");
    // printf("+--------------------------+------------+-----------+\n");
    // printf("| 总访问次数               | %10" PRIu64 " |     -     |\n", icache_total_access);
    // printf("| 命中次数                 | %10" PRIu64 " | %7.2f %% |\n", 
    //        icache_hit, 
    //        icache_total_access ? (double)icache_hit / icache_total_access * 100 : 0.0);
    // printf("| 未命中次数               | %10" PRIu64 " | %7.2f %% |\n", 
    //        icache_miss, 
    //        icache_total_access ? (double)icache_miss / icache_total_access * 100 : 0.0);
    // printf("| 平均每条指令缓存访问次数 |            | %7.2f   |\n", 
    //        total ? (double)icache_total_access / total : 0.0);
    // printf("+--------------------------+------------+-----------+\n");
    // printf("+----------------+------------+----------------------+------------+\n");
    // printf("| 模块名称       | 操作总数   | 每指令操作数 (次/条) | 活跃比 (%%) |\n");
    // printf("+----------------+------------+----------------------+------------+\n");
    // printf("| IFU (取指令)   | %10" PRIu64 " |   %18.2f |  %7.2f %% |\n", 
    //        ifu_get, total ? (double)ifu_get / total : 0.0, ifu_ratio);
    // printf("| LSU (取写数据) | %10" PRIu64 " |   %18.2f |  %7.2f %% |\n", 
    //        lsu_get, total ? (double)lsu_get / total : 0.0, lsu_ratio);
    // printf("| EXU (计算完成) | %10" PRIu64 " |   %18.2f |  %7.2f %% |\n", 
    //        exu_done, total ? (double)exu_done / total : 0.0, exu_ratio);
    // printf("+----------------+------------+----------------------+------------+\n");
#ifdef CONFIG_FTRACE
  puts("");
  Log("Function call statistics:");
  for (int i = 0; i < func_call_stats_size; i++) {
    Log("  %-8s: %lu calls", func_call_stats[i].name, func_call_stats[i].call_count);
  }
#endif
}
//===============================================================================//

// static void check_resp() {
// #ifdef YSYXSOC
// #define lsu_rresp top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__axi_lsu_rresp
// #define lsu_bresp top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__axi_lsu_bresp
// #define ifu_rresp top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__axi_if_rresp
// #else
// #define lsu_rresp top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__axi_lsu_rresp
// #define lsu_bresp top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__axi_lsu_bresp
// #define ifu_rresp top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__axi_if_rresp
// // #define clint_ar_addr top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__clint_araddr
// // #define clint_ar_valid top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__clint_arvalid
// #endif
// if(lsu_rresp != 0) printf("LSU <R> CHANNEL ACCESS FAULT!\n");
// if(lsu_bresp != 0) printf("LSU <W> CHANNEL ACCESS FAULT!\n");
// if(ifu_rresp != 0) printf("IFU <R> CHANNEL ACCESS FAULT!\n");
// // if((clint_ar_addr <= 0x02000000 || clint_ar_addr >= 0x0200ffff) && clint_ar_valid) printf("CLINT <R> CHANNEL ACCESS FAULLT!\n");
// }

uint64_t last_pc;
static void trace_and_difftest();
static void execute_once() {
    #ifdef YSYXSOC
    PCSet.pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IF_ID_pc;
    PCSet.inst = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IF_ID_inst;
    // printf("pc=0x%08x | inst=0x%08x\n",PCSet.pc,PCSet.inst);
    last_pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IF_ID_pc;
    do{
      // check_resp();
      
      single_cycle();
      single_cycle();
      #ifdef NVBOARD
      nvboard_update();
      #endif
      cycle_sum++;
    } while (last_pc == top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IF_ID_pc);
    #else
    PCSet.pc = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__IF_ID_pc;
    PCSet.inst = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__IF_ID_inst;
    last_pc = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__IF_ID_pc;
    do{
      trace_and_difftest();
      // check_resp();

      single_cycle();
      single_cycle();
      cycle_sum++;
      // trace_and_difftest();
    } while (last_pc == top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__IF_ID_pc);
    #endif

    if(!top->reset) g_nr_guest_inst++;
    if(run_time <= start_time) run_time++;

#ifdef CONFIG_FTRACE
  ftrace_handle();
#endif 

    #ifdef YSYXSOC
    PCSet.next_pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IF_ID_pc;
    PCSet.ninst = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IF_ID_inst;
    #else
    PCSet.next_pc = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__IF_ID_pc;
    PCSet.ninst = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__IF_ID_inst;
    #endif
    // printf("next_pc=0x%08x | next_inst=0x%08x\n\n",PCSet.next_pc,PCSet.ninst);

#ifdef CONFIG_ITRACE
    char *p = logbuf;
    p += snprintf(p, sizeof(logbuf), "0x%08x: 0x%08x ", PCSet.pc, PCSet.inst);
    *p = '\0';
    append_iringbuf(logbuf);
#endif

}

static bool first_step = true; // 用于第一次执行时的特殊处理

static void trace_and_difftest() {
#ifdef CONFIG_ITRACE
    log_write("%s\n", logbuf);
#endif
    if (g_print_step) {
        IFDEF(CONFIG_ITRACE, puts(logbuf));
    }

#ifdef CONFIG_DIFFTEST
#ifdef YSYXSOC
    // bool wb_valid = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wb_valid;
    // vaddr_t diff_pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wb_pc;
    // vaddr_t lsu_araddr = top->rootp->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_araddr;
    // vaddr_t lsu_awaddr = top->rootp->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awaddr;
    // bool lsu_arvalid = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_axi_arvalid;
    // bool lsu_awvalid = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_axi_awvalid;

    // if((((lsu_araddr < 0x30000000) | (lsu_araddr > 0x3fffffff)) & lsu_arvalid) & 
    //    (((lsu_araddr < 0x0f000000) | (lsu_araddr > 0x0f002000)) & lsu_arvalid) & 
    //    (((lsu_araddr < 0xa0000000) | (lsu_araddr > 0xbfffffff)) & lsu_arvalid)) {difftest_skip_ref();}
    // if((((lsu_awaddr < 0x30000000) | (lsu_awaddr > 0x3fffffff)) & lsu_awvalid) & 
    //    (((lsu_awaddr < 0x0f000000) | (lsu_awaddr > 0x0f002000)) & lsu_awvalid) & 
    //    (((lsu_awaddr < 0xa0000000) | (lsu_awaddr > 0xbfffffff)) & lsu_awvalid)) {difftest_skip_ref();}
#else
    // bool if_valid = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__IF_valid;
    bool wb_valid = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__wb_valid;
    vaddr_t diff_pc = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__wb_pc;
    bool master_arvalid = top->rootp->ysyx_25010030_npc__DOT__io_master_arvalid;
    bool clint_arvalid = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__clint_arvalid;
    bool master_awvalid = top->rootp->ysyx_25010030_npc__DOT__io_master_awvalid;
    vaddr_t master_araddr = top->rootp->ysyx_25010030_npc__DOT__io_master_araddr;
    vaddr_t clint_araddr = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__clint_araddr;
    vaddr_t master_awaddr = top->rootp->ysyx_25010030_npc__DOT__io_master_awaddr;
    // vaddr_t csr_addr = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__id_wb_csr_addr1;
    // vaddr_t opcode = top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__id_ex_opcode;

    if(((master_araddr < 0x80000000) | (master_araddr > 0x90000000)) & master_arvalid) {difftest_skip_ref();}
    if(((clint_araddr  < 0x80000000) | (clint_araddr  > 0x90000000)) & clint_arvalid ) {difftest_skip_ref();}
    if(((master_awaddr < 0x80000000) | (master_awaddr > 0x90000000)) & master_awvalid) {difftest_skip_ref();}
    // if((opcode == 0x73) & (csr_addr == 0x342 || csr_addr == 0x300 || csr_addr == 0x341)) {difftest_skip_ref();} // 忽略对mepc和mstatus的R操作
#endif

    if(wb_valid){
      // if(first_step) first_step = false;
      // else difftest_step(diff_pc, diff_pc);
      difftest_step(diff_pc, diff_pc);
    }
#endif

#ifdef CONFIG_WATCHPOINTS
  WP *wp=get_wp_head();
  while(wp != NULL){
    word_t val = expr(wp->expr);
    if(val != wp->old_val){
      // printf("Watchpoint NO.%d: Expression '%s' changed from 0x%08x to 0x%08x.\n", wp->NO, wp->expr, wp->old_val, val);
      _Log("Watchpoint NO.%d: Expression" ANSI_FG_YELLOW " '%s' " ANSI_NONE "changed from"
      ANSI_FG_BLUE " 0x%08x " ANSI_NONE "to" ANSI_FG_BLUE " 0x%08x\n" ANSI_NONE,wp->NO, wp->expr, wp->old_val, val);
      npc_state.state = NPC_STOP;
      wp->old_val = val;
      //sdb_mainloop();
      break;
    }
    // wp->old_val=val;
    wp = wp->next;
  }
#endif
}

// word_t last_pc; 

static void execute(uint64_t n) {
    
    for (; n > 0; n--) {
        // last_pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IF_ID_pc;
        execute_once();
        // if(!top->reset && last_pc != top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IF_ID_pc) g_nr_guest_inst++;
        // g_nr_guest_inst++;
        // trace_and_difftest();
        if (npc_state.state != NPC_RUNNING){
            break;
        }
    }
    if(npc_state.state==NPC_END || npc_state.state==NPC_ABORT){
        IFDEF(CONFIG_MTRACE,close_mtrace());
    }
}

void cpu_exec(uint64_t n) {
    g_print_step = (n < MAX_INST_TO_PRINT);

    switch (npc_state.state) {
        case NPC_END:
        case NPC_ABORT:
            printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
            return;
        default:
            npc_state.state = NPC_RUNNING;
    }

    execute(n);

    switch (npc_state.state) {
        case NPC_RUNNING:
            npc_state.state = NPC_STOP;
            break;

        case NPC_END:
        case NPC_ABORT:
            if(npc_state.state == NPC_ABORT) IFDEF(CONFIG_ITRACE,display_iringbuf());
            Log("%s: %s at pc = 0x%08x",ANSI_FMT("NPC", ANSI_FG_YELLOW ANSI_BG_RED),
                (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
                (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
                                           ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
                npc_state.halt_pc);
                // die();
        case NPC_QUIT:
            statistic();
            // die();
    }
}