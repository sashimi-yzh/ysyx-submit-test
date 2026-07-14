#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm> // 新增，用于 std::sort
#include <getopt.h>
#include "include/trace.h"
#include "config.h"

// Cache 块（元数据结构）
struct CacheLine
{
    bool valid = false;
    uint32_t tag = 0;
    uint32_t age = 0; // 用于 LRU 替换策略的计数器
};

// 用于保存 DSE 结果的结构体
struct SimResult 
{
    uint32_t size;
    uint32_t block;
    uint32_t assoc;
    double miss_rate;
    double tmt;

    // 重载小于号，按 TMT 升序排序 (TMT 越小性能越好)
    bool operator<(const SimResult& other) const {
        return tmt < other.tmt;
    }
};

// Cache 模拟器核心类
class CacheSimulator
{
private:
    uint32_t cache_size;    // 总容量 (Bytes)
    uint32_t block_size;    // 块大小 (Bytes)
    uint32_t associativity; // 相联度 (Ways)

    uint32_t num_blocks; // 总 Block 数
    uint32_t num_sets;   // 总 Set 数

    uint32_t offset_bits; // 块内偏移位数
    uint32_t index_bits;  // 组索引位数
    uint32_t tag_bits;    // Tag 位数

    uint32_t index_mask; // Index 掩码

    // 二维结构：[set_index][way_index]
    std::vector<std::vector<CacheLine>> cache;

    // 性能计数器
    uint64_t total_accesses = 0;
    uint64_t miss_count = 0;
    uint64_t hit_count = 0;

public:
    CacheSimulator(uint32_t c_size, uint32_t b_size, uint32_t assoc)
        : cache_size(c_size), block_size(b_size), associativity(assoc)
    {
        num_blocks = cache_size / block_size;
        num_sets = num_blocks / associativity;

        // 计算各个字段的位宽
        offset_bits = static_cast<uint32_t>(std::log2(block_size));
        index_bits = static_cast<uint32_t>(std::log2(num_sets));
        tag_bits = 32 - index_bits - offset_bits;

        // 构造掩码
        index_mask = (num_sets > 1) ? (num_sets - 1) : 0;

        // 初始化元数据存储阵列
        cache.resize(num_sets, std::vector<CacheLine>(associativity));
    }

    // 处理单次 PC 访问
    void access(uint32_t pc)
    {
        total_accesses++;

        // 提取物理地址字段
        uint32_t index = (pc >> offset_bits) & index_mask;
        uint32_t tag = pc >> (offset_bits + index_bits);

        auto &current_set = cache[index];
        bool is_hit = false;
        uint32_t hit_way = 0;

        // 1. 查找是否命中
        for (uint32_t w = 0; w < associativity; ++w)
        {
            if (current_set[w].valid && current_set[w].tag == tag)
            {
                is_hit = true;
                hit_way = w;
                break;
            }
        }

        if (is_hit)
        {
            hit_count++;
            // 更新 LRU 状态：命中的块变为最年轻（age=0），其他比它年轻的块 age 加 1
            uint32_t old_age = current_set[hit_way].age;
            for (uint32_t w = 0; w < associativity; ++w)
            {
                if (current_set[w].valid && current_set[w].age < old_age)
                {
                    current_set[w].age++;
                }
            }
            current_set[hit_way].age = 0;
        }
        else
        {
            miss_count++;

            // 2. 发生缺失，寻找替换槽位
            uint32_t victim_way = 0;
            bool found_invalid = false;

            // 优先寻找无效(invalid)槽位
            for (uint32_t w = 0; w < associativity; ++w)
            {
                if (!current_set[w].valid)
                {
                    victim_way = w;
                    found_invalid = true;
                    break;
                }
            }

            // 若全满，执行 LRU 策略寻找 age 最大的块
            if (!found_invalid)
            {
                uint32_t max_age = 0;
                for (uint32_t w = 0; w < associativity; ++w)
                {
                    if (current_set[w].age > max_age)
                    {
                        max_age = current_set[w].age;
                        victim_way = w;
                    }
                }
            }

            // 升级当前组内所有有效块的 age
            for (uint32_t w = 0; w < associativity; ++w)
            {
                if (current_set[w].valid)
                {
                    current_set[w].age++;
                }
            }

            // 将新块调入被选中的 victim_way
            current_set[victim_way].valid = true;
            current_set[victim_way].tag = tag;
            current_set[victim_way].age = 0;
        }
    }

    // 根据 block_size 动态估算 Miss 代价
    double get_miss_penalty() const
    {
        double r = PARA_R;
        // 每 4 字节一拍突发
        uint32_t beats = block_size / 4; 
        if (beats == 0) beats = 1; // 兜底防止 block_size < 4 的异常情况

        // 第一拍耗时 7.42*r，随后每一拍耗时 1*r
        double penalty = (7.42 * r) + ((beats - 1) * r);
        return penalty;
    }

    double get_miss_rate() const
    {
        return (total_accesses == 0) ? 0.0 : (static_cast<double>(miss_count) / total_accesses) * 100.0;
    }

    double get_tmt() const
    {
        return miss_count * get_miss_penalty();
    }

    // 打印探索报告
    void print_summary() const
    {
        std::cout << "--------------------------------------------------\n";
        std::cout << "Size: " << std::setw(3) << cache_size << " B | "
                  << "Block: " << std::setw(2) << block_size << " B | "
                  << "Assoc: " << associativity << "-Way\n";
        std::cout << "[Tag: " << tag_bits << " | Idx: " << index_bits << " | Off: " << offset_bits << "]  ";

        std::cout << "Hits: " << hit_count << " | Misses: " << miss_count
                  << std::fixed << std::setprecision(2)
                  << " | Miss Rate: " << get_miss_rate() << " %\n";
        std::cout << "Penalty/Miss: " << get_miss_penalty() << " cycles | "
                  << "Total Miss Time (TMT): " << get_tmt() << " cycles\n";
    }
};

void run_cache_single()
{
    if (!pctrace_read_init())
    {
        std::cerr << "Error: 无法初始化 Trace 回放输入源！" << std::endl;
        return;
    }

    std::cout << "\n=== [单组参数验证模式] ===\n";
    CacheSimulator sim(TARGET_CACHE_SIZE_B, TARGET_BLOCK_SIZE_B, TARGET_ASSOC);

    uint32_t pc = 0;
    while (pctrace_read_next(&pc))
    {
        sim.access(pc);
    }
    pctrace_read_close();

    sim.print_summary();
    std::cout << "==========================\n\n";
}

// 模式 2：设计空间探索 (DSE)
void run_cache_dse()
{
    if (!pctrace_read_init())
    {
        std::cerr << "Error: 无法初始化 Trace 回放输入源！" << std::endl;
        return;
    }

    // 内存缓冲 Trace，加速多组参数的遍历
    std::vector<uint32_t> trace_buffer;
    uint32_t pc = 0;
    while (pctrace_read_next(&pc))
    {
        trace_buffer.push_back(pc);
    }
    pctrace_read_close();

    if (trace_buffer.empty())
    {
        std::cerr << "Warning: 未读取到任何 Trace 记录。" << std::endl;
        return;
    }

    std::cout << "\n=== [设计空间探索 (DSE) 模式] ===\n";
    std::cout << "Trace 总数: " << trace_buffer.size() << "\n\n";

    // 调整为小面积约束下的设计空间
    std::vector<uint32_t> cache_sizes_b = {64};
    std::vector<uint32_t> block_sizes = { 8, 16, 32}; 
    std::vector<uint32_t> associativities = {1, 2, 4, };

    std::vector<SimResult> dse_results; // 存放扫描结果

    for (uint32_t size_b : cache_sizes_b)
    {
        for (uint32_t block : block_sizes)
        {
            for (uint32_t assoc : associativities)
            {
                if (block > size_b)
                    continue;
                if ((size_b / block) < assoc)
                    continue;

                CacheSimulator sim(size_b, block, assoc);

                for (uint32_t trace_pc : trace_buffer)
                {
                    sim.access(trace_pc);
                }

                sim.print_summary();
                
                // 将结果推入记录中用于后续排行
                dse_results.push_back({size_b, block, assoc, sim.get_miss_rate(), sim.get_tmt()});
            }
        }
    }
    
    // 对结果按 TMT 从低到高(好到坏)进行排序
    std::sort(dse_results.begin(), dse_results.end());

    // 打印排行榜
    std::cout << "\n=== [DSE 扫描完成：按 TMT 性能排行榜] ===\n";
    std::cout << std::left 
              << std::setw(6)  << "Rank" 
              << std::setw(10) << "Size(B)" 
              << std::setw(10) << "Block(B)" 
              << std::setw(10) << "Assoc" 
              << std::setw(15) << "Miss Rate(%)" 
              << "TMT (cycles)\n";
    std::cout << "--------------------------------------------------------------\n";
    
    for(size_t i = 0; i < dse_results.size(); ++i) {
        std::cout << std::left 
                  << std::setw(6)  << (i + 1)
                  << std::setw(10) << dse_results[i].size
                  << std::setw(10) << dse_results[i].block
                  << std::setw(10) << dse_results[i].assoc
                  << std::setw(15) << std::fixed << std::setprecision(2) << dse_results[i].miss_rate
                  << std::fixed << std::setprecision(2) << dse_results[i].tmt << "\n";
    }
    
    std::cout << "==============================================================\n\n";
}