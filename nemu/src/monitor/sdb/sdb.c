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
#include "sdb.h"
#include <assert.h>
static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
word_t paddr_read(paddr_t addr, int len);
word_t expr(char *e, bool *success);
void sdb_watchpoint_display ();
void delete_watchpoint (int NO);
void create_watchpoint (char* args);

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
// 继续运行
static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

// 退出
static int cmd_q(char *args) {
	nemu_state.state = NEMU_QUIT;
  return -1;
}
//帮助
static int cmd_help(char *args);

// 单步执行
static int cmd_si(char *args){
	int N;
	// int i;
	if (args == NULL){
		N = 1;
	}else {
		N = atoi(args);
	}
	cpu_exec(N);
	/*
	for (i = 0 ; i < N ; i++){
		cpu_exec(1);// nemu/src/cpu/cpu-exec.c 
	}
	*/
	return 0;
}

// 获得信息
static int cmd_info(char *args){
	if (args == NULL) {
		printf("Invalid command\n");
		printf("Please input: info [arg]\n");
		return 0;
	}
	char* Arg = strtok(args," ");
	if(strcmp( Arg , "r") == 0){
		isa_reg_display();	
	}
	else if(strcmp( Arg , "w") == 0 )	{
		sdb_watchpoint_display();
	}
	else {
	printf("Invalid argument");
	}
	return 0;
}

// 扫描内存
static int cmd_x (char *args){
	//获得次数
	const char delim[] = " ";
	char* N_str = strtok(args, delim);
	int N;
	if (N_str) {
		N = atoi(N_str);
		//printf("N: %d\t",N);
	} 
	else {
		printf("Invalid number\n");
		printf("Please input: x [number] [address]\n");
		return 0;
	} 
//获 得地址	
	// char *endptr;
	// char* addr_str = strtok(NULL, delim);
	// uint32_t addr = strtol(addr_str, &endptr, 16);
	// if (*endptr == '\0') {
	// printf("addr: 0x%x\n",addr);
	// } 
	// else {
	// 	printf("Parsed hex string. Stopped at: %s\n", endptr);
	// } 
	bool success = false;
	char* addr_str = strtok(NULL, delim);
	uint32_t addr = expr(addr_str, &success);
	if (addr < 0x80000000) {
		printf("Invalid address\n");
		printf("Address is out of range\n");
		return 0;
	}
	for(int i = 0 ; i < N  ; i++){
		printf("addr:0x%08x --> %08x\n",addr,paddr_read(addr,4));
		addr += 4;
	}
	return 0;
}

// 表达式求值
static int cmd_p (char* args){
	if (args == NULL) {
		printf("Invalid command\n");
		printf("Please input: p <expr>");
		return 0;
	}
		init_regex(args);
		//printf("%s\n", args);
		bool success = false;
		uint32_t result = expr(args,&success);
		if (success) printf("Expression: %s\nResult: 0x%x (%u)\n", args, result, result);
		//make_token(args);
	return 0;
}

// 设置监视点
static int cmd_w (char* args){
	
	if (args == NULL) {
		printf("Please input: w <expression>.\n");
		return 0;
	} 

	create_watchpoint (args);
	return 0;
}

// 删除监视点
static int cmd_d (char* args){
	if (args == NULL) {
		printf("Please input: d [number].\n");
		return 0;
	}
	int NO = atoi(args);
	delete_watchpoint(NO);
	return 0;
}

void cachesim_mainloop(int SIZE, int BANK);
static int cmd_cachesim (char* args){

	int CACHE_BLOCK_SIZE = 16; // default
	int CACHE_BLOCK_BANK = 4;

	if (args == NULL) {
		printf("Use default cache_block_size: %d\tcache_block_bank: %d.\n", CACHE_BLOCK_SIZE, CACHE_BLOCK_BANK);
	}
	else {
		char args_buf[128];
        strncpy(args_buf, args, sizeof(args_buf) - 1);
        args_buf[sizeof(args_buf) - 1] = '\0'; // 确保字符串结束
        
        // 步骤2：分割第一个参数（CACHE_BLOCK_SIZE）
        char *token = strtok(args_buf, " \t"); // 按空格/制表符分割
        if (token != NULL) {
            long size_val = atol(token); // 用atol更安全，避免int溢出
            // 合法性检查：必须是正数，且合理范围
            if (size_val % 4 == 0) {
                CACHE_BLOCK_SIZE = (int)size_val;
            } else {
                printf("Invalid cache_block_size: %s, use default: %d.\n", token, CACHE_BLOCK_SIZE);
            }

            // 步骤3：分割第二个参数（CACHE_BLOCK_BANK）
            token = strtok(NULL, " \t");
            if (token != NULL) {
                long bank_val = atol(token);
                if (bank_val % 4 == 0) {
                    CACHE_BLOCK_BANK = (int)bank_val;
                } else {
                    printf("Invalid cache_block_bank: %s, use default: %d.\n", token, CACHE_BLOCK_BANK);
                }
            } else {
                printf("No cache_block_bank provided, use default: %d.\n", CACHE_BLOCK_BANK);
            }
        } else {
            printf("Invalid argument format, use default values.\n");
        }

        // 打印最终使用的参数值
        printf("Use cache_block_size: %d\tcache_block_bank: %d.\n", CACHE_BLOCK_SIZE, CACHE_BLOCK_BANK);
	}
	cachesim_mainloop(CACHE_BLOCK_SIZE, CACHE_BLOCK_BANK);
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

  /* TODO: Add more commands */
	{ "si", "Execute one step", cmd_si },
	{ "info", "Display status", cmd_info },
	{ "x", "Display memory" , cmd_x },
	{"p", "Do math", cmd_p},
	{"w", "Create watchpoint", cmd_w},
	{"cachesim", "cache simulator", cmd_cachesim},
	{"d", "Delete watchpoint", cmd_d}
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
