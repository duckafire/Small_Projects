#ifndef __STRUCT
#define __STRUCT

typedef struct{
	SDL_Renderer *renderer;
	SDL_Window   *window;
} App;

typedef struct{
	// dim -> dimension (width == height)
	unsigned int x, y, dim, hp;
	float spd;
	SDL_Texture *spt;
} Entity;

typedef struct{
	unsigned short top;
	unsigned short bel;
	unsigned short lef;
	unsigned short rig;
	unsigned short fire;
} Control;

App app;
Entity player;
Entity bullet;
Control control;

#endif