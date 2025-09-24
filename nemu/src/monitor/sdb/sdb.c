/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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
#include "sdb.h"
#include <memory/paddr.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void isa_reg_display();
void p();
void test();
void add_wp(word_t val, char *e);
void delete_wp(int n);
void info_wp();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

	char *prompt = ANSI_FG_CYAN "nemu >> " ANSI_NONE;

  line_read = readline(prompt);

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_w(char *args) {
  #ifndef CONFIG_WATCHPOINT
  printf("Not enable watchpoint!\n");
  #else
    strtok(args, " ");
    char *e = strtok(NULL, "\n");
    if (e == NULL) { printf("w needs argument EXPR\n"); return 0; }

    uint32_t val = 0;
    bool success = true;

    val = expr(e, &success);
    if (!success)  printf(ANSI_FG_RED "val invalid.\n" ANSI_NONE);

    add_wp(val, e);
  #endif /* ifdef CONFIG_WATCHPOINT */
  return 0;
}

static int cmd_d(char *args) {
  #ifndef CONFIG_WATCHPOINT
  printf("Not enable watchpoint!\n");
  #else
  if (!CONFIG_WATCHPOINT) {
    printf("Not enable watchpoint!\n");
  } else {
    int n = atoi(args);
    delete_wp(n);
  }
  #endif /* ifdef CONFIG_WATCHPOINT */
  return 0;
}

static int cmd_p(char *args) {
  strtok(args, " ");
  char *e = strtok(NULL, "\n");
  if (e == NULL) { printf("p needs argument EXPR\n"); return 0; }

  uint32_t val = 0;
  bool success = true;

  val = expr(e, &success);
  if (!success)  printf(ANSI_FG_RED "val invalid.\n" ANSI_NONE);
  printf("0x%.8x   %u\n", val, val);
	return 0;
}

static int cmd_test() {
	test();
	return 0;
}

static int cmd_pc() {
  printf("0x%.8x\n", cpu.pc);
  return 0;
}

static void  inst_format(word_t inst) {
  for (int i = 31; i >= 0; i--) {
    if (i == 24 || i == 19 || i == 14 || i == 11 || i == 6)
      printf(" ");
    printf("%c", (inst & (1 << i)) ? '1' : '0');
  } 
  printf("\n");
}

static int cmd_x(char *args) {
	char *e = strtok(NULL, " ");
	int count = 1;
  bool success = true;

	if (args != NULL)  count++; 
  if (e != NULL)  count++; 

	if (count != 3) {
		printf("x command needs two arguments.\n");
	}else {
		int n = atoi(args);
		paddr_t paddr = expr(e, &success);
    if (!success)  printf(ANSI_FG_RED "val invalid.\n" ANSI_NONE);

		for (int i = 0; i < n; i++) {
			paddr_t paddr_loop = paddr + i*4;
			word_t pmem_content;
			memcpy(&pmem_content, guest_to_host(paddr_loop), sizeof(word_t));
			printf(ANSI_FG_BLUE "0x%.8x" ANSI_NONE ":   0x%.8x   %-12u", paddr_loop, pmem_content, pmem_content);
      inst_format(pmem_content);
		}
	}

	return 0;
}

static int cmd_info(char *args) {
	if (args == NULL) {
		printf("command info needs argument.\n");
	} else if (strcmp(args, "r") == 0) {
		isa_reg_display();
	} else if (strcmp(args, "w") == 0) {
    info_wp();
  }
	else {
    printf("Unknown command 'info %s'\n", args);
	}

	return 0;
}

static int cmd_si(char *args) {
	int n = 1;

	if (args != NULL) {
		n = atoi(args);
	}

	if (n > 0) {
		cpu_exec(n);
	}else {
    printf("Unknown command 'si %s'\n", args);
	}

	return 0;
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

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "      Display information about all supported commands", cmd_help },
	{ "test", "      Verify expression evaluate", cmd_test},
	{ "si", " [N]    Execute N instructions of the program", cmd_si },
  { "c", "         Continue the execution of the program", cmd_c },
  { "q", "         Exit NEMU", cmd_q },
	{ "info", " r    Print the register state\n"
    "    "  " w    Print using watchpoint information", cmd_info },
  { "pc", "        Show PC value", cmd_pc },
	{ "p", " EXPR    Calculate expression", cmd_p },
  { "w", " EXPR    Add watchpoint", cmd_w },
  { "d", " N       Delete watchpoint", cmd_d },
	{ "x", " N EXPR  Starting from EXPR, output N sets of 4 bytes", cmd_x}
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  //char *arg = strtok(NULL, " ");
  int i;

  //if (arg == NULL) {
  if (args == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s%s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(args, cmd_table[i].name) == 0) {
        printf("%s%s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", args);
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
    char str_bak[512] = {};
    strcpy(str_bak, str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
		char *args = strtok(NULL, " ");

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (i == 7) { 
          cmd_table[7].handler(str_bak); 
          break; 
        } else if (i == 8){ 
          cmd_table[8].handler(str_bak); 
          break; 
        } else {
          if (cmd_table[i].handler(args) < 0) { return; }
          break;
        }
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
