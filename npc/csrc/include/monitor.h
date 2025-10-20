#ifndef MONITOR_H
#define MONITOR_H

word_t expr(char *e, bool *success);

void new_wp(char *e, bool *success);
void free_wp(int NO);
void watchpoint_printf();
int watchpoint_exec(int *sign);

void init_monitor(int argc, char *argv[]);
void sdb_set_batch_mode();
void parse_elf(char *elf_file);

#endif
