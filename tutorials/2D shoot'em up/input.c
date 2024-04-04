#include <SDL.h>
#include "defs.h"
#include "struct.h"

static void keyboard(SDL_KeyboardEvent *event, short down){
	if(event->repeat == 0){
		int id[4] = {SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D};
		int key = event->keysym.scancode;
		
		if(key == id[0]) control.top = -1 * down;
		if(key == id[1]) control.bel =  1 * down;
		if(key == id[2]) control.lef = -1 * down;
		if(key == id[3]) control.rig =  1 * down;
		
	}
}

void doInput(void){
	SDL_Event event;
	
	while(SDL_PollEvent(&event)){
		
		switch(event.type){
			case SDL_QUIT:
				exit(0);
				break;
			case SDL_KEYDOWN:
				keyboard(&event.key, 1);
				break;
			case SDL_KEYUP:
				keyboard(&event.key, 0);
				break;
			default:
				break;
		}
		
	}
}