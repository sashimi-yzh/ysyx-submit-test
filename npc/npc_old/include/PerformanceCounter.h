#pragma once
#include <spdlog/spdlog.h>

struct Statistics {
  long long simulation_time;
  long long simulation_clocks;
  long long simulation_instructions;
};

inline Statistics performance_statistics;
