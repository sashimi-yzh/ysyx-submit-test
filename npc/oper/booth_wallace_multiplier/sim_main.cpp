#include <verilated.h>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <tuple>
#include <climits>
#include <chrono>
#include <random>
#include "Vbooth_wallace_multiplier.h"

// Test configuration
#define MAX_CYCLES 20
#define RESET_CYCLES 2
#define PROPAGATION_CYCLES 2
#define INT31_MAX 1073741823
#define INT31_MIN -1073741824

class BoothWallaceTester {
private:
    Vbooth_wallace_multiplier* dut;
    vluint64_t sim_time;

    void clock_cycle() {
        dut->clk = 1; dut->eval();
        dut->clk = 0; dut->eval();
        sim_time++;
    }

    void reset() {
        dut->rst_n = 0;
        for (int i = 0; i < RESET_CYCLES; i++) {
            clock_cycle();
        }
        dut->rst_n = 1;
    }

    bool run_test_case(int64_t multiplicand, int64_t multiplier, bool is_signed, double& test_time_us) {
        // 记录测试用例开始时间
        auto start = std::chrono::high_resolution_clock::now();

        // Set inputs
        dut->multiplicand = multiplicand;
        dut->multiplier = multiplier;
        dut->is_signed = is_signed;

        // Propagation cycles
        for (int i = 0; i < PROPAGATION_CYCLES; i++) {
            clock_cycle();
        }

        // Wait for valid output
        int cycles = 0;
        while (!dut->valid && cycles < MAX_CYCLES) {
            clock_cycle();
            cycles++;
        }

        // 记录测试用例结束时间
        auto end = std::chrono::high_resolution_clock::now();
        test_time_us = std::chrono::duration<double, std::micro>(end - start).count();

        // Calculate expected result
        int64_t expected = multiplicand * multiplier;

        // Verify result
        bool pass = (dut->valid && dut->product == expected);
        printf("Test: %" PRId64 " * %" PRId64 " (signed=%d) = %" PRId64 ", Expected: %" PRId64 ", %s, Time: %.2f μs\n",
               multiplicand, multiplier, is_signed, dut->product, expected,
               pass ? "\033[32m**PASS**\033[0m" : (dut->valid ? "\033[31m**FAIL**\033[0m" : "TIMEOUT"), test_time_us);
        return pass;
    }

public:
    BoothWallaceTester(int argc, char** argv) : sim_time(0) {
        Verilated::commandArgs(argc, argv);
        dut = new Vbooth_wallace_multiplier;
        dut->clk = 0;
    }

    ~BoothWallaceTester() {
        delete dut;
    }

    int run_tests() {
        // Define test cases: {multiplicand, multiplier, is_signed}
        std::vector<std::tuple<int64_t, int64_t, bool>> test_cases = {
            {256, 327, true},      // Positive * Positive (signed)
            {-100, 100, true},     // Negative * Positive (signed)
            {-100, -100, true},    // Negative * Negative (signed)
            {0, 12345, true},      // Zero * Positive (signed)
            {100, 100, false},     // Positive * Positive (unsigned)
            {INT32_MAX, 2, true},  // Large number (signed)
            {INT32_MAX, 2, false}, // Large number (unsigned)
            {1, 0, true},          // One * Zero (signed)
            {6732, 871, false},    // Random positive numbers (unsigned)
            {8234, -1234, true},   // Positive * Negative (unsigned)
        };

        // 随机生成测试用例
        std::random_device rd;
        std::mt19937_64 rng(rd());
        std::uniform_int_distribution<int64_t> dist31(INT31_MIN, INT31_MAX);
        std::uniform_int_distribution<int> sign_dist(0, 1);

        for (int i = 0; i < 10000; ++i) {
            int64_t a = dist31(rng);
            int64_t b = dist31(rng);
            // 随机让一部分数靠近边界
            if (i % 4 == 0) a = INT31_MAX - dist31(rng) % 1000;
            if (i % 4 == 1) b = INT31_MIN + dist31(rng) % 1000;
            // bool is_signed = sign_dist(rng);
            bool is_signed = ((a < 0) | (b < 0));
            test_cases.emplace_back(a, b, is_signed);
        }

        int passed = 0;
        reset();

        printf("\nStarting Booth-Wallace Multiplier Tests\n");
        printf("=======================================\n");

        for (const auto& test : test_cases) {
            double test_time_us = 0.0;
            if (run_test_case(std::get<0>(test), std::get<1>(test), std::get<2>(test), test_time_us)) {
                passed++;
            }
            reset(); // Reset between tests
        }

        printf("\nTest Summary: %d/%zu tests passed\n", passed, test_cases.size());
        return (passed == test_cases.size()) ? 0 : 1;
    }
};

int main(int argc, char** argv) {
    // 记录程序开始时间
    auto start = std::chrono::high_resolution_clock::now();

    BoothWallaceTester tester(argc, argv);
    int result = tester.run_tests();

    // 记录程序结束时间并计算总运行时间
    auto end = std::chrono::high_resolution_clock::now();
    double total_time_us = std::chrono::duration<double, std::micro>(end - start).count();
    printf("Total Execution Time: %.2f μs\n", total_time_us);

    return result;
}