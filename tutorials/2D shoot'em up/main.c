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
	player.spd = 4.0;
	player.spt = loadImage("player.png", &player, 2);
	
	int movePlayer(int nPos, int mm){
		if(mm != 0) return (nPos + player.dim <= mm ? nPos : mm - player.dim);
		return (nPos >= mm ? nPos : mm);
	}
	
	atexit(NULL);
	
	while(1){
		updateScene();
		doInput();
		
		//if((control.top || control.bel) && (control.lef || control.rig)) player.spd = 5.65; else player.spd = 4.0; // a^2 = 4^2 + 4^2
	
		if(control.top) player.y = movePlayer(player.y - player.spd, 0);
		if(control.bel) player.y = movePlayer(player.y + player.spd, SCREEN_HEIGHT);
		if(control.lef) player.x = movePlayer(player.x - player.spd, 0);
		if(control.rig) player.x = movePlayer(player.x + player.spd, SCREEN_WIDTH);
		
		sprite(&player);
		
		drawScene();
		
		// lock loop in ~62 (fps) tics/s
		SDL_Delay(16);
	}
	
	return 0;
}