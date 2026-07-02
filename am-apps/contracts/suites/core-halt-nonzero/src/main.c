#include <contract_suite.h>

int main(const char *args) {
  (void)args;
  contract_suite_begin();
  contract_begin_point("halt-nonzero-bad");
  contract_puts("CORE_HALT_NONZERO_TOKEN\n");
  contract_pass_point("halt-nonzero-bad");
  contract_puts("CONTRACT " CONTRACT_SUITE " PASS\n");
  halt(1);
}
