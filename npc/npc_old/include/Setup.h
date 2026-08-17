#pragma once
#include <argparse/argparse.hpp>
#include <cstddef>
#include <fmt/format.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <string>

void register_argparse(argparse::ArgumentParser &program);
void register_logger(argparse::ArgumentParser &program);
struct Config {
  std::string image_path;
  size_t mem_size;
  uint32_t base_memory;
  size_t device_size;
  uint32_t base_device;
  bool batch_mode;
  bool difftest;
  bool use_waveform;
  std::string waveform_file;

  bool enable_vga;
  bool enable_audio;

  bool mtracer;
  bool ftracer;
  std::string elf_path;
  size_t itracer;
};

inline Config config;

Config setup(argparse::ArgumentParser &program);