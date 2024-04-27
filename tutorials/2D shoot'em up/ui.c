#include <SDL.h>
#include <SDL_ttf.h>
#include <string.h>

#include "defs.h"
#include "struct.h"

SDL_Rect panel;

void initUI(void){
	panel.x = 0;
	panel.y = 0;
	panel.w = SCREEN_WIDTH;
	panel.h = GAME_UI_HEIGHT;
	
	app.textColor.r = 216;
	app.textColor.g = 216;
	app.textColor.b = 216;
	app.textColor.a = 255;
	
	app.normalFont = TTF_OpenFont("../!Build/font/fff-forward.ttf", 25);
}

void showUI(void){
	SDL_SetRenderDrawColor(app.renderer, 25, 25, 25, 255);
	SDL_RenderFillRect(app.renderer, &panel);
	
	SDL_SetRenderDrawColor(app.renderer, 200, 200, 255, 255);
	SDL_RenderDrawLine(app.renderer, 0, panel.h, SCREEN_WIDTH, panel.h);
}

static void showText(short x, short y, char *text){
	memset(app.textSurface, 0, sizeof(app.textSurface));
	
	app.textSurface = TTF_RenderText_Solid(app.normalFont, text, app.textColor);
	SDL_Texture *msg = SDL_CreateTextureFromSurface(app.renderer, app.textSurface);
	
	SDL_Rect rect = {10, 10, 100, 100};
	SDL_RenderCopy(app.renderer, msg, NULL, &rect);
	
	SDL_DestroyTexture(msg);
}