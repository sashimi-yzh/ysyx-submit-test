#include "Cache.h"
#include <cmath>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <random>
#include <chrono>
#include <iostream>
#include <sstream>
#include <iomanip> 

namespace cachesim {

Cache::Cache(const CacheConfig& cfg)
    : num_sets_(0),
      num_ways_(0),
      cache_type_(cfg.cache_type) {

    if(cfg.block_size == 0 && cfg.block_offset_bits.has_value()) {
        block_size_ = 1 << cfg.block_offset_bits.value();
    } else {
        block_size_ = cfg.block_size;
    }

    // 先初始化缓存结构
    initialize_cache_structure(cfg);
    
    // 然后初始化位数（支持从配置传入或自动计算）
    initialize_bits(cfg);
}

void Cache::initialize_cache_structure(const CacheConfig& cfg) noexcept {
    uint32_t line_num;
    if(cfg.line_num == 0 && cfg.set_index_bits.has_value()) {
        line_num = 1 << cfg.set_index_bits.value();
    } else {
        line_num = cfg.line_num;
    }

    switch (cache_type_) {
        case CacheConfig::CacheTypeEnum::DirectMapped:
            num_sets_ = line_num;
            num_ways_ = 1;
            break;
        case CacheConfig::CacheTypeEnum::FullyAssociative:
            num_sets_ = 1;
            num_ways_ = line_num;
            break;
        case CacheConfig::CacheTypeEnum::SetAssociative:
            if(cfg.associativity == 0) {
                assert(false && "[Error] SetAssociative cfg.associativity cannot be set to 0");
            }
            num_sets_ = line_num / cfg.associativity;
            num_ways_ = cfg.associativity;
            break;
    }
    
    sets_.resize(num_sets_);
    for (auto& set : sets_) {
        set.resize(num_ways_);
    }
}

void Cache::initialize_bits(const CacheConfig& cfg) noexcept {
    if (cfg.block_offset_bits.has_value()) {
        block_offset_bits_ = cfg.block_offset_bits.value();
    } else {
        if (block_size_ > 0 && (block_size_ & (block_size_ - 1)) == 0) {
            block_offset_bits_ = __builtin_ctz(block_size_);
        } else {
            block_offset_bits_ = calculate_bits_runtime(block_size_);
        }
    }

    // 根据不同的 cache 类型计算 set_index_bits 和 tag_bits
    switch (cache_type_) {
        case CacheConfig::CacheTypeEnum::DirectMapped:
        case CacheConfig::CacheTypeEnum::SetAssociative: {
            // 直接映射和组相连：都有多个 sets，需要 set_index
            if (cfg.set_index_bits.has_value()) {
                set_index_bits_ = cfg.set_index_bits.value();
            } else {
                if (num_sets_ > 0 && (num_sets_ & (num_sets_ - 1)) == 0) {
                    set_index_bits_ = __builtin_ctz(num_sets_);
                } else {
                    set_index_bits_ = calculate_bits_runtime(num_sets_);
                }
            }
            
            // tag_bits（可选，通常不需要显式存储，但可以用于验证）
            if (cfg.tag_bits.has_value()) {
                tag_bits_ = cfg.tag_bits.value();
                uint32_t expected_tag_bits = 32 - block_offset_bits_ - set_index_bits_;
                if (tag_bits_ != expected_tag_bits) {
                    assert(false && "tag_bits mismatch: specified value does not match calculated value");
                }
            } else {
                tag_bits_ = 32 - block_offset_bits_ - set_index_bits_;
            }
            break;
        }
        
        case CacheConfig::CacheTypeEnum::FullyAssociative: {
            // 全相连映射：只有 1 个 set，不需要 set_index
            set_index_bits_ = 0;
            
            // tag_bits：全相连映射中，tag = 地址的高位（除了 block_offset）
            if (cfg.tag_bits.has_value()) {
                tag_bits_ = cfg.tag_bits.value();
                uint32_t expected_tag_bits = 32 - block_offset_bits_;
                if (tag_bits_ != expected_tag_bits) {
                    assert(false && "tag_bits mismatch: specified value does not match calculated value");
                }
            } else {
                tag_bits_ = 32 - block_offset_bits_;
            }
            break;
        }
    }
    
    block_offset_mask_ = (1u << block_offset_bits_) - 1;
    set_index_mask_ = (1u << set_index_bits_) - 1;
}

Cache::AddressParts Cache::parse_address(uint32_t address) const noexcept {
    AddressParts parts;
    
    parts.block_offset = address & block_offset_mask_;
    parts.set_index = calculate_set_index(address);
    parts.tag = calculate_tag(address);
    
    return parts;
}

uint32_t Cache::calculate_set_index(uint32_t address) const noexcept {
    return (address >> block_offset_bits_) & set_index_mask_;
}

uint32_t Cache::calculate_tag(uint32_t address) const noexcept {
    return address >> (block_offset_bits_ + set_index_bits_);
}

std::optional<uint32_t> Cache::find_in_set(
    uint32_t set_index, 
    uint32_t tag
) const noexcept {
    // 只实现直接映射的查找逻辑
    if (cache_type_ == CacheConfig::CacheTypeEnum::DirectMapped) {
        const auto& line = sets_[set_index][0];
        if (line.valid && line.tag == tag) {
            return 0;
        }
        return std::nullopt; 
    } else if(cache_type_ == CacheConfig::CacheTypeEnum::FullyAssociative) {
        const auto& cache_ways = sets_[0];
        for (size_t i = 0; i < cache_ways.size(); ++i) {
            if (cache_ways[i].tag == tag && cache_ways[i].valid) {
                return static_cast<uint32_t>(i);
            }
        }
        return std::nullopt;
    } else {
        // 组相连映射： 拥有多个set， 同时每个set有多个ways， 通过index来确定set， 通过tag确定ways
        const auto &cache_group = sets_[set_index];
        for(size_t i = 0; i < cache_group.size(); ++i) {
            if(cache_group[i].tag == tag && cache_group[i].valid) {
                return static_cast<uint32_t>(i);
            }
        }
        return std::nullopt;
    }
}

uint32_t Cache::select_way_to_replace(Cache::AddressParts &addr_parts) const noexcept {
    if (cache_type_ == CacheConfig::CacheTypeEnum::DirectMapped) {
        // 直接映射：每个 set 只有 1 个 way，直接返回 0
        return 0;
    } else {
        // 全相连使用 sets_[0]，组相连使用当前 set_index
        const auto &cache_ways = (cache_type_ == CacheConfig::CacheTypeEnum::FullyAssociative)
                             ? sets_[0]
                             : sets_[addr_parts.set_index];
        size_t cache_way_num = cache_ways.size();
        for(size_t i = 0; i < cache_way_num; ++i) {
            if(cache_ways[i].valid == false) {
                return static_cast<uint32_t>(i);
            }
        }

        switch (replaycement_policy) {
            case CacheConfig::ReplacementPolicy::Random: {
                static std::mt19937 engine(std::chrono::steady_clock::now().time_since_epoch().count());
                std::uniform_int_distribution<uint32_t> dist(0, cache_way_num - 1);
                return dist(engine);
                break;
            }
            case CacheConfig::ReplacementPolicy::LRU: {
                uint32_t victim = 0;
                uint32_t olderest_lru = 0;
                for(size_t i = 0; i < cache_way_num; ++i) {
                    if(cache_ways[i].lru_bit > olderest_lru) {
                        victim = i;
                        olderest_lru = cache_ways[i].lru_bit;
                    }
                }
                return victim;
                break;
            }
            case CacheConfig::ReplacementPolicy::FIFO:{
                uint32_t victim = 0;
                uint32_t max_fifo = cache_ways[0].fifo_bit;
                for (size_t i = 1; i < cache_way_num; ++i) {
                    if (cache_ways[i].fifo_bit > max_fifo) {
                        max_fifo = cache_ways[i].fifo_bit;
                        victim = static_cast<uint32_t>(i);
                    }
                }
                return victim;
                break;
            }
        }
    }
    return 0;
}

void Cache::replace_way(Cache::AddressParts &parts) noexcept {
    uint32_t way = select_way_to_replace(parts);
    auto &set  = sets_[parts.set_index];
    auto &line = set[way];

    for (size_t i = 0; i < set.size(); ++i) {
        if (i == way) continue;
        set[i].lru_bit++;
        set[i].fifo_bit++;
    }


    line.valid    = true;
    line.tag      = parts.tag;
    line.lru_bit  = 0;
    line.fifo_bit = 0;
}

// 3. 实现 access 函数
void Cache::access(uint32_t address) noexcept {
    auto parts = parse_address(address);
    
    auto way_opt = find_in_set(parts.set_index, parts.tag);
    
    if (way_opt.has_value()) {
        ++hit_count_;
        // update lru
        auto &set  = sets_[parts.set_index];
        for (size_t i = 0; i < set.size(); ++i) {
            if (i == way_opt.value()) continue;
            set[i].lru_bit++;
        }
        set[way_opt.value()].lru_bit = 0;
    } else {
        ++miss_count_;
        replace_way(parts);   
    }
}

uint64_t Cache::get_hit_time() const noexcept {
    return hit_count_;
}

uint64_t Cache::get_miss_time() const noexcept {
    return miss_count_;
}

double Cache::get_miss_rate() const noexcept {
    uint64_t total = hit_count_ + miss_count_;
    if (total == 0) {
        return 0.0;
    }
    return static_cast<double>(miss_count_) / static_cast<double>(total);
}

double Cache::get_reset_time() const noexcept {
    return reset_count_;
}

void Cache::set_way_invalid(Cache::AddressParts &parts) noexcept {
    if(cache_type_ == CacheConfig::CacheTypeEnum::DirectMapped) {
        sets_[parts.set_index][0].valid = false;
    } else if(cache_type_ == CacheConfig::CacheTypeEnum::FullyAssociative) {
        auto ways = sets_[0];
        for (auto way : ways) {
            if(way.tag == parts.tag) {
                way.valid = false;
                return ;
            }
        }
    } else {
        // CacheConfig::CacheTypeEnum::SetAssociative
        auto ways = sets_[parts.set_index];
        for(auto way : ways) {
            if(way.tag == parts.tag) {
                way.valid = false;
                return ;
            }
        }
    }
}

void Cache::reset(uint32_t address) noexcept {
    auto parts = parse_address(address);
    set_way_invalid(parts);
    ++reset_count_;
}

// Cache.cpp 中实现
void Cache::print_config() const {
    auto type_str = [this]() {
        switch (cache_type_) {
            case CacheConfig::CacheTypeEnum::DirectMapped:     return "DirectMapped";
            case CacheConfig::CacheTypeEnum::FullyAssociative: return "FullyAssociative";
            case CacheConfig::CacheTypeEnum::SetAssociative:   return "SetAssociative";
        }
        return "Unknown";
    };

    // 盒子打印辅助
    auto pad = [](const std::string& label, uint32_t bits, int width) {
        std::ostringstream oss;
        oss << std::left << std::setw(width - 2) << (label + " (" + std::to_string(bits) + ")");
        return oss.str();
    };
    auto box2 = [&](const std::string& tag_txt, const std::string& off_txt) {
        std::cout << "+" << std::string(18, '-') << "+" << std::string(14, '-') << "+\n";
        std::cout << "|" << tag_txt << "|" << off_txt << "|\n";
        std::cout << "+" << std::string(18, '-') << "+" << std::string(14, '-') << "+\n\n";
    };
    auto box3 = [&](const std::string& tag_txt, const std::string& idx_txt, const std::string& off_txt) {
        std::cout << "+" << std::string(18, '-') << "+" << std::string(14, '-') << "+" << std::string(14, '-') << "+\n";
        std::cout << "|" << tag_txt << "|" << idx_txt << "|" << off_txt << "|\n";
        std::cout << "+" << std::string(18, '-') << "+" << std::string(14, '-') << "+" << std::string(14, '-') << "+\n\n";
    };

    uint32_t offset_bits = block_offset_bits_;
    uint32_t index_bits  = set_index_bits_; // 全相连时应为 0
    uint32_t tag_bits    = tag_bits_;
    uint32_t total_lines = num_sets_ * num_ways_;
    uint32_t total_bytes = total_lines * block_size_;

    std::string tag_txt    = pad(" tag",   tag_bits,    20);
    std::string index_txt  = pad(" index", index_bits,  16);
    std::string offset_txt = pad(" offset",offset_bits, 16);

    std::cout << "=== Cache Configuration ===\n";
    std::cout << "  Type: " << type_str() << "\n";
    std::cout << "  Block size: " << block_size_ << " bytes (offset = "
              << offset_bits << " bits)\n";
    std::cout << "  Sets: " << num_sets_ << "\n";
    std::cout << "  Ways per set: " << num_ways_ << "\n";
    std::cout << "  Total lines: " << total_lines << "\n";
    std::cout << "  Total cache size: " << total_bytes << " bytes\n";
    std::cout << "  Address format [31:0] (high -> low):\n";

    if (cache_type_ == CacheConfig::CacheTypeEnum::FullyAssociative) {
        // 全相连：仅 tag + offset
        box2(tag_txt, offset_txt);
    } else {
        // 直映 / 组相连：tag + index + offset
        box3(tag_txt, index_txt, offset_txt);
    }
}

}