#include <nterm.h>
#include <stdarg.h>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <SDL.h>

char handle_key(SDL_Event *ev);

static void sh_printf(const char *format, ...) {
  static char buf[256] = {};
  va_list ap;
  va_start(ap, format);
  int len = vsnprintf(buf, 256, format, ap);
  va_end(ap);
  term->write(buf, len);
}

static void sh_banner() {
  sh_printf("Built-in Shell in NTerm (NJU Terminal)\n\n");
}

static void sh_prompt() {
  sh_printf("sh> ");
}

static void sh_handle_cmd(const char *cmd) {
  char buf[256];
  strcpy(buf, cmd);
  *strchr(buf, '\n') = '\0';

  char *argv[10];
  int argc = 1;
  if (!(argv[0] = strtok(buf, " \t"))) return;
  while ((argv[argc] = strtok(NULL, " \t"))) ++argc;

  if (!argc) return;

  if (!strcmp(argv[0], "echo")) {
    for (int i = 1; i < argc; ++i) sh_printf("%s ", argv[i]);
    sh_printf("\n");
  } else {
    argv[argc] = NULL;
    execvp(argv[0], argv);
  }
}

void builtin_sh_run() {
  sh_banner();
  sh_prompt();

  setenv("PATH", "/bin:/usr/bin", 0);

  while (1) {
    SDL_Event ev;
    if (SDL_PollEvent(&ev)) {
      if (ev.type == SDL_KEYUP || ev.type == SDL_KEYDOWN) {
        const char *res = term->keypress(handle_key(&ev));
        if (res) {
          sh_handle_cmd(res);
          sh_prompt();
        }
      }
    }
    refresh_terminal();
  }
}
