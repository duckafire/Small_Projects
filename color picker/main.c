#include <SDL.h>
#include "main.h"

int main(int argc, char *argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_DisplayMode desktop;
	SDL_Window     *window;
	SDL_Renderer   *renderer;
	
	SDL_GetDesktopDisplayMode(0, &desktop);
	window   = SDL_CreateWindow("Color Picker", (desktop.w - SCREEN_DIM) / 2, (desktop.h - SCREEN_DIM) / 2, SCREEN_DIM, SCREEN_DIM, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
	SDL_RenderClear(renderer);
	
	unsigned short curRed = 255;
	unsigned short curGreen = 255;
	unsigned short curBlue = 255;
	unsigned short curAlpha = 255;
	
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	
	curRed = 255;
	curGreen = 0;
	curBlue = 0;
	
	// current color
	SDL_SetRenderDrawColor(renderer, curRed, curGreen, curBlue, 255);
	SDL_Rect square = {0, 0, 255, 255};
	SDL_RenderFillRect(renderer, &square);
	
	curRed = 255;
	curGreen = 255;
	curBlue = 255;
	
	// white
	for(int i = 0; i < 128; i++){
		SDL_SetRenderDrawColor(renderer, curRed, curGreen, curBlue, curAlpha);
		SDL_RenderDrawLine(renderer, i, 0, i, 255);
		
		if(curRed   > 0) curRed--;
		if(curGreen > 0) curGreen--;
		if(curBlue  > 0) curBlue--;
		if(curAlpha > 0) curAlpha -= 2;
	}
	
	curRed = 0;
	curGreen = 0;
	curBlue = 0;
	curAlpha = 255;
	
	// black
	for(int i = 255; i > 128; i--){
		SDL_SetRenderDrawColor(renderer, curRed, curGreen, curBlue, curAlpha);
		SDL_RenderDrawLine(renderer, 0, i, 255, i);
		
		if(curRed   < 255) curRed += 0.5;
		if(curGreen < 255) curGreen += 0.5;
		if(curBlue  < 255) curBlue += 0.5;
		if(curAlpha > 0) curAlpha -= 2;
	}
	
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
	
	SDL_RenderPresent(renderer);

	SDL_Delay(10000);
	
	return 0;
}