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
#ifndef __CPU_IRINGBUF_H__
#define __CPU_IRINGBUF_H__

#include <common.h>

#include <cpu/decode.h>

//指令环形缓冲区 - iringbuf
#define IRINGBUF_LENGTH 20

typedef struct IringbufNode {
	struct IringbufNode *next;
	struct IringbufNode *prev;
	word_t pc;
	word_t inst;
} IringbufNode;

typedef struct Iringbuf {
	int count;
	IringbufNode *first;
	IringbufNode *last;
} Iringbuf;

extern Iringbuf *iringbuf;

void iringbuf_display();
void iringbuf_trace(Decode *s);

//函数调用的踪迹 - ftrace
#define INSTPAT_FTRACE_JALR { \
	if(rd == 1){trace_func_call(s->pc, s->dnpc, false);}/*跳转到目标地址,保存返回地址(pc+4)到 ra(x1)*/\
    else if (s->isa.inst == 0x00008067) {trace_func_ret(s->pc);}/*ret: 函数返回,跳转回ra*/\
	else if(rd == 0 && imm == 0){trace_func_call(s->pc, s->dnpc, true);} /* 尾调用: 不保存返回地址 */\
}
#define INSTPAT_FTRACE_JAL {\
	if(rd == 1){trace_func_call(s->pc, s->dnpc, false);}/*跳转到目标地址,保存返回地址(pc+4)到 ra(x1)*/\
	else if(rd == 0) {trace_func_call(s->pc, s->dnpc, true);} /* 尾调用: 不保存返回地址 */\
}
	

typedef struct {
	char name[32]; // 函数名
	paddr_t addr;
	unsigned char info;
	word_t size;
} Ftrace_Elf_Symbol_Table;
extern Ftrace_Elf_Symbol_Table *ftrace_symbol_table; 

typedef struct tail_rec_node {
	paddr_t pc;
	int depth;
	struct tail_rec_node *next;
} TailRecNode;
extern TailRecNode *tail_rec_head ; 

extern size_t ftrace_symbol_table_size;

void trace_func_call(paddr_t pc, paddr_t target, bool is_tail);
void trace_func_ret(paddr_t pc);


#endif
