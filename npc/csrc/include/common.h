#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <macro.h>
#include <config.h>

typedef uint32_t   word_t;
typedef  int32_t  sword_t;
#define FMT_WORD "0x%08x"

typedef   word_t vaddr_t;
typedef uint32_t paddr_t;
#define FMT_PADDR "0x%08x"
typedef uint16_t ioaddr_t;

#endif

#ifndef __CPU_H__
#define __CPU_H__

enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };
extern bool pass_diff;
typedef struct {
  int state;
  vaddr_t halt_pc;
  uint32_t halt_ret;
} NPCState ;

typedef struct {
  word_t gpr[32];
  vaddr_t pc;
  word_t csr[4];
} CPU_state;

// decode
typedef struct {
  union {
    uint32_t val;
  } inst;
} ISADecodeInfo;

typedef struct Decode {
  vaddr_t pc;
  vaddr_t snpc; // static next pc
  vaddr_t dnpc; // dynamic next pc
  ISADecodeInfo isa;
  char logbuf[128];
} Decode;

#endif

#ifndef __ISA_H__
#define __ISA_H__



extern CPU_state cpu;



#endif

#ifndef __DIFFTEST_H__
#define __DIFFTEST_H__

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

#endif


