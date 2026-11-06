#include <common.h>
#include <cpu/cpu.h>
#include <memory/paddr.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <assert.h>
static int is_batch_mode = false;

//word_t paddr_read(paddr_t addr, int len);
static int cmd_help(char *args);
void isa_reg_display();

static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(soc) ");

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
	//nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_si(char *args){
    //printf("si process\n");
	int N;
	// int i;
	if (args == NULL){
		N = 1;
	}else {
		N = atoi(args);
	}
	cpu_exec(N);
	return 0;
}

static int cmd_info(char *args){
	if (args == NULL) {
		printf("Invalid command\n");
		printf("Please input: info [arg]\n");
		return 0;
	}
	char* Arg = strtok(args," ");
	if(strcmp( Arg , "r") == 0){
		isa_reg_display();	
        //printf("0x%o8x\n", top->IDU->gpr->reg_file[2]);
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
// //获 得地址	
	char* addr_str = strtok(NULL, delim);
    char *endptr;
    uint32_t addr = strtoul(addr_str, &endptr, 16);
    if (*endptr != '\0' || addr > UINT32_MAX) {
        printf("转换失败或超出范围\n");
        return 1;
    }
  #ifdef PLATFORM_YSYXSOC
    	if (addr < CONFIG_MROM_BASE || addr >= CONFIG_MROM_BASE + CONFIG_MROM_SIZE &&
          addr < CONFIG_FLASH_BASE || addr >= CONFIG_FLASH_BASE + CONFIG_FLASH_SIZE) {
		printf("Invalid address\n");
		printf("Address is out of range\n");
		return 0;
	}
	for(int i = 0 ; i < N  ; i++){
    // printf("%08x\n", addr);
    if (addr >= CONFIG_MROM_BASE && addr < CONFIG_MROM_BASE + CONFIG_MROM_SIZE){
  		printf("\033[32mmrom:0x%08x -> \033[0m\033[33m%08x\033[0m\n",addr, sdb_mrom_read(addr));
    }
    else if (addr >= CONFIG_FLASH_BASE && addr < CONFIG_FLASH_BASE + CONFIG_FLASH_SIZE){
  		printf("\033[32mflash:0x%08x -> \033[0m\033[33m%08x\033[0m\n",addr, sdb_flash_read(addr));
    }
		addr += 4;
	}
  #else
	if (addr < PMEM_LEFT || addr > PMEM_RIGHT) {
		printf("Invalid address\n");
		printf("Address is out of range\n");
		return 0;
	}
	for(int i = 0 ; i < N  ; i++){
		printf("\033[32maddr:0x%08x -> \033[0m\033[33m%08x\033[0m\n",addr,pmem_read(addr,4));
		addr += 4;
	}
  #endif
	return 0;
}

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },
	{ "si", "Execute one step", cmd_si },
	{ "info", "Display status", cmd_info },
	{ "x", "Display memory" , cmd_x }
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

