#include <SDL.h>
#include "defs.h"

void initSDL(void){
	int rendererFlags = SDL_RENDERER_ACCELERATED;
	int windowFlags   = 0;
	
	// start video system
	if (SDL_Init(SDL_INIT_VIDEO) < 0) exit(1);
	
	// window renderizator (SDL_WINDOWPOS_UNDEFINED == any position)
	app.window = SDL_CreateWindow("Shoot'em up", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
	
	if(!app.window) exit(1);
	
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	
	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);
	
	if(!app.renderer) exit(1);
}