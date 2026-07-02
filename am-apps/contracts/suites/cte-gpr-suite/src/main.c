#include <contract_suite.h>

static volatile int seen;
static Context *handler(Event ev, Context *ctx) {
  CONTRACT_CHECK_POINT("gpr-preservation", ev.event == EVENT_YIELD, "event-yield");
  seen++;
  return ctx;
}

static void point_gpr_preservation(void) {
  CONTRACT_CHECK_POINT("gpr-preservation", cte_init(handler), "cte-init");
#ifdef __riscv_e
  register uintptr_t s0 asm("s0") = 0x10203040u;
  register uintptr_t s1 asm("s1") = 0x55667788u;
  asm volatile("" : "+r"(s0), "+r"(s1));
  yield();
  asm volatile("" : "+r"(s0), "+r"(s1));
  CONTRACT_CHECK_POINT("gpr-preservation", seen == 1, "yield-count");
  CONTRACT_CHECK_POINT("gpr-preservation", s0 == 0x10203040u && s1 == 0x55667788u, "s-registers");
#else
  register uintptr_t s2 asm("s2") = 0x10203040u;
  register uintptr_t s3 asm("s3") = 0x55667788u;
  register uintptr_t s4 asm("s4") = 0xa5a55a5au;
  asm volatile("" : "+r"(s2), "+r"(s3), "+r"(s4));
  yield();
  asm volatile("" : "+r"(s2), "+r"(s3), "+r"(s4));
  CONTRACT_CHECK_POINT("gpr-preservation", seen == 1, "yield-count");
  CONTRACT_CHECK_POINT("gpr-preservation", s2 == 0x10203040u && s3 == 0x55667788u && s4 == 0xa5a55a5au, "s-registers");
#endif
}

int main(const char *args) { (void)args; contract_suite_begin(); CONTRACT_RUN("gpr-preservation", point_gpr_preservation); contract_suite_pass(); }
