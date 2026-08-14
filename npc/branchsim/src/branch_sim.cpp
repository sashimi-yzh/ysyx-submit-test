#include "branch_sim.h"
#include <iomanip>

bool BranchSimulator::predictBTFN(uint32_t pc, uint32_t target_pc) const {
    // BTFN: 如果目标地址 < PC（后向跳转）则预测 Taken，否则 Not Taken
    // 注意：对于无条件直接跳转，通常也是后向（循环）居多，BTFN 适用。
    return (target_pc < pc);
}

BranchSimulator::PredictionResults 
BranchSimulator::predictAndUpdate(const BranchRecord& rec) {
    bool actual = rec.taken;

    // 1. Always Not Taken 预测
    bool pred_ant = false;
    bool ant_correct = (pred_ant == actual);

    // 2. Always Taken 预测
    bool pred_at = true;
    bool at_correct = (pred_at == actual);

    // 3. BTFN 预测
    bool pred_btfn = predictBTFN(rec.pc, rec.target_pc);
    bool btfn_correct = (pred_btfn == actual);

    // 更新统计
    stats_ant_.total_branches++;
    stats_at_.total_branches++;
    stats_btfn_.total_branches++;

    if (ant_correct) stats_ant_.correct++; else stats_ant_.incorrect++;
    if (at_correct)  stats_at_.correct++;  else stats_at_.incorrect++;
    if (btfn_correct)stats_btfn_.correct++;else stats_btfn_.incorrect++;

    return {ant_correct, at_correct, btfn_correct};
}

void BranchSimulator::processTrace(const std::vector<BranchRecord>& trace) {
    for (const auto& rec : trace) {
        predictAndUpdate(rec);
    }
}

void BranchSimulator::reset() {
    stats_ant_ = PredictorStats();
    stats_at_  = PredictorStats();
    stats_btfn_ = PredictorStats();
}

void BranchSimulator::printReport() const {
    std::cout << "\n========================================\n";
    std::cout << "  Branch Predictor Simulation Results\n";
    std::cout << "========================================\n";
    std::cout << "Total branches processed: " << stats_ant_.total_branches << "\n\n";

    auto print_stats = [](const std::string& name, const PredictorStats& s) {
        std::cout << "Predictor: " << name << "\n";
        std::cout << "  Correct:   " << s.correct << "\n";
        std::cout << "  Incorrect: " << s.incorrect << "\n";
        std::cout << "  Accuracy:  " << std::fixed << std::setprecision(2) 
                  << s.accuracy() << "%\n\n";
    };

    print_stats("Always Not Taken", stats_ant_);
    print_stats("Always Taken",     stats_at_);
    print_stats("BTFN",             stats_btfn_);
}