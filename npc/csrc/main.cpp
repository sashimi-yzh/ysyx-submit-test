#include "tpdef.h"
#include <cstdio>

void sdb_mainloop();

int main(int argc, char** argv)
{
    if (!initialize(argc, argv))
    {
        printf(ANSI_FG_RED "Initialize have some error." ANSI_NONE);
        return 1;
    }

    sdb_mainloop();

    return 0;
}