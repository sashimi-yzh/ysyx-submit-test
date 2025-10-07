#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <NDL.h>

uint32_t NDL_GetTicks();
int NDL_Init(uint32_t flags);
int main() {
  NDL_Init(0);
  struct timeval tv;
  int ms = 500;
  while (1) {
    while (NDL_GetTicks() < ms) {
    }
    ms += 500;
    printf("ms = %d\n", ms);
  }
}
