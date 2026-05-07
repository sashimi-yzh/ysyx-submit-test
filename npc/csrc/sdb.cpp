#include "common.h"
#include "debug.h"
#include "macro.h"
#include "utils.h"
#include "include.h"
#include <readline/readline.h>
#include <readline/history.h>

static int is_batch_mode = false;

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

static int cmd_si(char *args) {
	char *arg = strtok(NULL, " ");
	char num_c[5];
	int num;
	if (arg == NULL) {
		num=1;
	}
	else {
		strcpy( num_c, arg);
		sscanf(num_c,"%d",&num);
		//printf("%d",num);
	}
	cpu_exec(num);


	return 0;
}

static int cmd_info(char *args) {
	char *arg = strtok(NULL, " ");
       
        if (arg == NULL) {
                printf("please add sub command and try again\n");
        }
        else {
		if(strcmp(arg,"r")==0){
			isa_reg_display();

		}
		else if(strcmp(arg,"w")==0){
      print_wp();
			//printf("www");
		}
		else{
			printf("Unknown command '%s'\n", arg);
		}
	}
        
        return 0;
}

static int cmd_x(char *args) {
  char *arg = strtok(NULL, " ");
	unsigned int num;
	char line[100];

  if (arg == NULL) {
          printf("please add sub command and try again\n");
  }
  else {
    strcpy( line, arg);
    //printf("%s\n",line);
    sscanf(line,"%d",&num);
    arg = strtok(NULL, " ");
    if(arg==NULL) {
      printf("please add sub command and try again\n");
    }
    else {
      strcpy(line, arg);
      bool success;
      bool *ptr_success = &success;
      uint32_t result;
      //printf("%s\n",arg);
      result=expr(line,ptr_success);
      
      //sscanf(line,"%x",&result);
      
      uint32_t i,j;
      for(i=0;i<num;i++) {
        printf("0x%8x: %08x",result+4*i,mem[result/4+i]);
        
        printf("\n");
        
      }
      
    }

                
	}
	return 0;
}

static int cmd_p(char *args) {
	char *arg = strtok(NULL, "\0");
	bool success;
	bool *ptr_success = &success;
	uint32_t result;
	printf("%s\n",arg);
	result=expr(arg,ptr_success);
	printf("result=%u\n",result);
        return 0;
}

static int cmd_w(char *args) {
  char *arg = strtok(NULL, "\0");
	bool success;
	bool *ptr_success = &success;
	uint32_t result;
	//printf("%s\n",arg);
	result=expr(arg,ptr_success);
  //printf("result=%u\n",result);
  new_wp(arg,result);
        return 0;
}

static int cmd_d(char *args) {
  char *arg = strtok(NULL, " ");
	char num_c[5];
	int num;
	if (arg == NULL) {
		assert(0);
	}
	else {
		strcpy( num_c, arg);
		sscanf(num_c,"%d",&num);
		//printf("%d",num);
	}
  free_wp(num);
        return 0;
}


static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  //exit(0);
  cpu_state = NPC_QUIT;
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
  { "q", "Exit NEMU", cmd_q },
  { "si", "Continue the execution for N steps, N is number you input, default N=1", cmd_si },
  { "info", "print the state of the program", cmd_info },
  { "x", "scan the memory", cmd_x },
  { "p", "", cmd_p },
  { "w", "", cmd_w },
  { "d", "", cmd_d }, 

  /* TODO: Add more commands */

};

#define NR_CMD 9

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

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
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