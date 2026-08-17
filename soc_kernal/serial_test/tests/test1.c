#include "am.h"
#include <klib.h>
#include <stdint.h>

#define NR_DATA LENGTH(test_data)
char buffer[3][8];
int cnt[3];
int main() {
  int a = 123, b = 456;
  int c = a + b;
  while (a != 0) {
    buffer[0][cnt[0]++] = a % 10 + '0';
    a /= 10;
  }
  while (b != 0) {
    buffer[1][cnt[1]++] = b % 10 + '0';
    b /= 10;
  }
  while (c != 0) {
    buffer[2][cnt[2]++] = c % 10 + '0';
    c /= 10;
  }
  for (int i = cnt[0] - 1; i >= 0; i--)
    putch(buffer[0][i]);
  putch('+');
  for (int i = cnt[1] - 1; i >= 0; i--)
    putch(buffer[1][i]);
  putch('=');
  for (int i = cnt[2] - 1; i >= 0; i--)
    putch(buffer[2][i]);
  putch('\n');
  return 0;
}
