#pragma once
#include <atomic>
#include <string_view>
enum class CmdResult { OKAY, INVALID_ARG, ERROR };

inline std::atomic_bool quit;

CmdResult cmd_c(std::string_view arg);
CmdResult cmd_s(std::string_view arg);
CmdResult cmd_x(std::string_view arg);
CmdResult cmd_q(std::string_view arg);
CmdResult cmd_l(std::string_view arg);
CmdResult cmd_p(std::string_view arg);
CmdResult cmd_w(std::string_view arg);
CmdResult cmd_d(std::string_view arg);
CmdResult cmd_help(std::string_view arg);

using Cmd_Func = CmdResult (*)(std::string_view);

constexpr struct {
  Cmd_Func call;
  std::string_view command;
  std::string_view help;
} cmd_list[] = {
    {cmd_c, "c", "Start running. Usage : c"},
    {cmd_s, "s", "Step specific instructions. Usage : s [# of steps]"},
    {cmd_x, "x", "Scan memory. Usage : x (# of words) (base address)"},
    {cmd_q, "q", "Quit"},
    {cmd_l, "l", "List infomation. Usage : li (r|w)"},
    {cmd_p, "p", "Print expression. Usage : p (expression)"},
    {cmd_w, "w", "Add a watcher. Usage : w (expression)"},
    {cmd_d, "d", "Remove a watcher. Usage : d (watcher id)"},
    {cmd_help, "help", "Show help. Usage : help [command]"}};

constexpr size_t NR_CMD = sizeof(cmd_list) / sizeof(cmd_list[0]);
