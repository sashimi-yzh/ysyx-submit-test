#ifndef __ISA_H__
#define __ISA_H__

#include <memory/memory.h>
#include <string.h>
#include <common.h>
#include <cpu/top.h>

// const int gpr_size = MUXDEF(CONFIG_RVE, 16, 32);
const int gpr_size = 16;
const int csr_size = 5;
typedef enum  {
  // STAP    = 0x180, 
  // MSTATUS = 0x300,
  // MTVEC   = 0x305,
  // MEPC    = 0x341,
  // MCAUSE  = 0x342,
  STAP    = 0, 
  MSTATUS = 1,
  MTVEC   = 2,
  MEPC    = 3,
  MCAUSE  = 4,
} csrs;

static const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

static const char *csr_names[] = {
  "stap", "mstatus", "mtvec", "mepc", "mcause"
};

typedef struct {
    word_t gpr[gpr_size];
    vaddr_t pc; 
    word_t csr[csr_size];
} CPU_state;

// this is not consistent with uint8_t
// but it is ok since we do not access the array directly
// static const uint32_t img [] = {
//         0x00100513,      //addi a0 x0 1
//         0x00150513,      //addi a0 a0 1
//         0x00150513,      //addi a0 a0 1
//         0x00150513,      //addi a0 a0 1
//         0x00150513,      //addi a0 a0 1
//         0x00000513,      //addi a0 x0 0
//         0x00100073,      //ebreak
// };
#ifndef CONFIG_SOC
static const uint32_t img [] = { 
        0x00100513,      //addi a0 x0 1
        0x00150513,      //addi a0 a0 1
        0x00150513,      //addi a0 a0 1
        0x00009117,      //auipc	sp,0x9 # 80009000
        0x00a12223,      //sw a0, 4(sp)
        0x00000513,      //addi a0 x0 0
        0x00412503,      //lw a0, 4(sp)
        0x00150513,      //addi a0 a0 1
        0xffc50513,      //addi a0 a0 -4
        // 0x00150513,      //addi a0 a0 1
        // 0x00150513,      //addi a0 a0 1
        // 0x00000513,      //addi a0 x0 1
        0x00100073,      //ebreak
};
#endif

#ifdef CONFIG_SOC
static const uint32_t img [] = {
        0x00100513,    //addi a0 x0 1        30000000  
        0x00150513,    //addi a0 a0 1        30000004  
        0x00150513,    //addi a0 a0 1        30000008  
        0xdf001117,    //auipc sp,0x000df001 3000000c  
        0x00a12223,    //sw a0, 4(sp)        30000010  
        0x00000513,    //addi a0 x0 0        30000014  
        0x00412503,    //lw a0, 4(sp)        30000018 
        0x00150513,    //addi a0 a0 1        3000001c 
        0xffc50513,    //addi a0 a0 -4       30000020 
        0x00100073,    //ebreak              30000024 
};

// static const uint32_t img [] = {
//         0x00100513,    //addi a0 x0 1        30000000  
//         0x00150513,    //addi a0 a0 1        30000004  
//         0x00150513,    //addi a0 a0 1        30000008  
//         0xdf001117,    //auipc sp,0x000df001 3000000c  
//         0x00a12223,    //sw a0, 4(sp)        30000010  
//         0x00000513,    //addi a0 x0 0        30000014  
//         0x00C51A63,    //bne a0,a2 0x14      30000018
//         0x00412503,    //lw a0, 4(sp)        3000001c 
//         0x004005EF,    //jal a1, 4           30000020
//         0xFF4585E7,    //jalr a1, a1 -12     30000024
//         0x004005EF,    //jal a1, 4           3000002c
//         0x004005EF,    //jal a1, 4           30000030
//         0xffd50513,    //addi a0 a0 -3       30000028 
//         0x00100073,    //ebreak              30000034 
// };
// static const uint32_t img [] = {
//         0x00100513,      //addi a0 x0 1     30000000       
//         0x00150513,      //addi a0 a0 1     30000004  
//         0x00250513,      //addi a0 a0 2     30000008  
//         0x00350513,      //addi a0 a0 3     3000000c  
//         0x00450513,      //addi a0 a0 4     30000010  
//         0xff550513,      //addi a0 a0 -11   30000014  
//         0x00100073,      //ebreak           30000018
// };
#endif

void isa_reg_display();

word_t isa_reg_str2val(const char *s, bool *success);


static void init_isa(){
/* Load built-in image. */
  // IFDEF(CONFIG_SOC,memcpy(guest_to_mrom(CONFIG_MROM_BASE), img, sizeof(img)));
  // IFNDEF(CONFIG_SOC,memcpy(guest_to_host(MBASE), img, sizeof(img)));
  memcpy(guest_to_host(MBASE), img, sizeof(img));

}

#endif