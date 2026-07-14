#include "include/common.h"
void serial_write(int addr, int data, char wmask)
{
    if (addr == SERIAL_PORT && (wmask & 0x1))
    {
        putchar(data & 0xFF);
        fflush(stdout);
    }
}

void init_serial()
{
    add_device(SERIAL_PORT, 4, nullptr, serial_write);
}