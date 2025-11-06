#include <cache.h>

//cache -> CacheSet_t(vector<cacheBlock_t>) -> cacheBlock
Cache::Cache(int s,int w,int size)
{
    sets = s;
    ways = w;
    block_size = size;
    
    cache = new CacheSet_t[sets];
    for(int i = 0;i < s; i++){
        cache[i].resize(w);
        for(int j = 0;j < w; j++){
            cache[i][j].valid = false;
        }
    }

    report.hit      = 0;
    report.miss     = 0;
    report.req_cnt  = 0;
}

Cache::~Cache()
{
    // 释放内存
    delete[] cache;
}

// 判断这个缓存组中是否还有空间,然后返回空的位置
int Cache::has_empty(CacheSet_t set){
    int place = 0;
    for(place = 0; place < ways; place++){
        if(set[place].valid == false){
            break;
        }
    }
    return (place < ways) ? place : -1;
}

// 输出打印信息
void Cache::statistic(){
    double miss_penalty;
    // 目前不是突发的读,而是直接四次独立的传输,所以缺失代价时间会很大
    if(block_size == 4) miss_penalty = 19.775591;           // 真实的
    else if(block_size == 8) miss_penalty = 27.434193;      // 真实的
    else if(block_size == 16) miss_penalty = 42.020867;     // 真实的
    else miss_penalty = 0;
    printf("Cache par = set(%d) way(%d) bsz(%d)\n", sets, ways, block_size);
    printf("Req count : %lu\n", report.req_cnt);
    printf("Hit count : %lu\n", report.hit);
    printf("Miss count : %lu\n", report.miss);
    printf("TMT : %lf\n", report.miss * miss_penalty);
    printf("Hit rate : %lf\n", (double)report.hit / (double)report.req_cnt);
}
