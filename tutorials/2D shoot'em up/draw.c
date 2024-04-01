#include <string.h>
#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "struct.h"

SDL_Texture *loadImage(char *file){ return IMG_LoadTexture(app.renderer, file); }

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

void draw(SDL_Texture *img, int x, int y){
	// a structure with: x, y, w(idth), h(eight)
	SDL_Rect obj;
	obj.x = x;
	obj.y = y;
	
	// get image width and height
	SDL_QueryTexture(img, NULL, NULL, &obj.w, &obj.h);
	
	// renderer image
	SDL_RenderCopy(app.renderer, img, NULL, &obj);
}