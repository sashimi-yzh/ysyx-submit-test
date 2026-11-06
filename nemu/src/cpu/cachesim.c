#include <cpu/cpu.h>
#include <locale.h>
#include <memory/vaddr.h>

// #define  CACHE_BLOCK_SIZE     16
// #define  CACHE_BLOCK_BANK     4
// #define  CACHE_BLOCK_COUNT    (CACHE_BLOCK_SIZE / 4)
// #define  m                    4 // $clog2(CACHE_BLOCK_SIZE)
// #define  n                    2 // $clog2(CACHE_BLOCK_BANK)
#define  SDRAM_BASE_ADDR      0xa0000000
#define  SDRAM_SIZE           0x20000000
#define  icache_access_time   1
#define  icache_miss_penalty  19 // 36 apb delay_on dram // 19 axiburst
#define  MAX_LINE_LENGTH      20    

static uint64_t total_count = 0;
static uint64_t hit_count = 0;
static int CACHE_BLOCK_SIZE = 16;
static int CACHE_BLOCK_BANK = 4;
static uint32_t m = 4;
static uint32_t n = 2;
static uint32_t *cache_addr = NULL;
static uint32_t *cache_valid = NULL;
static uint32_t CACHE_BLOCK_COUNT = 4;

static void cachesim_init();
static void cachesim_process(uint32_t pc);
static void cachesim_statistics();
static int cache_hit(uint32_t addr_tag, uint32_t index);
static int clog2(uint32_t x);

void cachesim_mainloop(int SIZE, int BANK) {

    CACHE_BLOCK_SIZE = SIZE;
    CACHE_BLOCK_BANK = BANK;
    m = clog2(CACHE_BLOCK_SIZE);
    n = clog2(CACHE_BLOCK_BANK);
    CACHE_BLOCK_COUNT = SIZE / 4;
    cache_addr = (uint32_t*)malloc(CACHE_BLOCK_BANK * sizeof(uint32_t));
    cache_valid = (uint32_t*)malloc(CACHE_BLOCK_BANK * sizeof(uint32_t));

    cachesim_init();

    const char *filename = "/home/long/ysyx-workbench/nemu/build/addresses.txt";
    FILE *file = fopen(filename, "r");

    // 检查文件是否成功打开
    if (file == NULL) {
        perror("文件打开失败");
        return ;
    }

    char line[MAX_LINE_LENGTH]; 
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        uint32_t hex_value = strtoul(line, NULL, 16);
        cachesim_process(hex_value);
    }

    // 关闭文件
    fclose(file);

    cachesim_statistics();
}

static int clog2(uint32_t x) {
    if (x == 0) return 0; // 防止除以0
    int result = 0;
    // 如果是2的幂，直接计算
    if ((x & (x - 1)) == 0) {
        while (x > 1) {
            x >>= 1;
            result++;
        }
    } else {
        // 非2的幂，向上取整
        while (x > 0) {
            x >>= 1;
            result++;
        }
        result--; // 调整偏移
    }
    return result;
}

static void cachesim_init() {
    for (int i = 0; i < CACHE_BLOCK_BANK; i++) {
        cache_addr[i] = 0;
        cache_valid[i] = 0;
    }
    total_count = 0;
    hit_count = 0;
}

static int cache_hit(uint32_t addr_tag, uint32_t index) {
    if (cache_valid[index] && (cache_addr[index] >> (m + n)) == addr_tag) {
        return 1;
    }
    return 0;
}

static void cachesim_process(uint32_t pc) {
    total_count++;
    if (pc < SDRAM_BASE_ADDR || pc >= SDRAM_BASE_ADDR + SDRAM_SIZE) return;
    uint32_t addr_tag = pc >> (m + n);
    uint32_t index    = (pc >> m) % CACHE_BLOCK_BANK;
    if (cache_hit(addr_tag, index)) {
        hit_count++;
    } 
    else {
        cache_addr[index] = addr_tag << (m + n);
        cache_valid[index] = 1;
    }
}

static void cachesim_statistics() {
    double hit_rate = (double)hit_count / total_count;
    printf("\033[1;33mcachesim hit rate: %.6lf\n\033[0m", hit_rate);
    printf("\033[1;33mAMAT: %.6lf\n\033[0m", icache_access_time + (1 - hit_rate) * icache_miss_penalty);
}

