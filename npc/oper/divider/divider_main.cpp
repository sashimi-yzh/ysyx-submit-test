#include <verilated.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstdint>
#include <cstring>
#include "Vdivider.h"

int pass_cnt = 0;
int total_cnt = 0;

struct TestCase {
    int32_t  dividend;
    int32_t  divisor;
    bool     is_signed;
    int32_t  expected_quotient;
    int32_t  expected_remainder;
    bool     expected_valid;
    const char* test_name;
};

void clock_cycle(Vdivider* dut) {
    dut->clk = 1;  dut->eval();
    dut->clk = 0;  dut->eval();
}

void run_test(Vdivider* dut, const TestCase& t) {
    // Reset
    dut->reset = 1;
    clock_cycle(dut);
    dut->reset = 0;

    // Apply inputs
    dut->dividend  = t.dividend;
    dut->divisor   = t.divisor;
    dut->is_signed = t.is_signed;

    // Single-cycle for divide-by-zero or overflow
    if (t.divisor == 0 ||
       (t.is_signed && t.dividend == INT32_MIN && t.divisor == -1)) {
        clock_cycle(dut);
    } else {
        // Up to 32 cycles for regular division
        for (int cycle = 0; cycle < 33 && !dut->valid; ++cycle) {
            clock_cycle(dut);
        }
    }

    // Check results
    bool pass = (dut->quotient  == t.expected_quotient) &&
                (dut->remainder == t.expected_remainder) &&
                (dut->valid     == t.expected_valid);
    std::cout << "Test: " << t.test_name << " - ";
    if (pass) {
        std::cout << "\033[32m**PASS**\033[0m\n";
        ++pass_cnt;
    } else {
        std::cout << "\033[31m**FAIL**\033[0m\n";
        std::cout << "  Dividend: "  << std::hex << t.dividend
                  << ", Divisor: " << t.divisor
                  << ", Signed: "  << t.is_signed << "\n";
        std::cout << "  Expected Quotient: " << std::dec << t.expected_quotient
                  << ", Got: " << dut->quotient << "\n";
        std::cout << "  Expected Remainder: " << t.expected_remainder
                  << ", Got: " << dut->remainder << "\n";
        std::cout << "  Expected Valid: " << t.expected_valid
                  << ", Got: " << (int)dut->valid << "\n";
    }
    ++total_cnt;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vdivider* dut = new Vdivider;

    // Seed RNG
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generate 100 random test cases
    std::vector<TestCase> tests;
    tests.reserve(100);
    for (int i = 0; i < 10000; ++i) {
        int32_t a = (std::rand() << 16) | (std::rand() & 0xFFFF);
        int32_t b;
        do {
            b = (std::rand() << 16) | (std::rand() & 0xFFFF);
        } while (b == 0);

        bool is_signed = (std::rand() & 1) != 0;

        // Compute expected values
        bool overflow = false;
        int32_t q=0, r=0;
        if (b == 0) {
            q = is_signed ? -1 : static_cast<int32_t>(0xFFFFFFFF);
            r = a;
        } else if (is_signed && a == INT32_MIN && b == -1) {
            overflow = true;
            q = a; r = 0;
        } else {
            if (is_signed) {
                q = a / b;
                r = a % b;
            } else {
                uint32_t ua = static_cast<uint32_t>(a);
                uint32_t ub = static_cast<uint32_t>(b);
                q = static_cast<int32_t>(ua / ub);
                r = static_cast<int32_t>(ua % ub);
            }
        }

        // Name the test
        char* namebuf = new char[32];
        std::snprintf(namebuf, 32, "RND %03d: %c %d / %d",
                      i+1,
                      is_signed ? 'S' : 'U',
                      a, b);

        tests.push_back({
            a, b, is_signed,
            q, r, (!overflow && b!=0),
            namebuf
        });
    }

    // Run all tests
    for (const auto& t : tests) {
        run_test(dut, t);
    }

    // Summary
    std::printf("\nTest Summary: Pass %d / Total %d\n",
                pass_cnt, total_cnt);

    delete dut;
    return 0;
}
