#include <am.h>
#include <klib-macros.h>

bool mpe_init(void (*entry)()) {
  entry();
  panic("MPE entry returns");
  return false;
}

int cpu_count() {
  return 1;
}

int cpu_current() {
  return 0;
}

int atomic_xchg(int *addr, int newval) {
  int old = *addr;
  *addr = newval;
  return old;
}
