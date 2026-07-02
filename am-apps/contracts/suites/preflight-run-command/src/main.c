#include <contract_suite.h>

static void point_run_command(void) {
  contract_puts("PREFLIGHT_RUN_COMMAND_TOKEN\n");
}

int main(const char *args) {
  (void)args;
  contract_suite_begin();
  CONTRACT_RUN("run-command", point_run_command);
  contract_suite_pass();
}
