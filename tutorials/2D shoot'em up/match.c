#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "defs.h"
#include "struct.h"

// texture (from: defs.h)
SDL_Texture *enemySpt;
SDL_Texture *enemyBulletSpt;
SDL_Texture *playerBulletSpt;

// timers (from: defs.h)
unsigned int enemyCooldown;

void initMatch(void){
	// random seed
	srand(time(NULL));
	
	// references
	app.update = update;
	app.draw = draw;
	
	// start TAIL in same point of HEAD
	app.shipTail = &app.shipHead;
	app.projTail = &app.projHead;
	
	// load all player informations
	initPlayer();
	
	// load sprite to entities that will spawn in bigger quantity, to save memory (ram) and cpu
	enemySpt        = loadImage("enemy");
	enemyBulletSpt  = loadImage("enemy_bullet");
	playerBulletSpt = loadImage("player_bullet");
	
	// timer to create the first enemy
	enemyCooldown = 151 + rand() % 150;
}

static void update(void){
	doBullets();
	doEnemies();
	doPlayer();
	enemiesSpawn();
}

static void draw(void){
	drawBullets();
	drawShips();
}


static void memAlloc(struct Entity **obj, short isShip){
	// alloc space in memory to the adress of the pointer used like argument
	*obj = malloc(sizeof(struct Entity));
	
	// clear memory trash in space allocated
	memset(*obj, 0, sizeof(struct Entity));
	
	// update the last object pointed by TAIL (1th is HEAD)
	// update TAIL value (adress)
	if(isShip){
		app.shipTail->next = *obj;
		app.shipTail = *obj;
		
	}else{
		app.projTail->next = *obj;
		app.projTail = *obj;	
	}
}

static int movePlayer(int nPos, int dir, int mm){
	// update parameter value
	nPos += player->spd * dir;
	
	// lessing position (top or left)
	if(mm != 0) return (nPos + player->dim <= mm ? nPos : mm - player->dim);
	
	// adding position (below or right)
	return (nPos >= mm ? nPos : mm);
}


static void initPlayer(void){
	memAlloc(&player, 1);
	
	// basic
	player->spt = loadImage("player");
	getDimensions(player, 2);
	
	player->x = (int)SCREEN_WIDTH  * 0.1;
	player->y = ((int)SCREEN_HEIGHT / 2) - player->dim / 2;
	player->spd = 4.0;
}

static void doPlayer(void){
	// moviment
	if(control.top) player->y = movePlayer(player->y, -1, 0);
	if(control.bel) player->y = movePlayer(player->y,  1, SCREEN_HEIGHT);
	if(control.lef) player->x = movePlayer(player->x, -1, 0);
	if(control.rig) player->x = movePlayer(player->x,  1, SCREEN_WIDTH);
	
	// shoot cooldown and shoot
	if(player->cooldown > 0) player->cooldown--;
	if(control.sht && player->cooldown == 0) shootPlayer();
}


static void enemiesSpawn(void){
	// less enemy cooldown
	if(enemyCooldown > 0) enemyCooldown--;
	
	if(enemyCooldown == 0){
		struct Entity *enemy;
		memAlloc(&enemy, 1);
		
		// basic
		enemy->spt = enemySpt;
		getDimensions(enemy, 2);
		
		enemy->x   = SCREEN_WIDTH + rand() % 50;
		enemy->y   = rand() % (SCREEN_HEIGHT - enemy->dim);
		enemy->spd = 3 + rand() % 5;
		enemy->hp  = rand() % 3 + 1;
		
		// reboot enemy cooldown
		enemyCooldown = 61 + rand() % 180;
	}
}

static void doEnemies(void){
	struct Entity *e, *prev = &app.shipHead;
	
	// load all ships (pointer addition)
	for(e = app.shipHead.next; e != NULL; e = e->next){
		// only enemies
		if(e != player){
			
			// moviment (horizontal)
			e->x -= e->spd;
		
			// out of screen (width: <0), destroy enemy
			if(e->x < (signed)-e->dim){		
				if(e == app.shipTail) app.shipTail = prev;
				
				// enemy: last, curr, futu
				// last.nest = curr.next (futu)
				prev->next = e->next;
				free(e);
				e = prev;
			}
			
		}
		// next object
		prev = e;
		// it will not changed if the condition in top happen
	}
}


static void shootPlayer(void){
	struct Entity *bullet;
	
	memAlloc(&bullet, 0);
	
	// basic
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
	
	// reboot player shoot cooldown
	player->cooldown = 10;
}

static void doBullets(void){
	struct Entity *b, *prev = &app.projHead;
	
	// load all ships (pointer addition)
	for(b = app.projHead.next; b != NULL; b = b->next){
		// moviment (horizontal)
		b->x += b->spd;
		
		// out of screen (width: max>), destroy enemy
		if(b->x + b->dim > SCREEN_WIDTH){
			if(b == app.projTail) app.projTail = prev;
			
			// bullet: last, curr, futu
			// last.nest = curr.next (futu)
			prev->next = b->next;
			free(b);
			b = prev;
		}
		
		// next object
		prev = b;
		// it will not changed if the condition in top happen
	}
}


static void drawShips(){
	// draw all player and enemies
	struct Entity *e;
	for(e = app.shipHead.next; e != NULL; e = e->next) sprite(e);
}

static void drawBullets(){
	// draw player and enemies bullet
	struct Entity *b;
	for(b = app.projHead.next; b != NULL; b = b->next) sprite(b);
}

