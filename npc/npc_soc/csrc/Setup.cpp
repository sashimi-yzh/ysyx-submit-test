#include "Setup.h"
#include "spdlog/spdlog.h"
using std::string;

void register_argparse(argparse::ArgumentParser &program) {
  program.add_argument("-i", "--image")
      .help("Path to log file")
      .nargs(1)
      .required();
  program.add_argument("-l", "--log").help("The program image file");
  program.add_argument("-d", "--difftest")
      .help("Use NEMUemu as differential test")
      .flag();
  program.add_argument("-m", "--mtracer").help("Enable mtracer").flag();
  program.add_argument("-b", "--batch").help("Use batch mode").flag();
  program.add_argument("-n", "--nvboard").help("Use nvboard").flag();
}

void register_logger(argparse::ArgumentParser &program) {
  bool provided_logfile = program.is_used("--log");
  if (provided_logfile) {
    string log_path = program.get("--log");
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%t] [%^%l%$] %v");

    auto file_sink =
        std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_path, true);
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [thread %t] [%^%l%$] - %v");
    spdlog::logger logger("multi_logger", {console_sink, file_sink});
    spdlog::set_default_logger(std::make_shared<spdlog::logger>(logger));
    spdlog::info("Logging to file : {}", log_path);
  }

  spdlog::flush_every(std::chrono::seconds(5));
  spdlog::flush_on(spdlog::level::warn);
}

Config setup(argparse::ArgumentParser &program) {

  Config ret = {};

  ret.image_path = program.get("--image");
  ret.batch_mode = program.get<bool>("--batch");
  spdlog::info("Image path  : {}", ret.image_path);
  ret.difftest = program.get<bool>("--difftest");
  ret.mtracer = program.get<bool>("--mtracer");
  ret.nvboard = program.get<bool>("--nvboard");

  if (ret.difftest)
    spdlog::info("Using difftest");
  if (ret.nvboard)
    spdlog::info("Using nvboard");
  if (ret.mtracer)
    spdlog::info("Using mtracer");

  return ret;
}
