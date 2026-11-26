#include "core/cpu.h"
#include "core/device.h"
#include "core/ebreak.h"
#include "core/npc.h"
#include "sdb/sdb.h"
#include "utils/difftest.h"
#include "utils/log.h"

#include <cstdio>
#include <string>
#include <verilated.h>
#ifdef SOC_MODE
#include "VysyxSoCFull.h"
#else
#include "Vtop.h"
#endif

#ifdef ENABLE_FST
#include <verilated_fst_c.h>
#endif

#ifdef ENABLE_TRACE
#include "trace/ftrace.h"
#include "trace/itrace.h"
#include "trace/mtrace.h"
#endif

#ifdef ENABLE_NVBOARD
#include <nvboard.h>
void nvboard_bind_all_pins(VysyxSoCFull* top);
static bool g_nvboard_enabled = false;
#endif

#ifdef SOC_MODE
using SimTop = VysyxSoCFull;
#else
using SimTop = Vtop;
#endif

SimTop* top = nullptr;
static VerilatedContext* contextp = nullptr;
static bool print_itrace = false;

#ifdef ENABLE_FST
static VerilatedFstC* tfp = nullptr;
#endif

uint64_t npc_get_time() {
    return contextp ? contextp->time() : 0;
}

static void eval_half_cycle(int clock_value) {
#ifdef SOC_MODE
    top->clock = clock_value;
#else
    top->clk = clock_value;
#endif
    top->eval();
#ifdef ENABLE_FST
    if (tfp) tfp->dump(contextp->time());
#endif
    contextp->timeInc(1);
}

bool init_cpu(int argc, char** argv) {
    contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    top = new SimTop{contextp};

#ifdef ENABLE_FST
    Verilated::traceEverOn(true);
    tfp = new VerilatedFstC;
    top->trace(tfp, 99);

    std::string fst_path = "wave/dump.fst";
#ifdef ENABLE_LOG
    const char *run_dir = log_run_dir();
    if (run_dir != NULL && run_dir[0] != '\0') {
        fst_path = std::string(run_dir) + "/dump.fst";
    }
#endif
    tfp->open(fst_path.c_str());
    Log("FST: ON  -> %s", fst_path.c_str());
#else
    Log("FST: OFF");
#endif

#ifdef ENABLE_TRACE
    Log("Trace: ON");
#else
    Log("Trace: OFF");
#endif
#ifdef SOC_MODE
    Log("Mode: ysyxSoC, multi-cycle core");
#else
    Log("Mode: AXI4 PMEM, multi-cycle core");
#endif
#ifdef ENABLE_NVBOARD
    nvboard_bind_all_pins(top);
    nvboard_init();
    g_nvboard_enabled = true;
    Log("NVBoard: ON");
#else
    Log("NVBoard: OFF");
#endif
    return true;
}

void reset_cpu() {
    Log("Resetting multi-cycle NPC...");
#ifdef SOC_MODE
    top->reset = 1;
#else
    top->rst = 1;
#endif
    for (int i = 0; i < 10; i++) {
        eval_half_cycle(0);
        eval_half_cycle(1);
    }
#ifdef ENABLE_NVBOARD
    if (g_nvboard_enabled) nvboard_update();
#endif
#ifdef SOC_MODE
    top->reset = 0;
#else
    top->rst = 0;
#endif
    Log("Reset complete");
}

void exec_once() {
    const uint32_t current_pc = npc_get_pc();
    const uint64_t current_commit = npc_get_commit_count();

    while (current_commit == npc_get_commit_count()) {
        eval_half_cycle(0);
        eval_half_cycle(1);
        npc_inc_cycle();
        device_update();
#ifdef ENABLE_NVBOARD
        if (g_nvboard_enabled) nvboard_update();
#endif
        if (npc_get_state()->state == NPC_END) break;
    }

#ifdef ENABLE_TRACE
    itrace_log(current_pc, npc_get_inst(), print_itrace);
    ftrace_flush(print_itrace);
    mtrace_flush(print_itrace);
#endif

    const uint32_t inst = npc_get_inst();
    const uint32_t opcode = inst & 0x7f;
    const uint32_t funct3 = (inst >> 12) & 0x7;
    const uint32_t csr_addr = inst >> 20;
    
    const bool is_csr =
        opcode == 0x73 &&
        ((funct3 >= 1 && funct3 <= 3) ||
         (funct3 >= 5 && funct3 <= 7));
    
    if (is_csr && (csr_addr == 0xb00 || csr_addr == 0xb80)) {
        difftest_skip_ref();
    }

    difftest_step(current_pc, npc_get_pc());
}

void set_itrace_print(bool enable) {
    print_itrace = enable;
}

void cpu_exec(uint64_t n) {
    NPCState* state = npc_get_state();
    if (state->state == NPC_END || state->state == NPC_ABORT) {
        printf("Program has already exited. Use 'q' to quit.\n");
        return;
    }

    state->state = NPC_RUNNING;
    set_itrace_print(n <= 10);
    uint64_t instructions = 0;

    while (instructions < n || n == static_cast<uint64_t>(-1)) {
        if (check_breakpoints()) {
            state->state = NPC_STOP;
            printf("Program stopped at breakpoint 0x%08x.\n", npc_get_pc());
            break;
        }

        exec_once();
        instructions++;

        if (npc_should_exit() || state->state != NPC_RUNNING) break;

        if (check_watchpoints()) {
            state->state = NPC_STOP;
            printf("Program stopped due to watchpoint.\n");
            Log("Program stopped due to watchpoint");
            npc_dump_snapshot();
            break;
        }
    }

    if (state->state == NPC_RUNNING) state->state = NPC_STOP;
    Log("Executed %lu instructions in %lu cycles, IPC=%.4f",
        instructions, npc_get_cycle(),
        npc_get_cycle() ? static_cast<double>(instructions) / npc_get_cycle() : 0.0);
}

void cleanup_cpu() {
    top->final();
#ifdef ENABLE_FST   
    if (tfp) {
        tfp->close();
        delete tfp;
        tfp = nullptr;
    }
#endif
#ifdef ENABLE_NVBOARD
    if (g_nvboard_enabled) {
        nvboard_quit();
        g_nvboard_enabled = false;
    }
#endif
    delete top;
    delete contextp;
    top = nullptr;
    contextp = nullptr;
    device_cleanup();
    log_flush();
}
