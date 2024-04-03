#include <SDL.h>
#include "defs.h"
#include "struct.h"

static void keyboard(SDL_KeyboardEvent *event, int down){
	if(event->repeat == 0){
		int id[4] = {SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT};
		int key = event->keysym.scancode;
		
		int up = 1;
		if(!down) up = 0;
		
		int checkKey(int _id){
			if(key == id[_id    ]){ return -1 * up; }
			if(key == id[_id + 1]){ return  1 * up; }
			return 0;
		}
		
		// top - down; left - right
		app.dirY = checkKey(0);
		app.dirX = checkKey(2);
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