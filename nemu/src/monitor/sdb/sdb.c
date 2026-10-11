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

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdint.h>
#include <memory/vaddr.h>
#include <stdio.h>
#include "sdb.h"
#include "common.h"

static int is_batch_mode = false;
WP* new_wp(char *args,word_t result);
void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
    nemu_state.state = NEMU_QUIT;
    return -1;
}

static int cmd_help(char *args);
static int cmd_si(char *args){
    char *arg=strtok(NULL," ");
    if(arg==NULL){
        cpu_exec(1);
    }else{
        int i=atoi(arg);
        cpu_exec(i);
    }
    return 0;
}
static int cmd_info(char *args){
    char *arg=strtok(NULL," ");
    if(arg==NULL){
        printf("Input info r or info w\n");
    }else{
        if(strcmp(arg,"r")==0){
            isa_reg_display();
        }else if(strcmp(arg,"w")==0){
            show_WP();
        }else if(strcmp(arg,"i")==0){
            extern void iringbuf_print();
            iringbuf_print();
        }else if(strcmp(arg,"f")==0){
            ftrace_print();
        }
    }
    return 0;
}
static int cmd_x(char *args){
    int i;vaddr_t p;
    int ret=sscanf(args,"%d %x",&i,&p);
    if(ret!=2){
        printf("please input: x n expr\n");
    }
    int j;word_t value;
    for(j=0;j<i;j++){
        value=vaddr_read(p+j*4,4);
        printf("%02X %02X %02X %02X\n",(value>>24)&0xff,(value>>16)&0xff,(value>>8)&0xff,value&0xff);
    }
    return 0;
}
static int cmd_p(char *args){
    bool success;
    word_t ret=expr(args,&success);
    if(success==false){
        printf("Error expression\n");
    }else{
        printf("%u\n",ret); 
    }
    return 0;
}
static int cmd_w(char *args){
    bool success;
    word_t ret=expr(args,&success);
    if(success==false){
        printf("Error watch point expression\n");
    }else{
        new_wp(args,ret);
    }
    return 0;
}
static int cmd_d(char *args){
    char *arg=strtok(NULL," ");
    if(arg==NULL){
        printf("delete what?\n");
        return 0;
    }else {
        free_wp(atoi(arg));
    }
    return 0;
}
static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  {"si","Execute the program n times",cmd_si},
  {"info","Print registers",cmd_info},
  {"x","Scan the memory",cmd_x},
  {"p","Evaluate expression",cmd_p},
  {"w","Set up monitoring points",cmd_w},
  {"d","Delete watch point",cmd_d},
  /* TODO: Add more commands */

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

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
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
