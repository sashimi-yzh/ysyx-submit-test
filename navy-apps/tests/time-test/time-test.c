#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval tv;
    struct timezone tz;
    long us;
    int counter = 0;

    while(!gettimeofday(&tv, &tz)) {
        // 简单的测试循环
        if(tv.tv_usec - us > 500000) {
            printf("Time: %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
            us = tv.tv_usec;
            counter++;
        }

        if(counter == 10) {
            break;
        }
    }
    return 0;
}