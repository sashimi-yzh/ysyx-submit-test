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

#include "../local-include/reg.h"

char *cause_val2str(word_t cause)
{
    switch(cause) {
        case 0: return "Instruction address misaligned";
        case 1: return "Instruction access fault";
        case 2: return "Illegal instruction";
        case 3: return "Breakpoint";
        case 4: return "Load address misaligned";
        case 5: return "Load access fault";
        case 6: return "Store/AMO address misaligned";
        case 7: return "Store/AMO access fault";
        case 8: return "Environment call from U-mode";
        case 9: return "Environment call from S-mode";
        case 11: return "Environment call from M-mode";
        case 12: return "Instruction page fault";
        case 13: return "Load page fault";
        case 15: return "Store/AMO page fault";
        case -1: return "Yield";
        default: return "Unknown cause";
    }
}

void etrace()
{
    printf("[ETRACE] cause: %s!\nmcause=0x%08x, mepc: 0x%08x, mtvec: 0x%08x\n", cause_val2str(Mcause()), Mcause(), Mepc(), Mtvec());
}

word_t isa_raise_intr(word_t NO, vaddr_t epc)
{
    /* TODO: Trigger an interrupt/exception with ``NO''.
     * Then return the address of the interrupt/exception vector.
     */

    Mcause() = NO;
    Mepc() = epc;
    Mstatus() = (Mstatus() | 0x1800); // set M-mode
    Mstatus() = ((Mstatus() << 4) & (0x80)) | (Mstatus() & (~0x80)); // save interrupt enable
    Mstatus() = (Mstatus() & (~0x8)); // disable interrupt


    // void isa_reg_display();
    // isa_reg_display();
    // IFDEF(CONFIG_ETRACE, etrace());
    
    return Mtvec();
}

word_t isa_query_intr()
{
    return INTR_EMPTY;
}
