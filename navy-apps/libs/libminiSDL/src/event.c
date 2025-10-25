#include <NDL.h>
#include <SDL.h>
#include <string.h>
#include <assert.h>
#define keyname(k) #k,

static const char *keyname[] = {
	"NONE",
	_KEYS(keyname)};
int key_num = sizeof(keyname) / sizeof(keyname[0]);
uint8_t key_state[512] = {0};
int SDL_PushEvent(SDL_Event *ev)
{
	return 0;
}
int match_key(SDL_Event *ev, char *buf)
{
	char type[4] = {0};
	char key_name[16] = {0};
	sscanf(buf, "%s %s", type, key_name);
	if (strcmp(type, "kd") == 0)
	{
		ev->type = SDL_KEYDOWN;
	}
	else if (strcmp(type, "ku") == 0)
	{
		ev->type = SDL_KEYUP;
	}
	else
	{
		printf("Unknown event type: %s\n", type);
		return 0; // Not a key event
	}
	for (int i = 0; i < sizeof(keyname) / sizeof(keyname[0]); i++)
	{
		if (strcmp(keyname[i], key_name) == 0)
		{
			ev->key.keysym.sym = i;
			if (ev->type == SDL_KEYDOWN)
			{
				key_state[i] = 1; // Set key state to pressed
			}
			else if (ev->type == SDL_KEYUP)
			{
				key_state[i] = 0; // Set key state to released
			}
			else
			{
				printf("Unknown event type: %s\n", type);
				return 0; // Not a valid key event
			}
			break;
		}
	}
	if (ev->key.keysym.sym == SDLK_NONE)
	{
		printf("Unknown key: %s\n", key_name);
		return 0; // Unknown key}
	}
	return 1; // Event successfully read
}
int SDL_PollEvent(SDL_Event *ev)
{
	char buf[64] = {0};
	char buf_cmptarget[64] = {0};

	NDL_PollEvent(buf, sizeof(buf) - 1);
	if (memcmp(buf, buf_cmptarget, 64) == 0)
	{
		ev->type = SDL_KEYUP;			// 如果buf是空字符串，返回一个空事件
		ev->key.keysym.sym = SDLK_NONE; // 设置为无效键
		return 0;						// 返回一个空事件
	}
	return match_key(ev, buf); // 尝试匹配事件
}

int SDL_WaitEvent(SDL_Event *event)
{
	char buf[64] = {0};
	char buf_cmptarget[64] = {0};
	char type[4] = {0};
	char key_name[16] = {0};
	do
	{
		NDL_PollEvent(buf, sizeof(buf) - 1);
	} while (memcmp(buf, buf_cmptarget, 64) == 0); // 直到buf不是空字符串

	return match_key(event, buf); // 尝试匹配事件
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask)
{
	assert(0);
	return 0;
}

uint8_t *SDL_GetKeyState(int *numkeys)
{
	if (numkeys)
		numkeys = &key_num;
	return key_state;
}
