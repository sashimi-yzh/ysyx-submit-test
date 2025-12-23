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
	printf("addr : %08x\n",paddr_read(addr,4));
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

