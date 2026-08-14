#ifndef REF_CACHE_H
#define REF_CACHE_H

#include <cstdint>
#include <vector>

class RefCache {
public:
    // 配置结构 - 改为可动态配置
    struct Config {
        uint32_t BLOCK_SIZE;
        uint32_t NUM_BLOCKS;
        uint32_t WAYS;
        uint32_t NUM_SETS;
        uint32_t ADDR_WIDTH;
        uint32_t OFFSET_BITS;
        uint32_t INDEX_BITS;
        uint32_t TAG_BITS;
        
        // 默认构造函数 - 使用原始配置
        Config() : BLOCK_SIZE(16), NUM_BLOCKS(16), WAYS(4),
                   ADDR_WIDTH(32) {
            calculateDerived();
        }
        
        // 参数化构造函数
        Config(uint32_t block_size, uint32_t num_blocks, uint32_t ways) 
            : BLOCK_SIZE(block_size), NUM_BLOCKS(num_blocks), WAYS(ways),
              ADDR_WIDTH(32) {
            calculateDerived();
        }
        
        void calculateDerived() {
            NUM_SETS = NUM_BLOCKS / WAYS;
            OFFSET_BITS = 0;
            uint32_t temp = BLOCK_SIZE;
            while (temp > 1) {
                temp >>= 1;
                OFFSET_BITS++;
            }
            INDEX_BITS = 0;
            temp = NUM_SETS;
            while (temp > 1) {
                temp >>= 1;
                INDEX_BITS++;
            }
            TAG_BITS = ADDR_WIDTH - OFFSET_BITS - INDEX_BITS;
        }
    };

    RefCache();
    explicit RefCache(const Config& config);
    
    // 返回是否命中，并更新统计
    bool access(uint32_t addr);
    
    // 批量处理trace
    void processTrace(const std::vector<uint32_t>& trace);
    
    // 获取统计数据
    uint64_t getHits()   const { return hits_; }
    uint64_t getMisses() const { return misses_; }
    uint64_t getTotal()  const { return hits_ + misses_; }
    double   getHitRate() const;
    
    // 重置
    void reset();
    
    // 获取配置信息
    const Config& getConfig() const { return config_; }

private:
    // Cache行结构
    struct CacheLine {
        uint32_t tag;     // tag bits
        bool     valid;   // valid bit
        bool     dirty;   // dirty bit (for write-back)
        uint8_t lru_counter; // LRU counter for replacement
        
        CacheLine() : tag(0), valid(false), dirty(false), lru_counter(0) {}
    };
    
    // 地址解析
    uint32_t getTag(uint32_t addr) const;
    uint32_t getIndex(uint32_t addr) const;
    
    // LRU替换策略
    uint32_t findLRU(uint32_t set_index) const;
    void updateLRU(uint32_t set_index, uint32_t way_index);
    
    // Cache存储：NUM_SETS sets, each with WAYS ways
    std::vector<std::vector<CacheLine>> cache_;
    
    // 配置
    Config config_;
    
    // 统计计数器
    uint64_t hits_;
    uint64_t misses_;
};

#endif