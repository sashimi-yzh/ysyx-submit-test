#include "include/common.h"
#include "include/CPU.h"
void dpic_putch(char c)
{
    putchar(c);
    if(c == '\n')
    {
        // printf ("[cycle: %llu]     ", (unsigned long long)cpu->cycle_count);
    }

}