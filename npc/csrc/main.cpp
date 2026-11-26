#include <cstdio>
#include <cstring>
#include "core/npc.h"
#include "core/cpu.h"
#include "core/memory.h"
#include "core/device.h"
#include "core/perf.h"
#include "core/reg.h"
#include "sdb/sdb.h"
#include "utils/log.h"
#include "utils/difftest.h"

#ifdef ENABLE_TRACE
#include "trace/itrace.h"
#include "trace/mtrace.h"
#include "trace/ftrace.h"
#endif

#ifdef F_CPU
#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)
#define F_STR STRINGIFY(F_CPU)
#else
#define F_STR "0"
#endif

static void print_usage(const char* prog_name) {
    printf("Usage: %s <program.bin> [-b] [-l trace_log] [-e elf_file] [-d ref_so]\n", prog_name);
    printf("  -b: batch mode (non-interactive)\n");
    printf("  -l trace_log: optional trace log path override (default: log/<timestamp>/trace.log)\n");
    printf("  -e elf_file: specify ELF file for ftrace\n");
    printf("  -d ref_so: specify REF shared object for DiffTest\n");
    printf("Log files (LOG=1): log/<timestamp>/{npc.log,trace.log,perf.log}\n");
    printf("FST waveform: log/<timestamp>/dump.fst when LOG=1, otherwise wave/dump.fst\n");
    printf("Example: %s build/dummy-riscv32e-npc.bin\n", prog_name);
}

static bool parse_args(int argc, char** argv, 
                      const char** program_file,
                      bool* batch_mode,
                      const char** log_file,
                      const char** elf_file,
                      const char** ref_so_file) {
    if (argc < 2) {
        return false;
    }
    
    *program_file = argv[1];
    *batch_mode = false;
    *log_file = NULL;
    *elf_file = NULL;
    *ref_so_file = NULL;
    
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-b") == 0) {
            *batch_mode = true;
        } else if (strcmp(argv[i], "-l") == 0 && i + 1 < argc) {
            *log_file = argv[i + 1];
            i++;
        } else if (strcmp(argv[i], "-e") == 0 && i + 1 < argc) {
            *elf_file = argv[i + 1];
            i++;
        } else if (strcmp(argv[i], "-d") == 0 && i + 1 < argc) {
            *ref_so_file = argv[i + 1];
            i++;
        }
    }
    
    return true;
}

static bool init_subsystems(const char* log_file, const char* elf_file) {
#ifdef ENABLE_LOG
    if (!log_run_init(log_file)) {
        return false;
    }
#else
    init_log(NULL);
#endif

#ifdef ENABLE_TRACE
    init_itrace();
    init_mtrace();
    init_ftrace(elf_file);
#endif

    init_device();
    init_sdb();
    return true;
}

// 初始化DiffTest
static void init_difftest_if_needed(const char* ref_so_file, const char* program_file) {
    if (ref_so_file != NULL) {
        // 获取程序大小
        FILE* fp = fopen(program_file, "rb");
        if (fp) {
            fseek(fp, 0, SEEK_END);
            long img_size = ftell(fp);
            fclose(fp);
            init_difftest(ref_so_file, img_size);
        }
    } else {
        Log("DiffTest is disabled (no REF specified)");
        printf("DiffTest: OFF\n\n");
    }
}

static void print_welcome() {
    const char *title = log_color_enabled() ? ANSI_FG_CYAN : "";
    const char *dim = log_color_enabled() ? ANSI_DIM : "";
    const char *reset = log_color_enabled() ? ANSI_NONE : "";
    printf("%sNPC - RISC-V processor simulator with Simple Debugger%s\n", title, reset);
    printf("%s======================================================%s\n\n", dim, reset);
}

static void print_exit_info() {
    if (npc_should_exit()) {
        uint32_t exit_code = npc_get_exit_code();
        Log("Exit reason: EBREAK instruction (program completed)");
        Log("Exit code: %d", exit_code);
        printf("Exit reason: EBREAK instruction (program completed)\n");
        printf("Exit code: %d\n", exit_code);

    }
}

int main(int argc, char** argv) {
    const char* program_file;
    bool batch_mode;
    const char* log_file;
    const char* elf_file;
    const char* ref_so_file;
    
    // 解析命令行参数
    if (!parse_args(argc, argv, &program_file, &batch_mode, &log_file, &elf_file, &ref_so_file)) {
        print_usage(argv[0]);
        return 1;
    }
    
    // 初始化子系统
    if (!init_subsystems(log_file, elf_file)) {
        fprintf(stderr, "Failed to initialize logging submodule\n");
        return 1;
    }

    Log("Config: mode=%s trace=%s log=%s fst=%s perf=%s nvboard=%s F=%s",
#ifdef SOC_MODE
        "soc",
#else
        "standalone",
#endif
#ifdef ENABLE_TRACE
        "on",
#else
        "off",
#endif
#ifdef ENABLE_LOG
        "on",
#else
        "off",
#endif
#ifdef ENABLE_FST
        "on",
#else
        "off",
#endif
#ifdef ENABLE_PERF
        "on",
#else
        "off",
#endif
#ifdef ENABLE_NVBOARD
        "on",
#else
        "off",
#endif
        F_STR);
    Log("Images: program=%s elf=%s ref=%s",
        program_file, elf_file ? elf_file : "(none)",
        ref_so_file ? ref_so_file : "(none)");

    Log("NPC - RISC-V processor simulator with Simple Debugger");
    Log("Build time: %s, %s", __TIME__, __DATE__);
    
    // 打印欢迎信息
    print_welcome();
    
#ifdef SOC_MODE
    if (!flash_load(program_file)) return 1;
#else
    if (!load_program(program_file)) return 1;   
#endif
    
    printf("\n");
    
    // 初始化CPU
    if (!init_cpu(argc, argv)) {
        return 1;
    }
    
    // 复位CPU
    reset_cpu();
    
    // 初始化DiffTest
    init_difftest_if_needed(ref_so_file, program_file);
    
    // 设置批处理模式
    if (batch_mode) {
        sdb_set_batch_mode();
        Log("Running in batch mode");
        printf("Running in batch mode...\n\n");
    } else {
        printf("Entering interactive mode. Type 'help' for commands.\n\n");
    }
    
    Log("Starting simulation from PC=0x%08x", npc_get_pc());
    
    // 进入sdb主循环
    sdb_mainloop();
    
    // 打印退出信息
    Log("Simulation finished");
    printf("\nSimulation finished.\n");
    print_exit_info();

#ifdef ENABLE_PERF
    // 仿真结束时打印性能报告 (仅 PERF=1 构建)
    perf_report();
#endif

    // 清理资源
    cleanup_cpu();
#ifdef ENABLE_LOG
    log_close_run();
#else
    log_flush();
#endif
    
    return npc_get_exit_code();
}
