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

//sdb需要调用的与cpu相关函数只有:(1)cpu_exec (2)isa_reg_str2val

#include <isa.h>
#include <memory/paddr.h>//newly included
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"

extern const char *regs[]; //defined in src/isa/riscv32/reg.c

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
  set_nemu_state(NEMU_QUIT, 0, 0);
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args);

static int cmd_p(char *args);

static int cmd_px(char *args);

static int cmd_info(char *args);

static int cmd_x(char *args);

static int cmd_modr(char *args);
//modify the contents of a certain reg (4B)
static int cmd_modm(char *args);
//modify the contents of certain memory (4B)

static int cmd_w(char *args);

static int cmd_d(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Execute instruction(s) and pause; Usage: si EXPR", cmd_si},
  { "p", "Calculate the expression (result in decimal); Usage: p EXPR", cmd_p},
  { "px", "Calculate the expression (result in hexadecimal); Usage: px EXPR", cmd_px},
  { "info", "Print the current state of the program; Usage: info r/[name]/s", cmd_info},
  { "x", "Scan the memory at certain address and print; Usage: x N addr",cmd_x},
  { "modr", "Modify the contents of a certain reg; Usage: modr reg EXPR", cmd_modr},
  { "modm", "Modify the contents of certain memory; Usage: modm mem EXPR", cmd_modm},
  { "w", "Add a new watchpoint; Usage: w EXPR", cmd_w},
  { "d", "Delete a watchpoint; Usage: d EXPR", cmd_d},
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


long str2int(char *str){
    int i;
    long sum = 0;
    for( i=0; i < strlen(str); ++i){
        if(str[i] < '0' || str[i] > '9')
            return -1;
        else{
            sum *= 10;
            sum += str[i] - '0';
        }
    }
    return sum;
}

long xstr2int(char *str){
    int i;
    long sum = 0;
    if (strlen(str)!=10 || str[0] != '0' || !(str[1] == 'x' || str[1] == 'X'))
            return -1;
    for( i=2; i < strlen(str); ++i){// string must start with 0x and be 8 digits
        if(!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') ||\
                        (str[i] >= 'A' && str[i] <= 'F')))
                return -1;
        else{
            sum *= 16;
            if (str[i] >= '0' && str[i] <= '9')
                    sum += str[i] - '0';
            else if (str[i] >= 'a' && str[i] <= 'f')
                    sum += str[i] - 'a' + 10;
            else
                    sum += str[i] - 'A' + 10;
        }
    }
    return sum;
}


static int cmd_si(char *args){
    /*extract the first argument*/
    char *arg = strtok(NULL, "\0");

	bool success,null;
	word_t tmp = expr(arg, &success, &null);

	if(null){
		printf("1 instruction executed\n");
       	cpu_exec(1);
	}
	else if(!success)// invalid character encountered
    	printf("invalid expression\n");
    else{
        printf("%u instruction(s) executed\n",tmp);
		cpu_exec(tmp);
	}
    return 0;
}


static int cmd_p(char *args){
    char *arg = strtok(NULL,"\0");

    bool success,null;
	//printf("%s\n",arg);
	word_t result = expr(arg, &success, &null);

	if(null)//empty EXPR
		printf("Usage: p EXPR\n");
	else if(!success)// invalid character encountered
        printf("invalid character detected\n");
    else
        printf("result: %u\n",result);

    return 0;
}



static int cmd_px(char *args){
    char *arg = strtok(NULL,"\0");

	bool success,null;
    //printf("%s\n",arg);
    word_t result = expr(arg, &success, &null);

	if(null)//empty EXPR
		printf("Usage: px EXPR\n");
	else if(!success)// invalid character encountered
        printf("invalid character detected\n");
    else
        printf("result: 0x%x\n",result);

    return 0;
}



static int cmd_info(char *args){
    char *arg = strtok(NULL, " ");
	int wp_used[32]; 
	char expression_stored[32][32];
	word_t result[32];

    if(arg == NULL){
        printf("Usage: info r/[name]/s\n");
		return 0;
    }

    bool success;
    word_t ret;
    ret = isa_reg_str2val(arg, &success);
    if (success){// visit one specific reg
            printf("%3s : 0x%8.8x\n", arg, ret);
    }
    else if (strcmp(arg, "r") == 0){// visit all the regs
        isa_reg_display();
    }
    else if(strcmp(arg, "s") == 0){
        int i = check_usage(wp_used, expression_stored, result);
		if(i == 0){
			printf("no watchpoints created yet\n");
		}
		else{
			printf("%d watchpoint(s) created:\n", i);
			for(int j = 0; j <= 31; j++){
				for(int k = 0; k < i; k++)
					if(wp_used[k] == j){
						printf("NO.%d : %s\n",j, expression_stored[k]);
						break;
					}
			}
		}

    }
    else{
        printf("Usage: info r/[name]/s\n");
    }
    return 0;
}


static int cmd_x(char *args){
    char *arg1 = strtok(NULL, " ");
    char *arg2 = strtok(NULL, "\0");
    if (arg1 == NULL){
        printf("Usage: x N addr\n");
    }
    else{
        long tmp1 = str2int(arg1);
        //long tmp2 = xstr2int(arg2);
		bool success2,null2;
        word_t tmp2 = expr(arg2, &success2, &null2);

		if(null2)//empty arg2
			printf("Usage: x N addr\n");
		else if(!success2||tmp1 <= 0)// invalid character encountered
            printf("Invalid expression\n");
        else{
        	for ( ;tmp1 > 0; --tmp1){
                printf("0x%8.8x : 0x%8.8x\n", tmp2, paddr_read(tmp2,4));
                tmp2 += 4;
            }
		}
    }
    return 0;
}


static int cmd_modr(char *args){
    char *arg1 = strtok(NULL, " ");
    char *arg2 = strtok(NULL, "\0");
    if (arg1 == NULL){
        printf("Usage: modr reg EXPR\n");
    }
    else{
        bool success1,success2,null2;
        isa_reg_str2val(arg1, &success1);
        word_t tmp2 = expr(arg2, &success2, &null2);

		if(null2)
			printf("Usage: modr reg EXPR\n");

		else if(!success1||!success2){
            printf("Invalid expression\n");
        }
        else if(strcmp(arg1, "pc") == 0){
            cpu.pc = (uint32_t)tmp2;
        }
        else{
            for(int i = 0; i < 32; ++i){
                if(strcmp(arg1, regs[i]) == 0)
                        cpu.gpr[i] = (uint32_t)tmp2;
            }
        }
    }
    return 0;
}



static int cmd_modm(char *args){
    char *arg1 = strtok(NULL, " ");
    char *arg2 = strtok(NULL, "\0");
    if (arg1 == NULL){
        printf("Usage: modm mem EXPR\n");
    }
    else{
		bool success1,null1,success2,null2;
		word_t tmp1 = expr(arg1, &success1, &null1);
		word_t tmp2 = expr(arg2, &success2, &null2);

        if(null2)
			printf("Usage: modm mem EXPR\n");
		else if(!success1||!success2)
			printf("Invalid expression\n");
        else{
            paddr_write((uint32_t)tmp1, 1, (uint8_t)tmp2);
        }
    }
    return 0;
}



static int cmd_w(char *args){
    char *arg = strtok(NULL, "\0");

	bool success,null;
    //printf("%s\n",arg);
    word_t tmp = expr(arg, &success, &null);

    if(null)//empty EXPR
        printf("Usage: w EXPR\n");
    else if(!success)// invalid character encountered
        printf("invalid character detected\n");
    else{
        WP* watchpoint = new_wp();
		if(watchpoint != NULL){
			strcpy(watchpoint -> expression, arg);
			watchpoint -> result = tmp;
			printf("watchpoint NO.%d successfully created\n",watchpoint -> NO);
		}
	}
    return 0;
}


static int cmd_d(char *args){
    char *arg = strtok(NULL,"\0");
    bool success,null;
    //printf("%s\n",arg);
    word_t no = expr(arg, &success, &null);

    if(null)//empty EXPR
        printf("Usage: d N\n");
    else if(!success)// invalid character encountered
        printf("invalid character detected\n");
    else{
        free_wp(no);
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
