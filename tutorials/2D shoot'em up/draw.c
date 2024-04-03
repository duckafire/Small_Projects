#include <string.h>
#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "struct.h"

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

SDL_Texture *loadImage(char *file){
	char path[30]; // 17 -> path
	memset(path, '\0', 30);
	
	strcpy(path, "img/shoot-em_up/");
	strcat(path, file);
	
	return IMG_LoadTexture(app.renderer, path);
}

void sprite(SDL_Texture *img, int x, int y, int scale){
	// a structure with: x, y, w(idth), h(eight)
	SDL_Rect obj;
	obj.x = x;
	obj.y = y;
	
	// get image width and height
	SDL_QueryTexture(img, NULL, NULL, &obj.w, &obj.h);
	obj.w *= scale;
	obj.h *= scale;
	
	// renderer image
	SDL_RenderCopy(app.renderer, img, NULL, &obj);
}