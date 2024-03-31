#include <stdio.h>
#include <string.h>
#include <SDL.h>

#include "defs.h"

int main(int argc, char *argv[]){
	// define a struct and clear (to 0) all spaces
	memset(&app, 0, sizeof(App));
	
	initSDL();
	
	atexit(NULL);
	
	while(1){
		updateScene();
		doInput();
		drawScene();
		
		// lock loop in ~62 (fps) tics/s
		SDL_Delay(16);
	}
	
	return 0;
}