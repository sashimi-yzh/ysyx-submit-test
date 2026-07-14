#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>

#include "include/trace.h"
#include "config.h"

// 替换策略枚举
enum class ReplacePolicy
{
    LRU,
    FIFO
};

// 预测算法枚举（新增了三种混合算法）
enum class PredictorType
{
    AlwaysTaken,
    AlwaysNotTaken,
    BTFN,
    OneBit,
    TwoBit,
    HistAndDir,      // 新增: 1-bit 历史 AND 分支方向
    HistOrDir,       // 新增: 1-bit 历史 OR 分支方向
    TwoBitDirHybrid  // 新增: 2-bit 状态与分支方向混合
};

// BTB 表项（元数据结构），融入了预测器状态
struct BTBEntry
{
    bool valid = false;
    uint32_t tag = 0;
    uint32_t age = 0;

    // 预测器状态
    bool history_1bit = false; // 1-bit 预测器状态
    uint8_t history_2bit = 1;  // 2-bit 饱和计数器: 0(SNT), 1(WNT), 2(WT), 3(ST)
};

// 扩展 SimResult 以支持新的维度和指标
struct SimResult
{
    uint32_t entries;
    uint32_t assoc;
    ReplacePolicy policy;
    PredictorType predictor;

    double hit_rate;
    double miss_rate;
    double accuracy;

    // 按命中率影响下的预测准确率降序排序，若准确率相同则按命中率排序
    bool operator<(const SimResult &other) const
    {
        if (std::abs(accuracy - other.accuracy) > 1e-6)
            return accuracy > other.accuracy;
        return hit_rate > other.hit_rate;
    }
};

// 辅助结构：用于在内存中缓存 Trace 记录
struct BranchTraceItem
{
    uint32_t pc;
    bool is_backward;
    bool is_taken;
};

// BTB 模拟器核心类
class BTBSimulator
{
private:
    uint32_t num_entries;
    uint32_t associativity;
    uint32_t num_sets;
    ReplacePolicy policy;
    PredictorType predictor;

    uint32_t offset_bits;
    uint32_t index_bits;
    uint32_t tag_bits;
    uint32_t index_mask;

    std::vector<std::vector<BTBEntry>> btb;

    uint64_t total_branches = 0;
    uint64_t miss_count = 0;
    uint64_t hit_count = 0;
    uint64_t correct_predictions = 0; // 预测正确计数

public:
    BTBSimulator(uint32_t entries, uint32_t assoc, ReplacePolicy p, PredictorType pred)
        : num_entries(entries), associativity(assoc), policy(p), predictor(pred)
    {
        num_sets = num_entries / associativity;

        offset_bits = 2;
        index_bits = static_cast<uint32_t>(std::log2(num_sets));
        tag_bits = 32 - index_bits - offset_bits;
        index_mask = (num_sets > 1) ? (num_sets - 1) : 0;

        btb.resize(num_sets, std::vector<BTBEntry>(associativity));
    }

    void access(uint32_t pc, bool is_backward, bool is_taken)
    {
        total_branches++;

        uint32_t index = (pc >> offset_bits) & index_mask;
        uint32_t tag = pc >> (offset_bits + index_bits);

        auto &current_set = btb[index];
        bool is_hit = false;
        uint32_t hit_way = 0;
        bool predicted_taken = false;

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

            // --- 提取预测结果 ---
            switch (predictor)
            {
            case PredictorType::AlwaysTaken:
                predicted_taken = true;
                break;
            case PredictorType::AlwaysNotTaken:
                predicted_taken = false;
                break;
            case PredictorType::BTFN:
                predicted_taken = is_backward;
                break;
            case PredictorType::OneBit:
                predicted_taken = current_set[hit_way].history_1bit;
                break;
            case PredictorType::TwoBit:
                predicted_taken = (current_set[hit_way].history_2bit >= 2);
                break;
            
            // 新增：保守型 1-Bit 结合方向 (历史为跳转 且 方向为向后 才预测跳转)
            case PredictorType::HistAndDir:
                predicted_taken = current_set[hit_way].history_1bit && is_backward;
                break;
            
            // 新增：激进型 1-Bit 结合方向 (历史为跳转 或 方向为向后 就预测跳转)
            case PredictorType::HistOrDir:
                predicted_taken = current_set[hit_way].history_1bit || is_backward;
                break;
            
            // 新增：2-Bit 弱状态时回退到分支方向预测
            case PredictorType::TwoBitDirHybrid:
                if (current_set[hit_way].history_2bit == 0) {
                    predicted_taken = false;       // 强不跳
                } else if (current_set[hit_way].history_2bit == 3) {
                    predicted_taken = true;        // 强跳
                } else {
                    predicted_taken = is_backward; // 信心弱 (1或2) 时，听从静态方向 BTFN
                }
                break;
            }

            // --- 更新预测器状态 ---
            current_set[hit_way].history_1bit = is_taken;
            if (is_taken)
            {
                if (current_set[hit_way].history_2bit < 3)
                    current_set[hit_way].history_2bit++;
            }
            else
            {
                if (current_set[hit_way].history_2bit > 0)
                    current_set[hit_way].history_2bit--;
            }

            // --- 更新替换策略年龄 ---
            if (policy == ReplacePolicy::LRU)
            {
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
        }
        else
        {
            miss_count++;

            // 在实际硬件中，BTB Miss 通常意味着取指部件根本不知道这里有一条分支指令，
            // 只能按顺序继续取指（即默认预测为 Not Taken）。
            predicted_taken = false;

            // 2. 发生缺失，寻找替换槽位
            uint32_t victim_way = 0;
            bool found_invalid = false;

            for (uint32_t w = 0; w < associativity; ++w)
            {
                if (!current_set[w].valid)
                {
                    victim_way = w;
                    found_invalid = true;
                    break;
                }
            }

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

            for (uint32_t w = 0; w < associativity; ++w)
            {
                if (current_set[w].valid)
                    current_set[w].age++;
            }

            // 录入新分支指令，重置相关状态
            current_set[victim_way].valid = true;
            current_set[victim_way].tag = tag;
            current_set[victim_way].age = 0;

            // 根据当前实际结果初始化历史状态
            current_set[victim_way].history_1bit = is_taken;
            current_set[victim_way].history_2bit = is_taken ? 2 : 1; // 2=WT, 1=WNT
        }

        // 3. 统计预测准确率
        if (predicted_taken == is_taken)
        {
            correct_predictions++;
        }
    }

    double get_hit_rate() const { return (total_branches == 0) ? 0.0 : (static_cast<double>(hit_count) / total_branches) * 100.0; }
    double get_miss_rate() const { return (total_branches == 0) ? 0.0 : (static_cast<double>(miss_count) / total_branches) * 100.0; }
    double get_accuracy() const { return (total_branches == 0) ? 0.0 : (static_cast<double>(correct_predictions) / total_branches) * 100.0; }
};

// 辅助函数：将枚举转为字符串以供对齐打印
std::string get_pred_name(PredictorType pt)
{
    switch (pt)
    {
    case PredictorType::AlwaysTaken:    return "Always-T";
    case PredictorType::AlwaysNotTaken: return "Always-NT";
    case PredictorType::BTFN:           return "BTFN";
    case PredictorType::OneBit:         return "1-Bit";
    case PredictorType::TwoBit:         return "2-Bit";
    case PredictorType::HistAndDir:     return "1B-AND-Dir";
    case PredictorType::HistOrDir:      return "1B-OR-Dir";
    case PredictorType::TwoBitDirHybrid:return "2B-Dir-Hyb";
    default:                            return "Unknown";
    }
}

// ==============================================================================
// 模式：设计空间探索 (DSE)
// ==============================================================================
void run_btb_dse()
{
    if (!branchtrace_read_init())
    {
        std::cerr << "Error: 无法初始化 Branch Trace 回放输入源！" << std::endl;
        return;
    }

    // 内存缓冲 Trace（现在包含完整信息以供预测），加速多组参数的遍历
    std::vector<BranchTraceItem> trace_buffer;
    uint32_t pc = 0;
    bool is_backward = false;
    bool is_taken = false;

    while (branchtrace_read_next(&pc, &is_backward, &is_taken))
    {
        trace_buffer.push_back({pc, is_backward, is_taken});
    }
    branchtrace_read_close();

    if (trace_buffer.empty())
    {
        std::cerr << "Warning: 未读取到任何 Trace 记录。" << std::endl;
        return;
    }

    std::cout << "\n=== [BTB 设计空间探索 (DSE) 模式 - 预测算法维度] ===\n";
    std::cout << "分支指令 Trace 总数: " << trace_buffer.size() << "\n\n";

    // 探索参数
    std::vector<uint32_t> btb_entries_list = {4, 8};
    std::vector<uint32_t> associativities = { 4, 8};
    std::vector<ReplacePolicy> policies = {ReplacePolicy::LRU, ReplacePolicy::FIFO};
    
    // 把新的预测器加入 DSE 扫描列表中
    std::vector<PredictorType> predictors = {
        PredictorType::AlwaysTaken,
        // PredictorType::AlwaysNotTaken,
        PredictorType::BTFN,
        PredictorType::OneBit,
        PredictorType::TwoBit,
        PredictorType::HistAndDir,
        PredictorType::HistOrDir,
        PredictorType::TwoBitDirHybrid
    };

    std::vector<SimResult> dse_results;

    for (uint32_t entries : btb_entries_list)
    {
        for (uint32_t assoc : associativities)
        {
            if (entries < assoc)
                continue;

            for (ReplacePolicy pol : policies)
            {
                for (PredictorType pred : predictors)
                {
                    BTBSimulator sim(entries, assoc, pol, pred);

                    for (const auto &item : trace_buffer)
                    {
                        sim.access(item.pc, item.is_backward, item.is_taken);
                    }

                    dse_results.push_back({entries, assoc, pol, pred,
                                           sim.get_hit_rate(), sim.get_miss_rate(), sim.get_accuracy()});
                }
            }
        }
    }

    // 按命中率影响下的预测准确率从高到低排序
    std::sort(dse_results.begin(), dse_results.end());

    // 打印排行榜
    std::cout << "\n=== [BTB DSE 扫描完成：综合性能排行榜 (按 Accuracy 排列)] ===\n";
    std::cout << std::left
              << std::setw(6) << "Rank"
              << std::setw(12) << "Entries"
              << std::setw(8) << "Assoc"
              << std::setw(10) << "Policy"
              << std::setw(14) << "Predictor"
              << std::setw(15) << "Hit Rate(%)"
              << "Accuracy(%)\n";
    std::cout << "-------------------------------------------------------------------------------\n";

    for (size_t i = 0; i < dse_results.size(); ++i)
    {
        std::string policy_str = (dse_results[i].policy == ReplacePolicy::LRU) ? "LRU" : "FIFO";
        std::string pred_str = get_pred_name(dse_results[i].predictor);

        std::cout << std::left
                  << std::setw(6) << (i + 1)
                  << std::setw(12) << dse_results[i].entries
                  << std::setw(8) << dse_results[i].assoc
                  << std::setw(10) << policy_str
                  << std::setw(14) << pred_str
                  << std::setw(15) << std::fixed << std::setprecision(2) << dse_results[i].hit_rate
                  << std::fixed << std::setprecision(2) << dse_results[i].accuracy << "\n";
    }

    std::cout << "===============================================================================\n\n";
}