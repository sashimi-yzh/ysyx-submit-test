#include "kasan_init.h"
#include "klib.h"
#undef kasan_init

#ifdef KASAN_ENABLED
#error "kasan should not be enable when build kasan, something maybe wrong"
#endif

void kasan_init() {
  void initialize_heap();
  void initialize_kasan();
  void call_global_ctors();
  // nemu will clear the shadow memory
	// npc will clear the shadow memory
#ifndef ARCH_IS_NEMU
  // _no_asan_kmemzero((void *)KASAN_SHADOW_MEMORY_START,
  // KASAN_SHADOW_MEMORY_SIZE);
#endif

  // Needed to invoke KASan globals instrumentation.
  initialize_heap();
  initialize_kasan();
  call_global_ctors();
}
