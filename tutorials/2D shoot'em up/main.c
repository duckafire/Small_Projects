#include <string.h>
#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"
#include "struct.h"

int main(int argc, char *argv[]){
	// define a struct and clear (to 0) all spaces
	memset(&app,    0, sizeof(App));
	memset(&player, 0, sizeof(Entity));
	memset(&bullet, 0, sizeof(Entity));
	
	initSDL();
	
	player.x = (int)SCREEN_WIDTH  * 0.1;
	player.y = ((int)SCREEN_HEIGHT / 2) - player.dim / 2;
	player.spd = 4.0;
	player.spt = loadImage("player", &player, 2);
	
	bullet.spd = 15;
	bullet.spt = loadImage("player_bullet", &bullet, 2);
	
	int movePlayer(int nPos, int mm){
		if(mm != 0) return (nPos + player.dim <= mm ? nPos : mm - player.dim);
		return (nPos >= mm ? nPos : mm);
	}
	
	atexit(NULL);
	
	while(1){
		updateScene();
		doInput();
		
		if(control.top) player.y = movePlayer(player.y - player.spd, 0);
		if(control.bel) player.y = movePlayer(player.y + player.spd, SCREEN_HEIGHT);
		if(control.lef) player.x = movePlayer(player.x - player.spd, 0);
		if(control.rig) player.x = movePlayer(player.x + player.spd, SCREEN_WIDTH);
		
		if(control.fire && bullet.hp == 0){
			bullet.x  = player.x + (player.dim - bullet.dim) / 2;
			bullet.y  = player.y + (player.dim - bullet.dim) / 2;
			bullet.hp = 1;
		}
		
		if(bullet.x + bullet.dim > SCREEN_WIDTH) bullet.hp = 0;
		
		bullet.x += bullet.spd;
		
		if(bullet.hp) sprite(&bullet);
		sprite(&player);
		
		drawScene();
		
		// lock loop in ~62 (fps) tics/s
		SDL_Delay(16);
	}
	
	return 0;
}