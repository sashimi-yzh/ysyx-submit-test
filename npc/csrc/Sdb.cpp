#define MAX_LINE_LENGTH 1024
#include <readline/readline.h>
#include <readline/history.h>
#include "Sdb.h"
uint64_t cycle_count = 0;
uint64_t pc_count = 0;
VysyxSoCFull *Npc::top = NULL;
long Sdb::load_img()
{
	if (img_file == NULL)
	{
		printf("No image is given. Use the default build-in image.");
		return 4096; // built-in image size
	}

	FILE *fp = fopen(img_file, "rb");
	// Assert(fp, "Can not open '%s'", img_file);

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);

	printf("The image is %s, size = %ld\n", img_file, size);

	fseek(fp, 0, SEEK_SET);
	int ret = fread(pmem, size, 1, fp);
	assert(ret == 1);

	fclose(fp);
	return size;
}
char *Sdb::rl_gets()
{
	static char *line_read = NULL;

	if (line_read)
	{
		free(line_read);
		line_read = NULL;
	}

	line_read = readline("(npc) ");

	if (line_read && *line_read)
	{
		add_history(line_read);
	}

	return line_read;
}

int Sdb::cmd_d(char *args)
{
	int id;
	sscanf(args, "%d", &id);
	wpool.free_wp_id(id);
	return 0;
}

int Sdb::cmd_w(char *args)
{
	char regex[512];
	sscanf(args, "%[^\n]", regex);
	wpool.add_wp(regex, expr);
	return 0;
}

int Sdb::cmd_si(char *args)
{
	int res;
	if (args == NULL)
		res = 1;
	else
		res = atoi(args);
	run(res);
	return 0;
}

int Sdb::cmd_x(char *args)
{
	unsigned int num;
	unsigned addr;
	char regex[512];
	bool is_success;

	sscanf(args, "%u %[^\n]", &num, regex);
	addr = expr.expr(regex, &is_success);
	// Log("%s = %u/%x", regex, addr, addr);
	if (!is_success)
	{
		printf("calcu failed");
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
		printf("0x%x ", paddr_read(addr, 4, 1, 1));
		addr += 4;
	}
	printf("\n");
	return 0;
}

int Sdb::cmd_info(char *args)
{
	if (args == NULL)
		return 0;
	if (strcmp(args, "r") == 0)
		npc.reg_display();
	if (strcmp(args, "w") == 0)
		wpool.print_wp();
	return 0;
}

int Sdb::cmd_help(char *args)
{
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

int Sdb::sdb_mainloop()
{
	printf("Welcome to NPC!\n");
	if(is_batch_mode){
		printf("Batch mode enabled. Program will run without interactive prompts.\n");
		while(1){
			npc.step_top();
		}
		return 0;
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

		int i;
		for (i = 0; i < NR_CMD; i++)
		{
			if (strcmp(cmd, cmd_table[i].name) == 0)
			{
				if ((this->*cmd_table[i].handler)(args) < 0)
				{
					return -1;
				}
				break;
			}
		}

		if (i == NR_CMD)
		{
			printf("Unknown command '%s'\n", cmd);
		}
		if (npc_state == NPC_QUIT)
		{
			printf("quit successfully\n");
			break;
		}
		if (npc_state == NPC_ABORT)
		{
			printf("aborted\n");
			return -1;
		}
	}
	return 0;
}
int Sdb::parse_args(int argc, char **argv)
{
	const struct option table[] = {
		{"elf", required_argument, NULL, 'e'},
		{"log", required_argument, NULL, 'l'},
		{"diff", required_argument, NULL, 'd'},
		{"port", required_argument, NULL, 'p'},
		{"help", no_argument, NULL, 'h'},
		{"batch", no_argument, NULL, 'b'},
		{0, 0, NULL, 0},
	};
	int o;
	while ((o = getopt_long(argc, argv, "-bhl:d:p:", table, NULL)) != -1)
	{
		switch (o)
		{
		case 'e':
			elf_file = optarg;
			break;
		case 'p':
			sscanf(optarg, "%d", &difftest_port);
			break;
		case 'l':
			log_file = optarg;
			break;
		case 'd':
			diff_so_file = optarg;
			break;
		case 'b':
			is_batch_mode = true;
			return 0;
		case 1:
			img_file = optarg;
			break;
		default:
			printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
			printf("\t-l,--log=FILE           output log to FILE\n");
			printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
			printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
			printf("\n");
			exit(0);
		}
	}
	return 0;
}

int Sdb::run(uint32_t n)
{

	for (uint32_t i = 0; i < n; i++)
	{
		if (n == 0xFFFFFFFF)
			i--;
		if (npc_state == NPC_STOP)
		{
			printf("the program is stopped,q to quit\n");
			return 0;
		}
		if (npc_state == NPC_QUIT)
		{
			printf("the program is quit\n");
			return 0;
		}
		if (npc_state == NPC_ABORT)
		{
			return -1;
		}
		unsigned int is_device = 0;
		while (npc.wbu_state == 0)
		{
			npc.step_top();
			cycle_count++;
			is_device |= npc.is_device;
		}
		uint32_t pc = npc.regs_val[0];

		do
		{
			npc.step_top();
			cycle_count++;
			is_device |= npc.is_device;
		} while (pc == npc.regs_val[0]);

		pc_count++;
#ifdef TRACE
		if (n < 12)
			printf("%s", npc.message);
#endif
#ifdef DIFFTEST
		if (is_device)
			npc.difftest_skip_ref();
		else
			npc.difftest_step();
#endif
#ifdef ITRACE
		iringbuf.push_iringbuf(npc.message);
#endif

#ifdef TRACE
		bool res = wpool.check_wp(expr);
#endif
#ifdef FTRACE
		elf.check(npc.message);
#endif

#ifdef TRACE
		if (res)
			return 0;
#endif
	}
	return 0;
}