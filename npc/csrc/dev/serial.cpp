#include "device.h"

#include <cstdio>

void serial_handler(word_t addr, void* data, bool isw)
{
    if (isw)
    {
        int* ch = (int*)data;
        putchar(*ch);
        fflush(stdout);
    }
    else 
    {
        *((int*)data) = getchar();
    }
}