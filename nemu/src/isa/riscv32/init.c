/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <memory/paddr.h>
#include "local-include/reg.h"

// this is not consistent with uint8_t
// but it is ok since we do not access the array directly
  // static const uint32_t img [] = {
  //   0x00000297,  // auipc t0,0
  //   0x00028823,  // sb  zero,16(t0)
  //   0x0102c503,  // lbu a0,16(t0)
  //   0x00100073,  // ebreak (used as nemu_trap)
  //   0xdeadbeef,  // some data
  // };
//   static const uint32_t img []  = { 
//         0x00100513,      //addi a0 x0 1
//         0x00150513,      //addi a0 a0 1
//         0x00150513,      //addi a0 a0 1
//         0x70000117,      //auipc	sp,0xef001
//         0xffc10113,      //addi	  sp,sp,-4 # f001000 
//         0x00a12223,      //sw a0, 4(sp)
//         0x00000513,      //addi a0 x0 0
//         0x00412503,      //lw a0, 4(sp)
//         0x00150513,      //addi a0 a0 1
//         0xffc50513,      //addi a0 a0 -4
//         0x00100073,      //ebreak
// };

static const uint32_t img [] = {
        0x00100513,    //addi a0 x0 1        30000000  
        0x00150513,    //addi a0 a0 1        30000004  
        0x00150513,    //addi a0 a0 1        30000008  
        0xdf001117,    //auipc sp,0x000df001 3000000c  
        0x00a12223,    //sw a0, 4(sp)        30000010  
        0x00000513,    //addi a0 x0 0        30000014  
        0x00C51A63,    //bne a0,a2 0x14      30000018
        0x00412503,    //lw a0, 4(sp)        3000001c 
        0x004005EF,    //jal a1, 4           30000020
        0xFF4585E7,    //jalr a1, a1 -12    30000024
        0x004005EF,    //jal a1, 4           3000002c
        0x004005EF,    //jal a1, 4           30000030
        0xffd50513,    //addi a0 a0 -4       30000028 
        0x00100073,    //ebreak              30000034 
};
static void restart() {
  /* Set the initial program counter. */
  cpu.pc = RESET_VECTOR;

  /* The zero register is always 0. */
  cpu.gpr[0] = 0;
  cpu.csr[mvendorid] = 0x78797379;
  cpu.csr[marchid] = 24100012;
}

void init_isa() {
  /* Load built-in image. */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));

  /* Initialize this virtual computer system. */
  restart();
}
