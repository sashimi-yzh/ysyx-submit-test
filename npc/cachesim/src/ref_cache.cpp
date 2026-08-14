#include "ref_cache.h"
#include <iostream>
#include <algorithm>
#include <cmath>

RefCache::RefCache() : config_(), hits_(0), misses_(0) {
    cache_.resize(config_.NUM_SETS);
    for (auto& set : cache_) {
        set.resize(config_.WAYS);
    }
}

RefCache::RefCache(const Config& config) : config_(config), hits_(0), misses_(0) {
    cache_.resize(config_.NUM_SETS);
    for (auto& set : cache_) {
        set.resize(config_.WAYS);
    }
}

void RefCache::reset() {
    hits_ = 0;
    misses_ = 0;
    for (auto& set : cache_) {
        for (auto& line : set) {
            line.valid = false;
            line.tag = 0;
            line.dirty = false;
            line.lru_counter = 0;
        }
    }
}

uint32_t RefCache::getTag(uint32_t addr) const {
    return addr >> (config_.OFFSET_BITS + config_.INDEX_BITS);
}

uint32_t RefCache::getIndex(uint32_t addr) const {
    uint32_t mask = (1 << config_.INDEX_BITS) - 1;
    return (addr >> config_.OFFSET_BITS) & mask;
}

uint32_t RefCache::findLRU(uint32_t set_index) const {
    uint32_t lru_way = 0;
    uint32_t max_counter = 0;
    
    for (uint32_t way = 0; way < config_.WAYS; way++) {
        if (!cache_[set_index][way].valid) {
            return way;
        }
        if (cache_[set_index][way].lru_counter > max_counter) {
            max_counter = cache_[set_index][way].lru_counter;
            lru_way = way;
        }
    }
    return lru_way;
}

void RefCache::updateLRU(uint32_t set_index, uint32_t way_index) {
    for (uint32_t way = 0; way < config_.WAYS; way++) {
        if (way == way_index) {
            cache_[set_index][way].lru_counter = 0;
        } else if (cache_[set_index][way].valid) {
            cache_[set_index][way].lru_counter++;
        }
    }
}

bool RefCache::access(uint32_t addr) {
    uint32_t tag = getTag(addr);
    uint32_t set_index = getIndex(addr);
    if(addr >= 0xf000000 && addr < 0x10000000) {
        misses_++;
        return false;
    }
    for (uint32_t way = 0; way < config_.WAYS; way++) {
        if (cache_[set_index][way].valid && cache_[set_index][way].tag == tag) {
            hits_++;
            updateLRU(set_index, way);
            return true;
        }
    }
    
    misses_++;
    uint32_t replace_way = findLRU(set_index);
    cache_[set_index][replace_way].valid = true;
    cache_[set_index][replace_way].tag = tag;
    cache_[set_index][replace_way].dirty = false;
    updateLRU(set_index, replace_way);
    
    return false;
}

void RefCache::processTrace(const std::vector<uint32_t>& trace) {
    for (auto addr : trace) {
        access(addr);
    }
}

double RefCache::getHitRate() const {
    uint64_t total = hits_ + misses_;
    if (total == 0) return 0.0;
    return (double)hits_ / total * 100.0;
}