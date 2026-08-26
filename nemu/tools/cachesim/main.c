#include <stdio.h>
#include <stdlib.h>
//file
#include <string.h>
#include <stdint.h>
#include <math.h>
uint64_t inst_count=0;
uint64_t MEM_count=0;
FILE* fp = NULL;
uint32_t* PC_list = NULL;
uint32_t* MEM_list = NULL;
uint32_t*  MEMop_list = NULL;
// #define CONFIG_ICACHE_BLOCK_SIZE 4
// #define CONFIG_ICACHE_BLOCK_NUM 16



// uint32_t test_para_list[][2] = 

void test(uint32_t block_size_bit, uint32_t block_num_bit, double hit_wait, double miss_wait){
    
    uint64_t cnt_inst=0;
    uint64_t cnt_cache_hit=0;
    uint64_t cnt_cache_miss=0;
    uint32_t block_size = 1 << block_size_bit;
    uint32_t block_num = 1 << block_num_bit;
    // printf("block_size = %d, block_num = %d\n", block_size, block_num);
    uint8_t  icache_valid[block_num];
    uint32_t icache_tag[block_num];
    for(uint64_t i=0;i<inst_count;i++){
        uint32_t PC = PC_list[i];
        uint32_t block_index = (PC >> block_size_bit) & (block_num - 1);
        uint32_t tag = (PC >> block_size_bit) >> block_num_bit;
        // printf("PC: %08X, Block: %d, Tag: %08X\n", PC, block_index, tag);
        cnt_inst++;
        if(icache_valid[block_index] && icache_tag[block_index] == tag){
            cnt_cache_hit++;
            // printf("Cache hit!\n");
        }else{
            cnt_cache_miss++;
            // printf("Cache miss!\n");
            icache_valid[block_index] = 1;
            icache_tag[block_index] = tag;
        }
        if(cnt_inst % 10000 == 0){
            // printf("PC: %08X, Block: %d, Tag: %08X", PC, block_index, tag);
            // printf("Count: %ld, Hit: %ld, Miss: %ld\n", cnt_inst, cnt_cache_hit, cnt_cache_miss);
        }
    }
    double hit_rate = (double)cnt_cache_hit / (double)cnt_inst;
    printf("Size %03u\tBlock %03u\tCount: %ld\tHit: %010ld\tMiss: %010ld\t[hit rate: %f%%][clk: %.2f] \n", block_size, block_num, cnt_inst, cnt_cache_hit, cnt_cache_miss, hit_rate*100.0, (double)(hit_rate * hit_wait + (1.0-hit_rate) * miss_wait));

    
}

void M_test(uint32_t block_size_bit, uint32_t block_num_bit, double hit_wait, double miss_wait){
    
    uint64_t cnt_inst=0;
    uint64_t cnt_cache_hit=0;
    uint64_t cnt_cache_miss=0;
    uint32_t block_size = 1 << block_size_bit;
    uint32_t block_num = 1 << block_num_bit;
    // printf("block_size = %d, block_num = %d\n", block_size, block_num);
    uint8_t  mcache_valid[block_num];
    uint32_t mcache_tag[block_num];
    for(uint64_t i=0;i<MEM_count;i++){
        uint32_t addr = MEM_list[i];
        uint32_t op = MEMop_list[i];
        uint32_t block_index = (addr >> block_size_bit) & (block_num - 1);
        uint32_t tag = (addr >> block_size_bit) >> block_num_bit;
        uint32_t offset = addr & (block_size - 1);
        
        cnt_inst++;
        if(op){
            mcache_valid[block_index] = 1;
            mcache_tag[block_index] = tag;
        }else{
            if(mcache_valid[block_index] && mcache_tag[block_index] == tag){
                cnt_cache_hit++;
            // printf("Cache hit!\n");
            }else{
                cnt_cache_miss++;
                // printf("Cache miss!\n");
                mcache_valid[block_index] = 1;
                mcache_tag[block_index] = tag;
            }
        }
        if(cnt_inst % 10000 == 0){
            // printf("Addr: %08X, Op: %08X, Block: %d, Tag: %08X, Offset: %08X\n", addr, op, block_index, tag, offset);
            // printf("Count: %ld,Read: %ld, Hit: %ld, Miss: %ld\n", cnt_inst, cnt_cache_miss+cnt_cache_hit, cnt_cache_hit, cnt_cache_miss);
        }
    }
    double hit_rate = (double)cnt_cache_hit / (double)(cnt_cache_miss+cnt_cache_hit);
    printf("Size %03u\tBlock %03u\tCount: %010ld\tRead: %010ld\tHit: %010ld\tMiss: %010ld\t[hit rate: %f%%][clk: %.2f] \n", block_size, block_num, cnt_inst, (cnt_cache_miss+cnt_cache_hit),cnt_cache_hit, cnt_cache_miss, hit_rate*100.0, (double)(hit_rate * hit_wait + (1.0-hit_rate) * miss_wait));

    
}

int main() {
    printf("Hello, CacheSim!\n");
    fp = fopen("../../itrace.log", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("size = %ld\n", size);
    printf("pc_count = %ld\n", size / 4);
    PC_list = malloc(size);
    if(PC_list == NULL){
        fprintf(stderr, "Error allocating memory\n");
        return 1;
    }

    uint32_t line;
    while(fread(&line, sizeof(uint32_t), 1, fp) != NULL) {
        PC_list[inst_count] = line;
        inst_count++;
        // printf("%08X\n", line);
    }
    fclose(fp);

    fp = fopen("../../mtrace.log", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long sizem = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("size = %ld\n", sizem);
    printf("MEM_count = %ld\n", sizem / 8);
    MEM_list = malloc(sizem/2);
    if(MEM_list == NULL){
        fprintf(stderr, "Error allocating memory\n");
        return 1;
    }
    MEMop_list = malloc(sizem/2);
    if(MEMop_list == NULL){
        fprintf(stderr, "Error allocating memory\n");
        return 1;
    }
    uint32_t line1,line2;
    while(1) {
        uint32_t flag=0;
        flag = fread(&line1, sizeof(uint32_t), 1, fp);
        if(flag == 0) {
            break;
        }
        flag = fread(&line2, sizeof(uint32_t), 1, fp);
        if(flag == 0) {
            break;
        }
        MEM_list[MEM_count] = line1;
        MEMop_list[MEM_count] = line2;
        MEM_count++;
        // printf("%08X %08X\n", line1, line2);
    }
    fclose(fp);

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            test(i, j, 0.01, 53.39);
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            M_test(i, j, 0.45, 65.77);
        }
    }
    
    return 0;
}