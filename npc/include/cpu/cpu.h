#ifndef __CPU_CPU_H__
#define __CPU_CPU_H__

#include <common.h>

#ifdef __cplusplus
extern "C" {
#endif

void cpu_exec(uint64_t n);
void assert_fail_msg();

#ifdef __cplusplus
}
#endif

#endif
