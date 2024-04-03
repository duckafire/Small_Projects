#include <string.h>
#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "struct.h"

int main(int argc, char *argv[]){
	// define a struct and clear (to 0) all spaces
	memset(&app, 0, sizeof(App));
	memset(&player, 0, sizeof(Entity));
	
	initSDL();
	
	player.x = 100;
	player.y = 100;
	player.sprite = loadImage("player.png");
	
	atexit(NULL);
	
	while(1){
		updateScene();
		doInput();
		
		sprite(player.sprite, player.x, player.y, 2);
		
		drawScene();
		
		// lock loop in ~62 (fps) tics/s
		SDL_Delay(16);
	}
	
	return 0;
}