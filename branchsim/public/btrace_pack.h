#ifndef __BTRACE_PACK_H__
#define __BTRACE_PACK_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	uint32_t pc;
	uint32_t code;
	uint32_t nxt_pc;
} btrace_record_t;

typedef struct btrace_pack_imp* btrace_pack_t;

btrace_pack_t btrace_pack_create(const char* path);
btrace_pack_t btrace_pack_open(const char* path);
void btrace_pack_close(btrace_pack_t pack);
void btrace_pack_add(btrace_pack_t pack, const btrace_record_t* record);
// return 0 if no record, otherwise return 1 and fill record
int btrace_pack_pick(btrace_pack_t pack, btrace_record_t* record);

#ifdef __cplusplus
}
#endif

#endif
