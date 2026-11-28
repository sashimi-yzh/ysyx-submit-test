#ifndef __NPC_DIFFTEST_H__
#define __NPC_DIFFTEST_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void init_difftest(const char *ref_so_file, long img_size);
void check_difftest(uint32_t pc);
bool difftest_enabled();


#ifdef __cplusplus
}
#endif

#endif
