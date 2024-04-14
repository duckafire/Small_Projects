#include <SDL.h>

#include "defs.h"
#include "struct.h"

SDL_Rect panel;

void initUI(void){
	panel.x = 0;
	panel.y = 0;
	panel.w = SCREEN_WIDTH;
	panel.h = GAME_UI_HEIGHT;
}

void showUI(void){
	SDL_SetRenderDrawColor(app.renderer, 25, 25, 25, 255);
	SDL_RenderFillRect(app.renderer, &panel);
	
	SDL_SetRenderDrawColor(app.renderer, 200, 200, 255, 255);
	SDL_RenderDrawLine(app.renderer, 0, panel.h, SCREEN_WIDTH, panel.h);
}