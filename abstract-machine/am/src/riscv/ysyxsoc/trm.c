#include <ysyxsoc.h>

extern char _heap_start, _heap_end;
int main(const char *args);


Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

// divisor factor = freq / (16 * baudrate)
static void serial_init()
{
    outb(SERIAL_PORT + 3, 0x80); // Enable DLAB
    outb(SERIAL_PORT + 1, 0x00); // Set baud rate divisor
    outb(SERIAL_PORT + 0, 0x01); // Divisor low byte
    outb(SERIAL_PORT + 3, 0x03); // 8 bits, no parity, one stop bit
}

static void serial_transmit_wait()
{
    while((inb(SERIAL_PORT + 5) & 0x20) == 0)
        ;
}
void putch(char ch)
{
    serial_transmit_wait();
    outb(SERIAL_PORT, ch);
}

void halt(int code)
{
    ysyxsoc_trap(code);
    while (1)
        ;
}

void _trm_init()
{
    serial_init();
    // uint32_t ysyx_logo = ysyxsoc_csr_read(CSR_MVENDORID);
    // // printf("mvendorid: 0x%08x\n", ysyx_logo);
    // uint32_t stu_num = ysyxsoc_csr_read(CSR_MARCHID);
    // printf("========================================\n");
    // printf("Version: %s\n", VERSION);
    // printf("Welcome to %s!\n", ysyx_logo == YSYX_LOGO ? "YSYX" : "Unknown");
    // printf("Student Number: ysyx_%x\n", stu_num);
    // printf("Name: %s\n", "HUANG HAIHONG");
    // printf("========================================\n");
    
    int ret = main(mainargs);
    halt(ret);
}
