#ifdef NPC

#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <time.h>
#include <csignal>
#include <cassert>
#include <VysyxSoCFull.h>
#include <autoconf.h>

#ifdef CONFIG_ENABLE_FST_TRACE
#include <verilated_fst_c.h>
#endif

#include <sdb.h>
#include <trace.h>
#include <difftest.h>
#include <utils.h>

static void check_stop();

static TOP_NAME top;

#ifdef CONFIG_ENABLE_FST_TRACE
VerilatedFstC *tfp = NULL;
#endif

struct timespec start, end;
bool check_wp();
void load_img(const char *path);
uint32_t read_fetch_pc();
extern uint32_t img_size;

uint64_t cycle = 0;
uint64_t dump_time = 0;

static bool running = false;

void eval() {
    top.eval();
#ifdef CONFIG_ENABLE_FST_TRACE
    if (tfp) tfp->dump(dump_time);
    dump_time++;
#endif
}

static void single_cycle() {
    top.clock = !top.clock;
    eval();
    top.clock = !top.clock;
    eval();
    cycle++;
    check_stop();
}

void cpu_exec(int n) {
    running = true;
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            do {
                single_cycle();
                if (!running) break;
            } while (!check_commit());
            if (check_wp()) {
                running = false;
            }
            printNextInst();
            if (!running) break;
        }
    } else {
        while (1) {
            single_cycle();
            if (check_commit() && check_wp()) {
                running = false;
                printNextInst();
            }
            if (!running) break;
        }
    }
}

void init_mem(const char *img_path) {
    if (img_path != NULL) {
        load_img(img_path);
    }
}

void init_cpu() {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    top.reset = 1;
    top.clock = 0;
    eval();
    for (int i = 0; i < 15; i++) {
        top.clock = 1;
        eval();
        top.clock = 0;
        eval();
    }
    top.reset = 0;
}

static volatile sig_atomic_t g_stop = 0;
static void on_signal(int) { g_stop = 1; }
static void check_stop() {
    if (g_stop) {
        close_tfp();
        fprintf(stderr, "\n[Ctrl-C] 退出\n");
        exit(0);
    }
}
void init_engine(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    signal(SIGINT, on_signal);
    signal(SIGTERM, on_signal);
    const char *img_file = NULL;
    const char *diff_so_file = NULL;
    const char *elf_file = NULL;
    const char *trace_dir = NULL;
    bool batch_mode = false;

    const struct option table[] = {
        {"batch", no_argument, NULL, 'b'},
        {"image", required_argument, NULL, 'i'},
        {"diff",  required_argument, NULL, 'd'},
        {"trace", required_argument, NULL, 't'},
        {"elf",   required_argument, NULL, 'e'},
        {"help",  no_argument,       NULL, 'h'},
        {0, 0, NULL, 0},
    };
    int o;
    while ((o = getopt_long(argc, argv, "-bhi:d:t:e:", table, NULL)) != -1) {
        switch (o) {
            case 'b': batch_mode = true; sdb_set_batch_mode(); break;
            case 'i': img_file = optarg; break;
            case 'd': diff_so_file = optarg; break;
            case 't': trace_dir = optarg; break;
            case 'e': elf_file = optarg; break;
            case 1: img_file = optarg; break;
            case 'h':
                printf("Usage: %s [OPTION...] IMAGE\n\n", argv[0]);
                printf("\t-b,--batch           batch mode (disable SDB)\n");
                printf("\t-i,--image=IMAGE     program image\n");
                printf("\t-d,--diff=REF_SO     DiffTest reference SO\n");
                printf("\t-t,--trace=TRACE_DIR trace output directory\n");
                printf("\t-e,--elf=ELF         ELF file for ftrace\n");
                printf("\n");
                exit(0);
            default:
                exit(1);
        }
    }

#ifdef CONFIG_ENABLE_SDB
    if (!batch_mode) {
        init_sdb();
    }
#endif
    if (img_file == NULL) {
        fprintf(stderr, "错误: 未指定镜像文件，请用 -i <image.bin> 指定\n");
        exit(1);
    }

    if (img_file) {
        init_mem(img_file);
    } else {
        init_mem(NULL);
    }
    init_cpu();
#ifdef CONFIG_ENABLE_FST_TRACE
    Verilated::traceEverOn(true);
    tfp = new VerilatedFstC;
    top.trace(tfp, 99);
    tfp->open("waveform.fst");
#endif
    init_trace(trace_dir, elf_file ? elf_file : img_file);
#ifdef CONFIG_ENABLE_DIFFTEST
    {
        const char *ref_so = diff_so_file;
        if (ref_so == NULL) {
            ref_so = getenv("NEMU_REF_SO");
        }
        if (ref_so == NULL) {
            ref_so = "../nemu/build/riscv32-nemu-interpreter-so";
        }
        init_difftest(ref_so, img_size);
    }
#endif
    running = false;
}

void sdb_mainloop();

void start_engine() {
    sdb_mainloop();
}

void close_tfp() {
#ifdef CONFIG_ENABLE_FST_TRACE
    if (tfp) {
        tfp->close();
        tfp = NULL;
    }
#endif
}

#endif
