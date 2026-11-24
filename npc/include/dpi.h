#include "svdpi.h"

#include <cstdio>
#include <cstring>

// scopes don't change after the model is created,
// so cache the lookup result
#define SCOPE_CACHE_SIZE 8

static void setup_scope(const char *name) {
  static struct {
    const char *name;
    svScope     scope;
  } scope_cache[SCOPE_CACHE_SIZE];
  static int scope_cache_nr = 0;

  for (int i = 0; i < scope_cache_nr; i++) {
    if (strcmp(scope_cache[i].name, name) == 0) {
      svSetScope(scope_cache[i].scope);
      return;
    }
  }

  const char *scope_prefix;
  char scope_name[128];

#ifdef CONFIG_NPC
  scope_prefix = "TOP.ysyxSoCFull.";
#else
  scope_prefix = "TOP.ysyxSoCFull.asic.cpu.";
#endif

  snprintf(scope_name, sizeof(scope_name), "%s%s", scope_prefix, name);

  svScope scope = svGetScopeFromName(scope_name);
  if (scope == NULL) {
    printf("Error: Failed to find scope '%s'\n", scope_name);
    return;
  }
  if (scope_cache_nr < SCOPE_CACHE_SIZE) {
    // callers pass string literals, so keeping the pointer is safe
    scope_cache[scope_cache_nr].name  = name;
    scope_cache[scope_cache_nr].scope = scope;
    scope_cache_nr++;
  }
  svSetScope(scope);
}

extern "C" int get_gpr_npc(int index);
extern "C" int get_pc_npc();
extern "C" int get_pc();
extern "C" int get_npc();
extern "C" int get_inst();
extern "C" bool get_cycle_done();
extern "C" bool get_lsu_wbu_valid_o();
