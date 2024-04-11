#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "defs.h"
#include "struct.h"

// texture (from: defs.h)
SDL_Texture *playerSpt;
SDL_Texture *enemySpt;
SDL_Texture *enemyBulletSpt;
SDL_Texture *playerBulletSpt;

// timers (from: defs.h)
unsigned int enemyCooldown;

void initMatch(void){
	// random seed
	srand(time(NULL));
	
	// start TAIL in same point of HEAD
	tail.ship = &head.ship;
	tail.bull = &head.bull;

	// load sprite to entities that will spawn in bigger quantity, to save memory (ram) and cpu
	playerSpt       = loadImage("player");
	enemySpt        = loadImage("enemy");
	enemyBulletSpt  = loadImage("enemy_bullet");
	playerBulletSpt = loadImage("player_bullet");
	
	// load all player informations
	initPlayer();
	
	// timer to create the first enemy
	enemyCooldown = 151 + rand() % 150;
}

void updateMatch(void){
	doBullets();
	doEnemies();
	doPlayer();
	enemiesSpawn();
}

void drawMatch(void){
	drawBullets();
	drawShips();
}


static void initPlayer(void){
	memAlloc(&player, NULL);
	
	// basic
	player->spt = playerSpt;
	getDimensions(player, NULL, 2);
	
	player->x = (int)SCREEN_WIDTH  * 0.1;
	player->y = ((int)SCREEN_HEIGHT / 2) - player->dim / 2;
	player->spd = 4.0;
	player->isEnemy = 0;
	player->maxHp = 5;
	player->hp = player->maxHp;
		
	setLifebar(player);
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
		Ship *enemy;
		memAlloc(&enemy, NULL);
		
		// basic
		enemy->spt = enemySpt;
		getDimensions(enemy, NULL, 2);
		
		enemy->x       = SCREEN_WIDTH + rand() % 50;
		enemy->y       = rand() % (SCREEN_HEIGHT - enemy->dim);
		enemy->spd     = 3 + rand() % 5;
		enemy->maxHp   = rand() % 3 + 1;
		enemy->hp      = enemy->maxHp;
		enemy->isEnemy = 1;
		
		setLifebar(enemy);
		
		// reboot enemy cooldown
		enemyCooldown = 61 + rand() % 180;
	}
}

static void doEnemies(void){
	Ship *e, *prev = &head.ship;
	
	// load all ships (pointer addition)
	for(e = head.ship.next; e != NULL; e = e->next){
		// only enemies
		if(e != player){
			
			// moviment (horizontal)
			e->x -= e->spd;
		
			// out of screen (width: <0), destroy enemy
			if(e->x < (signed)-e->dim || e->hp == 0){		
				if(e == tail.ship) tail.ship = prev;
				
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
	Bull *bullet;
	
	memAlloc(NULL, &bullet);
	
	// basic
	bullet->spt = playerBulletSpt;
	getDimensions(NULL, bullet, 2);
	
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
	bullet->isEnemy = 0;
	
	// reboot player shoot cooldown
	player->cooldown = 10;
}

static void doBullets(void){
	Bull *b, *prev = &head.bull;
	
	// load all ships (pointer addition)
	for(b = head.bull.next; b != NULL; b = b->next){
		// moviment (horizontal)
		b->x += b->spd;
		
		// out of screen (width: max>), destroy enemy
		if(hitShip(b) || b->x + b->dim > SCREEN_WIDTH){
			if(b == tail.bull) tail.bull = prev;
			
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
	Ship *e;
	for(e = head.ship.next; e != NULL; e = e->next){
		// lifebar
		e->lifebar.w = e->dim;
		SDL_RenderFillRect(app.shapeRed, &(e->lifebar));
		// e->lifebar.w = e->hp * (e->lifebar.w / e->maxHp);
		// SDL_RenderFillRect((e == player ? app.shapeGreen : app.shapeRed), &(e->lifebar));
		
		// ship sprite
		sprite(e, NULL);
	}
}

static void drawBullets(){
	// draw player and enemies bullet
	Bull *b;
	for(b = head.bull.next; b != NULL; b = b->next) sprite(NULL, b);
}

