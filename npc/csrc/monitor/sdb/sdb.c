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

#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include "./../../include/common.h"

extern bool RUNNING;
static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void sdb_watchpoint_display();
void create_watchpoint(char* args);
void delete_watchpoint(int no);

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");		//读取用户输入

  if (line_read && *line_read) {
    add_history(line_read);
  }		//添加输入到历史记录

  return line_read;
}

static int cmd_c(char *args) {
	RUNNING = true;
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args) {
  return -1;
}

static int cmd_help(char *args);

/***添加调试内容***/
static int cmd_si(char *args);
static int cmd_info(char *args);
static int cmd_x(char *args);
static int cmd_p(char *args);
static int cmd_w(char *args);
static int cmd_d(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },
	{ "si", "Pause execution after the program steps N instructions", cmd_si }    ,
	{ "info", "r--Print register status   -w--Print watchpoint information", cmd_info },
	{ "x", "Evaluate the expression EXPR, use the result as the starting memory address, and output N consecutive 4-bytes in hexadecimal form", cmd_x },
  { "p", "Evaluates the value of the expression EXPR", cmd_p },
	{ "w", "When the value of the expression EXPR changes, program execution is suspended", cmd_w },
	{ "d", "Delete a watch with serial number N", cmd_d },

	/* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)		//返回cmd_table数组长度为NR_CMD

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");		//分割字符串
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }		//cmd_table
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }		//strcmp对比字符，相同返回0
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

/***
#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif
***/

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }		//对比第一段字符和cmb_table

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
	init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}

static int cmd_si(char *args) {
	RUNNING = true;
  if (args == NULL) {
		 cpu_exec(1);
	}
  else {
     int n = atoi(args);
     cpu_exec(n);
  }
	return 0;
}

static int cmd_info(char *args) {
	if (args == NULL) {
		      printf("Please enter parameter:'r'or'w'\n");
    } 
  else {
		if (*args == 'r') {
			isa_regs_display();
    }
		else if (*args == 'w') {
			sdb_watchpoint_display();
    }
    else {
      printf("Unknown command '%s'\n", args);
    }
	}
  return 0;
}

static int cmd_x(char *args) {
  char *arg = strtok(NULL, " ");
  char *arg2 = strtok(NULL, " ");
  int N = atoi(arg);
	paddr_t addr = 0;
	bool success = false;
	word_t tmp = expr(arg2,&success);
	if(success) {
		char s[66536];
		sprintf(s, "%x", tmp);
		sscanf(s, "%x", &addr); 
		for(int i = 0; i < N; i++) {
			printf("0x%08x  ", paddr_read(addr, 4));
			addr = addr + 4;
		}
		printf("\n");
	}
	else printf("EXPR Invalid.\n");
	return 0;
}

static int cmd_p(char *args) {
	if (args == NULL) {
		printf("Please enter EXPR.\n");
		return 0;
	}
//printf("args = %s\n", args);
	bool success = false;
	printf("expr result = %u\n", expr(args, &success));
	return 0;
}

static int cmd_w(char *args) {
	if (args == NULL) {
		printf("Please enter EXPR.\n");
		return 0;
	}
	else {
		create_watchpoint(args);
	}
	return 0;
}

static int cmd_d(char *args) {
	if (args == NULL) {
    printf("Please enter EXPR.\n");
		return 0;
  }
	else {
		delete_watchpoint(atoi(args));
	}
	return 0;
}
