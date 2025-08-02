#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PC 1000000 // 假设最大PC数

typedef struct {
    unsigned int tag;
    int valid;
    int last_access;
} CacheLine;

typedef struct {
    int num_ways;
    int num_sets;
    int block_size;
    CacheLine **lines;
} Cache;

int hit_count = 0;
int access_count = 0;

Cache *create_cache(int num_ways, int num_sets, int block_size) {
    Cache *cache = (Cache *)malloc(sizeof(Cache));
    cache->num_ways = num_ways;
    cache->num_sets = num_sets;
    cache->block_size = block_size;
    cache->lines = (CacheLine **)malloc(num_sets * sizeof(CacheLine *));
    
    for (int i = 0; i < num_sets; i++) {
        cache->lines[i] = (CacheLine *)calloc(num_ways, sizeof(CacheLine));
    }
    
    return cache;
}

void destroy_cache(Cache *cache) {
    for (int i = 0; i < cache->num_sets; i++) {
        free(cache->lines[i]);
    }
    free(cache->lines);
    free(cache);
}

// 模拟Cache访问
void access_cache(Cache *cache, unsigned int address) {
    int set_index = (address / cache->block_size) % cache->num_sets;
    unsigned int tag = address / (cache->block_size * cache->num_sets);
    
    int hit = 0;
    int least_recent = 0;
    int min_access = __INT_MAX__;

    for (int i = 0; i < cache->num_ways; i++) {
        if (cache->lines[set_index][i].valid && cache->lines[set_index][i].tag == tag) {
            hit = 1;
            cache->lines[set_index][i].last_access = access_count;
            break;
        }
        if (cache->lines[set_index][i].last_access < min_access) {
            min_access = cache->lines[set_index][i].last_access;
            least_recent = i;
        }
    }

    if (!hit) {
        cache->lines[set_index][least_recent].tag = tag;
        cache->lines[set_index][least_recent].valid = 1;
        cache->lines[set_index][least_recent].last_access = access_count;
    } else {
        hit_count++;
    }

    access_count++;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <num_ways> <num_sets> <block_size> <trace_file>\n", argv[0]);
        return 1;
    }

    int num_ways = atoi(argv[1]);
    int num_sets = atoi(argv[2]);
    int block_size = atoi(argv[3]);
    char *trace_file = argv[4];

    if (block_size != 4 && block_size != 8 && block_size != 16) {
        fprintf(stderr, "Block size must be 4, 8 or 16 bytes.\n");
        return 1;
    }

    Cache *cache = create_cache(num_ways, num_sets, block_size);

    FILE *file = fopen(trace_file, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    unsigned int pc;
    while (fscanf(file, "%x", &pc) != EOF) {
        access_cache(cache, pc);
    }

    fclose(file);

    double hit_rate = (double)hit_count / access_count * 100;
    printf("Cache Hit Rate: %f%%\n", hit_rate);

    destroy_cache(cache);

    return 0;
}


// **使用说明**：
// 1. 编译程序：`gcc -o cachesim cachesim.c`
// 2. 运行程序：`./cachesim <路数> <组数> <块大小> <trace文件路径>`

// 例如：`./cachesim 2 16 16 trace.txt`

// 这个程序实现了以下功能：
// - 根据命令行参数创建一个Cache。
// - 读取文本文件中的PC值，并模拟访问Cache。
// - 计算并输出Cache的命中率。

// 注意：这个程序假设Cache采用的是LRU（最近最少使用）替换策略，并且Cache是直接映射的。如果需要更复杂的Cache策略或其他功能，可能需要进一步修改代码。
