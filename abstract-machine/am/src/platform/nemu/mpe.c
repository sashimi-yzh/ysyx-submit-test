#include <am.h>
#include <stdatomic.h>
#include <klib-macros.h>

bool mpe_init(void (*entry)()) {
  entry();
  panic("MPE entry returns");
}

int cpu_count() {
  return 1;
}

int cpu_current() {
  return 0;
}

int atomic_xchg(int *addr, int newval) {
#ifdef __clang__
	// make clang happy
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Watomic-alignment"
#endif
  return atomic_exchange((_Atomic(int)*)addr, newval);
#ifdef __clang__
#pragma clang diagnostic pop
#endif
}
