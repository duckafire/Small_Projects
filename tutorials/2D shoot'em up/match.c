#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "defs.h"
#include "struct.h"

// texture (from: defs.h)
SDL_Texture *playerSpt;
SDL_Texture *enemySpt;
SDL_Texture *playerBulletSpt;
SDL_Texture *enemyBulletSpt;
SDL_Texture *explosionSpt;

// timers (from: defs.h)
unsigned int enemyCooldown;

// background stars
Star stars[500];
unsigned short explosionScale[6] = {4, 8, 16, 24, 32, 40};

void initMatch(short loadImg){
	// random seed
	srand(time(NULL));
	
	// clear trash
	memset(&head, 0, sizeof(Head));
	memset(&tail, 0, sizeof(Tail));
	
	// add value to tails
	tail.ship = &head.ship;
	tail.bull = &head.bull;
	tail.expl = &head.expl;
	tail.debr = &head.debr;
	
	if(loadImg == 1){
		playerSpt       = loadImage("player");
		enemySpt        = loadImage("enemy");
		playerBulletSpt = loadImage("player_bullet");
		enemyBulletSpt  = loadImage("enemy_bullet");
		explosionSpt    = loadImage("explosion");
	}
	
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
	initMatch(0);
}

void updateMatch(void){
	doStars();
	doBullets();
	doEnemies();
	doPlayer();
	enemiesSpawn();
	doExplosion();
	doDebris();
}

void drawMatch(void){
	drawBullets();
	drawShips();
	drawDebris();
	drawExplosions();
}


static void initPlayer(void){
	player = malloc(sizeof(Ship));
	memset(player, 0, sizeof(Ship));
	tail.ship->next = player;
	tail.ship = player;

	
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
		enemy = malloc(sizeof(Ship));
		memset(enemy, 0, sizeof(Ship));
		tail.ship->next = enemy;
		tail.ship = enemy;

		// basic
		enemy->spt = enemySpt;
		getDimensions(enemy, NULL, 2);
		
		enemy->x        = SCREEN_WIDTH + rand() % 50;
		enemy->y        = rand() % (SCREEN_HEIGHT - enemy->dim);
		enemy->spd      = 1 + rand() % 6;
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
				if(e->hp == 0) newExplosion(e->x, e->y, rand() % 5 + 4);
				
				if(e == tail.ship) tail.ship = prev;
				
				// enemy: past, curr, futu
				// past.next = curr.next (-> futu)
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


static void initStar(void){
	for(int i = 0; i < 500; i++){
		stars[i].x = rand() % SCREEN_WIDTH + 1;
		stars[i].y = rand() % SCREEN_HEIGHT + 1;
		stars[i].spd = 1 + rand() % 10;
	}
}

void newExplosion(int x, int y, int max){
	Expl *explosion;
	
	for(int i = 0; i < max; i++){
		explosion = malloc(sizeof(Expl));
		memset(explosion, 0, sizeof(Expl));
		tail.expl->next = explosion;
		tail.expl = explosion;

		explosion->x   = x + 5 + rand() % 22;
		explosion->y   = y + 5 + rand() % 22;
		explosion->sx  = ((rand() % 5 + 7) / 10) * (rand() % 2 == 1 ? 1 : -1);
		explosion->sy  = ((rand() % 5 + 7) / 10) * (rand() % 2 == 1 ? 1 : -1);
		explosion->dim = explosionScale[rand() % 5];
		
		// RBGA
		switch(rand() % 3){
			case 0: explosion->g = 0;   break;
			case 1: explosion->g = 117; break;
			case 2: explosion->g = 234; break;
		}
		explosion->r = 234;
		explosion->b = 0;
		explosion->a = FPS * (rand() % 3 + 1);
	}
}

void newDebris(Ship *e){
	Debr *debris;
	int w = e->dim / 2, h = e->dim / 2;

	for(int y = 0; y <= h; y += h){
		for(int x = 0; x <= w; x += w){
			debris = malloc(sizeof(Debr));
			memset(debris, 0, sizeof(Debr));
			tail.debr->next = debris;
			tail.debr = debris;
			
			debris->x   = e->x + w;
			debris->y   = e->y + h;
			debris->sx  = (rand() % 5) - (rand() % 5);
			debris->sy  = (rand() % 5) - (rand() % 5);
			debris->spt = explosionSpt;
			debris->destroyed = FPS * 2;
			
			debris->rect.x = x;
			debris->rect.y = y;
			debris->rect.w = w;
			debris->rect.h = h;
		}
	}
}


static void shootShip(Ship *ship){
	Bull *bullet;
	bullet = malloc(sizeof(Bull));
	memset(bullet, 0, sizeof(Bull));
	tail.bull->next = bullet;
	tail.bull = bullet;

	
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
	ship->cooldown = (ship->isEnemy ? 30 + rand() % 90 : 10);
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
		if(stars[i].x < -5) stars[i].x = SCREEN_WIDTH;
	}
}

static void doExplosion(void){
	Expl *e, *prev = &head.expl;
	
	for(e = head.expl.next; e != NULL; e = e->next){
		e->x += e->sx;
		e->y += e->sy;
		e->a -= 4;
		
		// opacity/alpha
		if(e->a <= 0){
			if(e == tail.expl) tail.expl = prev;
			prev->next = e->next;
			free(e);
			e = prev;
		}
		
		prev = e;
	}
}

static void doDebris(void){
	Debr *d, *prev = &head.debr;
	
	for(d = head.debr.next; d != NULL; d = d->next){
		d->x  += d->sx;
		d->y  += d->sy;
		
		if(d->sx > 0.5) d->sx -= 0.5;
		if(d->sy > 0.5) d->sy -= 0.5;
		
		if(--d->destroyed){
			if(d == tail.debr) tail.debr = prev;
			prev->next = d->next;
			free(d);
			d = prev;
		}
		
		prev = d;
	}
}


static void drawShips(){
	// draw all player and enemies
	Ship *e;
	for(e = head.ship.next; e != NULL; e = e->next){
		e->lifebar.x = e->x;
		e->lifebar.y = e->y - 8;
		
		// lifebar backgound
		e->lifebar.w = e->maxHp * (e->dim / e->maxHp);
		SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(app.renderer, &(e->lifebar));
	
		// lifebar health
		e->lifebar.w = e->hp * (e->dim / e->maxHp);
		SDL_SetRenderDrawColor(app.renderer, 199, 0, 0, 255);
		SDL_RenderFillRect(app.renderer, &(e->lifebar));
		
		// ship sprite
		sprite(e->spt, e->x, e->y, e->dim);
	}
}

static void drawBullets(){
	// draw player and enemies bullet
	Bull *b;
	for(b = head.bull.next; b != NULL; b = b->next) sprite(b->spt, b->x, b->y, b->dim);
}

static void drawStars(void){
	int c;
	for(int i = 0; i < 500; i++){
		c = 32 * stars[i].spd;
		SDL_SetRenderDrawColor(app.renderer, c, c, c, 255);
		SDL_RenderDrawLine(app.renderer, stars[i].x, stars[i].y, stars[i].x + 3, stars[i].y);
	}
}

static void drawExplosions(void){
	Expl *e;
	
	SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_ADD);
	SDL_SetTextureBlendMode(explosionSpt, SDL_BLENDMODE_ADD);

	for(e = head.expl.next; e != NULL; e = e->next){
		SDL_SetTextureColorMod(explosionSpt, e->r, e->g, e->b);
		SDL_SetTextureAlphaMod(explosionSpt, e->a);
		sprite(explosionSpt, e->x, e->y, e->dim);
	}
	
	SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_NONE);
}

static void drawDebris(void){
	Debr *d;
	for(d = head.debr.next; d != NULL; d = d->next) debrSprite(d);
}

