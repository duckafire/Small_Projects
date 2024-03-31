#include <SDL.h>
#include "defs.h"

void updateScene(void){
	// background color (RGBA)
	SDL_SetRenderDrawColor(app.renderer, 50, 50, 50, 255);

	// clear "scene"
	SDL_RenderClear(app.renderer);
}

void drawScene(void){
	// draw new frame
	SDL_RenderPresent(app.renderer);
}