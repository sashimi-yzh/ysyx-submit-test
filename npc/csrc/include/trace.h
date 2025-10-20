#ifndef TRACE_H
#define TRACE_H

#define RINGBUF_MAX 20

void iringbuf(uint32_t thispc, uint32_t inst);
void iringbuf_printf();
void parse_elf(char *elf_file);

#ifdef __cplusplus
extern "C" {
#endif

void call_func(word_t pc, word_t func_addr);
void ret_func(word_t pc);

#ifdef __cplusplus
}
#endif

#endif