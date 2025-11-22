/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include <memory/paddr.h>
#include <common.h>
#include "../monitor/sdb/watchpoint.h"
#include "../monitor/sdb/sdb.h"

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10
#define IRINGBUF_SIZE 16
#define MAX_FTRACE_SIZE 1000

extern void init_dtrace();
extern void close_dtrace();

/*********** INST_TRACE ***********/
typedef struct {
  vaddr_t pc;                      //指令pc
  uint32_t inst;                   //指令编码
  char logbuf[128];                //反汇编
}instInfo;

typedef struct{
  instInfo entries[IRINGBUF_SIZE]; //环形缓冲区
  int w_ptr;                       //写指针
  int r_ptr;                       //读指针
  bool full;                       //溢出检测
}Iringbuf;

static Iringbuf iringbuf;

void iringbuf_init(){
  iringbuf.w_ptr=0;
  iringbuf.r_ptr=0;
  iringbuf.full=false;
  memset(iringbuf.entries,' ',sizeof(iringbuf.entries));
}

void iringbuf_push(vaddr_t pc,uint32_t inst,char *logbuf){
  iringbuf.entries[iringbuf.w_ptr].pc = pc;
  iringbuf.entries[iringbuf.w_ptr].inst = inst;
  strncpy(iringbuf.entries[iringbuf.w_ptr].logbuf, logbuf, sizeof(iringbuf.entries[iringbuf.w_ptr].logbuf) - 1);
  iringbuf.entries[iringbuf.w_ptr].logbuf[sizeof(iringbuf.entries[iringbuf.w_ptr].logbuf) - 1] = '\0';

  iringbuf.w_ptr = (iringbuf.w_ptr + 1) % IRINGBUF_SIZE;//更新写指针
  if(iringbuf.full) iringbuf.r_ptr = (iringbuf.r_ptr + 1) % IRINGBUF_SIZE;//如果满，则更新读指针
  iringbuf.full = (iringbuf.r_ptr == iringbuf.w_ptr);//更新溢出状态
}

void iringbuf_dummy(vaddr_t error_pc){
  // printf("Recent inst\n");
  int count = iringbuf.full ? IRINGBUF_SIZE : iringbuf.w_ptr;//如果满，则输出IRINGBUF_SIZE条，否则输出w_ptr条
  for(int i = 0; i < count; i++){
    int index = (iringbuf.r_ptr + i) % IRINGBUF_SIZE;//计算当前索引
    if(iringbuf.entries[index].pc == error_pc) printf(" --> ");//检测到出错的pc并指出
    else printf("     ");
    printf("%-20s %02x %02x %02x %02x\n",
              // iringbuf.entries[index].pc,
              iringbuf.entries[index].logbuf,
              (iringbuf.entries[index].inst >> 24) & 0xff,
              (iringbuf.entries[index].inst >> 16) & 0xff,
              (iringbuf.entries[index].inst >> 8) & 0xff,
              iringbuf.entries[index].inst & 0xff);
  }
}
/*********** FUNC_TRACE ***********/
typedef struct {
  uint32_t addr;  // 函数地址
  uint32_t size;  // 函数大小
  char name[64];  // 函数名
} func_symbol_t;
extern int func_count;
extern func_symbol_t func_table[];

typedef struct{
  vaddr_t pc;//函数调用地址
  char *name;//函数名
  vaddr_t back;//返回地址
}ftrace_info;

static ftrace_info ftrace[MAX_FTRACE_SIZE];
static int ftrace_size=0;//当前调用栈深度

typedef struct {
  char *name;
  uint64_t call_count;
} func_call_stats_t;

static func_call_stats_t func_call_stats[MAX_FTRACE_SIZE];
static int func_call_stats_size = 0;

void ftrace_call(vaddr_t pc,char *name,vaddr_t back,vaddr_t dnpc){
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

void ftrace_ret(vaddr_t pc,char *name){
  if(ftrace_size <= 0){
    printf("Call stack underflow!\n");
    return;
  }
  // 检查返回地址是否匹配栈顶记录
  // if(pc!=ftrace[ftrace_size-1].back){
  //   printf("Mismatched return address! Expected 0x%08x, got 0x%08x\n",
  //          ftrace[ftrace_size-1].back,pc);
  // }
  ftrace_size--;
  // 输出返回信息
  printf("0x%x: ",pc);
  for (int i = 0; i < ftrace_size; i++) {
    printf(" | "); // 缩进
  }
  printf("ret  [%s]\n", name);
}

char *get_func_name(vaddr_t addr){
  for(int i=0;i<func_count;i++){
    if(addr>=func_table[i].addr && addr<func_table[i].addr+func_table[i].size){// 检查给出的地址是否落在区间[Value, Value + Size)内
      return func_table[i].name;
    }
  }
  return "???"; // 未知函数
}

#define BHT_SIZE 1024       // 分支历史表大小
#define GHR_SIZE 8          // 全局历史寄存器位数（记录最近 8 次分支结果）
#define BTB_SIZE 256        // 分支目标缓冲区大小

// 分支历史表条目 (2-bit 饱和计数器)
typedef struct {
  uint8_t state;        // 2-bit 状态: 00 (强不跳), 01 (弱不跳), 10 (弱跳), 11 (强跳)
  uint64_t jump_count; // 跳转次数
  uint64_t not_jump_count; // 不跳转次数
} BHT_entry;

// 分支目标缓冲区条目
typedef struct {
  vaddr_t pc;           // 分支指令的 PC（用于索引和验证）
  vaddr_t target;       // 预测的目标地址
  bool valid;           // 条目是否有效
} BTB_entry;

static BHT_entry bht[BHT_SIZE];    //分支历史表
static BTB_entry btb[BTB_SIZE];    //分支目标缓冲区
static uint8_t ghr = 0;            //全局历史（记录跳转历史）
static uint64_t bht_hits = 0;      //预测命中次数
static uint64_t bht_misses = 0;    //预测失误次数
static uint64_t btb_hits = 0;      //BTB目标地址命中次数
static uint64_t btb_misses = 0;    //BTB目标地址失误次数

// 初始化预测器
void predictor_init(){
  for(int i=0;i<BHT_SIZE;i++){
    bht[i].state = 0x1;  // 默认弱不跳
    bht[i].jump_count = 0;
    bht[i].not_jump_count = 0;
  }
  for(int i=0;i<BTB_SIZE;i++){
    btb[i].pc = 0;
    btb[i].target = 0;
    btb[i].valid = false;
  }
  ghr = 0;
  bht_hits=bht_misses=btb_hits=btb_misses=0;
}

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
#ifdef CONFIG_WATCHPOINTS
  if(CONFIG_WATCHPOINTS){
    WP *wp=get_wp_head();
    while(wp!=NULL){
      word_t val=expr(wp->expr);
      if(val!=wp->old_val){
        // printf("Watchpoint NO.%d: Expression '%s' changed from 0x%08x to 0x%08x.\n", wp->NO, wp->expr, wp->old_val, val);
        _Log("Watchpoint NO.%d: Expression" ANSI_FG_YELLOW " '%s' " ANSI_NONE "changed from"
        ANSI_FG_BLUE " 0x%08x " ANSI_NONE "to" ANSI_FG_BLUE " 0x%08x\n" ANSI_NONE,wp->NO, wp->expr, wp->old_val, val);
        nemu_state.state=NEMU_STOP;
        wp->old_val=val;
        //sdb_mainloop();
        break;
      }
      // wp->old_val=val;
      wp=wp->next;
    }
  }
#endif
}
// int cnt =0;
static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);

  // if(cnt <= 10) cnt++;
  // else{
  //   printf("pc: 0x%08x\n",s->pc);
  //   cnt = 0;
  // }

  uint32_t opcode = s->isa.inst & 0x7f;
  if(opcode == 0x0000006f || opcode == 0x00000067) {}//空转，不做任何事情
#ifdef CONFIG_BRANCH_Predictor
  // =================分支预测器逻辑===============
  // uint32_t opcode = s->isa.inst & 0x7f;
  bool is_branch = (opcode == 0x63);  //条件分支 (beq,bne等)
  bool is_jal = (opcode == 0x6f);     //无条件跳转(jal)
  bool is_jalr = (opcode == 0x67);    //间接跳转(jalr)

  if(is_branch || is_jal || is_jalr){
    //哈希.通过取模操作使得索引在有效范围内，防止越界
    uint32_t bht_idx = ((s->pc >> 2)^ghr) % BHT_SIZE;//计算BHT索引，异或ghr是为了增加随机性，将pc右移是为了忽略指令的字节对齐
    uint32_t btb_idx = (s->pc >> 2) % BTB_SIZE;//计算BTB索引

    bool jump = (s->dnpc != s->snpc);  //实际是否跳转
    bool predicted_jump = (bht[bht_idx].state >= 2);  //预测是否跳转
    vaddr_t predicted_target = btb[btb_idx].valid && btb[btb_idx].pc == s->pc 
                              ? btb[btb_idx].target : s->snpc;  //BTB预测的目标地址
    //更新预测统计
    if(predicted_jump == jump){//预测是否跳转正确
      bht_hits++;
    }else{
      bht_misses++;
    }
    if(jump && predicted_target==s->dnpc){//跳转条件下，地址预测正确
      btb_hits++;
    }else if(jump){
      btb_misses++;
    }
    //更新饱和计数器
    if(jump){
      if (bht[bht_idx].state < 3) bht[bht_idx].state++;//跳转条件下，若非强跳转，则增加状态
      bht[bht_idx].jump_count++;
    }else{
      if (bht[bht_idx].state > 0) bht[bht_idx].state--;//非跳转条件下，若非强不跳转，则减少状态
      bht[bht_idx].not_jump_count++;
    }
    //更新BTB
    if(jump){
      btb[btb_idx].pc = s->pc;
      btb[btb_idx].target = s->dnpc;
      btb[btb_idx].valid = true;
    }

    // 更新GHR（左移，记录最新结果：1表示跳转，0表示不跳转）
    ghr = (ghr << 1) | (jump ? 1 : 0);//左移为新的历史记录腾出空间同时将新的分支结果记录到ghr最低位
    ghr &= (1 << GHR_SIZE) - 1;  //截断到GHR_SIZE位。掩码（1<<GHR_SIZE）-1的二进制表示为GHR_SIZE个1

    // // 调试输出（可选）
    // #ifdef CONFIG_ITRACE
    // printf("Branch at 0x%x: %s, GHR=0x%02x, predicted %s (target 0x%x), actual %s (target 0x%x)\n",
    //        s->pc, s->logbuf, ghr, 
    //        predicted_jump ? "jump" : "not jump", predicted_target,
    //        jump ? "jump" : "not jump", s->dnpc);
    // #endif
  }
#endif

#ifdef CONFIG_FUNC_TRACE
  // ===============函数调用跟踪逻辑===============
  // uint32_t opcode = s->isa.inst & 0x7f;
  vaddr_t target=s->dnpc;
  if(opcode==0x6f){ //JAL指令（函数调用）11011 11//JALR指令11001 11
    vaddr_t ret_addr=pc+4;
    char *name=get_func_name(target);
    ftrace_call(pc,name,ret_addr,s->dnpc);
  }else if(opcode==0x67){//JALR指令11001 11
    if(s->isa.inst==0x00008067){//ret指令
      if(ftrace_size>0){//判断是否为函数返回
        ftrace_ret(pc,ftrace[ftrace_size-1].name);
      }
    }
    // if(ftrace_size>0 && target==ftrace[ftrace_size-1].back){
    //   char *name=get_func_name(target);
    //   ftrace_call(target,name,pc+4);
    // }
  }
#endif
  cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE
  // ===============指令跟踪逻辑===============
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst;
#ifdef CONFIG_ISA_x86
  for (i = 0; i < ilen; i ++) {
#else
  for (i = ilen - 1; i >= 0; i --) {
#endif
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen);

  iringbuf_push(cpu.pc,s->isa.inst,s->logbuf);
#endif
}

static void execute(uint64_t n) {
  Decode s;
  
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
  if(nemu_state.state==NEMU_END || nemu_state.state==NEMU_ABORT){
    IFDEF(CONFIG_MEMORY_TRACE,close_mtrace());
    IFDEF(CONFIG_DEVICE_TRACE,close_dtrace());
  }
  if(nemu_state.state==NEMU_ABORT){//程序出错时
    vaddr_t error_pc=cpu.pc;
    iringbuf_dummy(error_pc);
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");

#ifdef CONFIG_FUNC_TRACE
  puts("");
  Log("Function call statistics:");
  for (int i = 0; i < func_call_stats_size; i++) {
    Log("  %-20s: %" PRIu64 " calls", func_call_stats[i].name, func_call_stats[i].call_count);
  }
#endif

#ifdef CONFIG_BRANCH_Predictor
  //添加分支预测器统计
  puts("");
  Log("Branch Predictor Statistics:");
  Log("  Total direction predictions: %" PRIu64, bht_hits + bht_misses);
  Log("  Direction hits: %" PRIu64, bht_hits);
  Log("  Direction misses: %" PRIu64, bht_misses);
  if(bht_hits+bht_misses > 0){
    double direction_hit_rate = (double)bht_hits / (bht_hits+bht_misses)*100;
    Log("  Direction hit rate: %.2f%%", direction_hit_rate);
  }
  Log("  Total target predictions: %" PRIu64, btb_hits+btb_misses);
  Log("  Target hits: %" PRIu64, btb_hits);
  Log("  Target misses: %" PRIu64, btb_misses);
  if(btb_hits+btb_misses > 0){
    double target_hit_rate = (double)btb_hits / (btb_hits+btb_misses)*100;
    Log("  Target hit rate: %.2f%%", target_hit_rate);
  }
#endif
}

void assert_fail_msg() {
  isa_reg_display();
  puts("");
  isa_csr_display();
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT: case NEMU_QUIT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;iringbuf_init();predictor_init();
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT: statistic();
  }
}
