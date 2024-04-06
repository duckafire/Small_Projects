#include <string.h>
#include <SDL.h>
#include <SDL_image.h>

#include "struct.h"
#include "defs.h"

void lastScene(void){
	// background color (RGBA)
	SDL_SetRenderDrawColor(app.renderer, 50, 50, 50, 255);

	// clear "scene"
	SDL_RenderClear(app.renderer);
}

void currentScene(void){
	// draw new frame
	SDL_RenderPresent(app.renderer);
}

SDL_Texture *loadImage(char *file){
	char path[30]; // 17 -> path
	memset(path, '\0', 30);
	
	strcpy(path, "img/shoot-em_up/");
	strcat(path, file);
	strcat(path, ".png");
	
	return IMG_LoadTexture(app.renderer, path);
}

void getDimensions(struct Entity *obj, int scale){
	SDL_QueryTexture(obj->spt, NULL, NULL, &(obj->dim), NULL);
	obj->dim *= scale;
}

void sprite(struct Entity *obj){
	SDL_Rect body = {obj->x, obj->y, obj->dim, obj->dim};
	// renderer image
	SDL_RenderCopy(app.renderer, obj->spt, NULL, &body);
}
