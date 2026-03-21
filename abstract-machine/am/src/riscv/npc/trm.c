#include <npc.h>

extern char _heap_start;
int main(const char *args);

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch)
{
    outb(SERIAL_PORT, ch);
}

void halt(int code)
{
    npc_trap(code);
    while (1)
        ;
}

void _trm_init()
{
    // uint32_t ysyx_logo = npc_csr_read(CSR_MVENDORID);
    // // printf("mvendorid: 0x%08x\n", ysyx_logo);
    // uint32_t stu_num = npc_csr_read(CSR_MARCHID);
    // printf("========================================\n");
    // printf("Version: %s\n", VERSION);
    // printf("Welcome to %s!\n", ysyx_logo == YSYX_LOGO ? "YSYX" : "Unknown");
    // printf("Student Number: ysyx_%x\n", stu_num);
    // printf("Name: %s\n", "HUANG HAIHONG");
    // printf("========================================\n");
    
    int ret = main(mainargs);
    halt(ret);
}
