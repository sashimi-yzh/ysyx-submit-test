#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define CACHE_SIZE_BYTES   256
#define LINE_SIZE_BYTES    16          // Cache行大小 (修改时需同步修改 OFFSET_BITS)
#define OFFSET_BITS        4           // log2(16) = 4
#define NUM_LINES          (CACHE_SIZE_BYTES / LINE_SIZE_BYTES)

typedef struct {
    uint32_t tag;
    int valid;
    uint64_t lru_stamp;
} CacheLine;

static CacheLine cache[NUM_LINES];
static uint64_t global_lru_counter = 0;
static uint64_t total_accesses = 0;
static uint64_t hits = 0;

void cache_init(void) {
    for (int i = 0; i < NUM_LINES; i++) {
        cache[i].valid = 0;
        cache[i].tag = 0;
        cache[i].lru_stamp = 0;
    }
}

int access_cache(uint32_t addr) {
    
    uint32_t tag = addr >> OFFSET_BITS;
    total_accesses++;

    // 1. 检查是否命中
    for (int i = 0; i < NUM_LINES; i++) {
        if (cache[i].valid && cache[i].tag == tag) {
            hits++;
            cache[i].lru_stamp = ++global_lru_counter; // 更新最近访问时间
            return 1; // Hit
        }
    }

    // 2. 未命中：寻找替换位置（优先使用空行，其次替换最久未使用的行）
    int replace_idx = 0;
    uint64_t min_stamp = ~0ULL; // 初始化为最大值
    int found_empty = -1;

    for (int i = 0; i < NUM_LINES; i++) {
        if (!cache[i].valid) {
            found_empty = i;
            break; // 发现空行直接跳出
        }
        if (cache[i].lru_stamp < min_stamp) {
            min_stamp = cache[i].lru_stamp;
            replace_idx = i;
        }
    }

    if (found_empty != -1) {
        replace_idx = found_empty;
    }

    // 3. 加载新块（软件仿真只需更新元数据，无需实际读内存）
    cache[replace_idx].valid = 1;
    cache[replace_idx].tag = tag;
    cache[replace_idx].lru_stamp = ++global_lru_counter;

    return 0; // Miss
}

/* ================= 主程序 ================= */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <memory_trace.bin>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Failed to open trace file");
        return EXIT_FAILURE;
    }

    cache_init();

    uint32_t addr;
    // 每次读取4字节（32位地址）
    while (fread(&addr, sizeof(uint32_t), 1, fp) == 1) {
        access_cache(addr);
    }
    fclose(fp);

    // 输出统计结果
    uint64_t misses = total_accesses - hits;
    double hit_rate = (total_accesses > 0) ? (double)hits / total_accesses : 0.0;

    printf("=== Cache Simulation Result ===\n");
    printf("Cache Size      : %d bytes\n", CACHE_SIZE_BYTES);
    printf("Line Size       : %d bytes\n", LINE_SIZE_BYTES);
    printf("Total Accesses  : %lu\n", total_accesses);
    printf("Hits            : %lu\n", hits);
    printf("Misses          : %lu\n", misses);
    printf("Hit Rate        : %.4f (%.2f%%)\n", hit_rate, hit_rate * 100);

    return EXIT_SUCCESS;
}