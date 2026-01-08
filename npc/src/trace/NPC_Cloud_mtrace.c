#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "npc.h"
#include "trace.h"


/*内存访问的踪迹 - mtrace的相关内容*/
typedef struct mtraceNode {
	struct mtraceNode *next;
	struct mtraceNode *prev;
	uint32_t pmem;
	uint32_t addr;
} mtraceNode;

typedef struct mtrace {
	int count;
	mtraceNode *first;
	mtraceNode *last;
} mtrace;

mtrace *mtrace_read = NULL; 
mtrace *mtrace_write = NULL; 

void mtrace_read_display(uint32_t addr){
    // 初始化：第一次调用时分配内存
	if (mtrace_read == NULL) {
        mtrace_read = (mtrace *)calloc(1, sizeof(mtrace));
        mtrace_read->count = 0;
        mtrace_read->first = NULL;
        mtrace_read->last = NULL;
    }
	//向mtrace_read链表尾部增加元素
	mtraceNode *node = (mtraceNode *)malloc(sizeof(mtraceNode));;
	node->addr = addr;
	node->pmem = *paddr_read(addr);
	node->next = NULL;
    node->prev = NULL;
	if(mtrace_read->last == NULL) {
		mtrace_read->first = node;
		mtrace_read->last = node;
	} else {
		mtrace_read->last->next = node;
		node->prev = mtrace_read->last;
		mtrace_read->last = node;
	}
	mtrace_read->count++;
	//display
	mtraceNode *current = mtrace_read->first;
    int i = 0;
	printf("\nmtrace_read_dispaly:\n");
    while (current != NULL) {
        printf("NO.%d 0X%08X:0X%08X\n", i++, current->addr, current->pmem);
        current = current->next;
    }
	printf("End!\n\n");
}

void mtrace_write_display(uint32_t addr){
    // 初始化：第一次调用时分配内存
	if (mtrace_write == NULL) {
        mtrace_write = (mtrace *)calloc(1, sizeof(mtrace));
        mtrace_write->count = 0;
        mtrace_write->first = NULL;
        mtrace_write->last = NULL;
    }
	//向mtrace_write链表尾部增加元素
	mtraceNode *node = (mtraceNode *)malloc(sizeof(mtraceNode));;
	node->addr = addr;
	node->pmem = *paddr_read(addr);
	node->next = NULL;
    node->prev = NULL;
	if(mtrace_write->last == NULL) {
		mtrace_write->first = node;
		mtrace_write->last = node;
	} else {
		mtrace_write->last->next = node;
		node->prev = mtrace_write->last;
		mtrace_write->last = node;
	}
	mtrace_write->count++;
	//display
	mtraceNode *current = mtrace_write->first;
    int i = 0;
	printf("\nmtrace_write_dispaly:\n");
    while (current != NULL) {
        printf("NO.%d 0X%08X:0X%08X\n", i++, current->addr, current->pmem);
        current = current->next;
    }
	printf("End!\n\n");
}