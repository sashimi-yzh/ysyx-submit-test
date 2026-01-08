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

#include <memory/vaddr.h>

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


static int cmd_si(char *args) {
	char *arg = strtok(NULL, " ");
	int i; //执行指令数
	if (arg == NULL) { i = 1; }  //当N没有给出时, 执行1条指令
	else { sscanf (arg, "%d", &i); } //单步执行N条	
	cpu_exec(i);
	return 0;
}


static int cmd_info(char *args) {
	char *arg = strtok(NULL, " ");
	if ( strcmp(arg, "r") == 0 ) { isa_reg_display(); }  //打印寄存器状态
	else if (strcmp(arg, "w") == 0) { isa_watchpoint_display(); } //打印监视点信息
	else {printf("info r: register; info w: watchpoint.\n");}
	return 0;
}


static int cmd_x(char *args) {
	char *arg1 = strtok(NULL, " ");
	char *arg2 = strtok(NULL, " ");
	int N, expr,i; 
	sscanf (arg1, "%d", &N);
	sscanf (arg2, "%x", &expr);
	for(i = 0; i < N; i++){
		word_t w = vaddr_read(expr + i * 4, 4);
		printf("0x%-8x: 0x%-8x\n", expr + i * 4, w);
	}
 	return 0;
}

static int cmd_p(char *args) {
	int success;
	word_t result = expr(args, &success);
	if(!success){
		printf("Bad expression\n");
	}
	else{
		if(success == 16)
			printf("result:0x%-8x\n",result);
		else
			printf("result:%u\n",result);
	}
 	return 0;
}


static int cmd_w(char *args) {
	char *arg = strtok(NULL, " ");
	int success;
	word_t result = expr(arg, &success);
	if(!success){
		printf("Bad expression of watchpoints\n");
	}
	else{
		set_watchpoint(arg, result, &success);
	}
 	return 0;
}


static int cmd_d(char *args) {
	char *arg = strtok(NULL, " ");
	int NO_watchpoint;
	sscanf(arg, "%d", &NO_watchpoint);
	remove_watchpoint(NO_watchpoint);
 	return 0;
}


static void test_p() {
 	
	FILE *fp = fopen("./tools/gen-expr/input", "r");
	if (fp == NULL) printf("fopen input error\n"); //打开input文件并验证打开成功与否

	char *e = NULL;
	word_t result_correct;
	size_t len = 0;
	ssize_t read;
	int success = false;
	
	while (true) {
    	if(fscanf(fp, "%u ", &result_correct) == -1) break;//读取测试程序运算结果,读取不到数据时跳出循环
    	read = getline(&e, &len, fp);//读取测试程序生成表达式
    	e[read-1] = '\0';
		
    	word_t result = expr(e, &success); //用expr计算表达式
		//printf("result_correct:%u, result_expr: %u\n", result_correct, result);
	
    	if (result != result_correct) {
      		puts(e);
      		printf("result_correct:%u\nresult_expr: %u\n", result_correct, result);
      		assert(0);
    	} //判断测试程序和求值程序运算结果是否一致，不一样则输出
  	}

  	fclose(fp);
  	if (e) free(e);    //关闭文件，释放表达式内存

  	printf("All the inputs tested by expr are correct\n"); //测试程序与求值程序结果全部一致
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
	{ "si", "single step", cmd_si},
	{ "info", "Print register", cmd_info},
	{ "x", "Scan Memory", cmd_x},
	{ "p", "expression evaluation", cmd_p},
	{ "w", "Set watchpoint", cmd_w},
	{ "d", "Delete watchpoint", cmd_d}
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
	if(0) { test_p(); } //测试表达式生成器	
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
