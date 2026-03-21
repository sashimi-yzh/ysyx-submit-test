#include "common.h"
#include "utils.h"

#ifndef CONFIG_SOC
extern "C" paddr_t paddr_read(paddr_t raddr);
extern "C" void paddr_write(paddr_t waddr, word_t wdata, uint32_t wmask);

vaddr_t vaddr_read(vaddr_t raddr) {
    return paddr_read(raddr);
}

void vaddr_write(vaddr_t waddr, word_t wdata, uint32_t wmask) {
    paddr_write(waddr, wdata, wmask);
}
#else

word_t paddr_read(paddr_t addr);
void paddr_write(paddr_t addr, word_t data, int len);

vaddr_t vaddr_read(vaddr_t raddr) {
    return paddr_read(raddr);
}

void vaddr_write(vaddr_t waddr, word_t wdata, uint32_t len) {
    paddr_write(waddr, wdata, len);
}
#endif