#include <stdio.h>
#include <parameter.h>

// static uint32_t icache[CACHE_SIZE] = {};
static uint32_t cache_tag[CACHE_SIZE] = {};

static uint64_t inst_total = 0;
static uint64_t inst_hit = 0;

static uint64_t miss_penalty = 0;

static uint32_t n = 0;
static uint32_t m = 0;

static uint32_t init_para(char* size){
    
    uint32_t n = 0;

    int value = atoi(size);
    switch (value)
    {
    case 4:
        n = 2;
        break;

    case 8:
        n = 3;
        break;
    
    case 16:
        n = 4;
        break;

    case 32:
        n = 5;
        break;
        
    case 64:
        n = 6;
        break;

    case 128:
        n = 7;
        break;
    
    default:
        break;
    }

    return n;

}

static void cachesim_exec(uint32_t* data, long file_size){
    
    uint32_t times = 0;
    uint32_t pc = 0;
    uint32_t idx = 0;
    uint32_t tag = 0;

    long pc_size = file_size >> 2;
    for (int i = 0; i < pc_size; i = i + 2) {
        times = data[i + 1];
        pc = data[i];
        for(int j = 0; j <= times; j++){
            inst_total ++;
            pc = pc + 4 * j;
            idx = BITS(pc, m + n -1, n);
            tag = BITS(pc, 31, m + n);
            if(cache_tag[idx] == tag){
                inst_hit ++;
            }
            else {
                cache_tag[idx] = tag;
            }
        }
    }
}

int main(int argc, char *argv[]){

    if(argc != 4){
        printf("please input: file, block_size, cache_size\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("open .bin error!\n");
        return 1;
    }

    n = init_para(argv[2]);
    m = init_para(argv[3]);

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    printf("size = %ld\n", file_size);

    if(file_size % sizeof(uint32_t) != 0){
        printf("size error!\n");
        return 1;
    }

    uint32_t* data = (uint32_t*)malloc(file_size);
    if (data == NULL) {
        printf("malloc error!\n");
        fclose(file);
        return 1;
    }

    int ret = fread(data, 1, file_size, file);

    // for(int i = 0; i < 10; i++){
    //     printf("%08x\n", data[i]);
    // }

    cachesim_exec(data, file_size);

    float p_hit = (float)inst_hit / (float)inst_total;
    printf("total = %ld, hit = %ld, p_hit = %.2f\n", inst_total, inst_hit, p_hit);

    free(data);
    fclose(file);

    return 0;
}

