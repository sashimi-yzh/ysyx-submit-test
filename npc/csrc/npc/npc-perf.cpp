#ifdef NPC

#include "svdpi.h"
#include "VysyxSoCFull__Dpi.h"
#include "perf_names.h"
#include <stdio.h>
#include <string.h>

void printPMU() {
    for (int i = 0; i < PERF_COUNT; i++) {
        char scope[256];
        snprintf(scope, sizeof(scope), "TOP.ysyxSoCFull.cpu.%s", perf_scope_names[i]);
        svScope s = svGetScopeFromName(scope);
        if (!s) {
            printf("Error: DPI Scope '%s' not found!\n", scope);
            continue;
        }
        svSetScope(s);
        long long data = 0;
        perf_read(&data);
        const char *name = strrchr(perf_scope_names[i], '.');
        name = name ? name + 1 : perf_scope_names[i];
        printf("[PERF] %s: %llu\n", name, (unsigned long long)data);
    }
}

#endif
