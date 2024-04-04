#ifndef __DEFS
#define __DEFS

#include "struct.h"

#define SCREEN_WIDTH  1080
#define SCREEN_HEIGHT 640

// draw.c
void updateScene(void);
void drawScene(void);
SDL_Texture *loadImage(char *file, Entity *obj, int scale);
void sprite(Entity *obj);

// init.c and input.c
void initSDL(void);
void doInput(void);

#endif