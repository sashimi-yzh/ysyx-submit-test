#ifndef BRANCH_SIM_H
#define BRANCH_SIM_H

#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

// 分支预测器类型
enum class BranchPredictor {
    ALWAYS_NOT_TAKEN,
    ALWAYS_TAKEN,
    BTFN
};

// 单条分支记录
struct BranchRecord {
    uint32_t pc;
    uint32_t target_pc;
    bool     taken;          // 实际方向
};

// 预测统计
struct PredictorStats {
    uint64_t total_branches;
    uint64_t correct;
    uint64_t incorrect;

    PredictorStats() : total_branches(0), correct(0), incorrect(0) {}
    
    double accuracy() const {
        if (total_branches == 0) return 0.0;
        return (double)correct / total_branches * 100.0;
    }
};

// 分支预测器模拟器
class BranchSimulator {
public:
    BranchSimulator() = default;

    // 处理一条记录，返回三个预测器的结果（每个是否正确）
    struct PredictionResults {
        bool always_not_taken_correct;
        bool always_taken_correct;
        bool btfn_correct;
    };

    PredictionResults predictAndUpdate(const BranchRecord& rec);
    
    // 批量处理
    void processTrace(const std::vector<BranchRecord>& trace);
    
    // 获取各预测器统计
    const PredictorStats& getAlwaysNotTakenStats() const { return stats_ant_; }
    const PredictorStats& getAlwaysTakenStats() const    { return stats_at_; }
    const PredictorStats& getBTFNStats() const           { return stats_btfn_; }

    // 打印报告
    void printReport() const;

    // 重置
    void reset();

private:
    // BTFN 预测逻辑
    bool predictBTFN(uint32_t pc, uint32_t target_pc) const;

    PredictorStats stats_ant_;   // Always Not Taken
    PredictorStats stats_at_;    // Always Taken
    PredictorStats stats_btfn_;  // BTFN
};

#endif // BRANCH_SIM_H