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
#define MAX_LINE_LENGTH 1024
#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <memory/paddr.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void init_iringbuf();
void init_elf(char *elf_file);

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char *rl_gets()
{
	static char *line_read = NULL;

	if (line_read)
	{
		free(line_read);
		line_read = NULL;
	}

	line_read = readline("(nemu) ");

	if (line_read && *line_read)
	{
		add_history(line_read);
	}

	return line_read;
}

static int cmd_c(char *args)
{
	cpu_exec(-1);
	return 0;
}

static int cmd_q(char *args)
{
	nemu_state.state = NEMU_QUIT;
	return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args);

static int cmd_info(char *args);

static int cmd_x(char *args);

static int cmd_d(char *args);

static int cmd_w(char *args);

static int cmd_test(char *args);

static struct
{
	const char *name;
	const char *description;
	int (*handler)(char *);
} cmd_table[] = {
	{"help", "used without args Display information about all supported commands", cmd_help},
	{"c", "used without args Continue the execution of the program", cmd_c},
	{"q", "used without args Exit NEMU", cmd_q},
	{"si", "used as si [N]   execution [N]=1 lines of program", cmd_si},
	{"info", "used as info r or info w   r print the register w print watchpoints", cmd_info},
	{"x", "used as N EXPR  use EXPR as the start and print N hex", cmd_x},
	{"d", "used as d id    delete a watch point with id", cmd_d},
	{"w", "used as w EXPR  add a watch point with expression", cmd_w},
	{"test", "used without args perform some test", cmd_test}
	/* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_d(char *args)
{
	int id;
	sscanf(args, "%d", &id);
	free_wp_id(id);
	return 0;
}

static int cmd_test(char *args)
{

	FILE *file = fopen("/home/pglzjz/ysyx-workbench/nemu/tools/gen-expr/input", "r");
	if (file == NULL)
	{
		perror("failed to open");
		return EXIT_FAILURE;
	}

	char line[MAX_LINE_LENGTH];
	uint32_t number;
	char text[MAX_LINE_LENGTH];

	while (fgets(line, sizeof(line), file))
	{

		text[0] = '\0';

		if (sscanf(line, "%u %[^\n]", &number, text) >= 1)
		{
			printf("value: %u, string: \"%s\"\n", number, text);
			bool is;
			word_t addr = expr(text, &is);
			printf("%u == %u\n", number, addr);
			assert(number == (unsigned)addr);
		}
		else
		{
			printf("解析失败: %s", line);
		}
	}
	fclose(file);
	return 0;
}

static int cmd_w(char *args)
{
	char regex[512];
	sscanf(args, "%[^\n]", regex);
	new_wp_nonreturn(regex);
	return 0;
}

static int cmd_si(char *args)
{
	int res;
	if (args == NULL)
		res = 1;
	else
		res = atoi(args);
	// printf("args :%s,res %d\n", args, res);
	cpu_exec(res);
	return 0;
}
extern word_t vaddr_read(paddr_t addr, int len);
static int cmd_x(char *args)
{
	unsigned int num;
	unsigned addr;
	char regex[512];
	bool is_success;

	sscanf(args, "%u %[^\n]", &num, regex);
	addr = expr(regex, &is_success);
	Log("%s = %u/%x", regex, addr, addr);
	if (!is_success)
	{
		Log("calcu failed");
		return 0;
	}

	for (int i = 0; i < num; i++)
	{
		if (i % 4 == 0)
		{
			if (i != 0)
				printf("\n");
			printf("0x%x:\t", addr);
		}
		printf("0x%x ", vaddr_read(addr, 4));
		addr += 4;
	}
	printf("\n");
	return 0;
}

static int cmd_info(char *args)
{
	if (args == NULL)
		return 0;
	if (strcmp(args, "r") == 0)
		isa_reg_display();
	if (strcmp(args, "w") == 0)
		print_wp();
	return 0;
}

static int cmd_help(char *args)
{
	//(     57 / 42!=  8 ==    3) &&      ( 87)  != ( 42)/   49/ (62)  !=(  42-91  - (21))"
	/* extract the first argument */
	char *arg = strtok(NULL, " ");
	int i;

	if (arg == NULL)
	{
		/* no argument given */
		for (i = 0; i < NR_CMD; i++)
		{
			printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
		}
	}
	else
	{
		for (i = 0; i < NR_CMD; i++)
		{
			if (strcmp(arg, cmd_table[i].name) == 0)
			{
				printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
				return 0;
			}
		}
		printf("Unknown command '%s'\n", arg);
	}
	return 0;
}

void sdb_set_batch_mode()
{
	is_batch_mode = true;
}

void sdb_mainloop()
{
	if (is_batch_mode)
	{
		cmd_c(NULL);
		return;
	}

	for (char *str; (str = rl_gets()) != NULL;)
	{
		char *str_end = str + strlen(str);

		/* extract the first token as the command */
		char *cmd = strtok(str, " ");
		if (cmd == NULL)
		{
			continue;
		}

		/* treat the remaining string as the arguments,
		 * which may need further parsing
		 */
		char *args = cmd + strlen(cmd) + 1;
		if (args >= str_end)
		{
			args = NULL;
		}

#ifdef CONFIG_DEVICE
		extern void sdl_clear_event_queue();
		sdl_clear_event_queue();
#endif

		int i;
		for (i = 0; i < NR_CMD; i++)
		{
			if (strcmp(cmd, cmd_table[i].name) == 0)
			{
				if (cmd_table[i].handler(args) < 0)
				{
					return;
				}
				break;
			}
		}

		if (i == NR_CMD)
		{
			printf("Unknown command '%s'\n", cmd);
		}
	}
}

void init_sdb(char *elf_file)
{
	/* Compile the regular expressions. */
	init_regex();
	// init_iringbuf();
	/* Initialize the watchpoint pool. */
	init_wp_pool();
	init_iringbuf();

	IFDEF(CONFIG_FTRACE, init_elf(elf_file));
}
