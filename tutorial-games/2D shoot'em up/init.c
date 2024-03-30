#include "head.h"

void initSDL(void){
	int rendererFlags = SDL_RENDER_ACCELERATED;
	int windowFlags   = 0;
	
	// start video system
	if (SDL_Init(DFL_INIT_VIDEO) < 0) exit(1);
	
	// window renderizator (SDL_WINDOWPOS_UNDEFINED == any position)
	app.window = SDL_CreateWindow("Shooter Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
	
	if(!app.window) exit(1);
	
	SDL_SetHind(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	
	app.renderer = SDL_CreateRender(app.window, -1, rendererFlags)
	
	if(!app.renderer) exit(1);
}