#include <string.h>
#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "struct.h"

const SDL_Texture playerBulletSpt = loadImage("player_bullet");
const SDL_Texture enemyBulletSpt  = loadImage("enemy_bullet");

int main(int argc, char *argv[]){
	// define a struct and clear (to 0) all spaces
	memset(&app, 0, sizeof(App));
	
	initSDL();
	
	atexit(NULL);
	
	initMatch();
	
	long then = SDL_GetTicks();
	float remainder = 0;
	
	while(1){
		updateScene();
		doInput();
		app.update();
		app.draw();
		drawScene();
		lock60fps(&then, &remainder);
	}
	
	return 0;
}

static void lock60fps(long *then, float *remainder){
	long wait = 16 * *remainder;
	long frameTime = SDL_GetTicks() - *then;
	
	*remainder -= (int)*remainder;
	
	wait -= frameTime;
	
	if(wait < 1) wait = 1;
	
	SDL_Delay(wait);
	
	*remainder += 0.667;
	*then = SDL_GetTicks();
}