#include <string.h>
#include <stdlib.h>
#include <memory/memory.h>



static uint8_t *vmem = NULL;
static uint32_t *vgactl_port_base = NULL;


static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;



static void init_screen() {
  	SDL_Window *window = NULL;
  	char title[128];
	sprintf(title, "riscv32e-NPC");
  	
	SDL_Init(SDL_INIT_VIDEO);
  	SDL_CreateWindowAndRenderer(SCREEN_W * 2,SCREEN_H * 2, 0, &window, &renderer);
  	SDL_SetWindowTitle(window, title);
  	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
      		SDL_TEXTUREACCESS_TARGET, SCREEN_W, SCREEN_H);
  	SDL_RenderPresent(renderer);
}



static inline void update_screen() {
	SDL_Event event;
	while(SDL_PollEvent(&event));
	SDL_UpdateTexture(texture, NULL, (void *)vmem, SCREEN_W * sizeof(uint32_t));
  	SDL_RenderClear(renderer);
  	SDL_RenderCopy(renderer, texture, NULL, NULL);
  	SDL_RenderPresent(renderer);
  	//SDL_Delay(10);
}



//SDL_Event event;

void update_vga_screen() {
	//SDL_PollEvent(&event);
	//while(SDL_PollEvent(&event));
    if(vgactl_port_base[1] == 1){
        update_screen();
        vgactl_port_base[1] = 0;
    }
}



void init_vga() {
	vgactl_port_base = (uint32_t*)malloc(sizeof(uint32_t)*2);
	vgactl_port_base[0] = (SCREEN_W << 16) | SCREEN_H;

	vmem = (uint8_t*)malloc(sizeof(uint8_t)*SCREEN_SIZE);
  
	init_screen();
	memset(vmem, 0, SCREEN_SIZE);
}




//由memory.cpp调用
void update_vgactl_addr(uint32_t waddr, int sync, char wmask){
	if(waddr == VGACTL_ADDR + 4)
		vgactl_port_base[1] = sync;
}


void update_fb_addr(uint32_t waddr, int color, char wmask){
	//printf("in update fb\n");
	vmem[waddr - FB_ADDR] = (uint8_t)(color);
	vmem[waddr - FB_ADDR + 1] = (uint8_t)(color >> 8);
	vmem[waddr - FB_ADDR + 2] = (uint8_t)(color >> 16);
	vmem[waddr - FB_ADDR + 3] = (uint8_t)(color >> 24);
}


