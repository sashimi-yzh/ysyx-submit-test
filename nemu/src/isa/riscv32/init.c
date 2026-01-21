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
static const uint32_t img [] = 
#ifdef CONFIG_SOC_MODE
  {
    0x00500093,   // li	ra,5
    0x00300113,   // li	sp,3
    0x002081b3,   // add	gp,ra,sp
    0x02208233,   // mul	tp,ra,sp
    0xa00002b7,   // lui	t0,0xa0000
    0x0042a023,   // sw	tp,0(t0) # a0000000 
    0x0002a183,   // lw	gp,0(t0)
    0x00320463,   // beq	tp,gp,30000024 <ok>
    0x00100513,   // li	a0,1
    0x00100073   // ebreak
  };
#else
  {
    0x00500093,  // li	ra,5
    0x00300113,  // li	sp,3
    0x002081b3,  // add	gp,ra,sp
    0x02208233,  // mul	tp,ra,sp
    0x00001297,  // auipc	t0,0x1
    0x01c28293,  // addi	t0,t0,28
    0x0042a023,  // sw	tp,0(t0) # 8000102c
    0x0002a183,  // lw	gp,0(t0)
    0x00320463,  // beq	tp,gp,28
    0x00100513,  // li	a0,1
    0x00100073   // ebreak
  };
#endif
// 测试一下加法，乘法以及访存和跳转

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
