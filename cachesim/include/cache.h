#include <common.h>
#include <math.h>

class Cache
{
    private:
        cache_t cache;
        int sets = 16;
        int ways = 1;
        int block_size = 4;
        Report report;
    public:
        Cache(int sets,int ways,int block_size);
        ~Cache();
        inline int get_ways() {return ways;}
        inline void req_count() { report.req_cnt++; }
        inline void hit_count() { report.hit++; }
        inline void miss_count() { report.miss++; }
        inline int idxBits() { return log2(sets); }                 // 索引位长度
        inline int offBits() { return log2(block_size); }           // 偏移位长度
        inline int tagBits() { return 32 - idxBits() - offBits(); } // 标签位长度
        // OFFSET：最低 offBits() 位
        inline int OFFSET(paddr_t addr) { return addr & ((1 << offBits()) - 1); }
        // INDEX：中间的 idxBits() 位
        inline int INDEX(paddr_t addr){ return (addr >> offBits()) & ((1 << idxBits()) - 1);  }
        // TAG：最高 tagBits() 位
        inline int TAG(paddr_t addr) { return addr >> (offBits() + idxBits());  }
        inline CacheSet_t& decode(paddr_t addr) { return cache[INDEX(addr)]; }
        int has_empty(CacheSet_t set);                  // 缓存组是否还有空余，并返回第一个空的位置
        void statistic();
};


