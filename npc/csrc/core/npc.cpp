#include "core/npc.h"

static NPCState npc_state = { .state = NPC_STOP };
static bool should_exit = false;
static uint32_t exit_code = 0;
static uint64_t cycle_count = 0;
static uint64_t commit_count = 0;
static uint64_t commit_cycle = 0;
static uint64_t commit_time = 0;
static uint32_t reg_cache[32] = {};
static uint32_t csr_cache[6] = {};
static uint32_t pc_cache = 0;
static uint32_t inst_cache = 0;

NPCState* npc_get_state() {
    return &npc_state;
}

uint64_t npc_get_cycle() {
    return cycle_count;
}

uint64_t npc_get_commit_count() {
    return commit_count;
}

uint64_t npc_get_commit_cycle() {
    return commit_cycle;
}

uint64_t npc_get_commit_time() {
    return commit_time;
}

void npc_inc_cycle() {
    cycle_count++;
}

uint32_t npc_get_pc() {
    return pc_cache;
}

uint32_t npc_get_inst() {
    return inst_cache;
}

uint32_t npc_get_reg(int idx) {
    if (idx <= 0 || idx >= 32) return 0;
    return reg_cache[idx];
}

uint32_t npc_get_csr(int idx) {
    if (idx < 0 || idx >= 6) return 0;
    return csr_cache[idx];
}

void npc_set_exit(bool exit, uint32_t code) {
    should_exit = exit;
    exit_code = code;
}

bool npc_should_exit() {
    return should_exit;
}

uint32_t npc_get_exit_code() {
    return exit_code;
}

extern "C" void update_reg_value(int idx, int value) {
    if (idx > 0 && idx < 32) {
        reg_cache[idx] = static_cast<uint32_t>(value);
    }
}

extern "C" void update_pc_value(int pc_val) {
    pc_cache = static_cast<uint32_t>(pc_val);
}

extern "C" void update_inst_value(int pc_val, int inst_val) {
    (void)pc_val;
    inst_cache = static_cast<uint32_t>(inst_val);
    commit_cycle = cycle_count;
    commit_time = npc_get_time();
    commit_count++;
}

extern "C" void commit_instruction(int pc_val, int inst_val, int next_pc_val) {
    (void)pc_val;
    inst_cache = static_cast<uint32_t>(inst_val);
    pc_cache = static_cast<uint32_t>(next_pc_val);
    commit_cycle = cycle_count;
    commit_time = npc_get_time();
    commit_count++;
}

extern "C" void update_csr_values(int mstatus, int mtvec, int mepc, int mcause,
                                  int mcycle_lo, int mcycle_hi) {
    csr_cache[0] = static_cast<uint32_t>(mstatus);
    csr_cache[1] = static_cast<uint32_t>(mtvec);
    csr_cache[2] = static_cast<uint32_t>(mepc);
    csr_cache[3] = static_cast<uint32_t>(mcause);
    csr_cache[4] = static_cast<uint32_t>(mcycle_lo);
    csr_cache[5] = static_cast<uint32_t>(mcycle_hi);
}
