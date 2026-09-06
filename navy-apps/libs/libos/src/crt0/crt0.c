#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAXARG 32
#define MAXENVP 32

int main(int argc, char *argv[], char *envp[]);
extern char **environ;

extern int _write(int fd, void *buf, size_t count);
static void debug_write(const char *s) {
  _write(1, (void *)s, strlen(s));
}

void __attribute__((optimize("O0"))) call_main(uintptr_t *args) {
  char *argv[MAXARG];
  char *envp[MAXENVP];
  int argc = *(uint32_t *)args;

  char buf[] = "get to the function call_main\n";
  debug_write(buf);

  {
    char buf[64];
    snprintf(buf, sizeof(buf), "[call_main] args=%p argc=%d\n", (void *)args, argc);
    debug_write(buf);
  }

  char **ptr_array = (char **)(args + 1);
  int argv_count = 0;
  while (*ptr_array != NULL && argv_count < MAXARG) {
    argv[argv_count++] = *ptr_array++;
  }
  argv[argv_count] = NULL;
  ptr_array++;

  int envp_count = 0;
  while (*ptr_array != NULL && envp_count < MAXENVP) {
    envp[envp_count++] = *ptr_array++;
  }
  assert(envp_count != 0);
  envp[envp_count] = NULL;

  /* 调试：打印解析出的 argv */
  for (int i = 0; i < argv_count; i++) {
    char buf[128];
    snprintf(buf, sizeof(buf), "  argv[%d]=%p \"%s\"\n", i, (void *)argv[i], argv[i] ? argv[i] : "(null)");
    debug_write(buf);
  }
  for (int i = 0; i < (envp_count < 3 ? envp_count : 3); i++) {
    char buf[128];
    snprintf(buf, sizeof(buf), "  envp[%d]=%p \"%s\"\n", i, (void *)envp[i], envp[i] ? envp[i] : "(null)");
    debug_write(buf);
  }
  if (envp_count >= 3) debug_write("  ...\n");

  environ = envp;
  exit(main(argc, argv, envp));
  assert(0);
}
