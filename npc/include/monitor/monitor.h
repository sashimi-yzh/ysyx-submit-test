#ifndef __MONITOR_MONITOR_H__
#define __MONITOR_MONITOR_H__

#include <common.h>

#ifdef __cplusplus
extern "C" {
#endif

void init_monitor(int argc, char *argv[]);
void npc_cleanup();
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_sdb();
void sdb_set_batch_mode();
void init_disasm();
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
bool wp_check();

#ifdef __cplusplus
}
#endif

#endif
