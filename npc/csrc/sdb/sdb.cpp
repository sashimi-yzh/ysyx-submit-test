#include "common.h"
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string rl_gets() {
  std::string cmd;
  std::cout << "(npc) ";
  std::getline(std::cin, cmd);
  return cmd;
}

int cmd_help(const std::string &args);
int cmd_c(const std::string &args);
int cmd_q(const std::string &args);
int cmd_si(const std::string &args);
int cmd_info(const std::string &args);
int cmd_x(const std::string &args);
int cmd_p(const std::string &args);
int cmd_b(const std::string &args);
int cmd_d(const std::string &args);
int cmd_add_mem_guard(const std::string &args);
int cmd_echo_status(const std::string &args);
int cmd_start_trace(const std::string &args);

struct Command {
  const std::string name;
  const std::string description;
  int (*handler)(const std::string &args);
};

__attribute__((used))
const Command cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NPC", cmd_q},
    {"si", "Run the program N steps, default is 1", cmd_si},
    {"info", "arg r to print reg, arg w to print watchpoint", cmd_info},
    {"p", "eval the expreesion", cmd_p},
    {"b", "alloc new watchpoint", cmd_b},
    {"d", "delete a watchpoint", cmd_d},
    {"x", "print memory", cmd_x},
    {"m", "add memory guard", cmd_add_mem_guard},
    {"echo_status", "echo npc status", cmd_echo_status},
    {"trace", "switch the tracer state", cmd_start_trace},
};

#define NR_CMD sizeof(cmd_table) / sizeof(cmd_table[0])

int cmd_help(const std::string &args) {
  if (args.empty()) {
    for (const auto &cmd : cmd_table) {
      std::cout << cmd.name << " - " << cmd.description << std::endl;
    }
  } else {
    for (const auto &cmd : cmd_table) {
      if (cmd.name == args) {
        std::cout << cmd.name << " - " << cmd.description << std::endl;
        return 0;
      }
    }
    std::cout << "Unknown command '" << args << "'" << std::endl;
  }
  return 0;
}

int cmd_echo_status(const std::string &args) {
  echo_status();
  return 0;
}

#ifdef DIFFTEST
int cmd_add_mem_guard(const std::string &args){
  if(args.empty()){
    std::cout << "[error] add a paddr to check the mem" << std::endl;
    return 0;
  }
  std::stringstream ss(args);
  std::vector<std::string> arr;
  std::string item;
  while(std::getline(ss, item, ' ')) {
    arr.push_back(item);
  }
  if(arr.size() > 2){
    std::cout << "[error] too many args" << std::endl;
    std::cout << "usage: m <addr> <szie>" << std::endl;
  }
  uint32_t paddr = std::stoul(arr[0], nullptr, 16);
  size_t size = 4;
  if(arr.size() == 2) {
    size = std::stoi(arr[1]);
    if(!(size == 1 || size == 2 || size == 4)) {
      std::cout << "[error] get a invaild size: " << size << std::endl;
      return 0;
    }
  }
  add_mem_guard(paddr, size);
  return 0;
}

#else

int cmd_add_mem_guard(const std::string &args){
  std::cout << "[error] not support add mem guard without difftest" << std::endl;
  return 0;
}

#endif

int cmd_c(const std::string &args) {
  cpu_exec(-1);
  return 0;
}

int cmd_q(const std::string &args) {
  set_npc_quit();
  return -1;
}

int cmd_p(const std::string &args) {
  char *exp = new char[args.length() + 1];
  std::strcpy(exp, args.c_str());
  bool success = true;
  uint32_t res = expr(exp, &success);
  if (success == true) {
    printf("%d\n", res);
  }
  delete[] exp;
  return 0;
}

int cmd_si(const std::string &args) {
  int times = 1;
  if (!args.empty()) {
    times = std::stoi(args);
    if (times <= 0) {
      times = -1;
    }
  }
  cpu_exec(times);
  return 0;
}

int cmd_info(const std::string &args) {
  if (args == "r") {
    // api to print reg
    display_reg();
  } else if (args == "w") {
    info_wp();
  } else {
    std::cout << "[error] get a invalid arg: " << args << std::endl;
  }
  return 0;
}

int cmd_b(const std::string &args) {
  char *exp = new char[args.length() + 1];
  std::strcpy(exp, args.c_str());
  new_wp(exp);
  delete[] exp;
  return 0;
}

int cmd_d(const std::string &args) {
  int num = std::stoi(args, nullptr);
  free_wp(num);
  return 0;
}

int cmd_x(const std::string &args) {
  std::vector<std::string> arr;
  std::stringstream ss(args);
  std::string item;
  while (std::getline(ss, item, ' ')) {
    arr.push_back(item);
  }

  if (arr.size() != 2) {
    std::cout << "[error] get a invaild args: " << args << std::endl;
    return 0;
  }

  int times = std::stoi(arr[0], nullptr);
  if (times <= 0) {
    std::cout << "[error] get a invalid args: " << args << std::endl;
  }

  int addr = std::stoi(arr[1], nullptr, 16);
  for (int i = 0; i < times; i++) {
    std::cout << "0x" << std::hex << std::setfill('0') << std::setw(8) << addr
              << ' ';
    for (int j = 0; j < 4; j++) {
      int ret = paddr_read(addr, 1);
      std::cout << std::hex << std::setw(2) << std::setfill('0') << ret << ' ';
    }
    std::cout << std::dec << std::endl;
  }
  return 0;
}

int cmd_start_trace(const std::string &args) {
  std::vector<std::string> arr;
  std::stringstream ss(args);
  std::string item;

  if(!args.empty()) {
    while(std::getline(ss, item, ' ')) {
      arr.push_back(item);
    }
  }

  if(record_isenable()) {
    set_record_disenable();
    std::cout << "trace off" << std::endl;
  } else {
    set_record_enable();
    std::cout << "trace on" << std::endl;
  }

  return 0;
}

void sdb_main() {
  std::cout << "sdb start" << std::endl;

  while (true) {
    std::string str = rl_gets();
    if (str.empty()) {
      continue;
    }

    // Split the input string into command and arguments
    size_t space_pos = str.find(' ');
    std::string cmd =
        (space_pos == std::string::npos) ? str : str.substr(0, space_pos);
    std::string args =
        (space_pos == std::string::npos) ? "" : str.substr(space_pos + 1);

    size_t i = 0;
    for (i = 0; i < NR_CMD; i++) {
      if (cmd_table[i].name == cmd) {
        if (cmd_table[i].handler(args) < 0) {
          return;
        }
        break;
      }
    }

    if (i == NR_CMD) {
      std::cout << "Unknown command '" << cmd << "'" << std::endl;
    }
  }
}
