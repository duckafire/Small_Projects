#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "struct.h"

void initSDL(void){
	int rendererFlags = SDL_RENDERER_ACCELERATED;
	int windowFlags   = 0;
	
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	
	// window renderizator (SDL_WINDOWPOS_UNDEFINED == any position)
	app.window = SDL_CreateWindow("Shoot'em up", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);
	
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
}