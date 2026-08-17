#pragma once

#include <argparse/argparse.hpp>
#include <cstdint>
#include <fmt/format.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <string>

void register_argparse(argparse::ArgumentParser &program);
void register_logger(argparse::ArgumentParser &program);
struct Config {
  std::string image_path;
  bool batch_mode;
  bool difftest;
  bool mtracer;
  bool nvboard;
  bool waveform;
  uint32_t wave_pc_start;
  uint32_t wave_pc_end;
};

Config setup(argparse::ArgumentParser &program);

inline Config config;