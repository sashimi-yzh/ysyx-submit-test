#include <NDL.h>
#include <sdl-timer.h>
#include <stdio.h>
#include <sys/time.h>
uint32_t init_time1 = 0 ;
SDL_TimerID SDL_AddTimer(uint32_t interval, SDL_NewTimerCallback callback, void *param) {
  return NULL;
}

int SDL_RemoveTimer(SDL_TimerID id) {
  return 1;
}

uint32_t SDL_GetTicks() {
  struct timeval tv;
	gettimeofday(&tv,NULL);
  if( init_time1 == 0 ) {
    init_time1 = tv.tv_sec * 1000 + tv.tv_usec/1000;
  }
  uint32_t now = tv.tv_sec * 1000 + tv.tv_usec/1000;
  uint32_t total_time = (now - init_time1);
  return total_time;
}

void SDL_Delay(uint32_t ms) {
}
