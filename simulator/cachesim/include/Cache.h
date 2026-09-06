#include <vector>
#include <cstdint>
#include <optional>
#include "CacheConfig.h"

namespace cachesim {

struct CacheLine {
    bool valid = false;
    uint32_t lru_bit = 0;
    uint32_t fifo_bit = 0;

    uint32_t tag = 0;
    CacheLine() = default;
};

class Cache {
public:
    explicit Cache(const CacheConfig& cfg);
    ~Cache() = default;

    Cache(const Cache&) = delete;
    Cache& operator=(const Cache&) = delete;
    Cache(Cache&&) noexcept = default;
    Cache& operator=(Cache&&) noexcept = default;

    void access(uint32_t address) noexcept;
    void reset(uint32_t address) noexcept;
    
    [[nodiscard]] uint64_t get_hit_time() const noexcept;
    [[nodiscard]] uint64_t get_miss_time() const noexcept;
    [[nodiscard]] double get_miss_rate() const noexcept;
    [[nodiscard]] double get_reset_time() const noexcept;
    void print_config() const;

private:
    std::vector<std::vector<CacheLine>> sets_;
    
    // 缓存参数
    uint32_t block_size_;
    uint32_t num_sets_;
    uint32_t num_ways_;
    CacheConfig::CacheTypeEnum cache_type_;
    CacheConfig::ReplacementPolicy replaycement_policy;
    
    // 现代 C++：预计算的位数（避免每次访问时计算）
    uint32_t block_offset_bits_;  // block_offset 的位数
    uint32_t set_index_bits_;     // set_index 的位数
    uint32_t tag_bits_;           // tag 的位数
    
    // 预计算的掩码（进一步优化）
    uint32_t block_offset_mask_;  // (1 << block_offset_bits_) - 1
    uint32_t set_index_mask_;    // (1 << set_index_bits_) - 1
    
    // 统计信息
    mutable uint64_t hit_count_ = 0;
    mutable uint64_t miss_count_ = 0;
    mutable uint64_t reset_count_ = 0;

    struct AddressParts {
        uint32_t tag;
        uint32_t set_index;
        uint32_t block_offset;
    };
    
    // 现代 C++：constexpr 函数计算位数（编译时计算）
    [[nodiscard]] static constexpr uint32_t calculate_bits(uint32_t value) noexcept {
        // 计算 log2(value)，要求 value 是 2 的幂
        uint32_t bits = 0;
        while (value > 1) {
            value >>= 1;
            ++bits;
        }
        return bits;
    }
    
    // 运行时计算位数（处理非 2 的幂的情况）
    [[nodiscard]] static uint32_t calculate_bits_runtime(uint32_t value) noexcept {
        if (value == 0) return 0;
        uint32_t bits = 0;
        while (value > 1) {
            value >>= 1;
            ++bits;
        }
        return bits;
    }
    
    // 初始化位数（支持从配置传入或自动计算）
    void initialize_bits(const CacheConfig& cfg) noexcept;
    
    // 使用预计算的位数解析地址
    [[nodiscard]] AddressParts parse_address(uint32_t address) const noexcept;
    
    // 使用预计算的位数计算 set_index
    [[nodiscard]] uint32_t calculate_set_index(uint32_t address) const noexcept;
    
    // 使用预计算的位数计算 tag
    [[nodiscard]] uint32_t calculate_tag(uint32_t address) const noexcept;
    
    // 其他函数...
    void initialize_cache_structure(const CacheConfig& cfg) noexcept;
    [[nodiscard]] std::optional<uint32_t> find_in_set(
        uint32_t set_index, 
        uint32_t tag
    ) const noexcept;

    [[nodiscard]] uint32_t select_way_to_replace(Cache::AddressParts &addr_parts) const noexcept;

    void replace_way(Cache::AddressParts &parts) noexcept;

    void set_way_invalid(Cache::AddressParts &parts) noexcept;
};

}