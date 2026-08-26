#include "common.h"
#include "sdb.h"
#include "cpu.h"
#include "mem.h"
#include <readline/readline.h>
#include <readline/history.h>
static int is_batch_mode = false;
void init_regex();
void init_wp_pool();

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
  cpu_exec(-1);
  return 0;
}

static int cmd_si(char *args) {
  if(args!=NULL){
    if(atoi(args)>=1)
      cpu_exec(atoi(args));
    else
      printf("Unknown argumenet '%s'\n", args);
  }else{
    cpu_exec(1);
  }
  return 0;
}

static int cmd_info(char *args) {
  if(args!=NULL){
    const char s[2]=" ";
    char* argument;

    argument=strtok(args,s);
    while(1) {
      if(argument[0]!='\0') break;
      argument = strtok(NULL, s);
    }
    switch (argument[0])
    {
    case 'r':
      reg_display(cpu);
      break;
    case 'w':
      print_wp();
      break;
    default:
      printf("Incorrect argument! Please input 'r' or 'w'\n");
      break;
    }
  }else{
    printf("NULL argument! Please input 'r' or 'w'\n");
  }
  return 0;
}

static int cmd_x(char *args) {
    int num;
    const char s[2]=" ";
    char* argument;
    argument=strtok(args,s);
    if(argument==NULL){
      printf("NULL argument!\n");
      return 0;
    }
    num=atoi(argument);
    if(num<=0){
      printf("Error NUMBER!\n");
      return 0;
    }
    argument=strtok(NULL,s);
    if(argument==NULL){
      printf("NULL address!\n");
      return 0;
    }
    char *endptr;
    int val = strtol(argument, &endptr, 16);
    if (endptr == argument || val==0) {
        printf("NULL address: %s\n", argument);
        return 0;
    }
    printf("%x\n",val);
    for(int i=0;i<num;i++){
      uint32_t data=pmem_read((uint32_t)val+i*4);
      printf("%.4d\t0x%.8x\t0x%.8x\t%d\n",i,val+i*4,data,data);
    }
    
    return 0;
}

static int cmd_p(char *args) {
  bool good=true;
  uint32_t expval;
  if(args!=NULL){
    expval=expr(args,&good);
    if(good==false) printf("Error experiment!\n");
    else printf("=%u\n",expval);
  }else{
    printf("NULL argument!\n");
  }
  
  return 0;
}

static int cmd_w(char *args) {
  bool good=true;
  uint32_t expval;
  if(args!=NULL){
    expval=expr(args,&good);
    if(good==false) printf("Error experiment!\n");
    else{
      int no=new_wp(args,expval);
      if(no>=0){
        printf("Watchpoint [%d] was added. \"%s\"=%u\n",no,args,expval);
      }else{
      printf("Watchpoint FULL!\n");
      }
    }
  }else{
    printf("NULL argument!\n");
  }
  
  return 0;
}

static int cmd_d(char *args) {
  if(args!=NULL){
    int n=atoi(args);
    if(n>=0){
      WP* t=find_wp(n);
      if(t==NULL){
        printf("Cannot find watchpoint [%d].\n",n);
      }else{
        printf("Finded watchpoint [%d].\n",n);
        free_wp(t);
        printf("Deleted watchpoint [%d].\n",n);
      }
    }else printf("Unknown argumenet '%s'\n", args);
  }else{
    printf("NULL argumenet\n");
  }
  return 0;
}

static int cmd_q(char *args) {
  cpu.state = NPC_QUIT;
  return -1;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "si", "Single-step execution", cmd_si },
  { "info", "Print program status", cmd_info },
  { "x", "Scan memory", cmd_x },
  { "p", "Expression evaluation", cmd_p },
  { "w", "Set watchpoint", cmd_w },
  { "d", "Delete watchpoint", cmd_d },
  { "q", "Exit NPC", cmd_q },

  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the fireset argument */
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


void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the fireset token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
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

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}

void sdb_set_batch_mode(){
  is_batch_mode = true;
}