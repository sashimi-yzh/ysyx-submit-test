#ifndef __SDBC_H__
#define __SDBC_H__

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef struct sdb_debuger_imp* sdb_debuger;
typedef uint32_t sdb_paddr_t;

typedef struct{
	uint8_t* data;
	int len;
}sdbc_vlen_inst;

typedef enum{
	SDB_JUMP_NORMAL,
	SDB_JUMP_CALL,
	SDB_JUMP_RET
}sdb_jump_type;

typedef enum {
	SDB_STATE_RUNNING,
	SDB_STATE_STOP,
	SDB_STATE_END,
	SDB_STATE_ABORT,
	SDB_STATE_QUIT
}sdb_run_state;

typedef struct {
	sdb_run_state state;
	sdb_paddr_t pc;
	uint32_t halt_ret;
}sdbc_cpu_state;

// should return the next pc
typedef sdb_paddr_t(*sdb_cpu_executor)(size_t nstep);
// should return pointer to nbyte data at addr
typedef uint8_t*(*sdb_mem_loader)(sdb_paddr_t addr, size_t nbyte);
// should fill reg_snapshot with current register values
// reg_snapshot has enough size for all registers + extra
// never write out of register range!!!!
typedef void(*sdb_reg_snapshoter)(uint32_t* reg_snapshot);

typedef sdbc_vlen_inst(*sdb_inst_fetcher)(sdb_paddr_t pc);
typedef void(*sdb_disasmsembler)(char* str, int size, uint64_t pc, uint8_t* code, int nbyte);
typedef sdb_jump_type(*sdb_jump_recognizer)(sdbc_vlen_inst inst_code);

#define SDB_ENTRACE_INST 1
#define SDB_ENTRACE_FUNC 2
#define SDB_ENTRACE_DIFFTEST 4

sdb_debuger sdb_create_debuger(
	sdb_paddr_t init_pc,
	size_t img_size,
	sdb_cpu_executor exec,
	sdb_mem_loader loadmem,
	sdb_reg_snapshoter shotreg,
	const char** reg_names,
	size_t n_reg_names,
	sdb_inst_fetcher fetcher
);

void sdb_destroy_debuger(sdb_debuger dbg);

void sdb_enable_entrace(sdb_debuger dbg, int flags);

bool sdb_try_findload_elf_fromimg(sdb_debuger dbg, const char* img_file);
void sdb_load_elf(sdb_debuger dbg, const char* filename);
void sdb_load_difftest_ref(sdb_debuger dbg, const char* so_file, int port);

void sdb_exec(sdb_debuger dbg, const char* cmdline);
void sdb_skip_difftest_ref(sdb_debuger dbg);

void sdb_abort(sdb_debuger dbg);

void sdb_set_state(sdb_debuger dbg, sdbc_cpu_state state);
sdbc_cpu_state sdb_get_state(sdb_debuger dbg);


#ifdef __cplusplus
}
#endif

#endif
