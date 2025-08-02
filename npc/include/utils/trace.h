#ifndef TRACE_H
#define TRACE_H

void parse_elf(const char *elf_file);
void trace_func_call(uint32_t pc, uint32_t target);
void trace_func_ret(uint32_t pc);

#endif // TRACE_H
