#include <am.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef __KLIB_USE_PICOLIBC__
#include <stdio.h>

static char *brk = NULL;

static int am_stdio_put(char ch, FILE *stream) {
  (void)stream;
  putch(ch);
  return 0;
}

static int am_stdio_get(FILE *stream) {
  (void)stream;
  return _FDEV_EOF;
}

static FILE am_stdin = FDEV_SETUP_STREAM(NULL, am_stdio_get, NULL, _FDEV_SETUP_READ);
static FILE am_stdout = FDEV_SETUP_STREAM(am_stdio_put, NULL, NULL, _FDEV_SETUP_WRITE);

FILE *const stdin = &am_stdin;
FILE *const stdout = &am_stdout;
FILE *const stderr = &am_stdout;

static void *am_sbrk(ptrdiff_t incr) {
  if (brk == NULL) brk = heap.start;

  char *old = brk;
  char *new_brk = brk + incr;
  if (new_brk < (char *)heap.start || new_brk > (char *)heap.end) {
    errno = ENOMEM;
    return (void *)-1;
  }

  brk = new_brk;
  return old;
}

int write(int fd, const void *buf, size_t count) {
  if (fd != 1 && fd != 2) {
    errno = EBADF;
    return -1;
  }

  const char *s = buf;
  for (size_t i = 0; i < count; i++) {
    putch(s[i]);
  }
  return (int)count;
}

void *sbrk(ptrdiff_t incr) {
  return am_sbrk(incr);
}

int close(int fd) {
  (void)fd;
  return 0;
}

int fstat(int fd, struct stat *st) {
  (void)fd;
  st->st_mode = S_IFCHR;
  return 0;
}

int isatty(int fd) {
  return fd == 0 || fd == 1 || fd == 2;
}

off_t lseek(int fd, off_t offset, int whence) {
  (void)fd;
  (void)offset;
  (void)whence;
  return 0;
}

int read(int fd, void *buf, size_t count) {
  (void)fd;
  (void)buf;
  (void)count;
  return 0;
}

void _exit(int code) {
  halt(code);
}

int _write(int fd, const void *buf, size_t count) {
  return write(fd, buf, count);
}

void *_sbrk(ptrdiff_t incr) {
  return sbrk(incr);
}

int _close(int fd) {
  return close(fd);
}

int _fstat(int fd, struct stat *st) {
  return fstat(fd, st);
}

int _isatty(int fd) {
  return isatty(fd);
}

off_t _lseek(int fd, off_t offset, int whence) {
  return lseek(fd, offset, whence);
}

int _read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}

#endif
