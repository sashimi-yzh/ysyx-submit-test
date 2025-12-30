#ifndef __TRACE_H__
#define __TRACE_H__



//指令调用踪迹缓冲区 - itrace
void init_disasm();

typedef struct ItraceNode {
	struct ItraceNode *next;
	struct ItraceNode *prev;
	uint32_t pc;
	uint32_t inst;
} ItraceNode;

typedef struct Itrace {
	int count;
	ItraceNode *first;
	ItraceNode *last;
} Itrace;

extern Itrace *itrace;

void instruction_trace(uint32_t top_pc, uint32_t top_inst, uint32_t top_dnpc);
void itrace_display();

//函数调用的踪迹 - ftrace

//extern char *elf_file;

typedef struct {
	char name[32]; // 函数名
	uint32_t addr;
	unsigned char info;
	uint32_t size;
} Ftrace_Elf_Symbol_Table;
extern Ftrace_Elf_Symbol_Table *ftrace_symbol_table; 

typedef struct tail_rec_node {
	uint32_t pc;
	int depth;
	struct tail_rec_node *next;
} TailRecNode;
extern TailRecNode *tail_rec_head ; 

void load_elf(const char *elf_file) ;
void trace_func_call(uint32_t pc, uint32_t target, bool is_tail);
void trace_func_ret(uint32_t pc);

/*内存访问的踪迹 - mtrace的相关内容*/
void mtrace_read_display(uint32_t addr);
void mtrace_write_display(uint32_t addr);

#endif
