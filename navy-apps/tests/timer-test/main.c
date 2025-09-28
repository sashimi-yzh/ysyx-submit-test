#include <stdio.h>
#include <stdint.h>
#include <NDL.h>

int main() {
  NDL_Init(0);
  int cnt = 0;
  long lst = 0;
  
  while (1) {
    uint32_t tick = NDL_GetTicks();
    if (tick - lst >= 500) {
      printf("-0.5s x%d\n", ++cnt);
      lst = tick;
    }
  }

  return 0;
}
