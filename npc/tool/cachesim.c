#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// 缓存配置参数 (与 Verilog 代码匹配)
// #define BLOCK_SIZE 4
// #define NUM_BLOCKS 16
// #define OFFSET_BITS 2
// #define INDEX_BITS 4
// #define TAG_BITS 26
// 访问统计:
//   总访问次数: 266647888
//   命中次数: 202922212
//   缺失次数: 63725676
//   命中率: 76.10%

// 性能估算:
//   总缺失时间 (TMT): 5098054080 周期
// #define BLOCK_SIZE 8
// #define NUM_BLOCKS 16
// #define OFFSET_BITS 3
// #define INDEX_BITS 4
// #define TAG_BITS 25
// 访问统计:
//   总访问次数: 266647888
//   命中次数: 246526407
//   缺失次数: 20121481
//   命中率: 92.45%

// 性能估算:
//   总缺失时间 (TMT): 3219436960 周期

#define BLOCK_SIZE 16
#define NUM_BLOCKS 16
#define OFFSET_BITS 4
#define INDEX_BITS 4
#define TAG_BITS 24

// 访问统计:
//   总访问次数: 266647888
//   命中次数: 260894573
//   缺失次数: 5753315
//   命中率: 97.84%

// 性能估算:
//   总缺失时间 (TMT): 1841060800 周期
// 缓存块结构
typedef struct {
    int valid;          // 有效位
    uint32_t tag;       // 标签
    uint32_t data;      // 数据 (模拟器中仅用于调试)
} CacheBlock;

// 缓存模拟器结构
typedef struct {
    CacheBlock blocks[NUM_BLOCKS];  // 缓存块数组
    uint64_t hit_count;             // 命中计数器
    uint64_t miss_count;            // 缺失计数器
    uint64_t total_access;          // 总访问次数
} CacheSim;

// 初始化缓存模拟器
void cachesim_init(CacheSim* sim) {
    memset(sim, 0, sizeof(CacheSim));
    for (int i = 0; i < NUM_BLOCKS; i++) {
        sim->blocks[i].valid = 0;
        sim->blocks[i].tag = 0;
        sim->blocks[i].data = 0;
    }
}

// 地址解析函数 (与 Verilog 代码相同)
void parse_address(uint32_t addr, uint32_t* tag, uint32_t* index) {
    *index = (addr >> OFFSET_BITS) & ((1 << INDEX_BITS) - 1);
    *tag = addr >> (OFFSET_BITS + INDEX_BITS);
}

// 处理缓存访问 (精确匹配 RTL 行为)
int cache_access(CacheSim* sim, uint32_t pc) {
    sim->total_access++;
    
    uint32_t tag, index;
    parse_address(pc, &tag, &index);
    
    CacheBlock* block = &sim->blocks[index];
    
    // 检查是否命中
    if (block->valid && block->tag == tag) {
        sim->hit_count++;
        return 1; // 命中
    }
    
    // 未命中：更新缓存块
    sim->miss_count++;
    block->valid = 1;
    block->tag = tag;
    block->data = pc; // 实际应用中应为内存数据，这里用PC模拟
    
    return 0; // 缺失
}

// 从二进制文件加载 PC 序列
void load_binary_trace(CacheSim* sim, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("无法打开二进制文件");
        return;
    }
    
    // 获取文件大小
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // 计算记录数 (每8字节一条记录)
    long num_entries = file_size / 4;
    printf("文件大小: %ld 字节, 记录数: %ld\n", file_size, num_entries);
    
    uint32_t pc;
    
    for (long i = 0; i < num_entries; i++) {
        // 读取 PC 地址 (4字节)
        if (fread(&pc, sizeof(pc), 1, file) != 1) {
            perror("读取 PC 地址失败");
            break;
        }
        
        // 处理缓存访问
        cache_access(sim, pc);
        
        // 每100万条记录显示进度
        // if (i % 1000000 == 0 && i > 0) {
        //     printf("已处理 %ld 万条记录...\n", i / 1000000);
        // }
    }
    
    fclose(file);
}

// 打印缓存状态 (用于调试)
void print_cache_state(CacheSim* sim) {
    printf("\n当前缓存状态:\n");
    printf("Index | Valid | Tag         | Data\n");
    printf("------+-------+-------------+------------\n");
    
    for (int i = 0; i < NUM_BLOCKS; i++) {
        CacheBlock* block = &sim->blocks[i];
        printf(" %4d |    %d   | 0x%08x | 0x%08x\n", 
               i, block->valid, block->tag, block->data);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("用法: %s <binary_trace_file>\n", argv[0]);
        printf("示例: %s cache.bin\n", argv[0]);
        return 1;
    }
    
    CacheSim sim;
    cachesim_init(&sim);
    
    printf("开始处理二进制跟踪文件: %s\n", argv[1]);
    
    // 加载并处理二进制 PC 序列
    load_binary_trace(&sim, argv[1]);
    
    // 输出结果
    printf("\n缓存配置:\n");
    printf("  块大小: %d 字节\n", BLOCK_SIZE);
    printf("  总块数: %d\n", NUM_BLOCKS);
    printf("  偏移位: %d\n", OFFSET_BITS);
    printf("  索引位: %d\n", INDEX_BITS);
    printf("  标签位: %d\n", TAG_BITS);
    
    printf("\n访问统计:\n");
    printf("  总访问次数: %lu\n", sim.total_access);
    printf("  命中次数: %lu\n", sim.hit_count);
    printf("  缺失次数: %lu\n", sim.miss_count);
    printf("  命中率: %.2f%%\n", (double)sim.hit_count / sim.total_access * 100);
    
    // 计算总缺失时间 (TMT)
    uint64_t avg_miss_penalty = 320; // 假设平均缺失代价为 80 周期
    uint64_t tmt = sim.miss_count * avg_miss_penalty;
    printf("\n性能估算:\n");
    printf("  总缺失时间 (TMT): %lu 周期\n", tmt);
    
    // 打印缓存状态 (可选)
    // print_cache_state(&sim);
    
    return 0;
}