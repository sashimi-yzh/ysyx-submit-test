#include "Setup.h"
#include "spdlog/spdlog.h"
#include <cstddef>
#include <cstdint>
using std::string;

void register_argparse(argparse::ArgumentParser &program) {
  program.add_argument("-i", "--image")
      .help("The program image file")
      .nargs(1)
      .required();
  program.add_argument("-w", "--waveform").help("Waveform file name").nargs(1);
  program.add_argument("-l", "--log").help("Path to log file");
  program.add_argument("-d", "--difftest").help("Use differential test").flag();
  program.add_argument("--mem_size")
      .help("Capacity of memory in bytes")
      .scan<'x', size_t>();
  program.add_argument("--mem_base")
      .help("Address base of memory")
      .scan<'x', uint32_t>()
      .required();
  program.add_argument("--device_size")
      .help("Length of device space in bytes")
      .scan<'x', size_t>()
      .required();
  program.add_argument("--device_base")
      .help("Address base of device")
      .scan<'x', uint32_t>()
      .required();

  program.add_argument("-v", "--enable_vga")
      .help("Enable VGA and keyboard")
      .flag();
  program.add_argument("-a", "--enable_audio").help("Enable audio").flag();

  program.add_argument("--mtracer").help("Enable memory tracer").flag();
  program.add_argument("--ftracer")
      .help("Enable function tracer and set elf file path")
      .nargs(1);
  program.add_argument("--itracer")
      .help("Enable instruction tracer and set number of instructions to trace")
      .default_value<size_t>(0)
      .scan<'u', size_t>();

  program.add_argument("-b", "--batch").help("Use batch mode").flag();
}

void register_logger(argparse::ArgumentParser &program) {
  bool provided_logfile = program.is_used("--log");
  if (provided_logfile) {
    string log_path = program.get("--log");
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%t] [%^%l%$] %v");

    auto file_sink =
        std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_path, true);
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [thread %t] [%^%l%$] %v");
    spdlog::logger logger("multi_logger", {console_sink, file_sink});
    spdlog::set_default_logger(std::make_shared<spdlog::logger>(logger));
    spdlog::info("Log to file : {}", log_path);
  }

  spdlog::flush_every(std::chrono::seconds(5));
  spdlog::flush_on(spdlog::level::warn);
}

Config setup(argparse::ArgumentParser &program) {

  Config ret = {};
  ret.use_waveform = program.is_used("--waveform");
  ret.enable_audio = program.is_used("--enable_audio");
  ret.enable_vga = program.is_used("--enable_vga");
  if (ret.use_waveform) {
    ret.waveform_file = program.get("--waveform");
    spdlog::info("Waveform path  : {}", ret.waveform_file);
  }
  ret.mem_size = program.get<size_t>("--mem_size");
  ret.base_memory = program.get<uint32_t>("--mem_base");
  ret.device_size = program.get<size_t>("--device_size");
  ret.base_device = program.get<uint32_t>("--device_base");
  ret.mtracer = program.is_used("--mtracer");
  if (ret.mtracer)
    spdlog::info("Using mtracer");
  if (ret.ftracer)
    spdlog::info("Using ftracer");
  if (ret.itracer > 0)
    spdlog::info("Using itracer of length {}", ret.itracer);

  ret.ftracer = program.is_used("--ftracer");
  if (ret.ftracer)
    ret.elf_path = program.get("--ftracer");
  ret.itracer = program.get<size_t>("--itracer");
  ret.image_path = program.get("--image");
  ret.batch_mode = program.get<bool>("--batch");
  spdlog::info("Image path  : {}", ret.image_path);
  ret.difftest = program.get<bool>("--difftest");
  if (ret.difftest)
    spdlog::info("Using difftest");

  return ret;
}
