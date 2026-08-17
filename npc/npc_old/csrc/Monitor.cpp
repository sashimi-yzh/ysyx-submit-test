#include "Expression/Expression.h"
#include "Expression/Watcher.h"
#include "RingBuffer.hpp"
#include "Setup.h"
#include "Simulate.h"
#include "my_utils.h"
#include <Monitor.h>
#include <cstdint>
#include <ctre/ctre.hpp>
#include <fmt/format.h>
using ctll::fixed_string;
using ctre::match;
static constexpr auto RE_NO_ARG = fixed_string{R"(\s*)"};
static constexpr auto RE_ONE_NUMBER =
    fixed_string{R"(\s*(0[xX][a-fA-F0-9]+|0[0-7]+|[1-9][0-9]*|0)\s*)"};
static constexpr auto RE_SCAN =
    fixed_string{R"(\s*(0[xX][a-fA-F0-9]+|0[0-7]+|[1-9][0-9]*|0)\s*(.*)\s*)"};
static constexpr auto RE_ONE_EXPR = fixed_string{R"(\s*(.*)\s*)"};

CmdResult cmd_c(std::string_view arg) {
  if (match<RE_NO_ARG>(arg)) {
    run(-1);
    return CmdResult::OKAY;
  } else {
    return CmdResult::INVALID_ARG;
  }
}
CmdResult cmd_s(std::string_view arg) {
  if (match<RE_NO_ARG>(arg)) {
    run(1);
    return CmdResult::OKAY;
  } else if (auto [whole, num_str] = match<RE_ONE_NUMBER>(arg); whole) {
    auto value = to_number<unsigned long long>(num_str);
    if (value.has_value()) {
      unsigned long long steps = value.value();
      run(steps);
    } else {
      return CmdResult::INVALID_ARG;
    }
    return CmdResult::OKAY;
  } else {
    return CmdResult::INVALID_ARG;
  }
}

CmdResult cmd_x(std::string_view arg) {
  if (auto [whole, num_str, expr_str] = match<RE_SCAN>(arg); whole) {
    auto n_of_w = to_number<unsigned long long>(num_str);
    Result<Expr::Expression> result =
        Expr::Expression::create_expression(expr_str);

    if (!result)
      println("{}", result.error());
    else {
      uint32_t base_addr = result->last_value.value();
      if (!n_of_w.has_value())
        return CmdResult::INVALID_ARG;
      if (base_addr >= config.base_memory &&
          n_of_w.value() + base_addr < config.base_memory + config.mem_size) {
        println("Address \tHex     \tDec");
        for (int i = 0; i < n_of_w; i++) {
          uint32_t addr = (base_addr + i * sizeof(uint32_t)) & ~0x3;
          println("{0:08x}\t{1:08x}\t{1}", addr,
                  mem[(addr - config.base_memory) >> 2]);
        }
      } else {
        println("Invalid scan range [{:#010x},{:#010x})", base_addr & ~0x3,
                (n_of_w.value() + base_addr * sizeof(uint32_t)) & ~0x3);
        return CmdResult::INVALID_ARG;
      }
    }
  } else {
    return CmdResult::INVALID_ARG;
  }
  return CmdResult::OKAY;
}

CmdResult cmd_q(std::string_view arg) {
  if (match<RE_NO_ARG>(arg)) {
    quit.store(true);
    return CmdResult::OKAY;
  } else {
    return CmdResult::INVALID_ARG;
  }
}

CmdResult cmd_l(std::string_view arg) {
  if (match<R"(\s*r\s*)">(arg)) {
    dut->print_all_gpr();
    return CmdResult::OKAY;
  } else if (match<R"(\s*w\s*)">(arg)) {
    if (watchers.empty()) {
      println("No watchers");
    } else {
      println("ID\tHex     \tDec       \tExpression");
      for (size_t i = 0; i < watchers.size(); i++) {
        if (watchers[i].last_value.has_value())
          println("{0}\t{1:08x}\t{1:<10}\t{2}", i,
                  watchers[i].last_value.value(), watchers[i].display);
        else
          println("{0}\t        \tError     \t{1}", i, watchers[i].display);
      }
    }
  } else if (match<R"(\s*i\s*)">(arg)) {
    if (config.itracer > 0)
      instRingBuffer->display();
    else
      println("Instruction ringbuffer is not enabled.");

  } else {
    return CmdResult::INVALID_ARG;
  }
  return CmdResult::OKAY;
}
CmdResult cmd_p(std::string_view arg) {
  if (auto [whole, expr_str] = match<RE_ONE_EXPR>(arg); whole) {
    Result<Expr::Expression> result =
        Expr::Expression::create_expression(expr_str);
    if (!result)
      println("{}", result.error());
    else
      println("{0}\t{0:#010x}", result->last_value.value());
  } else {
    return CmdResult::INVALID_ARG;
  }
  return CmdResult::OKAY;
}

CmdResult cmd_help(std::string_view arg) {
  if (match<RE_NO_ARG>(arg)) {
    for (int i = 0; i < NR_CMD; i++) {
      fmt::println("{}\t{}", cmd_list[i].command, cmd_list[i].help);
    }
  } else {
    auto [whole, cmd] = match<R"(\s*([a-z]+)\s*)">(arg);
    for (int i = 0; i < NR_CMD; i++) {
      if (cmd.to_view() == cmd_list[i].command) {
        {
          fmt::println("{}\t{}", cmd_list[i].command, cmd_list[i].help);
          return CmdResult::OKAY;
        }
      }
    }
    println("No such command. All command list:");
    for (int i = 0; i < NR_CMD; i++) {
      fmt::println("{}\t{}", cmd_list[i].command, cmd_list[i].help);
    }
  }
  return CmdResult::OKAY;
}

CmdResult cmd_w(std::string_view arg) {
  if (auto [whole, expr_str] = match<RE_ONE_EXPR>(arg); whole) {
    auto result = Expr::Expression::create_expression(expr_str);
    if (!result) {
      println("{}", result.error());
      println("Didnot create watcher due to expression error");
    } else {
      println("Created a watcher : {}", result->display);
      println("Current value : {0}\t{0:#010x}", result->last_value.value());
      watchers.push_back(std::move(result.value()));
    }
  } else {
    return CmdResult::INVALID_ARG;
  }
  return CmdResult::OKAY;
}
CmdResult cmd_d(std::string_view arg) {
  if (auto [whole, num_str] = match<RE_ONE_NUMBER>(arg); whole) {
    auto value = to_number<unsigned long long>(num_str);
    if (value.has_value()) {
      unsigned long long id = value.value();
      if (id < watchers.size()) {
        watchers.erase(watchers.cbegin() + id);
      } else {
        println("No such watcher with id {}", id);
      }
    } else {
      return CmdResult::INVALID_ARG;
    }
    return CmdResult::OKAY;
  } else {
    return CmdResult::INVALID_ARG;
  }
}