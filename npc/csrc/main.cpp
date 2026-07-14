#include "VysyxSoCFull.h"
#include "verilated.h"
#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>
#include <VysyxSoCFull__Dpi.h>
#include "include/common.h"
#include "include/trace.h"
#include "config.h"

std::string build_dir;
std::string img_path;

static bool starts_with(const std::string &s, const std::string &prefix)
{
    return s.size() >= prefix.size() && s.compare(0, prefix.size(), prefix) == 0;
}
static std::string after_prefix(const std::string &s, const std::string &prefix)
{
    return starts_with(s, prefix) ? s.substr(prefix.size()) : std::string();
}
void parse_args(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i] ? argv[i] : "";

        if (starts_with(arg, "IMG="))
        {
            img_path = after_prefix(arg, "IMG=");
        }
        else if (starts_with(arg, "BUILD="))
        {
            build_dir = after_prefix(arg, "BUILD=");
        }
    }
}
void sim_init()
{

#if USE_YSYXSOC

    // init_rom(img_path);
    init_flash(img_path);
#else
    init_mem(img_path);
#endif

#ifdef ENABLE_FTRACE
    if (!init_ftrace(img_path.c_str()))
    {
        ftrace_enabled = false;
        std::cerr << "Failed to initialize ftrace with binary: " << img_path << std::endl;
    }
#endif

#ifdef ENABLE_ITRACE
    itrace_log_init(build_dir);
#endif
#ifdef ENABLE_FTRACE
    ftrace_log_init(build_dir);
#endif

    init_devices();
}

int main(int argc, char **argv)
{
    // 打印参数用于调试
    // std::cout << "Arguments: ";
    // for (int i = 0; i < argc; i++)
    // {
    //     std::cout << argv[i] << " ";
    // }
    // std::cout << std::endl;
    Verilated::commandArgs(argc, argv);

    parse_args(argc, argv);
#ifdef RUN_CACHESIM
#ifdef DSE_MODE
    run_cache_dse();
#else
    run_cache_single();
#endif
    return 0;
#endif
#ifdef RUN_BRANCHSIM
    run_btb_dse();
    return 0;
#endif
    sim_init();
    sdb_mainloop(argc, argv);

    return 0;
}
