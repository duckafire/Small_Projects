#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "defs.h"
#include "struct.h"

// texture (from: defs.h)
SDL_Texture* playerSpt       = loadImage("player");
SDL_Texture* enemySpt        = loadImage("enemy");
SDL_Texture* enemyBulletSpt  = loadImage("player_bullet");
SDL_Texture* playerBulletSpt = loadImage("enemy_bullet");
SDL_Texture* starSpt         = loadImage("star");
SDL_Texture* explosionSpt    = loadImage("explosion");

// timers (from: defs.h)
unsigned int enemyCooldown;

Star stars[500];

void initMatch(void){
	// random seed
	srand(time(NULL));
	
	// clear trash
	memset(&head, 0, sizeof(Head));
	memset(&tail, 0, sizeof(Tail));
	memset(&expl, 0, sizeof(Expl));
	memset(&debr, 0, sizeof(Debr));
	
	// add value to tails
	tail.ship = &head.ship;
	tail.bull = &head.bull;
	tail.expl = &head.expl;
	tail.debr = &head.debr;
	
	// load all player informations
	initPlayer();
	
	// create (new) stars
	initStar();
	
	// timer to create the first enemy
	enemyCooldown = 151 + rand() % 150;
}

void restartMatch(void){
	Ship *s;
	while(head.ship.next){
		s = head.ship.next;
		head.ship.next = s->next;
		free(s);
	}
	
	Bull *b;
	while(head.bull.next){
		b = head.bull.next;
		head.bull.next = b->next;
		free(b);
	}
	
	Expl *e;
	while(head.expl.next){
		e = head.expl.next;
		head.expl.next = e->next;
		free(e);
	}
	
	Debr *d;
	while(head.debr.next){
		d = head.debr.next;
		head.debr.next = d->next;
		free(d);
	}
	
	SDL_Delay(500); // 0.5s
	initMatch();
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
	if(control.sht && player->cooldown == 0) shootShip(player);
	
	// dead
	if(player->hp == 0) restartMatch();
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
		
		enemy->x        = SCREEN_WIDTH + rand() % 50;
		enemy->y        = rand() % (SCREEN_HEIGHT - enemy->dim);
		enemy->spd      = 3 + rand() % 5;
		enemy->maxHp    = rand() % 3 + 1;
		enemy->hp       = enemy->maxHp;
		enemy->isEnemy  = 1;
		enemy->cooldown = 15 + rand() % 30;
		
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
			
			// FIRE!
			if(--e->cooldown == 0) shootShip(e);
			
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


static void shootShip(Ship *ship){
	Bull *bullet;
	
	memAlloc(NULL, &bullet);
	
	// basic
	bullet->spt = (ship->isEnemy ? enemyBulletSpt : playerBulletSpt);
	getDimensions(NULL, bullet, 2);
	
	// adjust the bullet origin based in if the player is moving
	short adjMoveX = 0, adjMoveY = 0;
	
	if(!ship->isEnemy){
		short key[4] = {control.top, control.bel, control.lef, control.rig};
	
		if(key[0] && !key[1]) adjMoveY = -player->spd;
		if(key[1] && !key[0]) adjMoveY =  player->spd;
		if(key[3] && !key[2]) adjMoveX =  player->spd;
		if(key[2] && !key[3]) adjMoveX = -player->spd;
	}
	
	bullet->x  = ship->x + (ship->dim - bullet->dim) / 2 + adjMoveX;
	bullet->y  = ship->y + (ship->dim - bullet->dim) / 2 + adjMoveY;
	bullet->spd = (ship->isEnemy ? -16 : 16);
	bullet->isEnemy = ship->isEnemy;
	
	// reboot ship shoot cooldown
	ship->cooldown = (ship->isEnemy ? 15 + rand() % 30 : 10);
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

static void doStars(void){
	for(int i = 0; i < 500; i++){
		stars[i].x -= stars[i].spd;
		if(stars[i].x == 0) stars[i].x = SCREEN_WIDTH;
	}
}


static void doExplosion(void);
static void doDebris(void);


static void initStar(void){
	for(int i = 0; i < 500; i++){
		stars[i].x = rand() % SCREEN_WIDTH + 1;
		stars[i].y = rand() % SCREEN_HEIGHT + 1;
		start[i].spd = 1 + rand() % 10;
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

static void drawStars(void);
static void drawExplosion(void);
static void drawDebris(void);
