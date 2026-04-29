#ifndef _ITRACE_PACK_H_
#define _ITRACE_PACK_H_

#include <stdint.h>
#include <stddef.h>

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct itrace_pack_imp* itrace_pack_t;

itrace_pack_t itrace_pack_create(const char* filename);

itrace_pack_t itrace_pack_openfp(FILE* fp);
itrace_pack_t itrace_pack_open(const char* filename);

void itrace_pack_close(itrace_pack_t pack);
size_t itrace_pack_size(itrace_pack_t pack);
size_t itrace_pack_nrecords(itrace_pack_t pack);

// add a pc record to the pack
void itrace_pack_add(itrace_pack_t pack, uint32_t pc);

// return a pc record and remove it from the pack
// return 0 if the pack is empty
uint32_t itrace_pack_pickone(itrace_pack_t pack);

#ifdef __cplusplus
}
#endif

#endif
