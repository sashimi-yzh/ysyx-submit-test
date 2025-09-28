#include <NDL.h>
#include <assert.h>
#include <sdl-timer.h>
#include <stdint.h>
#include <stdio.h>

void CallbackHelper(int);

SDL_TimerID SDL_AddTimer(uint32_t interval, SDL_NewTimerCallback callback, void *param) {
  assert(0);
  return NULL;
}

int SDL_RemoveTimer(SDL_TimerID id) {
  assert(0);
  return 1;
}

uint32_t sdl_init_time_ms;

uint32_t SDL_GetTicks() {
  CallbackHelper(0);
  return NDL_GetTicks() - sdl_init_time_ms;
}

void SDL_Delay(uint32_t ms) {
  uint32_t t = SDL_GetTicks();
  while (SDL_GetTicks() - t <= ms);
}
