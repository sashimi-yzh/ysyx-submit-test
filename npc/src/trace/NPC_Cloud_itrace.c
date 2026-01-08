#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//
#include <dlfcn.h>

#include "npc.h"
#include "trace.h"

#ifdef NPC_ITRACE
//#include <capstone/capstone.h>
#include "../../tools/capstone/include/capstone/capstone.h"


// 函数指针类型定义
typedef cs_err (*cs_open_func_t)(cs_arch, cs_mode, csh*);
typedef size_t (*cs_disasm_func_t)(csh, const uint8_t*, size_t, uint64_t, size_t, cs_insn**);
typedef void (*cs_free_func_t)(cs_insn*, size_t);

static cs_disasm_func_t cs_disasm_dl = NULL;
static cs_free_func_t cs_free_dl = NULL;

static csh handle;

void init_disasm() {
	void *dl_handle;
	//dl_handle = dlopen("../capstone_ori/libcapstone.so.6", RTLD_LAZY);
	dl_handle = dlopen("./tools/capstone/libcapstone.so.6", RTLD_LAZY);
	assert(dl_handle);

  	cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = NULL;
	cs_open_dl = (cs_open_func_t)dlsym(dl_handle, "cs_open");
	assert(cs_open_dl);

	cs_disasm_dl = (cs_disasm_func_t)dlsym(dl_handle, "cs_disasm");
  	assert(cs_disasm_dl);

	cs_free_dl = (cs_free_func_t)dlsym(dl_handle, "cs_free");
  	assert(cs_free_dl);

  	cs_arch arch = CS_ARCH_RISCV;
  	cs_mode mode = CS_MODE_RISCV32;
	int ret = cs_open_dl(arch, mode, &handle);
  	assert(ret == CS_ERR_OK);

	Log("Initialized the disasm.");

}

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
	cs_insn *insn;
	size_t count = cs_disasm_dl(handle, code, nbyte, pc, 0, &insn);
	assert(count == 1);
	int ret = snprintf(str, size, "\t%s", insn->mnemonic);
	if (insn->op_str[0] != '\0') {
		snprintf(str + ret,   size - ret, "\t%s", insn->op_str);
	}
	cs_free_dl(insn, count);
}

/**实现itrace的相关函数*/
Itrace *itrace = NULL;

void instruction_trace(uint32_t top_pc, uint32_t top_inst, uint32_t top_dnpc){
	//初始化：第一次调用itrace时分配内存
	if (itrace == NULL) {
		itrace = (Itrace *)calloc(1, sizeof(Itrace));
		itrace->count = 0;
		itrace->first = NULL;
		itrace->last = NULL;
	}
	//向itrace链表写入元素
	ItraceNode *node = (ItraceNode *)malloc(sizeof(ItraceNode));
	node->pc = top_pc;
	node->inst = top_inst;
	node->next = NULL;
	node->prev = NULL;
	if(itrace->last == NULL) {
		itrace->first = node;
		itrace->last = node;
	}else{
		itrace->last->next = node;
		node->prev = itrace->last;
		itrace->last = node;
	}
	itrace->count++;
	//输出itrace
	char logbuf[128];
	char *p = logbuf; 
	p += snprintf(p, sizeof(logbuf), "0x%08x:0x%08x ", itrace->last->pc, itrace->last->inst);
	disassemble(p, logbuf + sizeof(logbuf) - p, itrace->last->pc, (uint8_t *)&itrace->last->inst, 4);
	if(NPC_ITRACE) {printf("[itrace]%s \tdnpc=0x%x\n\n",logbuf,top_dnpc);}
	//写入文本
	FILE *file = fopen("build/nemu-log.txt", "a");
    if (file == NULL) { // 尝试创建build目录（如果不存在）
        int ret = system("mkdir -p build");
		if (ret != 0) {// 处理错误，比如输出错误信息
			printf("Warning: Failed to create build directory (error code: %d)\n", ret);
		}
        file = fopen("build/nemu-log.txt", "a");
        if (file == NULL) {
            perror("无法打开日志文件");
            return;
        }
    }
    fprintf(file, "%s\n", logbuf);// 写入内容并换行
    fclose(file);// 关闭文件
}


void itrace_display(){
	printf("\nAccess to memory out of bounds!\tThe most recent instruction:\n");
	int i = 0;
	char logbuf[128];
	ItraceNode *current = itrace->first;
	while(current != NULL){
		/*copy自cpu-exec文件:exec_once函数 */
		char *p = logbuf; 
		p += snprintf(p, sizeof(logbuf), "0X%08X:0X%08X ", current->pc, current->inst);
		disassemble(p, logbuf + sizeof(logbuf) - p, current->pc, (uint8_t *)&current->inst, 4);
		printf("NO.%d ",i);
		puts(logbuf);
		current = current->next;
		i++;
	}
	printf("End!\n\n");
}
#endif