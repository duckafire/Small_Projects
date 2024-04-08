#include <string.h>
#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "struct.h"

// "RENDERER BUFFER" (backbuffer) -> its store all pixels of the window.

int main(int argc, char *argv[]){
	// define a struct and clear (to 0) all spaces
	memset(&app, 0, sizeof(App));
	
	initSDL();
	initMatch();
	
	long then = SDL_GetTicks(); // return the milliseconds after start sdl2 library
	float remainder = 0;        // accrued time between tics
	
	while(1){
		// color to fill "renderer buffer"; restart the "renderer buffer" filling it with the color above (clear it)
		SDL_SetRenderDrawColor(app.renderer, 50, 50, 50, 255);
		SDL_RenderClear(app.renderer);
		
		doInput();
		app.update();
		app.draw();
		
		// show the "renderer buffer", after add the elements to screen
		SDL_RenderPresent(app.renderer);
		
		lock60fps(&then, &remainder);
	}
	
	return 0;
}

static void initSDL(void){
	// starts libs
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	
	// window renderizator
	app.window = SDL_CreateWindow("Shoot'em up", 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	
	// "create a 2D rendering context for a window"
	app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
	
	// image quality (0. linear; 1. nearest; 2. best)
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
}

static void lock60fps(long *then, float *remainder){
	// time to wait
	long wait = 16 * *remainder;
	
	// "remove" integer values of remainder
	*remainder -= (int)*remainder;
	
	// time to wait = itself - (time after then last frame)
	wait -= (SDL_GetTicks() - *then);
	
	// minimum value of wait
	if(wait < 1) wait = 1;
	
	// loop delay
	SDL_Delay(wait);
	
	// update time not use in last frames
	*remainder += 0.667;
	
	// to find the time after last frame
	*then = SDL_GetTicks();
}

