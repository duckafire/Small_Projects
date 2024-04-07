#include <string.h>
#include <SDL.h>
#include <SDL_image.h>

#include "struct.h"
#include "defs.h"

// "RENDERER BUFFER" (backbuffer) -> its store all pixels of the window.

void backScene(void){
	// color to fill "renderer buffer"
	SDL_SetRenderDrawColor(app.renderer, 50, 50, 50, 255);

	// restart the "renderer buffer" filling it with the color above (clear it)
	SDL_RenderClear(app.renderer);
}

void frontScene(void){
	// show the "renderer buffer", after add the elements to screen
	SDL_RenderPresent(app.renderer);
}

SDL_Texture *loadImage(char *file){
	char path[30]; // 17 = reservad size; 12 = maximum file name
	memset(path, '\0', 30);
	
	// add path and extension to file name
	strcpy(path, "img/shoot-em_up/");
	strcat(path, file);
	strcat(path, ".png");
	
	// object texture
	return IMG_LoadTexture(app.renderer, path);
}

void getDimensions(struct Entity *obj, short scale){
	// get information about sprite (image)
	SDL_QueryTexture(obj->spt, NULL, NULL, &(obj->dim), NULL);
	
	// resize sprite
	obj->dim *= scale;
}

void sprite(struct Entity *obj){
	// type of 4th parameter of "SDL_RenderCoyp"
	SDL_Rect body = {obj->x, obj->y, obj->dim, obj->dim};
	
	// add image to "renderer buffer"
	SDL_RenderCopy(app.renderer, obj->spt, NULL, &body);
}

