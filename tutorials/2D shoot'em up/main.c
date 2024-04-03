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
		
		if(app.dirY == -1 && player.y > 0){
			player.y -= 4;
		}else if(app.dirY == 1 && player.y < SCREEN_HEIGHT){
			player.y += 4;
		}
		
		if(app.dirX == -1 && player.x > 0){
			player.x -= 4;
		}else if(app.dirX == 1 && player.x < SCREEN_WIDTH){
			player.x += 4;
		}
		
		sprite(player.sprite, player.x, player.y, 2);
		
		drawScene();
		
		// lock loop in ~62 (fps) tics/s
		SDL_Delay(16);
	}
	
	return 0;
}