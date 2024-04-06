#include <SDL.h>
#include <stdio.h>
#include <string.h>

#include "defs.h"
#include "struct.h"

SDL_Texture *playerBulletSpt;

void initMatch(void){
	app.update = update;
	app.draw = draw;
	
	app.shipTail = &app.shipHead;
	app.projTail = &app.projHead;
	
	initPlayer();
}

static void update(void){
	doPlayer();
	doBullets();
}

static void draw(void){
	drawPlayer();
	drawBullets();
}

static void initPlayer(void){
	player = malloc(sizeof(struct Entity));
	memset(player, 0, sizeof(struct Entity));
	
	playerBulletSpt = loadImage("player_bullet", player, 2);

	app.shipTail->next = player;
	app.shipTail = player;
	
	player->x = (int)SCREEN_WIDTH  * 0.1;
	player->y = ((int)SCREEN_HEIGHT / 2) - player->dim / 2;
	player->spd = 4.0;
	player->spt = loadImage("player", player, 2);
}

static int movePlayer(int nPos, int mm){
	if(mm != 0) return (nPos + player->dim <= mm ? nPos : mm - player->dim);
	return (nPos >= mm ? nPos : mm);
}

static void doPlayer(void){
	if(control.top) player->y = movePlayer(player->y - player->spd, 0);
	if(control.bel) player->y = movePlayer(player->y + player->spd, SCREEN_HEIGHT);
	if(control.lef) player->x = movePlayer(player->x - player->spd, 0);
	if(control.rig) player->x = movePlayer(player->x + player->spd, SCREEN_WIDTH);
	
	if(control.fire && player->cooldown == 0) shootPlayer();
}

static void shootPlayer(void){
	struct Entity *bullet;
	
	bullet = malloc(sizeof(struct Entity));
	memset(bullet, 0, sizeof(struct Entity));
	app.projTail->next = bullet;
	app.projTail = bullet;

	bullet->x  = player->x + (player->dim - bullet->dim) / 2;
	bullet->y  = player->y + (player->dim - bullet->dim) / 2;
	bullet->spd = 15;
	bullet->hp = 1;
	bullet->spt = playerBulletSpt;

	player->cooldown = 10;
}

static void drawPlayer(){
	sprite(player);
}

static void doBullets(void){
	struct Entity *b, *prev;
	
	for(b = app.projHead.next; b != NULL; b = b->next){
		b->x += b->spd;
		b->y += b->spd;
		
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