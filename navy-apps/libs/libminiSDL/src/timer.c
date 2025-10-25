#include <NDL.h>
#include <sdl-timer.h>
#include <stdio.h>
#include <assert.h>
extern uint32_t SDL_start_ticks;
SDL_TimerID SDL_AddTimer(uint32_t interval, SDL_NewTimerCallback callback, void *param)
{
	assert(0);
	return NULL;
}

int SDL_RemoveTimer(SDL_TimerID id)
{
	assert(0);
	return 1;
}

uint32_t SDL_GetTicks()
{
	return NDL_GetTicks() - SDL_start_ticks;
}

void SDL_Delay(uint32_t ms)
{
	uint32_t start = SDL_GetTicks();
	while (SDL_GetTicks() - start < ms)
	{
		// Busy-waiting to simulate delay
	}
	return;
}
