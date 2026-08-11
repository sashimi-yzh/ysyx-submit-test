#ifndef NPC_BASE_H
#define NPC_BASE_H

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <generated/autoconf.h>
#include <macro.h>

typedef uint32_t paddr_t;
typedef uint32_t word_t;
typedef int32_t sword_t;
typedef word_t vaddr_t;

#define FMT_WORD  "0x%08" PRIx32
#define FMT_PADDR "0x%08" PRIx32

#ifdef __cplusplus
#define NPC_EXTERN_C_BEGIN extern "C" {
#define NPC_EXTERN_C_END }
#else
#define NPC_EXTERN_C_BEGIN
#define NPC_EXTERN_C_END
#endif

#endif
