#ifndef __DEFS
#define __DEFS

#include "struct.h"

#define SCREEN_WIDTH  1080
#define SCREEN_HEIGHT 640

// main.c
extern SDL_Texture *playerBulletSpt;
static void lock60fps(long *then, float *remainder);

// draw.c
void lastScene(void);
void currentScene(void);
SDL_Texture *loadImage(char *file, struct Entity *obj, int scale);
void sprite(struct Entity *obj);

// init.c and input.c
void initSDL(void);
void doInput(void);

// match.c
void initMatch(void);
static void update(void);
static void draw();

static void initPlayer(void);
static int movePlayer(int nPos, int mm);
static void doPlayer(void);
static void shootPlayer(void);
static void drawPlayer();

static void doBullets(void);
static void drawBullets();

#endif