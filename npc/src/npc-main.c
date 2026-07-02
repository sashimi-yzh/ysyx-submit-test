#include <common.h>

#include <monitor/monitor.h>
void engine_start();
int is_exit_status_bad();
void npc_cleanup();

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
  init_monitor(argc, argv);

  /* Start engine. */
  engine_start();

  int ret = is_exit_status_bad();
  npc_cleanup();
  return ret;
}
