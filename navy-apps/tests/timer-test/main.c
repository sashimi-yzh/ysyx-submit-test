#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <NDL.h>


int main() {
    size_t ticks, last_ticks;
	size_t interval = 500000; // 0.5s
	NDL_Init(0);
	last_ticks  = NDL_GetTicks();

    while (1) {
		ticks = NDL_GetTicks();
        if ((ticks - last_ticks) >= interval) {
            printf("hello\n");
            last_ticks = ticks;
        }

    }

    return 0;
}
