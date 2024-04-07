#include <SDL.h>
#include <stdio.h>
#include "defs.h"
#include "struct.h"

// move to (top, below, left and right), shoot
int id[5] = {SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_RETURN};

static void keyboard(SDL_KeyboardEvent *event, short down){
	if(event->repeat == 0){
		int key = event->keysym.scancode;
		
		// on/off controls
		if(key == id[0]) control.top = 1 * down;
		if(key == id[1]) control.bel = 1 * down;
		if(key == id[2]) control.lef = 1 * down;
		if(key == id[3]) control.rig = 1 * down;
		if(key == id[4]) control.sht = 1 * down;
		
	}
}

void doInput(void){
	SDL_Event event;// any event
	
	// loop while any event is occurring
	while(SDL_PollEvent(&event)){
		
		switch(event.type){
			// close window
			case SDL_QUIT:
				exit(0);
				break;
			
			// a key was pressend
			case SDL_KEYDOWN:
				keyboard(&event.key, 1);
				break;
			
			// a key is not anymore being pressed
			case SDL_KEYUP:
				keyboard(&event.key, 0);
				break;
		}
		
	}
}

