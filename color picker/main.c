#include <SDL.h>
#include <stdio.h>
#include "main.h"

SDL_Window     *window;
SDL_Renderer   *renderer;

int main(int argc, char *argv[]){
	SDL_Init(SDL_INIT_VIDEO);
			
	SDL_DisplayMode desktop;
	SDL_GetDesktopDisplayMode(0, &desktop);
	
	window   = SDL_CreateWindow("Color Picker", (desktop.w - SCREEN_DIM) / 2, (desktop.h - SCREEN_DIM) / 2, SCREEN_DIM, SCREEN_DIM, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
	SDL_RenderClear(renderer);
	
	/////
	square(255, 0, 0);
	bar();
	/////
	
	SDL_RenderPresent(renderer);

	SDL_Delay(10000);
	
	return 0;
}

void square(float r, float g, float b){
	boards(4, 4, 268, 268, 7, 7, 262, 262);
	
	float rDelta = (255.0 - r) / 255.0;
	float gDelta = (255.0 - g) / 255.0;
	float bDelta = (255.0 - b) / 255.0;
	
	float red   = 255.0;
	float green = 255.0;
	float blue  = 255.0;
	
	for(int y = 0; y < 256; y++){
		for(int x = 0; x < 256; x++){
			SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
			SDL_RenderDrawPoint(renderer, 10 + x, 10 + y);
			
			if(red   > 0.0) red   -= rDelta;
			if(green > 0.0) green -= gDelta;
			if(blue  > 0.0) blue  -= bDelta;
		}
		
		red = green = blue = 255.0 - 1.0 - y;
	}
}

void bar(){
	boards(290, 4, 38, 268, 293, 7, 32, 262);
	
	for(int y = 10; y < 266; y++){
		SDL_SetRenderDrawColor(renderer, 216, 100, 100, 255);
		SDL_RenderDrawLine(renderer, 296, y, 321, y);
	}
}

void boards(short x1, short y1, short w1, short h1, short x2, short y2, short w2, short h2){
	SDL_Rect rect;
	
	// white
	rect.x = x1; 
	rect.y = y1; 
	rect.w = w1; 
	rect.h = h1; 
	
	SDL_SetRenderDrawColor(renderer, 234, 234, 234, 255);
	SDL_RenderFillRect(renderer, &rect);
	
	// black
	rect.x = x2; 
	rect.y = y2; 
	rect.w = w2; 
	rect.h = h2;
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
}

