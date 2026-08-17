#include "Setup.h"
#include "spdlog/spdlog.h"
using std::string;

void register_argparse(argparse::ArgumentParser &program) {
  program.add_argument("-i", "--image")
      .help("Path to log file")
      .nargs(1)
      .required();
  program.add_argument("-l", "--log").help("The program image file");
  program.add_argument("-b", "--batch").help("Use batch mode").flag();
  program.add_argument("--nr_icacheline")
      .help("Number of icache lines (2's pow)")
      .scan<'u', unsigned>();
  program.add_argument("--nr_icachesize")
      .help("Number of words in each icache line (2's pow)")
      .scan<'u', unsigned>();
  program.add_argument("--nr_dcacheline")
      .help("Number of dcache lines (2's pow)")
      .scan<'u', unsigned>();
  program.add_argument("--nr_dcachesize")
      .help("Number of words in each dcache line (2's pow)")
      .scan<'u', unsigned>();
  program.add_argument("--nr_btbsize")
      .help("Number of items in branch target buffer (2's pow)")
      .scan<'u', unsigned>();
  program.add_argument("--nr_jtbsize")
      .help("Number of items in jal target buffer (2's pow)")
      .scan<'u', unsigned>();
}

void register_logger(argparse::ArgumentParser &program) {
  bool provided_logfile = program.is_used("--log");
  if (provided_logfile) {
    string log_path = program.get("--log");
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_pattern(
        "[%Y-%m-%d %H:%M:%S.%e] [thread %t] [%^%l%$] - %v");

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
  ret.nr_icachelines_2pow = program.get<unsigned>("--nr_icacheline");
  ret.nr_icacheline_words_2pow = program.get<unsigned>("--nr_icachesize");
  ret.nr_dcachelines_2pow = program.get<unsigned>("--nr_dcacheline");
  ret.nr_dcacheline_words_2pow = program.get<unsigned>("--nr_dcachesize");
  ret.nr_btbsize_2pow = program.get<unsigned>("--nr_btbsize");

  spdlog::info("Image path  : {}", ret.image_path);
  spdlog::info("Instruction cacheline count  : 2^{}", ret.nr_icachelines_2pow);
  spdlog::info("Word count in each icacheline  : 2^{}",
               ret.nr_icacheline_words_2pow);
  spdlog::info("Data cacheline count  : 2^{}", ret.nr_dcachelines_2pow);
  spdlog::info("Word count in each dcacheline  : 2^{}",
               ret.nr_dcacheline_words_2pow);
  spdlog::info("Item count in branch target buffer : 2^{}",
               ret.nr_btbsize_2pow);

  return ret;
}
