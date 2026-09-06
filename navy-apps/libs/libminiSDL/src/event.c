#include <NDL.h>
#include <SDL.h>

#include "assert.h"

#define keyname(k) #k,

static const char *keyname[] = {"NONE", _KEYS(keyname)};

static int sdl_strcmp(const char *str1, const char *str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i])
      return 0;
    i++;
  }

  return str1[i] == str2[i];
}

static int sdl_stoi(const char *str) {
  int result = 0;

  assert(*str >= '0' && *str <= '9');

  while (*str >= '0' && *str <= '9') {
    result = result * 10 + (*str - '0');
    str++;
  }

  assert(*str == '\0');
  return result;
}

int SDL_PushEvent(SDL_Event *ev) { return 0; }

int SDL_PollEvent(SDL_Event *ev) { 
  char buf[16];
  int res = NDL_PollEvent(buf, 16);

  if(res == 0) return 0;

  char *is_press = buf;
  char *keyn = buf + 3;
  buf[2] = '\0';

  for(int i = 3; i < 16; i++) {
    if(buf[i] == '\n') {
      buf[i] = '\0';
      break;
    }
  }

  if (sdl_strcmp(is_press, "kd")) {
    ev->key.type = SDL_KEYDOWN;
  } else if (sdl_strcmp(is_press, "ku")) {
    ev->key.type = SDL_KEYUP;
  } else {
    assert(0);
  }

  for(int i = 0; i < sizeof(keyname) / sizeof(keyname[0]); i++) {
    if(sdl_strcmp(keyname[i], keyn)) {
      ev->key.keysym.sym = i;
      break;
    }
  }

  return 1; 
}

int SDL_WaitEvent(SDL_Event *event) {
  char buf[16];
  int res;
  while ((res = NDL_PollEvent(buf, 16)) == 0) {
    // busy wait until an event occurs
  }
  char *keystate = buf;
  char *keyn = buf + 3;
  buf[2] = '\0';

  for(int i = 3; i < 16; i++) {
    if(buf[i] == '\n') {
      buf[i] = '\0';
      break;
    }
  }

  if (sdl_strcmp(keystate, "kd")) {
    event->key.type = SDL_KEYDOWN;
  } else if (sdl_strcmp(keystate, "ku")) {
    event->key.type = SDL_KEYUP;
  } else {
    assert(0);
  }

  for(int i = 0; i < sizeof(keyname) / sizeof(keyname[0]); i++) {
    if(sdl_strcmp(keyname[i], keyn)) {
      event->key.keysym.sym = i;
      break;
    }
  }

  return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  return 0;
}

#define SDL_NUMKEYS (sizeof(keyname) / sizeof(keyname[0]))
static uint8_t keystate[SDL_NUMKEYS];

uint8_t *SDL_GetKeyState(int *numkeys) { 
  char buf[16];
  int res;

  for(int i = 0; i < sizeof(keyname) / sizeof(keyname[0]); i++) {
    keystate[i] = 0;
  }

  while((res = NDL_PollEvent(buf, 16)) != 0) {
      char *is_press = buf;
    char *keyn = buf + 3;
    buf[2] = '\0';

    for(int i = 3; i < 16; i++) {
      if(buf[i] == '\n') {
        buf[i] = '\0';
        break;
      }
    }

    int key_val = sdl_strcmp(is_press, "kd") ? 1 : 0;

    if (sdl_strcmp(is_press, "kd")) {
      for(int i = 0; i < sizeof(keyname) / sizeof(keyname[0]); i++) {
        if(sdl_strcmp(keyname[i], keyn)) {
          keystate[i] = key_val;
          break;
        }
      }
    } 
  }

  if(numkeys)
    *numkeys = SDL_NUMKEYS;
  return keystate;
}
