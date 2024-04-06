#include <SDL.h>
#include <stdio.h>
#include <string.h>

#include "defs.h"
#include "struct.h"

SDL_Texture *playerBulletSpt;

void initMatch(void){
	app.update = update;
	app.draw = draw;
	
	// start TAIL in same point of HEAD
	app.shipTail = &app.shipHead;
	app.projTail = &app.projHead;
	
	initPlayer();
	
	playerBulletSpt = loadImage("player_bullet");
}

static void update(void){
	doBullets();
	doPlayer();
}

static void draw(void){
	drawBullets();
	drawPlayer();
}

static void initPlayer(void){
	player = malloc(sizeof(struct Entity));
	memset(player, 0, sizeof(struct Entity));
	
	app.shipTail->next = player;
	app.shipTail = player;
	
	player->spt = loadImage("player");
	getDimensions(player, 2);
	
	player->x = (int)SCREEN_WIDTH  * 0.1;
	player->y = ((int)SCREEN_HEIGHT / 2) - player->dim / 2;
	player->spd = 4.0;
}

static int movePlayer(int nPos, int dir, int mm){
	nPos += player->spd * dir;
	
	if(mm != 0) return (nPos + player->dim <= mm ? nPos : mm - player->dim);
	
	return (nPos >= mm ? nPos : mm);
}

static void doPlayer(void){
	if(control.top) player->y = movePlayer(player->y, -1, 0);
	if(control.bel) player->y = movePlayer(player->y,  1, SCREEN_HEIGHT);
	if(control.lef) player->x = movePlayer(player->x, -1, 0);
	if(control.rig) player->x = movePlayer(player->x,  1, SCREEN_WIDTH);
	
	if(player->cooldown > 0) player->cooldown--;
	if(control.sht && player->cooldown == 0) shootPlayer();
}

static void shootPlayer(void){
	struct Entity *bullet;
	
	bullet = malloc(sizeof(struct Entity));
	memset(bullet, 0, sizeof(struct Entity));
	app.projTail->next = bullet;
	app.projTail = bullet;
	
	bullet->spt = playerBulletSpt;
	getDimensions(bullet, 2);
	
	// adjust the bullet origin based in if the player is moving
	short adjMoveX = 0, adjMoveY = 0;
	short key[4] = {control.top, control.bel, control.lef, control.rig};
	
	if(key[0] && !key[1]) adjMoveY = -player->spd;
	if(key[1] && !key[0]) adjMoveY =  player->spd;
	if(key[3] && !key[2]) adjMoveX =  player->spd;
	if(key[2] && !key[3]) adjMoveX = -player->spd;
	
	bullet->x  = player->x + (player->dim - bullet->dim) / 2 + adjMoveX;
	bullet->y  = player->y + (player->dim - bullet->dim) / 2 + adjMoveY;
	bullet->spd = 15;
	bullet->hp = 1;
	
	player->cooldown = 10;
}

static void drawPlayer(){
	sprite(player);
}

static void doBullets(void){
	struct Entity *b, *prev = &app.projHead;
	
	for(b = app.projHead.next; b != NULL; b = b->next){
		b->x += b->spd;
		
		if(b->x + b->dim > SCREEN_WIDTH){
			if(b == app.projTail) app.projTail = prev;
			
			prev->next = b->next;
			free(b);
			b = prev;
		}
		
		prev = b;
	}
}

static void drawBullets(){
	struct Entity *b;
	for(b = app.projHead.next; b != NULL; b = b->next) sprite(b);
}