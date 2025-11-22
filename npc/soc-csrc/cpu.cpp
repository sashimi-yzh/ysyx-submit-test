#include "../include/common.h"
#include "../include/utils.h"
#include "../include/debug.h"
#include "../include/macro.h"
#include "../include/conf.h"
#include "../include/paddr.h"
#include "../include/difftest.h"
#include "../include/watchpoint.h"
#include "VysyxSoCFull.h"
#include "VysyxSoCFull__Dpi.h"
#include "../obj_dir/VysyxSoCFull___024root.h"
#include "svdpi.h"
#include "verilated_vcd_c.h"

/********extern functions or variables********/

extern void single_cycle(void);
// extern NPCState npc_state;
extern VysyxSoCFull *top;
extern VerilatedVcdC *tfp;
extern vluint64_t main_time;
extern void die();
extern word_t expr(char *e);
extern WP *new_wp();
extern WP *get_wp_head();

#ifdef CONFIG_ITRACE 
extern void append_iringbuf(char *s);
extern void display_iringbuf(void);
#endif

#ifdef CONFIG_DIFFTEST
extern void difftest_step(vaddr_t pc, vaddr_t npc);
extern void (*ref_difftest_regcpy)(void *dut, bool direction);
#endif

extern vluint64_t main_time;
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
    uint32_t pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc;
    uint32_t instr = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__instr;
    uint32_t opcode = instr & 0x7F;
    
    // 获取译码阶段信号
    uint32_t imm = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm;
    uint32_t rs1_val = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rs1_val;

    // 计算真实跳转目标
    if (opcode == 0x6F) { // JAL
        uint32_t target = pc + imm;
        const char* name = get_func_name(target);
        ftrace_call(pc, name, pc + 4, target);
    }
    else if (opcode == 0x67) { // JALR
        uint32_t target = (rs1_val + imm) & ~0x1;
        if (target != pc + 4) { // 排除简单的寄存器操作
            const char* name = get_func_name(target);
            ftrace_call(pc, name, pc + 4, target);
        }
        
        // 处理ret指令（JALR x0, x1, 0）
        if ((instr & 0xFFFFF07F) == 0x00008067) {
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
uint64_t total_cycles[7] = {0};
uint64_t cycle_sum;
static void statistic() {
    Log("total guest instructions = %lu", g_nr_guest_inst);
    uint64_t inst_total = g_nr_guest_inst;
    printf("\033[33mIPC = %lf\033[0m\n", (double)g_nr_guest_inst / cycle_sum);
    printf("\033[33m平均每条指令执行周期: %lf\033[0m\n", (double)cycle_sum / g_nr_guest_inst);
    uint64_t cycle_total = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__cycle_cnt;
    printf("+----------------+------------+-----------+--------------+\n");
    printf("| 指令类型       | 数量       | 占比 (%%)  | 平均周期     |\n");
    printf("+----------------+------------+-----------+--------------+\n");
    printf("| R 类型         | %10" PRIu64 " | %7.2f %% | %9.2f    |\n", R_inst, inst_total ? (double)R_inst / inst_total * 100 : 0.0, R_inst ? (double)total_cycles[0] / R_inst : 0.0);
    printf("| I 类型         | %10" PRIu64 " | %7.2f %% | %9.2f    |\n", I_inst, inst_total ? (double)I_inst / inst_total * 100 : 0.0, I_inst ? (double)total_cycles[1] / I_inst : 0.0);
    printf("| J 类型         | %10" PRIu64 " | %7.2f %% | %9.2f    |\n", J_inst, inst_total ? (double)J_inst / inst_total * 100 : 0.0, J_inst ? (double)total_cycles[2] / J_inst : 0.0);
    printf("| L 类型         | %10" PRIu64 " | %7.2f %% | %9.2f    |\n", L_inst, inst_total ? (double)L_inst / inst_total * 100 : 0.0, L_inst ? (double)total_cycles[3] / L_inst : 0.0);
    printf("| S 类型         | %10" PRIu64 " | %7.2f %% | %9.2f    |\n", S_inst, inst_total ? (double)S_inst / inst_total * 100 : 0.0, S_inst ? (double)total_cycles[4] / S_inst : 0.0);
    printf("| B 类型         | %10" PRIu64 " | %7.2f %% | %9.2f    |\n", B_inst, inst_total ? (double)B_inst / inst_total * 100 : 0.0, B_inst ? (double)total_cycles[5] / B_inst : 0.0);
    printf("| CSR 类型       | %10" PRIu64 " | %7.2f %% | %9.2f    |\n", CSR_inst, inst_total ? (double)CSR_inst / inst_total * 100 : 0.0, CSR_inst ? (double)total_cycles[6] / CSR_inst : 0.0);
    printf("+----------------+------------+-----------+--------------+\n");
    printf("| 总指令数       | %10" PRIu64 " | %7.2f %% | %9ld    |\n", (R_inst + I_inst + J_inst + L_inst + S_inst + B_inst + CSR_inst), (double)(R_inst + I_inst + J_inst + L_inst + S_inst + B_inst + CSR_inst) / inst_total * 100, cycle_sum);
    printf("+----------------+------------+-----------+--------------+\n");
    printf("+----------------+------------+----------------------+\n");
    printf("| 模块名称       | 操作总数   | 每指令操作数 (次/条) |\n");
    printf("+----------------+------------+----------------------+\n");
    printf("| IFU (取指令)   | %10" PRIu64 " |   %18.2f |\n", 
           ifu_get, inst_total ? (double)ifu_get / inst_total : 0.0);
    printf("| LSU (取数据)   | %10" PRIu64 " |   %18.2f |\n", 
           lsu_get, inst_total ? (double)lsu_get / inst_total : 0.0);
    printf("| EXU (计算完成) | %10" PRIu64 " |   %18.2f |\n", 
           exu_done, inst_total ? (double)exu_done / inst_total : 0.0);
    printf("+----------------+------------+----------------------+\n");
#ifdef CONFIG_FTRACE
  puts("");
  Log("Function call statistics:");
  for (int i = 0; i < func_call_stats_size; i++) {
    Log("  %-8s: %lu calls", func_call_stats[i].name, func_call_stats[i].call_count);
  }
#endif
}
//===============================================================================//

uint64_t last_pc;

static void execute_once() {
    PCSet.pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc;
    PCSet.inst = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__instr;
    // printf("pc=0x%08x | inst=0x%08x\n",PCSet.pc,PCSet.inst);
    last_pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc;
    do{
      single_cycle();
      cycle_sum++;
    } while (last_pc == top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc);
    if(!top->reset) g_nr_guest_inst++;

    // if(run_time <= start_time) run_time++;

#ifdef CONFIG_FTRACE
  ftrace_handle();
#endif 

    PCSet.next_pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc;
    PCSet.ninst = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__instr;
    // printf("next_pc=0x%08x | next_inst=0x%08x\n\n",PCSet.next_pc,PCSet.ninst);

#ifdef CONFIG_ITRACE
    char *p = logbuf;
    p += snprintf(p, sizeof(logbuf), "0x%08x: 0x%08x ", PCSet.pc, PCSet.inst);
    *p = '\0';
    append_iringbuf(logbuf);
#endif

}
int reset_flag = 10;
static void trace_and_difftest(){
#ifdef CONFIG_ITRACE
    log_write("%s\n",logbuf);
#endif
  if(g_print_step){
    IFDEF(CONFIG_ITRACE,puts(logbuf));
    }
#ifdef CONFIG_DIFFTEST
  if(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wb_valid && !reset_flag){
    // printf("pc=0x%08x | inst=0x%08x\n",PCSet.pc,PCSet.inst);
    // printf("next_pc=0x%08x | next_inst=0x%08x\n\n",PCSet.next_pc,PCSet.ninst);
    difftest_step(PCSet.pc,PCSet.next_pc);
  }
  else if(reset_flag > 0){
    reset_flag -= 1;
  }
  // IFDEF(CONFIG_DIFFTEST,difftest_step(PCSet.pc,PCSet.next_pc));
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
        trace_and_difftest();
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
                // regs_display();
                // die();
        case NPC_QUIT:
            statistic();
            // die();
    }
}