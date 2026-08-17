#include <Args.h>
#include <iostream>
#include <print>

using std::cerr;
using std::string;

Config process_args(int argc, char *argv[]) {
  argparse::ArgumentParser program("NPC_SOC");

  register_argparse(program);
  try {
    program.parse_args(argc, argv);
  } catch (const std::exception &err) {
    cerr << err.what() << std::endl;
    cerr << program;
    std::terminate();
  }

  register_logger(program);

  return setup(program);
}
