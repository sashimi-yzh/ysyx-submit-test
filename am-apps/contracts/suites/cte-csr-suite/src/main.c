#include <contract_suite.h>

static volatile int seen;
static Context *handler(Event ev, Context *ctx) {
  CONTRACT_CHECK_POINT("csr-preservation", ev.event == EVENT_YIELD, "event-yield");
  CONTRACT_CHECK_POINT("csr-preservation", ctx != NULL, "ctx");
  CONTRACT_CHECK_POINT("csr-preservation", (ctx->mepc & 0x3u) == 0, "mepc-align");
  CONTRACT_CHECK_POINT("csr-preservation", ctx->mcause == 11, "mcause-ecall");
  seen++;
  return ctx;
}

static void point_csr_preservation(void) {
  CONTRACT_CHECK_POINT("csr-preservation", cte_init(handler), "cte-init");
  yield();
  CONTRACT_CHECK_POINT("csr-preservation", seen == 1, "yield-count");
}

int main(const char *args) { (void)args; contract_suite_begin(); CONTRACT_RUN("csr-preservation", point_csr_preservation); contract_suite_pass(); }
