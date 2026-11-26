#include "mtrace.h"
#include "../utils/log.h"
#include "../core/npc.h"
#include <stdio.h>
#include <deque>
#include <string>
#include <vector>

static bool trace_enabled = false;
static std::vector<std::string> mtrace_buffer;
static std::deque<std::string> mtrace_recent;
static const size_t RECENT_MAX = 32;

void init_mtrace() {
  trace_enabled = true;
  Log("mtrace initialized");
}

void set_mtrace_enabled(bool enable) {
  trace_enabled = enable;
}

bool mtrace_enabled() {
  return trace_enabled;
}

static void mtrace_add(const char *line) {
  mtrace_buffer.push_back(std::string(line));
  mtrace_recent.push_back(std::string(line));
  if (mtrace_recent.size() > RECENT_MAX) {
    mtrace_recent.pop_front();
  }
}

extern "C" void mtrace_event(int pc, int addr, int data, int len, int is_store) {
#ifndef ENABLE_TRACE
  (void)pc; (void)addr; (void)data; (void)len; (void)is_store;
  return;
#endif
  if (!trace_enabled) return;

  char prefix[160];
  log_trace_prefix_at(prefix, sizeof(prefix), "MTRACE", (uint32_t)pc,
                      npc_get_cycle(), npc_get_commit_count(), npc_get_time());

  char line[256];
  snprintf(line, sizeof(line), "%s%s addr=0x%08x len=%d data=0x%08x",
           prefix, is_store ? "STORE" : "LOAD ", (uint32_t)addr, len, (uint32_t)data);
  mtrace_add(line);
}

void mtrace_flush(bool print_to_console) {
  if (mtrace_buffer.empty()) return;

  std::string output;
  for (const auto &line : mtrace_buffer) {
    output += line + "\n";
  }
  log_write("%s", output.c_str());

  if (print_to_console) {
    printf("%s", output.c_str());
    fflush(stdout);
  }
  mtrace_buffer.clear();
}

void mtrace_dump_recent() {
  const char *header = "Recent data memory accesses (mtrace):";
  printf("\n%s\n", header);
  log_write("\n%s\n", header);

  if (mtrace_recent.empty()) {
    printf("  (empty)\n");
    log_write("  (empty)\n");
    return;
  }
  for (const auto &line : mtrace_recent) {
    printf("  %s\n", line.c_str());
    log_write("  %s\n", line.c_str());
  }
  printf("\n");
  log_write("\n");
}
