#include "core/npc.h"
#include "trace/ftrace.h"

extern "C" void ftrace_call_handler(int pc_val, int target_val) {
#ifdef ENABLE_TRACE
    ftrace_call(static_cast<uint32_t>(pc_val), static_cast<uint32_t>(target_val));
#else
    (void)pc_val;
    (void)target_val;
#endif
}

// The copied single-cycle RTL uses the historical one-argument return hook.
extern "C" void ftrace_ret_handler(int pc_val) {
#ifdef ENABLE_TRACE
    ftrace_ret(static_cast<uint32_t>(pc_val), npc_get_reg(1));
#else
    (void)pc_val;
#endif
}
