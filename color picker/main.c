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

	SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
	SDL_RenderClear(renderer);
	
	unsigned short curRed = 255;
	unsigned short curGreen = 255;
	unsigned short curBlue = 255;
	
	for(int x = 0; x < 256; x++){
		for(int y = 0; y < 256; y++){
			SDL_SetRenderDrawColor(renderer, curRed, curGreen, curBlue, 255);
			SDL_RenderDrawPoint(renderer, x, y);
			if(curRed   > 0) curRed--;
			if(curGreen > 0) curGreen--;
			if(curBlue  > 0) curBlue--;
		}
		
		curRed = 255;
		curGreen = 255;
		curBlue = 255;
	}
	
	SDL_RenderPresent(renderer);

	SDL_Delay(10000);
	
	return 0;
}