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

void sprite(SDL_Texture *spt, float x, float y, unsigned int dim){
	// SDLRect: type of 4th parameter of "SDL_RenderCoyp"
	SDL_Rect body = {x, y, dim, dim};
	
	// add image to "renderer buffer"
	SDL_RenderCopy(app.renderer, spt, NULL, &body);
}

void debrSprite(Debr *debr){
	SDL_Rect body = {debr->x, debr->y, debr->rect.w, debr->rect.h};
	
	// buffer, texture, texture piece (NULL = full), local in window to render the texture
	SDL_RenderCopy(app.renderer, debr->spt, &debr->rect, &body); // draw a image piece
}

