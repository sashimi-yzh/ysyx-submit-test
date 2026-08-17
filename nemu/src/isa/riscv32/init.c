/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <isa.h>
#include <memory/paddr.h>
#include <stdio.h>
// this is not consistent with uint8_t
// but it is ok since we do not access the array directly
static const uint32_t img[] = {
    0x00000297, // auipc t0,0
    0x00000313, // li t1,zero
    0x7ff00393, // li t2,2047
    0x02028223, // sb  zero,36(t0)
    0x0242c503, // lbu a0,36(t0)
    0x00130313, // addi t1,t1,1
    0xfe639ae3, // bne t2,t1,-12
    // 0x01004503, // lbu a0,0(zero) : error
    0x00100073, // ebreak (used as nemu_trap)
    0xdeadbeef, // some data
};

static void restart() {
  /* Set the initial program counter. */
  cpu.pc = RESET_VECTOR;

  /* The zero register is always 0. */
  cpu.gpr[0] = 0;
}

void init_isa() {
  /* Load built-in image. */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));

  /* Initialize this virtual computer system. */
  restart();
}
