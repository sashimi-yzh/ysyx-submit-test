#pragma once
#include "Npc.h"
#include "Wpool.h"
#include "Elf.h"
#include <getopt.h>
#include "Expr.h"
#include "config.h"
#define NR_CMD 8
extern "C" uint32_t paddr_read(uint32_t addr, int len, int is_fetch, int is_avail);
class Sdb;
enum NPC_STATE
{
	NPC_RUNNING,
	NPC_QUIT,
	NPC_STOP,
	NPC_ABORT
};
struct cmds
{
	const char *name;
	const char *description;
	int (Sdb::*handler)(char *);
};
class Sdb
{
public:
	Sdb(int argc, char *argv[]) : npc(argc, argv)
	{
		npc_state = NPC_RUNNING;
		parse_args(argc, argv);
		img_size = load_img();
#ifdef FTRACE
		elf.open_elf(elf_file);
#endif
		npc.reset_top();
#ifdef DIFFTEST
		npc.init_difftest(img_size);
		npc.irbuf = &iringbuf;
#endif
	}
	~Sdb() {};
	char *rl_gets();
	int cmd_help(char *args);
	int cmd_si(char *args);
	int cmd_info(char *args);
	int cmd_x(char *args);
	int cmd_d(char *args);
	int cmd_w(char *args);
	int cmd_c(char *args)
	{
		run(-1);
		return 0;
	}
	int cmd_q(char *args)
	{
		npc_state = NPC_QUIT;
		return -1;
	}
	int sdb_mainloop();
	int run(uint32_t n);
	static NPC_STATE npc_state;
	uint32_t get_reg(char *name, bool *success)
	{
		return npc.get_reg(name, success);
	}
	void print_iringbuf()
	{
		iringbuf.print_iringbuf();
	}
	Npc npc;

private:
	cmds cmd_table[NR_CMD] = {
		{"help", "used without args Display information about all supported commands", &Sdb::cmd_help},
		{"c", "used without args Continue the execution of the program", &Sdb::cmd_c},
		{"q", "used without args Exit NPC", &Sdb::cmd_q},
		{"si", "used as si [N]   execution [N]=1 lines of program", &Sdb::cmd_si},
		{"info", "used as info r or info w   r print the register w print watchpoints", &Sdb::cmd_info},
		{"x", "used as N EXPR  use EXPR as the start and print N hex", &Sdb::cmd_x},
		{"d", "used as d id    delete a watch point with id", &Sdb::cmd_d},
		{"w", "used as w EXPR  add a watch point with expression", &Sdb::cmd_w},
	};
	// {"test", "used without args perform some test", cmd_test}};
	int parse_args(int argc, char *argv[]);
	long load_img();

	Expr expr;
	Wpool wpool;
	Iringbuf iringbuf;
	Elf elf;
	bool is_batch_mode = false;
	char *log_file = NULL;
	char *diff_so_file = NULL;
	char *img_file = NULL;
	char *elf_file = NULL;
	int difftest_port = 1234;
	long img_size = 0;
};