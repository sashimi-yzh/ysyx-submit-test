#include <NDL.h>

int SDL_Init(uint32_t flags) {
  int res = NDL_Init(flags);
  extern uint32_t sdl_init_time_ms;
  sdl_init_time_ms = NDL_GetTicks();
  return res;
}

void SDL_Quit() {
  NDL_Quit();
}

char *SDL_GetError() {
  return "Navy does not support SDL_GetError()";
}

int SDL_SetError(const char* fmt, ...) {
  return -1;
}

int SDL_ShowCursor(int toggle) {
  return 0;
}

void SDL_WM_SetCaption(const char *title, const char *icon) {
}
