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

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>


#define NPC_MROM_MSIZE 0x1000
#define NPC_MROM_MBASE 0x20000000
#define NPC_SRAM_MSIZE 0x2000
#define NPC_SRAM_MBASE 0x0f000000
#define NPC_FLASH_MBASE 0x30000000
#define NPC_FLASH_MSIZE 0xfffffff
#define NPC_SDRAM_MBASE 0xa0000000
#define NPC_SDRAM_MSIZE 0x8000000

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
static uint8_t mrom[NPC_MROM_MSIZE];
static uint8_t sram[NPC_SRAM_MSIZE];
static uint8_t flash[NPC_FLASH_MSIZE];
static uint8_t sdram[NPC_SDRAM_MSIZE];
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
uint8_t* guest_to_host_mrom(paddr_t paddr) { return mrom + paddr - NPC_MROM_MBASE; }
uint8_t* guest_to_host_sram(paddr_t paddr) { return sram + paddr - NPC_SRAM_MBASE; }
uint8_t* guest_to_host_flash(paddr_t paddr) { return flash + paddr - NPC_FLASH_MBASE; }
uint8_t* guest_to_host_sdram(paddr_t paddr) { return sdram + paddr - NPC_SDRAM_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
	word_t ret = host_read(guest_to_host(addr), len);
	return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
	host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
	panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
			addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
	pmem = malloc(CONFIG_MSIZE);
	assert(pmem);
#endif
	IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
	memset(mrom, 0, NPC_MROM_MSIZE);
	memset(sram, 0, NPC_SRAM_MSIZE);
	Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

/*内存访问的踪迹 - mtrace的相关内容*/
typedef struct mtraceNode {
	struct mtraceNode *next;
	struct mtraceNode *prev;
	word_t peme;
	word_t addr;
} mtraceNode;

typedef struct mtrace {
	int count;
	mtraceNode *first;
	mtraceNode *last;
} mtrace;

mtrace *mtrace_read = NULL; 
mtrace *mtrace_write = NULL; 

void mtrace_read_display(paddr_t addr, int len){
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
	node->peme = pmem_read(addr, len);
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
        printf("NO.%d 0X%08X:0X%08X\n", i++, current->addr, current->peme);
        current = current->next;
    }
	printf("End!\n\n");
}

void mtrace_write_display(paddr_t addr, int len){
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
	node->peme = pmem_read(addr, len);
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
        printf("NO.%d 0X%08X:0X%08X\n", i++, current->addr, current->peme);
        current = current->next;
    }
	printf("End!\n\n");
}


word_t paddr_read(paddr_t addr, int len) {
	int ysyxsoc_difftest = 0;
	IFDEF(CONFIG_YSYXSOC_DIFFTEST, ysyxsoc_difftest = 1);
	if (ysyxsoc_difftest == 1){

		// if (addr >= 0x10000000 && addr <  0x10000fff) {	//访问ysyxSoC的UART16550
		// 	return;
    	// }
		if (addr >= NPC_MROM_MBASE && addr < NPC_MROM_MBASE + NPC_MROM_MSIZE - 1) {	//访问MROM
			word_t ret = host_read(guest_to_host_mrom(addr), len);
			return ret;
		}
		if (addr >= NPC_SRAM_MBASE && addr < NPC_SRAM_MBASE + NPC_SRAM_MSIZE - 1) {	//访问SRAM
			word_t ret = host_read(guest_to_host_sram(addr), len);
			//printf("READ sram[0x%x] len=%d -> 0x%x\n", addr, len, ret);  
			return ret;
		}
		if (addr >= NPC_FLASH_MBASE && addr < NPC_FLASH_MBASE + NPC_FLASH_MSIZE - 1) {	//访问flash
			word_t ret = host_read(guest_to_host_flash(addr), len);
			//printf("READ sram[0x%x] len=%d -> 0x%x\n", addr, len, ret);  
			return ret;
		}
		if (addr >= NPC_SDRAM_MBASE && addr < NPC_SDRAM_MBASE + NPC_SDRAM_MSIZE - 1) {	//访问sdram
			word_t ret = host_read(guest_to_host_sdram(addr), len);
			//printf("READ sram[0x%x] len=%d -> 0x%x\n", addr, len, ret);  
			return ret;
		}

	} 
	

	//printf("\npaddr_read:0x%x\n",addr);
	//mtrace_read_display(addr, len);
	IFDEF(CONFIG_MTRACE, mtrace_read_display(addr, len));
	if (likely(in_pmem(addr))) return pmem_read(addr, len);
	IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
	out_of_bound(addr);
	return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  	int ysyxsoc_difftest = 0;
	IFDEF(CONFIG_YSYXSOC_DIFFTEST, ysyxsoc_difftest = 1);
	if (ysyxsoc_difftest == 1){
		if (addr >= 0x10000000 && addr <  0x10000fff) {	//访问ysyxSoC的UART16550
			return;
    	}
		if (addr >= 0x10002000 && addr <  0x1000200f) {	//访问ysyxSoC的GPIO
			return;
    	}
		if (addr >= NPC_MROM_MBASE && addr < NPC_MROM_MBASE + NPC_MROM_MSIZE - 1) {	//访问MROM
			host_write(guest_to_host_mrom(addr), len, data);
			return;
    	}
		if (addr >= NPC_SRAM_MBASE && addr < NPC_SRAM_MBASE + NPC_SRAM_MSIZE - 1) {	//访问SRAM
			host_write(guest_to_host_sram(addr), len, data);
			//printf("WRITE sram[0x%x] len=%d = 0x%x\n", addr, len, data); 
			return;
    	}
		if (addr >= NPC_FLASH_MBASE && addr < NPC_FLASH_MBASE + NPC_FLASH_MSIZE - 1) {	//访问flash
			host_write(guest_to_host_flash(addr), len, data);
			//printf("READ sram[0x%x] len=%d -> 0x%x\n", addr, len, ret);  
			return;
    	}
		if (addr >= NPC_SDRAM_MBASE && addr < NPC_SDRAM_MBASE + NPC_SDRAM_MSIZE - 1) {	//访问sdram
			host_write(guest_to_host_sdram(addr), len, data);
			//printf("READ sram[0x%x] len=%d -> 0x%x\n", addr, len, ret);  
			return;
    	}
		//printf("\n0x%x: %c\n",addr,data);	
	}

	if (likely(in_pmem(addr))) { 
		pmem_write(addr, len, data); 
		//mtrace_write_display(addr, len);
		IFDEF(CONFIG_MTRACE, mtrace_write_display(addr, len));
		return; 
	}
	IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
	out_of_bound(addr);
}
