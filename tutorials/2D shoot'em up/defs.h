#ifndef __DEFS
#define __DEFS

#include "struct.h"

///// GLOBAL /////
#define SCREEN_WIDTH  1080
#define SCREEN_HEIGHT 640

#define MIN(a, b) ({ \
	__typeof__ (a) _a = (a); \
	__typeof__ (b) _b = (b); \
	_a < _b ? _a : _b; \
})

#define MAX(a, b) ({ \
	__typeof__ (a) _a = (a); \
	__typeof__ (b) _b = (b); \
	_a > _b ? _a : _b; \
})


///// MAIN.C /////
static void initSDL(void);
static void lock60fps(long *then, float *remainder);



///// DRAW.C /////
// get/generator
SDL_Texture *loadImage(char *file);
void getDimensions(struct Entity *obj, short scale);

// draw
void sprite(struct Entity *obj);



///// INPUT.C /////
void doInput(void);
static void keyboard(SDL_KeyboardEvent *event, short down);



///// MATCH.C /////
// texture
extern SDL_Texture *enemySpt;
extern SDL_Texture *enemyBulletSpt;
extern SDL_Texture *playerBulletSpt;

// timers
extern unsigned int enemyCooldown;

// collision
static int aabb(struct Entity *bul, struct Entity *ship);
static int hitShip(struct Entity *bul);

// call all
static void update(void);
static void draw(void);

// start/spawn
void initMatch(void);
static void initPlayer(void);
static void enemiesSpawn(void);
static void shootPlayer(void);

// save memory
static int movePlayer(int nPos, int dir, int mm);
static void memAlloc(struct Entity **obj, short isShip);

// update
static void doPlayer(void);
static void doEnemies(void);
static void doBullets(void);

// draw
static void drawShips(void);
static void drawBullets(void);



///// END /////

#endif