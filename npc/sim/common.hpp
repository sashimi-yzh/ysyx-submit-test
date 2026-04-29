#pragma once
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <format>

#include "vsrc.hpp"

std::string getOutputDir(std::string_view prefix);
inline auto genLogFilePath(std::string_view name) {
  return std::format("build/logs/{}.log", name);
  // return std::format("{}/{}.log", getOutputDir("build/logs"), name);
}
inline auto newFileLoggerSink(const std::string &name) {
  auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
      genLogFilePath(name), true);
  file_sink->set_level(spdlog::level::debug);
  return file_sink;
}

inline bool isMakePerf() { return getenv("MAKE_PERF") != nullptr; }
bool isCIEnv();
