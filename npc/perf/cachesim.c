#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_WAYS 16

static uint32_t total_count, miss_count, hit_count;
static uint32_t offset_bits, index_bits, nways;

typedef struct {
    uint32_t tag;
    bool     valid;
    uint32_t timestamp; // 记录访问时间，用于 LRU 替换
} CacheBlock; // cache 块

typedef struct {
    CacheBlock blocks[MAX_WAYS];
    uint32_t   access_counter;
} CacheGroup; // cache 组

typedef struct {
    CacheGroup *groups;
    uint32_t    nsets;
} Cache; // cache 整体

static void cache_init(Cache *cache) {
    cache->groups = calloc(cache->nsets, sizeof(CacheGroup));
    for (uint32_t g = 0; g < cache->nsets; g++) {
        for (uint32_t i = 0; i < nways; i++)
            cache->groups[g].blocks[i].valid = false;
    }
}

static void cache_handle(uint32_t addr, uint32_t *group, uint32_t *tag) {
    *group = (addr >> offset_bits) & ((1u << index_bits) - 1);
    *tag   = addr >> (offset_bits + index_bits);
}

static void cache_sim(Cache *cache, uint32_t pc) {
    uint32_t group, tag;
    cache_handle(pc, &group, &tag);
    CacheGroup *grp = &cache->groups[group];

    // check hit
    int hit_idx = -1;
    for (uint32_t i = 0; i < nways; i++) {
        if (grp->blocks[i].valid && grp->blocks[i].tag == tag) {
            hit_idx = i;
            break;
        }
    }

    if (hit_idx != -1) {
        hit_count++;
        grp->blocks[hit_idx].timestamp = grp->access_counter++;
    } else {
        miss_count++;

        // LRU replacement
        int lru_idx = 0;
        uint32_t min_ts = UINT32_MAX;
        for (uint32_t i = 0; i < nways; i++) {
            if (!grp->blocks[i].valid) { lru_idx = i; break; }
            if (grp->blocks[i].timestamp < min_ts) {
                min_ts = grp->blocks[i].timestamp;
                lru_idx = i;
            }
        }
        grp->blocks[lru_idx].tag       = tag;
        grp->blocks[lru_idx].valid     = true;
        grp->blocks[lru_idx].timestamp = grp->access_counter++;
    }
    total_count++;
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr,
            "Usage: %s <block_size_B> <num_sets> <ways> <miss_penalty> <itrace.bin>\n"
            "  block_size:  4, 8, 16, 32, 64 ...\n"
            "  num_sets:    1, 2, 4, 8, 16, 32, 64 ...\n"
            "  ways:        1 (direct), 2, 4, 8 ...\n"
            "  miss_penalty: cycles per miss (for AMAT)\n",
            argv[0]);
        return 1;
    }

    int bsize        = atoi(argv[1]);  // cache块大小
    int nsets        = atoi(argv[2]);  // 组个数
    int ways         = atoi(argv[3]);  // ways (组内 cache 块个数)
    int miss_penalty = atoi(argv[4]);  // 缺失代价
    const char *file = argv[5];

    offset_bits = 0; while ((1 << offset_bits) < bsize) offset_bits++;
    index_bits  = 0; while ((1 << index_bits)  < nsets) index_bits++;
    nways       = ways;

    printf("--Cache: %dB blocks, %d sets, %d-way, "
           "%d entries total (%.1fKB)\n",
           bsize, nsets, ways, nsets * ways,
           (float)(nsets * ways * bsize) / 1024);
    printf("--off=%d idx=%d tag=%d miss_penalty=%d\n",
           offset_bits, index_bits, 32 - offset_bits - index_bits, miss_penalty);

    FILE *fp = fopen(file, "rb");
    if (!fp) { perror(file); return 1; }

    Cache cache = { .nsets = nsets };
    cache_init(&cache);

    uint32_t pc;
    while (fread(&pc, sizeof(pc), 1, fp) == 1) // 读取 pc 启动模拟
        cache_sim(&cache, pc);

    fclose(fp);
    free(cache.groups);

    double miss_rate = total_count ? (double)miss_count / total_count * 100 : 0;
    double amat = 1.0 + (miss_rate / 100.0) * miss_penalty;

    printf("[access=%u hit=%u miss=%u miss_rate=%.2f%% AMAT=%.2f]\n",
           total_count, hit_count, miss_count, miss_rate, amat);
    return 0;
}
