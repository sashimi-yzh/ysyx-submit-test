#include <npc/platform.h>
#include <npc/runtime.h>
// The basic log write function for all logs
#if defined(CONFIG_MTRACE) || defined(CONFIG_DTRACE)
static void write_access_trace(TraceKind kind, char access, paddr_t address, int length, word_t value, const char *region) {
  if (region == NULL) return;
  trace_write(kind, FMT_WORD " %c %d " FMT_WORD " [%s]\n", address, access, length, value, region);
}
#endif
// trace the mem for npc (call by trace_bus_read && trace_bus_write)
static void trace_memory(char access, paddr_t address, int length, word_t value) {
#ifdef CONFIG_MTRACE
  if (MTRACE_COND) {
    write_access_trace(TRACE_MTRACE, access, address, length, value, mem_region(address));
  }
#else
  (void)access;
  (void)address;
  (void)length;
  (void)value;
#endif
}
// trace the mem for device (call by trace_bus_read && trace_bus_write)
static void trace_io(char access, paddr_t address, int length, word_t value) {
#ifdef CONFIG_DTRACE
  write_access_trace(TRACE_DTRACE, access, address, length, value, device_region(address));
#else
  (void)access;
  (void)address;
  (void)length;
  (void)value;
#endif
}
// top read bus trace (have directions)
void trace_bus_read(paddr_t address, int length, word_t value) {
  trace_memory('R', address, length, value);
  trace_io('R', address, length, value);
}
// top write bus trace (have directions)
void trace_bus_write(paddr_t address, int length, word_t value) {
  trace_memory('W', address, length, value);
  trace_io('W', address, length, value);
}
