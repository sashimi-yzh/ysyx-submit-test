#include <common.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <paddr.h>

void cpu_exec(uint64_t n);
void npc_quit();
void delete_module();
void isa_reg_display();

bool is_batch_mode = false ;

void sdb_set_batch_mode() {
    is_batch_mode = true ;
}

void init_regex();

void init_sdb(){

    init_regex();
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args) {
  npc_quit();
  return -1;
}

static int cmd_si(char *args) {
  int n;
  char *arg = strtok(NULL, " ");
  if( arg == NULL )
    n = 1;
  else
    sscanf(arg, "%d", &n);

  cpu_exec(n);

  return 0;
}

static int cmd_info(char *args) {
  if(strcmp(args,"r") == 0)
    isa_reg_display();

  return 0;
}

static int cmd_x(char *args){
  if(args == NULL){
	printf("No args\n");
	return 0;
    }
    char* n = strtok(args," ");
    char* addr_ = strtok(NULL," ");
    int len = 0;
    paddr_t addr = 0;
    sscanf(n, "%d", &len);
    sscanf(addr_,"%x", &addr);
    for(int i = 0 ; i < len ; i ++)
    {
	printf("addr : %08x\n",psram_read(addr,4));
	addr = addr + 4;
    }	      
  return 0;
  }

word_t expr(char *e, bool *success, bool *division_by_zero);
static int cmd_p(char* args){
    if(args == NULL){
	printf("No args\n");
	return 0;
    }
    bool flag = false;
 	bool division_by_zero = false;
    uint32_t result = expr(args, &flag, &division_by_zero);
 	if(!division_by_zero){
	printf("result = %u \n",result);
	
	}
	
    return 0;
}


static int cmd_w(char *args){
  return 0;
}

static int cmd_d(char *args){
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
    { "si", "run si program", cmd_si },
    { "info", "Get info", cmd_info },
    { "x", "Scan the virtual memory", cmd_x },
    {"p","caculate expr",cmd_p},
    {"d", "delete watchpoint by num", cmd_d},
    {"w", "create watchpoint with expr", cmd_w},
    /* TODO: Add more commands */
};

#define NR_CMD ARRLEN(cmd_table)

static char* rl_gets() {
  static char* line_read = NULL ;

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

void sdb_mainloop() {
  if(is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the reamining string as the arguments,
       witch may need further parsing
    */
    char *args = cmd + strlen(cmd) + 1;
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
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

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


void engine_start() {
  //cpu_exec(-1);
   
  sdb_mainloop();
}


const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};
const char *csrs[] = {
  "mepc", "mstatus", "mcause", "mtvec"
};
#define gpr(idx) (cpu.gpr[check_reg_idx(idx)])
#define csr(idx) (cpu.csr[idx])
word_t isa_reg_str2val(const char *s, bool *success) {
    
    for(int i = 0 ; i < 32 ; i ++){
   	if(strcmp(regs[i], s) == 0){
   	
		return cpu.gpr[i];
	}
    }
    *success = false;
    return cpu.pc;
}

static inline bool difftest_check_reg(const char *name, vaddr_t pc, word_t ref, word_t dut) {
    if (ref != dut) {
        Log("%s is different after executing instruction ap pc = " FMT_WORD
        ", right = " FMT_WORD ",wrong = " FMT_WORD ",diff = " FMT_WORD,
        name, pc, ref, dut, ref ^ dut);
        return false;
    }
    return true;
}

static inline int check_reg_idx(int idx){
   assert(idx >= 0 && idx < 32) ;
   return idx;
}

static const char* reg_name(int idx, int width) {
  return regs[check_reg_idx(idx)];
}

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  //printf("ref_pc:%x,dut_pc:%x\n", ref_r->pc, cpu.pc);
  
  for(int i=1; i<32; i++) {
    if( difftest_check_reg( reg_name(i, 64), ref_r->pc, ref_r->gpr[check_reg_idx(i)], gpr(i) ) == false )
      return false;
  }
  //printf("ref_pc:%x,dut_pc:%x\n", ref_r->pc, cpu.pc);
  if( difftest_check_reg( "pc", pc, ref_r->pc, cpu.pc ) == false ){return false;}
  return true ; 
}


void isa_reg_display() {
  int length = sizeof(regs)/sizeof(regs[0]);
  for (int i = 0; i < length; i++) {
    printf("%d:%s\t%x\n", i+1, regs[i], gpr(i));
  }
  for (int i = 0; i < 4; i++) {
    printf("%d:%s\t%x\n", i+1, csrs[i], csr(i));
  }
  printf("%d:%s\t%x\n", 33, "pc", cpu.pc);
}




static const uint32_t img [] = {
  0x00000297,  // auipc t0,0
  0x00028823,  // sb  zero,16(t0)
  0x0102c503,  // lbu a0,16(t0)
  0x00100073,  // ebreak (used as nemu_trap)
  0xdeadbeef,  // some data
};

static void restart() {  
  /* Set the initial program counter. */
  #ifdef YSYXSOC
  cpu.pc = 0x30000000;
  #else
  cpu.pc = 0x80000000;
  #endif
  printf("Reset PC: 0x%08x\n", cpu.pc);
  /* The zero register is always 0. */
  cpu.gpr[0] = 0;
  cpu.csr[1] = 0x1800;
}


void init_isa() {
  /* Load build-in image. */
  #ifdef YSYXSOC
  memcpy(guest_to_host(0x30000000), img, sizeof(img));
  #else
  memcpy(guest_to_host(0x80000000), img, sizeof(img));
  #endif
  /* Initialize this vertual computer system. */
  restart();
}
