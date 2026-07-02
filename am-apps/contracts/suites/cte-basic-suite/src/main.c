#include <contract_suite.h>

static volatile int basic_phase = 0;
static volatile int event_count = 0;
static volatile int trap_budget = 0;
static const char *active_point = "event-dispatch";

static Context *basic_handler(Event ev, Context *ctx) {
  CONTRACT_CHECK_POINT(active_point, trap_budget > 0, "trap-repeat");
  trap_budget--;
  CONTRACT_CHECK_POINT("event-dispatch", ctx != NULL, "ctx-nonnull");
  CONTRACT_CHECK_POINT("event-dispatch", ev.event == EVENT_YIELD || ev.event == EVENT_SYSCALL, "event-kind");
  if (basic_phase == 1) CONTRACT_CHECK_POINT("event-dispatch", ev.event == EVENT_YIELD, "yield-event");
  if (basic_phase == 2) CONTRACT_CHECK_POINT("event-dispatch", ev.event == EVENT_SYSCALL, "syscall-event");
  event_count++;
  return ctx;
}

static inline void do_syscall_ecall(void) {
#ifdef __riscv_e
  asm volatile("li a5, 1; ecall" ::: "a5", "memory");
#else
  asm volatile("li a7, 1; ecall" ::: "a7", "memory");
#endif
}

static void point_init_entry(void) { CONTRACT_CHECK_POINT("init-entry", cte_init(basic_handler), "cte-init"); }
static void point_event_dispatch(void) { active_point = "event-dispatch"; basic_phase = 1; int before = event_count; trap_budget = 1; yield(); CONTRACT_CHECK_POINT("event-dispatch", event_count == before + 1, "yield-count"); basic_phase = 2; before = event_count; trap_budget = 1; do_syscall_ecall(); CONTRACT_CHECK_POINT("event-dispatch", event_count == before + 1, "syscall-count"); }
static void point_mepc_return(void) { active_point = "mepc-return"; basic_phase = 1; int before = event_count; trap_budget = 1; yield(); CONTRACT_CHECK_POINT("mepc-return", event_count == before + 1, "yield-return"); basic_phase = 2; before = event_count; trap_budget = 1; do_syscall_ecall(); CONTRACT_CHECK_POINT("mepc-return", event_count == before + 1, "syscall-return"); }
static void point_interrupt_control(void) { active_point = "interrupt-control"; iset(false); CONTRACT_CHECK_POINT("interrupt-control", !ienabled(), "disabled"); basic_phase = 1; trap_budget = 1; yield(); iset(true); CONTRACT_CHECK_POINT("interrupt-control", !ienabled(), "enabled-current-semantics"); trap_budget = 1; yield(); iset(false); CONTRACT_CHECK_POINT("interrupt-control", !ienabled(), "disabled-again"); }

int main(const char *args) {
  (void)args; contract_suite_begin();
  CONTRACT_RUN("init-entry", point_init_entry);
  CONTRACT_RUN("event-dispatch", point_event_dispatch);
  CONTRACT_RUN("mepc-return", point_mepc_return);
  CONTRACT_RUN("interrupt-control", point_interrupt_control);
  contract_suite_pass();
}
