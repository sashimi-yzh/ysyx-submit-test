#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "sdb.h"
#include "npc.h"


static int is_batch_mode = false;

//void init_regex();
//void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
	static char *line_read = NULL;
	int sizeof_read = 65536;
	char buffer[sizeof_read];

	if (line_read) {
		free(line_read);
		line_read = NULL;
	}

	printf("(npc_cloud): ");

	if (fgets(buffer, sizeof_read, stdin) == NULL) {// 错误处理
        return NULL;
    }

	line_read = (char*)malloc(strlen(buffer) + 1);
    strcpy(line_read, buffer);
    
	line_read[strcspn(line_read, "\n")] = '\0';//移除换行符

	return line_read;
}


static int cmd_c(char *args) {
	cpu_exec(-1);
	return 0;
}


static int cmd_q(char *args) {
	npc_state = NPC_QUIT;
	return -1;
}


static int cmd_s(char *args) {
	//char *arg = strtok(NULL, " ");
	int i; //执行指令数
	if (args == NULL) { i = 1; }  //当N没有给出时, 执行1条指令
	else { sscanf (args, "%d", &i); } //单步执行N条	
	cpu_exec(i);
	return 0;
}


static int cmd_info(char *args) {
	//char *arg = strtok(NULL, " ");
	if ( strcmp(args, "r") == 0 ) { isa_reg_display(); }  //打印寄存器状态
	else if (strcmp(args, "w") == 0) { isa_watchpoint_display(); } //打印监视点信息
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
		uint32_t w = *paddr_read(expr + i * 4);
		printf("0X%08X: 0X%08X\n", expr + i * 4, w);
	}
 	return 0;
}

static int cmd_p(char *args) {
	int success;
	uint32_t result = expr(args, &success);
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
	uint32_t result = expr(arg, &success);
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
 	
	FILE *fp = fopen("../nemu/tools/gen-expr/input", "r");
	if (fp == NULL) printf("fopen input error\n"); //打开input文件并验证打开成功与否

	char *e = NULL;
	uint32_t result_correct;
	size_t len = 0;
	ssize_t read;
	int success = false;
	
	while (true) {
    	if(fscanf(fp, "%u ", &result_correct) == -1) break;//读取测试程序运算结果,读取不到数据时跳出循环
    	read = getline(&e, &len, fp);//读取测试程序生成表达式
    	e[read-1] = '\0';
		
    	uint32_t result = expr(e, &success); //用expr计算表达式
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
	{ "s", "single step", cmd_s},
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
	if(TEST_EXPR) { test_p(); } //测试表达式生成器	
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

		int i;
		for (i = 0; i < NR_CMD; i ++) {
			if (strcmp(cmd, cmd_table[i].name) == 0) {
				if (cmd_table[i].handler(args) < 0) { return; }
				break;
			}
		}

		if(npc_state != NPC_RUNNING) return;

		if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
	}
}
