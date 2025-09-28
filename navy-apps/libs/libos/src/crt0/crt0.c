#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[], char *envp[]);
void __libc_init_array();
extern char **environ;
void call_main(uintptr_t *args) {

  int argc = *args;
  char **argv = (char **)args + 1;
  char **envp = (char **)args + 1 + argc + 1;

  __libc_init_array();
  exit(main(argc, argv, envp));
  assert(0);
}
