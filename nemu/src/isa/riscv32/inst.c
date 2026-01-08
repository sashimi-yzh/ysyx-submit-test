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

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>

#include <elf.h>  // 主要ELF定义
#include <cpu/itrace.h>
#include "isa.h"

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

#define MSTATUS 0x300   // 机器状态寄存器
#define MTVEC   0x305   // 异常向量基地址
#define MEPC    0x341   // 异常程序计数器
#define MCAUSE  0x342   // 异常原因
#define MSCRATCH 0x340  // 机器临时寄存器

enum {
	TYPE_I, TYPE_U, TYPE_S,
	TYPE_N, 
	TYPE_J, TYPE_R, TYPE_B// none
};


#define src1R() do { *src1 = R(rs1); } while (0)// 读取寄存器cpu.gpr[rs1]的值到src1
#define src2R() do { *src2 = R(rs2); } while (0)// 读取寄存器cpu.gpr[rs2]的值到src2
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0) //提取立即数
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0) 
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0) 
#define immJ() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 20) | \
							(BITS(i, 30, 21) << 1) | \
							(BITS(i, 20, 20) << 11) | \
							(BITS(i, 19, 12) << 12);  \
							} while(0) 
#define immB() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 12) | \
							(BITS(i, 30, 25) << 5) | \
							(BITS(i, 11, 8) << 1) | \
							(BITS(i, 7, 7) << 11);  \
							} while(0) 

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
	uint32_t i = s->isa.inst;//读取的内存值
	int rs1 = BITS(i, 19, 15);// 从位19-15提取rs1寄存器编号
	int rs2 = BITS(i, 24, 20);// 从位24-20提取rs2寄存器编号  
	*rd     = BITS(i, 11, 7); // 从位11-7提取rd寄存器编号
	switch (type) {
		case TYPE_I: src1R();          immI(); break;
		case TYPE_U:                   immU(); break;
		case TYPE_S: src1R(); src2R(); immS(); break;
		case TYPE_J:                   immJ(); break;
		case TYPE_R: src1R(); src2R();         break;
		case TYPE_B: src1R(); src2R(); immB(); break;
		case TYPE_N: break;
		default: panic("unsupported type = %d", type);
	}
	//printf("PC: 0x%08X, inst: 0x%08X\nrs1: %d, rd: %d, imm: %d\n\n", s->pc, i, rs1, *rd, *imm);
}//根据传入的指令类型type来进行操作数的译码

#define CSR(i) *CSRs(i)
static vaddr_t* CSRs(word_t imm) {
  switch (imm)
  {
    case MEPC: return &(cpu.csr.mepc);
    case MCAUSE: return &(cpu.csr.mcause);
    case MSTATUS: return &(cpu.csr.mstatus);
    case MTVEC: return &(cpu.csr.mtvec);
	case 0xFFFFFF11: return &(cpu.csr.mvendorid);
	case 0xFFFFFF12: return &(cpu.csr.marchid);
    default: {printf("imm=0x%x\n", imm);
		panic("Error CSR!");}
  }
}

static int decode_exec(Decode *s) {
	s->dnpc = s->snpc; //同步动态pc=静态pc

#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
	int rd = 0; \
	word_t src1 = 0, src2 = 0, imm = 0; \
	decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
	__VA_ARGS__ ; \
}
#define SHAMT (BITS(s->isa.inst, 25, 20) & 0x1F)

	INSTPAT_START();

	//异常响应机制
	INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, s->dnpc = isa_raise_intr(3, s->pc); NEMUTRAP(s->pc, R(10))); // R(10) is $a0
	INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, R(rd) = CSR(imm); CSR(imm) = src1;);
	INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, R(rd) = CSR(imm); CSR(imm) |= src1;);
	INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , I, s->dnpc = isa_raise_intr(11, s->pc)); 
	INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , R, s->dnpc = CSR(MEPC) + 4;); 

	INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm);
	INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(rd) = (src1 < imm) ? 1 : 0 );
	INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, R(rd) = ((int32_t)src1 < (int32_t)imm) ? 1 : 0 );
	INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm);
	INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, R(rd) = ((int32_t)src1)  >> SHAMT);
	INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, R(rd) = (src1) <<  SHAMT);
	INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, R(rd) = (src1) >> SHAMT);
	INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = (src1 ^ imm) );
	INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1 + imm, 4));
	INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = (int16_t)Mr(src1 + imm, 2) );
	INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = (uint16_t)Mr(src1 + imm, 2) );
	INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(rd) = (int32_t)(int8_t)Mr(src1 + imm, 1) );
	INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = src1 | imm );
	INSTPAT("0000??? ????? 00000 000 00000 00011 11", fence  , I, {} );
	INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, 
		s->dnpc = (src1 + imm) &~ 1; 
		IFDEF(CONFIG_FTRACE, INSTPAT_FTRACE_JALR); 
		R(rd) = s->pc + 4);
	INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J,   
		s->dnpc = s->pc + imm; 
		IFDEF(CONFIG_FTRACE, INSTPAT_FTRACE_JAL);
		R(rd) = s->pc + 4);

	INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2) );
	INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + imm, 2, src2) );
	INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2) );
	INSTPAT("??????? ????? ????? 011 ????? 01000 11", sd     , S, Mw(src1 + imm, 8, src2) );

	INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
	INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2);
	INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = (src1 ^ src2) );
	INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = (src1 | src2) );
	INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2 );
	INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = src1 * src2 );
	INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, R(rd) = ( ( (int64_t)(int32_t)src1 * (int64_t)(int32_t)src2 ) >>32 )& 0xFFFFFFFF);
	INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu , R, R(rd) = ( ( (int64_t)(int32_t)src1 * (uint64_t)(uint32_t)src2 ) >>32 )& 0xFFFFFFFF);
	INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, R(rd) = ( ( (uint64_t)(uint32_t)src1 * (uint64_t)(uint32_t)src2 ) >>32 )& 0xFFFFFFFF);
	INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = (src2 == 0) ? -1 : ( ( (int32_t)src1 == INT32_MIN && (int32_t)src2 == -1) ? INT32_MIN : (int32_t)src1 / (int32_t)src2 ) );
	INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = (src2 == 0) ? UINT32_MAX : ((uint32_t)src1 / (uint32_t)src2) );
	INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = (src2 == 0) ? (int32_t)src1 : ( ( (int32_t)src1 == INT32_MIN && (int32_t)src2 == -1) ? 0 : (int32_t)src1 % (int32_t)src2 )  );
	INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = (src2 == 0) ? (uint32_t)src1 : (uint32_t)src1 % (uint32_t)src2);
	INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << ( (uint32_t)src2 & 0x1F ) );
	INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = ((int32_t)src1 < (int32_t)src2) ? 1 : 0 );
	INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = (src1 < src2) ? 1 : 0 );
	INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = (int32_t)src1 >> ((uint32_t)src2 & 0x1F) );
	INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = src1 >> ( (uint32_t)src2 & 0x1F ) );


	INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, if(src1 != src2) s->dnpc = s->pc + imm);
	INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if(src1 == src2) s->dnpc = s->pc + imm; );
	INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if((int32_t)src1 >= (int32_t)src2) s->dnpc = s->pc + imm);
	INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if(src1 >= src2) s->dnpc = s->pc + imm);
	INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if((int32_t)src1 < (int32_t)src2) s->dnpc = s->pc + imm);
	INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if((uint32_t)src1 < (uint32_t)src2) s->dnpc = s->pc + imm);


	INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm );



	INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
	//指令执行操作:将pc值赋值给cpu.gpr[5],即t0
	INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
	//指令执行操作:读取*0x80000010对应值后两位,赋值到寄存器a0(cpi.gpr[10])
	INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));
	//指令执行操作:1对应uint8_t，8字节对应2位16进制，故只将0x80000000后两位赋值给内存*0x80000010对应值
	INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
	//INSTPAT(模式字符串                             , 指令名称,类型,指令执行操作);
	INSTPAT_END();

	R(0) = 0; // reset $zero to 0

	//printf("0x%08x: 0x%08x\n", s->pc, s->isa.inst);
	// if((s->isa.inst & 0b1111111) == 0b1100011) { //判断是否为分支语句
	// 	printf("0x%08x\t",s->isa.inst);
	// 	if(s->dnpc == (s->pc + 4)){ printf("0\n");}   //0代表没有跳转
	// 	else{ printf("1\n"); }  //1代表跳转
	// }

	return 0;
}

int isa_exec_once(Decode *s) {
	//printf("0x%x\n", s->snpc);
	//printf("[0x%x]=0x%x\n", s->snpc, s->isa.inst);
	s->isa.inst = inst_fetch(&s->snpc, 4);//取值：读取内存并返回&&更新s->snpc(静态pc+4)
	IFNDEF(CONFIG_ITRACE,  iringbuf_trace(s));
	return decode_exec(s);//译码&&执行
}


/**实现指令环形缓冲区 - iringbuf的相关函数*/
Iringbuf *iringbuf = NULL;

void iringbuf_trace(Decode *s){
    //初始化指令环形缓冲区：第一次调用iringbuf时分配内存
	if (iringbuf == NULL) {
        iringbuf = (Iringbuf *)calloc(1, sizeof(Iringbuf));
        iringbuf->count = 0;
        iringbuf->first = NULL;
        iringbuf->last = NULL;
    }
	//向iringbuf链表写入元素
	IringbufNode *node = (IringbufNode *)malloc(sizeof(IringbufNode));
	node->pc = s->pc;
	node->inst = s->isa.inst;
	node->next = NULL;
    node->prev = NULL;
	if(iringbuf->last == NULL) {
		iringbuf->first = node;
		iringbuf->last = node;
	}else{
		if(iringbuf->count == IRINGBUF_LENGTH){
			IringbufNode *old_first = iringbuf->first;
			iringbuf->first = old_first->next;
			iringbuf->first->prev = NULL;
			free(old_first);
			iringbuf->count--;

		}
		iringbuf->last->next = node;
		node->prev = iringbuf->last;
		iringbuf->last = node;
	}
	iringbuf->count++;

	//iringbuf_display();
}

void iringbuf_display(){
	#ifdef CONFIG_ITRACE
	printf("\nAccess to memory out of bounds!\tThe most recent instruction:\n");
	int i = 0;
	char logbuf[128];
	IringbufNode *current = iringbuf->first;
	while(current != NULL){
		/*copy自cpu-exec文件:exec_once函数 */
		char *p = logbuf; 
		p += snprintf(p, sizeof(logbuf), "0X%08X:0X%08X ", current->pc, current->inst);
		void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
		disassemble(p, logbuf + sizeof(logbuf) - p, current->pc, (uint8_t *)&current->inst, 4);
		printf("NO.%d ",i);
		puts(logbuf);
		current = current->next;
		i++;
	}
	printf("End!\n\n");
	#endif
}

/**实现ftrace的相关函数*/
TailRecNode  *tail_rec_head = NULL;
int call_depth = 0;

static int find_symbol_func(paddr_t target, bool is_call) {
	int i;
	for (i = 0; i < ftrace_symbol_table_size ; i++) {
		if (ELF32_ST_TYPE(ftrace_symbol_table[i].info) == STT_FUNC) {
			if (is_call) {
				if (ftrace_symbol_table[i].addr == target) break; // 对于函数调用：精确匹配目标地址（函数入口点）
			} else {
				if (ftrace_symbol_table[i].addr <= target && target < ftrace_symbol_table[i].addr + ftrace_symbol_table[i].size) break;
			}// 对于函数返回：范围匹配（函数内的任何地址）
		}
	}
	return i < ftrace_symbol_table_size  ?i:-1;
}

void trace_func_call(paddr_t pc, paddr_t target, bool is_tail) {
	if (ftrace_symbol_table == NULL) return;
	// 初始化：第一次调用时创建链表头节点
	if (tail_rec_head == NULL) {
		tail_rec_head = (TailRecNode *)malloc(sizeof(TailRecNode));
        tail_rec_head->pc = 0;
        tail_rec_head->depth = 0;
        tail_rec_head->next = NULL;
    }

	call_depth++;
	if (call_depth <= 2) return; // 忽略前2层调用（_trm_init和main()）

	int i = find_symbol_func(target, true);

	//输出
	printf(FMT_PADDR ": ", pc);                               // 地址部分
	for(int k=0;k<(call_depth-2);k++) {printf(" ");}          // 缩进部分  
	printf("call [");                                         // call固定文本
	if (i >= 0) {printf("%s", ftrace_symbol_table[i].name);}  // 函数名
	else {printf("???"); }                                    // 未知函数
    printf("@" FMT_PADDR "]\n", target);                      // 目标地址和换行

	// 如果是尾调用，记录信息
	if (is_tail) {
		TailRecNode *node = (TailRecNode *)malloc(sizeof(TailRecNode));
		node->pc = pc;
		node->depth = call_depth - 1;
		node->next = tail_rec_head->next;
		tail_rec_head->next = node;
	}
}

void trace_func_ret(paddr_t pc) {
	if (ftrace_symbol_table == NULL) return;
	//初始化：第一次调用时创建链表头节点
	if (tail_rec_head == NULL) {
		tail_rec_head = (TailRecNode *)malloc(sizeof(TailRecNode));
        tail_rec_head->pc = 0;
        tail_rec_head->depth = 0;
        tail_rec_head->next = NULL;
    }
	
	if (call_depth <= 2) return; // 忽略前2层调用（_trm_init和main()）
	int i = find_symbol_func(pc, false);

	//输出
	printf(FMT_PADDR ": ", pc);                               // 地址部分
	for(int k=0;k<(call_depth-2);k++) {printf(" ");}          // 缩进部分  
	printf("ret [");                                          // ret固定文本
	if (i >= 0) {printf("%s", ftrace_symbol_table[i].name);}  // 函数名
	else {printf("???");}                                     // 未知函数   	                            
	printf("]\n");                                            // ]和换行

	
	call_depth--;

	// 当遇到函数返回时，检查是否有待处理的尾调用
	TailRecNode *node = tail_rec_head->next;
	if ( (node != NULL) && (node->depth == call_depth) ){
			paddr_t ret_target = node->pc;
			tail_rec_head->next = node->next;
			free(node);
			trace_func_ret(ret_target);
	}
}
