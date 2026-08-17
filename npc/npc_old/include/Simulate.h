#pragma once
#include "Ref.h"
#include <DUT.h>
#include <memory>
#include <fmt/format.h>
#include <replxx.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

inline std::unique_ptr<Dut> dut;
inline std::unique_ptr<Ref> ref;
inline std::unique_ptr<VerilatedContext> contextp;

enum class SimulationState { RUNNING, HALT, DIFFTEST_FAILED };
inline SimulationState sim_state;

int simulate();

void run(unsigned long long steps);