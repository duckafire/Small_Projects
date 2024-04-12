#include <string.h>
#include <SDL.h>
#include <SDL_image.h>

#include "struct.h"
#include "defs.h"

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

void getDimensions(Ship *ship, Bull *bull, short scale){
	// get information about sprite (image)
	// resize sprite
	
	if(ship != NULL){
		SDL_QueryTexture(ship->spt, NULL, NULL, &(ship->dim), NULL);
		ship->dim *= scale;
	
	}else{
		SDL_QueryTexture(bull->spt, NULL, NULL, &(bull->dim), NULL);
		bull->dim *= scale;
	}
}

void sprite(Ship *ship, Bull *bull){
	// SDLRect: type of 4th parameter of "SDL_RenderCoyp"
	// add image to "renderer buffer"
	
	if(ship != NULL){
		SDL_Rect body = {ship->x, ship->y, ship->dim, ship->dim};
		SDL_RenderCopy(app.renderer, ship->spt, NULL, &body);
	
	}else{
		SDL_Rect body = {bull->x, bull->y, bull->dim, bull->dim};
		SDL_RenderCopy(app.renderer, bull->spt, NULL, &body);
	}
}

void explSprite(float x, float y, SDL_Texture *spt, SDL_Rect *rect){
	SDL_Rect body = {x, y, rect->w, rect->h};
	SDL_RenderCopy(app.renderer, spt, rect, &body); // draw a image piece
}