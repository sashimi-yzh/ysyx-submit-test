#include <stdio.h>
#include <assert.h>

int main() {
  printf("[file-test] open file: /share/files/num (mode=r+)\n");
  FILE *fp = fopen("/share/files/num", "r+");
  assert(fp);

  printf("[file-test] seek to end, then ftell (expect size=5000)\n");
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  printf("[file-test] size = %ld\n", size);
  assert(size == 5000);

  printf("[file-test] seek to offset = %d (500 * 5), read numbers 501..1000\n", 500 * 5);
  fseek(fp, 500 * 5, SEEK_SET);
  int i, n;
  for (i = 500; i < 1000; i ++) {
    fscanf(fp, "%d", &n);
    assert(n == i + 1);
  }
  printf("[file-test] read tail part OK\n");

  printf("[file-test] seek to beginning, write numbers 1001..1500 (500 lines)\n");
  fseek(fp, 0, SEEK_SET);
  for (i = 0; i < 500; i ++) {
    fprintf(fp, "%4d\n", i + 1 + 1000);
  }
  printf("[file-test] write head part done, continue reading (expect 501..1000)\n");

  for (i = 500; i < 1000; i ++) {
    fscanf(fp, "%d", &n);
    assert(n == i + 1);
  }
  printf("[file-test] read tail part again OK\n");

  printf("[file-test] seek to beginning, verify numbers 1001..1500 (500 lines)\n");
  fseek(fp, 0, SEEK_SET);
  for (i = 0; i < 500; i ++) {
    fscanf(fp, "%d", &n);
    assert(n == i + 1 + 1000);
  }
  printf("[file-test] verify head part OK\n");

  printf("[file-test] close file\n");
  fclose(fp);

  printf("PASS!!!\n");

  return 0;
}
