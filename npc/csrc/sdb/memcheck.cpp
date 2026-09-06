#include "common.h"
#include <vector>

#ifdef DIFFTEST
std::vector<std::pair<uint32_t, size_t>> mem_guards;

int add_mem_guard(uint32_t paddr, size_t size) {
    if(!in_pmem(paddr)) {
        printf("add mem guard failed at paddr 0x%08x\n", paddr);
        return -1;
    }
    difftest_check_mem(paddr, paddr_read(paddr, size), size);
    mem_guards.push_back({paddr, size});
    return 0;
}

int check_mem_guard() {
    for (auto &guard : mem_guards) {
        uint32_t expect = paddr_read(guard.first, guard.second);
        difftest_check_mem(guard.first, expect, guard.second);
    }
    return 0;
}

#else 

int add_mem_guard(uint32_t paddr, size_t size) { return 0; }
int check_mem_guard() { return 0; }
#endif