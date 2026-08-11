#ifndef NPC_MONITOR_INTERFACE_H
#define NPC_MONITOR_INTERFACE_H

#include <npc/base.h>

NPC_EXTERN_C_BEGIN

void init_monitor(int argument_count, char *argument_values[]);
void delete_workspace(void);

void init_mem(void);
void init_difftest(char *reference_so, long image_size, int port);

void init_sdb(void);
void sdb_set_batch_mode(void);
bool check_watchpoints(void);

void init_disasm(void);
void disassemble(char *output, int output_size, uint64_t pc, uint8_t *instruction_bytes, int byte_count);

// the struct for trace and image
typedef struct {
  char *image;
  char *elf;
  char *reference;
  char *log;
  char *ftrace_log;
  char *etrace_log;
  char *mtrace_log;
  char *dtrace_log;
  int reference_port;
} MonitorOptions;
NPC_EXTERN_C_END

#endif
