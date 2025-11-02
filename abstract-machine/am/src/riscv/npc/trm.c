#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <riscv/riscv.h>
#include <npc.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)


# define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))


Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void putch(char ch) {
	outb(SERIAL_PORT, ch);
}

char getch(void){
	return inb(SERIAL_PORT);
}


void csrr_id(){
    //printf("csrr_id in trm.c\n");
    unsigned int mvendorid, marchid;
    asm volatile("csrr %0, mvendorid" : "=r"(mvendorid));
    asm volatile("csrr %0, marchid" : "=r"(marchid));

    char c0 = (char)(mvendorid & 0x000000ff);
    char c1 = (char)((mvendorid & 0x0000ff00) >> 8);
    char c2 = (char)((mvendorid & 0x00ff0000) >> 16);
    char c3 = (char)((mvendorid & 0xff000000) >> 24);
    const char vendor[5] = {c3, c2, c1, c0, '\0'};
    //putch(c3); putch(c2); putch(c1); putch(c0); putch('\n');
    printf("vendorid: %s, archid: %d\n", vendor, marchid);
}


void halt(int code) {
  npc_trap(code);
  while (1);
}

void _trm_init() {
  	csrr_id();
	int ret = main(mainargs);
  	halt(ret);
}
