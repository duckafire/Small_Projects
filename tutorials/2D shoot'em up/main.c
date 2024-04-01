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
	player.sprite = loadImage("img/shoot-em_up/player.png");
	
	atexit(NULL);
	
	while(1){
		updateScene();
		doInput();
		
		draw(player.sprite, player.x, player.y);
		
		drawScene();
		
		// lock loop in ~62 (fps) tics/s
		SDL_Delay(16);
	}
	
	return 0;
}