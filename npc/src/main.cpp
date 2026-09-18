#include <npc.h>
#include <common.h>
#include <device/map.h>

int main(int argc, char *argv[]) {
  sim_init(argc, argv);

  sdb_mainloop();

  sim_exit();

  return is_exit_status_bad(); 
}
