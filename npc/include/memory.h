#ifndef __MEMORY_H__
#define __MEMORY_H__

#define RESET_VECTOR CONFIG_IMEM_BASE              // 程序复位地址
extern uint8_t imem[CONFIG_IMEM_SIZE] __attribute((aligned(4096))); // 程序存储变量

typedef struct
{
  uint32_t vaddr;   // 虚拟地址 (Spike log 记录的是 VA)
  uint32_t data;    // 数据
  uint8_t len;      // 长度 (1, 2, 4, 8)
  uint8_t type;     // 0: None, 1: Load, 2: Store
} mem_info_t;
extern mem_info_t npc_mem_info;

enum {
    wen, ren
};

typedef struct {
  uint64_t fetch_count;         // 取指数量
  uint64_t commit_count;        // 提交数量
  uint64_t load_count;          // 加载操作数量
  uint64_t store_count;         // 存储操作数量
  uint64_t jump_count;          // 无条件跳转操作数量
  uint64_t branch_count;        // 条件跳转操作数量  
  uint64_t alu_count;           // 定点运算操作数量
  uint64_t system_count;        // 系统控制操作数量
  uint64_t predict_miss_count;     // 预测错误数量
  uint64_t predict_not_jump_count; // 预测非跳转数量
  uint64_t related_delay_count; // 相关性延迟周期数
  uint64_t icache_flash_count;  
  uint64_t icache_flash_miss;  
  uint64_t icache_flash_misscycle;
  uint64_t icache_sram_count;  
  uint64_t icache_sram_miss;   
  uint64_t icache_sram_misscycle;
  uint64_t icache_sdram_count; 
  uint64_t icache_sdram_miss;  
  uint64_t icache_sdram_misscycle; 
  uint64_t dcache_flash_count;  
  uint64_t dcache_flash_misscycle;
  uint64_t dcache_sram_wcount;
  uint64_t dcache_sram_rcount;  
  uint64_t dcache_sram_wmisscycle;
  uint64_t dcache_sram_rmisscycle;
  uint64_t dcache_sdram_wcount; 
  uint64_t dcache_sdram_rcount; 
  uint64_t dcache_sdram_wmisscycle;
  uint64_t dcache_sdram_rmisscycle;
} NPC_perforcount;

extern NPC_perforcount npc_perC;
long init_imem(char *img_file);
uint32_t vaddr_read(uint32_t paddr);


#endif