
// #include <isa.h>
// #include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
// #include "sdb.h"
#include "../include/watchpoint.h"
#include "../include/common.h"
#include "../include/conf.h"
#include "../include/paddr.h"
#include "../include/utils.h"
#include "../include/debug.h"
#include "../include/reg.h"

static int is_batch_mode = false;//批处理模式（省略c的键入）

/********extern functions or variables********/
extern void     cpu_exec(uint64_t n); 
extern void     regs_display(); 
extern void     init_regex();
extern word_t   single_reg_display(char *reg_name); 
extern word_t   reg_str2val(const char *s, bool *success); 
extern uint8_t* guest_to_host(paddr_t paddr);
extern word_t   host_read(void *addr, int len);
extern word_t   expr(char *e);
extern "C" void     pmem_write(paddr_t waddr,word_t wdata,int len);
extern "C" word_t   pmem_read(paddr_t raddr,int len);
extern void die();

extern void init_wp_pool();
extern WP *new_wp();
extern WP *get_wp_head();
// extern NPCState npc_state;
/*********************************************/

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);//将-1作为无符号的参数传入cpu_exec函数中，使得程序执行指令数量很大很大，程序几乎无法停止
  return 0;
}


static int cmd_q(char *args) {
  npc_state.state=NPC_QUIT;//直接改变good的值，防止其直接退出时good！=0（/src/utils/state.c）导致return出现异常
  // die();
  return -1;//只有-1的时候会在sdb_mainloop触发中断影响good
}

static int cmd_si(char *args){//自己编写的si命令，让程序单步执行N条指令后暂停执行,当N没有给出时, 缺省为1
  int N = 1; // 默认为1
  if (args != NULL && args[0] != '\0') { // 检查是否有提供参数
    N = atoi(args);
    if (N <= 0) { // 如果N不是一个正整数，则设置为默认值1
      printf("Invalid argument, using default value of 1.\n");
      N = 1;
    }
  }
  cpu_exec(N); // 执行N条指令
  printf("Executed %d instruction(s).\n", N);
  return 0;
}

static int cmd_info(char *args){
  char *arg;
  if(args!=NULL && args[0]!='\0'){
    arg=strtok(args," ");
    if(arg==NULL){
      printf("No argument provided. Please specify 'r'.\n");
    }
    if(strcmp(arg,"r")==0){
      regs_display();//打印寄存器，文件在isa/risv32/reg.c中
    }
    else if(strcmp(arg,"w")==0){
      const char *wp_state="turn off";
#ifdef CONFIG_WATCHPOINTS
      wp_state="working";
#endif
      WP *wp=get_wp_head();
      if(wp == NULL){
        printf(ANSI_FG_RED "No watchpoint set\n" ANSI_NONE);
        return 0;
      }
      printf("Current watchpoints state: ");
      printf(ANSI_FG_RED "%s\n" ANSI_NONE, wp_state);
      printf(ANSI_FG_GREEN "Watchpoint NO\t Expression\t Last Value\n" ANSI_NONE);
      while (wp != NULL) { // 打印监视点信息
        printf("%-2d\t\t %s\t\t 0x%08x\n" ANSI_NONE,
          wp->NO, wp->expr ? wp->expr : "N/A", wp->old_val);
        wp = wp->next;
     }
   }else printf("Invalid operation,please specify 'r' or 'w'.\n");
  }else printf("No argument provided. Please specify 'r'.\n");
  return 0;
}

static int cmd_x(char *args){//扫描内存
  int len;
  paddr_t addr;
  char *arg;
  
  arg = strtok(NULL, " ");// 解析第一个参数为整数N
  if (arg == NULL || sscanf(arg, "%d", &len) != 1 || len <= 0) {
    printf("Invalid number of words to display\n");
    return 0;
  }
  arg = strtok(NULL, " ");// 解析第二个参数EXPR,调用expr函数计算表达式得到内存地址
  if(arg==NULL){
    printf("Missing address expression\n");
    return 0;
  }
  if(arg[0]=='0' && (arg[1]=='x' || arg[1]=='X')){
    sscanf(arg,"%x",&addr);
  }else{
  addr=(paddr_t)expr(arg);
    if(addr==-1){
      printf("Invalid address expression,please provide a valid expression\n");
      return 0;
    }
  }
  _Log(ANSI_FG_YELLOW "Addr             Hex_Value       Dec_Value\n" ANSI_NONE);
  for(int i=0;i<len;i++){
    printf("0x%x :\t %08x\t %010u\n",addr,pmem_read(addr,4),pmem_read(addr,4));
    addr+=4;
  }
  return 0;
}

static int cmd_w(char *args){
  if(args==NULL || strlen(args)==0){
    printf("No expression provided\n");
    return 0;
  }
  char *EXPR=args;
  WP *wp = new_wp();
  if(wp == NULL) return 0;
  wp->expr = strdup(EXPR);
  if(expr(EXPR)==-1){
    free_wp(wp);
    return 0;
  }
  wp->old_val=expr(EXPR); 
  // printf("GET\n");
  return 0;
}

static int cmd_d(char *args){
  if (args==NULL || strlen(args)==0) {
    // printf("Invalid index. Please enter a valid number.\n");
    _Log(ANSI_FG_RED "Invalid index. Please enter a valid number.\n" ANSI_NONE);
    return 0;
  }
  int no=atoi(strtok(NULL," "));
  WP *wp=get_wp_head();
  while(wp!=NULL){
    if(wp->NO==no){
      free_wp(wp);
      // printf("Watchpoint NO.%d deleted.\n", no);
      _Log("Watchpoint " ANSI_FG_YELLOW "NO.%d" ANSI_NONE " deleted.\n",no);
      return 0;
    }
    wp=wp->next;
  }
  printf("Watchpoint with index %d not found.\n", no);
  return 0;
}

static int cmd_p(char *args) {
  if(args == NULL || strlen(args) == 0){
    printf("No expression provided\n");
    return 0;
  }
  word_t result =expr(args);
  printf("%s = %u\n", args, result);
  return 0;
}

static int cmd_mtrace(char *args){
#ifdef CONFIG_MTRACE
  typedef uint32_t paddr_t;
  char *arg1,*arg2,*arg3,*arg4;
  // if(args==NULL || strlen(args)<4){
  //   printf("No info provide\n");
  //   return 0;
  // }
  // if (arg1 == NULL || arg2 == NULL || arg3 == NULL || arg4 == NULL) {
  //   printf("Invalid arguments\n");
  //   return 0;
  // }
  arg1=strtok(args," ");
  arg2=strtok(NULL," ");
  arg3=strtok(NULL," ");
  arg4=strtok(NULL," ");
  paddr_t start_addr=(arg1!=NULL) ? strtoul(arg1, NULL, 16) : 0x80000000;
  paddr_t end_addr=(arg2!=NULL) ? strtoul(arg2, NULL, 16) : 0x8FFFFFFF;
  bool filter_en=(arg3!=NULL) ? atoi(arg3) : false;
  uint32_t filter_data=(arg4!=NULL) ? strtoul(arg4,NULL,16) : 0xFFFFFFFF;
  mtrace_filter_output(start_addr,end_addr,filter_en,filter_data);
  return 0;
#endif
  printf("memory trace not open\n");
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },

  /* TODO: Add more commands */
  { "si", "Let the program excute N instuctions and then suspend the excution(while the N is not given,the default value is 1)", cmd_si},
 { "info", "Print register/csr status with\"r or c\",or print the monitor status with \"w\" ",cmd_info},
  { "x", "Scan N pieces of memory base on 'EXPR' ",cmd_x},
  { "p", "Find the value of the expression 'EXPR' ",cmd_p},
  { "w", "Set watchpoint on 'EXPR',the programme will stop when it change",cmd_w},
  { "d", "Delete a watchpoint NO.n you set",cmd_d},
  { "mtrace", "使用格式:筛选起始地址 结束地址 是否筛选数据 需要筛选的数据。若不填则默认全打印",cmd_mtrace},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {//设置批处理模式
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    //批处理模式is_batch_mode
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;//cmd+strlen(cmd)指向命令的结尾，而cmd+strlen(cmd)+1指向命令后的第一个参数
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }//cmd_q不修改前直接返回-1会在这里引发报错
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();
  init_wp_pool();
}