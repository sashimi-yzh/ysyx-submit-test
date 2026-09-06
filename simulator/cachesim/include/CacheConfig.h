#include <cstdint>
#include <optional>  // 现代 C++：可选值

namespace cachesim {

struct CacheConfig {
    enum class CacheTypeEnum {
        DirectMapped,      // 直接映射
        FullyAssociative,  // 全相连
        SetAssociative     // 组相连（集合关联）
    } cache_type = CacheTypeEnum::DirectMapped;

    enum class ReplacementPolicy {
        LRU,
        FIFO,
        Random
    } replacement_policy = ReplacementPolicy::Random;

    uint32_t block_size = 0;
    uint32_t line_num = 0;
    uint32_t associativity = 0; // 仅用于组相连
    
    // 现代 C++：可选字段，如果提供则使用，否则自动计算
    std::optional<uint32_t> block_offset_bits;  // block_offset 的位数
    std::optional<uint32_t> set_index_bits;     // set_index 的位数
    std::optional<uint32_t> tag_bits;           // tag 的位数（可选）uint32_t block_size = 0;
};

}