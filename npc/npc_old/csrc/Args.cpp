#include <Args.h>
#include <Vnpc_top.h>
#include <iostream>
#include <fmt/format.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

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
