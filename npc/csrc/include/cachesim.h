#ifndef __CACHESIM_H__
#define __CACHESIM_H__

#include "common.h"
#include "utils.h"

// Cache配置参数
typedef struct {
    uint32_t size_kb;      // Cache大小(KB)
    uint32_t ways;         // 相联度
    uint32_t block_size;   // 块大小(字节)
    uint32_t sets;         // 组数（自动计算）
    bool is_icache;        // 是否为指令cache
    char replace_policy[10]; // 替换策略: lru/fifo/random
    bool write_back;       // 写策略: true=写回, false=写直达
    bool write_allocate;   // 写分配策略
} CacheConfig;

// Cache行元数据
typedef struct {
    uint64_t tag;
    bool valid;
    bool dirty;           // 脏位
    uint64_t lru_counter; // LRU计数器
    uint64_t fifo_counter; // FIFO计数器
} CacheLine;

// Cache模拟器
typedef struct {
    CacheConfig config;
    CacheLine *lines;      // 所有cache行
    uint64_t access_count;
    uint64_t read_count;
    uint64_t write_count;
    uint64_t hit_count;
    uint64_t miss_count;
    uint64_t read_hit;
    uint64_t read_miss;
    uint64_t write_hit;
    uint64_t write_miss;
    uint64_t write_backs;  // 写回次数
    uint64_t counter;      // 全局计数器
} CacheSim;

// 函数声明
CacheSim* cachesim_create(CacheConfig *config);
void cachesim_destroy(CacheSim *cache);
bool cachesim_access(CacheSim *cache, uint64_t addr, bool is_write);
void cachesim_print_stats(CacheSim *cache);
void cachesim_reset_stats(CacheSim *cache);
uint64_t cachesim_calculate_miss_penalty(uint32_t block_size, bool is_dram);
double cachesim_estimate_tmt(CacheSim *cache, double clock_freq);

#endif






#endif