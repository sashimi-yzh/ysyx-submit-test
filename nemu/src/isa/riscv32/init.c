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

// this is not consistent with uint8_t
// but it is ok since we do not access the array directly
static const uint32_t img [] = {
    0xa00002b7, // auipc t0,0
    0x12345337, // addi t0,t0,36     // t0 = 指令区首地址+36
    0x67830313, // li a0,1            // a0 = 1
    0x00629123, // sw  a0,0(t0)       // [t0+0] = a0 (把1写到数据区)
    0x00629123, // lw  a0,0(t0)       // a0 = [t0+0] (从数据区读回a0)
    0x00629223, // jal zero, +4       // 跳转到下一条（演示jal）
    0x00229503, // addi t0,t0,1       // t0 = t0 + 1
    0x00429583, // bne a0,a1,-4       // 如果a0!=a1, 跳回前面
    0x00100073, // ebreak             // 终止
    0xdeadbeef, // 数据区内容
    0x12345678, // 数据区内容
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
