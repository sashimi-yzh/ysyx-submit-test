#include <memory/memory.h>


#define NEMU_KEYS(f) \
  f(ESCAPE) f(F1) f(F2) f(F3) f(F4) f(F5) f(F6) f(F7) f(F8) f(F9) f(F10) f(F11) f(F12) \
f(GRAVE) f(1) f(2) f(3) f(4) f(5) f(6) f(7) f(8) f(9) f(0) f(MINUS) f(EQUALS) f(BACKSPACE) \
f(TAB) f(Q) f(W) f(E) f(R) f(T) f(Y) f(U) f(I) f(O) f(P) f(LEFTBRACKET) f(RIGHTBRACKET) f(BACKSLASH) \
f(CAPSLOCK) f(A) f(S) f(D) f(F) f(G) f(H) f(J) f(K) f(L) f(SEMICOLON) f(APOSTROPHE) f(RETURN) \
f(LSHIFT) f(Z) f(X) f(C) f(V) f(B) f(N) f(M) f(COMMA) f(PERIOD) f(SLASH) f(RSHIFT) \
f(LCTRL) f(APPLICATION) f(LALT) f(SPACE) f(RALT) f(RCTRL) \
f(UP) f(DOWN) f(LEFT) f(RIGHT) f(INSERT) f(DELETE) f(HOME) f(END) f(PAGEUP) f(PAGEDOWN)

#define NEMU_KEY_NAME(k) NEMU_KEY_ ## k,

enum {
  NEMU_KEY_NONE = 0,
  NEMU_KEYS(NEMU_KEY_NAME)
  //展成NEMU_KEY_ESCAPE = 1,
  //NEMU_KEY_F1 = 2,
  //...
};

#define SDL_KEYMAP(k) keymap[SDL_SCANCODE_ ## k] = NEMU_KEY_ ## k;
static uint32_t keymap[256] = {};


extern bool difftest_to_skip;
extern bool difftest_skipping;

uint32_t keyboard_addr[1] = {0};


void init_keymap() {
  NEMU_KEYS(SDL_KEYMAP)
  //SDL_KEYMAP(ESCAPE) ->   keymap[SDL_SCANCODE_ESCAPE] = NEMU_KEY_ESCAPE
  //                        keymap[SDL_SCANCODE_F1] = NEMU_KEY_F1
}


/*void update_keycode(){
	SDL_Event event;
	SDL_PollEvent(&event);
	return;

	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_KEYUP:
			case SDL_KEYDOWN:{
				uint8_t k = event.key.keysym.scancode;
				uint8_t kmap = keymap[k];
				bool is_keydown = (event.key.type == SDL_KEYDOWN);
				printf("is_keydown: %d\n",is_keydown);
				keyboard_addr[0] = is_keydown ? (0x8000|kmap) : kmap;
				break;
			}
			default: {
				//keyboard_addr[0] = 0;
				break;
			}
		}
	
	}

}*/

/*int fetch_keyboard_addr(uint32_t raddr){
    difftest_to_skip = true;
    if(raddr == KBD_ADDR){
        int tmp = keyboard_addr[0];
		keyboard_addr[0] = 0;
		return tmp;
    }
    return 0;
}*/

//int i = 0;

int fetch_keyboard_addr(uint32_t raddr){
	//printf("cnt in hw: %d\n",i++);
	difftest_skipping = true;
	int ret = 0;
	SDL_Event event;
	while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_KEYUP:
            case SDL_KEYDOWN:{
                uint8_t k = event.key.keysym.scancode;
				uint8_t kmap = keymap[k];
                bool is_keydown = (event.key.type == SDL_KEYDOWN);
                //printf("is_keydown: %d\n",is_keydown);
                ret = is_keydown ? (0x8000|kmap) : kmap;
				//printf("ret of hw: %x\n",ret);
				//return is_keydown ? (0x8000|kmap) : kmap;
            }
            default: break;
		}
	}
	return ret;
}
