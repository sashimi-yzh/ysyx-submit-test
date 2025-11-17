#include <am.h>
#include <ysyxsoc.h>
#include <klib.h>
#include <riscv.h>


void read_flash(void *addr, int offset, int size){
    memcpy(addr, FLASH_BASE + offset, size);
}