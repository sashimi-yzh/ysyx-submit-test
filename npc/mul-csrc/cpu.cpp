#include "../include/common.h"
#include "../include/utils.h"
#include "../include/debug.h"
#include "../include/macro.h"
#include "../include/conf.h"
#include "../include/paddr.h"
#include "../include/difftest.h"
#include "Vysyx_25010030.h"
#include "Vysyx_25010030__Dpi.h"
#include "../obj_dir/Vysyx_25010030___024root.h"
#include "svdpi.h"
#include "verilated_vcd_c.h"
// #include "../include/reg.h"

/********extern functions or variables********/

extern void single_cycle(void);
// extern NPCState npc_state;
extern Vysyx_25010030 *top;
extern VerilatedVcdC *tfp;
extern vluint64_t main_time;
extern void die();

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
    uint32_t pc = top->rootp->ysyx_25010030__DOT__pc;
    uint32_t instr = top->rootp->ysyx_25010030__DOT__instr;
    uint32_t opcode = instr & 0x7F;
    
    // 获取译码阶段信号
    uint32_t imm = top->rootp->ysyx_25010030__DOT__imm;
    uint32_t rs1_val = top->rootp->ysyx_25010030__DOT__rs1_val;

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

static void statistic() {
    Log("total guest instructions = %lu", g_nr_guest_inst);
#ifdef CONFIG_FTRACE
  puts("");
  Log("Function call statistics:");
  for (int i = 0; i < func_call_stats_size; i++) {
    Log("  %-8s: %lu calls", func_call_stats[i].name, func_call_stats[i].call_count);
  }
#endif
}

static void execute_once() {
    PCSet.pc = top->rootp->ysyx_25010030__DOT__pc;
    PCSet.inst = top->rootp->ysyx_25010030__DOT__instr;

    single_cycle();
    single_cycle(); // 执行一个时钟周期

#ifdef CONFIG_FTRACE
  ftrace_handle();
#endif 

    PCSet.next_pc = top->rootp->ysyx_25010030__DOT__pc;
    PCSet.ninst = top->rootp->ysyx_25010030__DOT__instr;

#ifdef CONFIG_ITRACE
    char *p = logbuf;
    p += snprintf(p, sizeof(logbuf), "0x%08x: 0x%08x ", PCSet.pc, PCSet.inst);
    *p = '\0';
    append_iringbuf(logbuf);
#endif

}

static void trace_and_difftest(){
  #ifdef CONFIG_ITRACE
    log_write("%s\n",logbuf);
  #endif
  if(g_print_step){
    IFDEF(CONFIG_ITRACE,puts(logbuf));
  }
  #ifdef CONFIG_DIFFTEST
  if(top->rootp->ysyx_25010030__DOT__wb_valid){
    // printf("pc=0x%08x | inst=0x%08x\n",PCSet.pc,PCSet.inst);
    // printf("next_pc=0x%08x | next_inst=0x%08x\n\n",PCSet.next_pc,PCSet.ninst);
    difftest_step(PCSet.pc,PCSet.next_pc);
  }
  // IFDEF(CONFIG_DIFFTEST,difftest_step(PCSet.pc,PCSet.next_pc));
  #endif
  
}

static void execute(uint64_t n) {
    
    for (; n > 0; n--) {
        
        execute_once();
        g_nr_guest_inst++;
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