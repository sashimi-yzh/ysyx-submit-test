#include <NDL.h>
#include <SDL.h>
#include <string.h>
#define keyname(k) #k,

static const char *keyname[] = {
  "NONE",
  _KEYS(keyname)
};

int SDL_PushEvent(SDL_Event *ev) {
  return 0;
}

int SDL_PollEvent(SDL_Event *ev) {
  char buf[20];
  
  if (NDL_PollEvent(buf, sizeof(buf)) == 0) return 0;
  ev->type = buf[1] == 'u' ? SDL_KEYUP : SDL_KEYDOWN;
  for (int i = 0; i < 83; i++) {
    if (strcmp(keyname[i], buf + 3) == 0) {
      ev->key.keysym.sym = i;
      return 1;
    }
  }

  return 0;
}

int SDL_WaitEvent(SDL_Event *event) {
  char buf[20];
  while (1) {
    if (NDL_PollEvent(buf, sizeof(buf)) == 0) continue;
    event->type = buf[1] == 'u' ? SDL_KEYUP : SDL_KEYDOWN;
    for (int i = 0; i < 83; i++) {
      if (strcmp(keyname[i], buf + 3) == 0) {
        event->key.keysym.sym = i;
        return 1;
      }
    }
  }
  return 0;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  return 0;
}

uint8_t* SDL_GetKeyState(int *numkeys) {
  return NULL;
}
