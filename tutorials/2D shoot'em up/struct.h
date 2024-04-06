#ifndef __STRUCT
#define __STRUCT

typedef struct{
	// dim -> dimension (width == height)
	unsigned float x, y;
	unsigned int dim, hp, cooldown;
	SDL_Texture *spt;
	float spd;
	Entity *next;
} Entity;

typedef struct{
	unsigned short top;
	unsigned short bel;
	unsigned short lef;
	unsigned short rig;
	unsigned short fire;
} Control;

typedef struct{
	SDL_Renderer *renderer;
	SDL_Window   *window;
	void (*update)(void);
	void (*draw)(void);
	Entity shipHead, projHead, *projTail, *shipTail;
} App;

Entity *player;
Control control;
App app;

#endif