#include <contract_suite.h>

static uint8_t child_stack[4096] __attribute__((aligned(16)));
static Context *main_ctx;
static Context *alt_ctx;
static Context *child_ctx;
static volatile int phase;
static volatile int child_seen;

static void child_entry(void *arg) {
  CONTRACT_CHECK_POINT("kcontext", (uintptr_t)arg == 0x13572468u, "child-arg");
  child_seen = 1;
  phase = 4;
  yield();
  contract_suite_fail("kcontext", "child-resume");
}

static Context *handler(Event ev, Context *ctx) {
  CONTRACT_CHECK_POINT(phase < 3 ? "handler-return-context" : "kcontext", ev.event == EVENT_YIELD, "event-yield");
  if (phase == 0) { main_ctx = ctx; phase = 1; return ctx; }
  if (phase == 2) { main_ctx = ctx; phase = 3; return alt_ctx; }
  if (phase == 4) { phase = 5; return main_ctx; }
  contract_suite_fail(phase < 3 ? "handler-return-context" : "kcontext", "unexpected-yield");
}

static void point_handler_return_context(void) {
  CONTRACT_CHECK_POINT("handler-return-context", cte_init(handler), "cte-init");
  phase = 0;
  yield();
  CONTRACT_CHECK_POINT("handler-return-context", phase == 1 && main_ctx != NULL, "return-same-context");
}

static void point_kcontext(void) {
  Area stack = {.start = child_stack, .end = child_stack + sizeof(child_stack)};
  child_ctx = kcontext(stack, child_entry, (void *)0x13572468u);
  CONTRACT_CHECK_POINT("kcontext", child_ctx != NULL, "kcontext-create");
  alt_ctx = child_ctx;
  phase = 2;
  yield();
  CONTRACT_CHECK_POINT("kcontext", phase == 5, "main-return");
  CONTRACT_CHECK_POINT("kcontext", child_seen == 1, "child-seen");
}

int main(const char *args) { (void)args; contract_suite_begin(); CONTRACT_RUN("handler-return-context", point_handler_return_context); CONTRACT_RUN("kcontext", point_kcontext); contract_suite_pass(); }
