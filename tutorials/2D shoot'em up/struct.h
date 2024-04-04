#ifndef __STRUCT
#define __STRUCT

typedef struct{
	SDL_Renderer *renderer;
	SDL_Window   *window;
} App;

typedef struct{
	// dim -> dimension (width == height)
	unsigned int x, y, dim;
	float spd;
	SDL_Texture *spt;
} Entity;

typedef struct{
	unsigned short top;
	unsigned short bel;
	unsigned short lef;
	unsigned short rig;
} Control;

App app;
Entity player;
Control control;

#endif