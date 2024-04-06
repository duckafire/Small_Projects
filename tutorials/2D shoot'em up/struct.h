#ifndef __STRUCT
#define __STRUCT

struct Entity{
	// dim -> dimension (width == height)
	float x, y, spd;
	unsigned int dim, hp, cooldown;
	SDL_Texture *spt;
	struct Entity *next;
};

typedef struct{
	unsigned short top;
	unsigned short bel;
	unsigned short lef;
	unsigned short rig;
	unsigned short fire;
} Control;

typedef struct{
	SDL_Renderer *renderer;
	SDL_Window *window;
	void (*update)(void);
	void (*draw)(void);
	struct Entity shipHead, projHead, *shipTail, *projTail;
} App;

struct Entity *player;
Control control;
App app;

#endif