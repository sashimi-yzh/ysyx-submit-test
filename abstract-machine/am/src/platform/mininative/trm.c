#include <am.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define HEAP_SIZE (80 * 1024 * 1024)
Area heap = {};

int main(const char *args);

__attribute__((constructor)) void trm_init() {
  void *p = malloc(HEAP_SIZE);
  assert(p);
  heap.start = p;
  heap.end = p + HEAP_SIZE;

  const char *args = getenv("mainargs");
  halt(main(args ? args : "")); // call main here!
}

void putch(char ch) {
  putchar(ch);
}

void halt(int code) {
  printf("Exit (%d)\n", code);
  exit(code);
}

void __am_send_kbd_intr() {
}
