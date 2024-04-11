#ifndef __STRUCT
#define __STRUCT


/////////////////////////////////////////////////////////////////


// for all entities
struct _Ship{
	SDL_Texture *spt;
	float x, y, spd;
	unsigned int dim, cooldown;
	unsigned short isEnemy, hp, maxHp;
	SDL_Rect lifebar;
	struct _Ship *next;
};

struct _Bull{
	SDL_Texture *spt;
	float x, y, spd;
	unsigned int dim;
	unsigned short isEnemy;
	struct _Bull *next;
};


/////////////////////////////////////////////////////////////////


// for player control
struct _Control{
	unsigned short top;
	unsigned short bel;
	unsigned short lef;
	unsigned short rig;
	unsigned short sht; // SHooT
};


/////////////////////////////////////////////////////////////////


// first entity in a chain
struct _Head{
	struct _Ship ship;
	struct _Bull bull;
};

// last entity in a chain
struct _Tail{
	struct _Ship *ship;
	struct _Bull *bull;
};


/////////////////////////////////////////////////////////////////


// for general control of program
struct _App{
	// about window
	SDL_Renderer *renderer; // pointer to "back buffer"
	SDL_Window   *window;   // poniter to the own window
	
	// draw shapes (colors)
	SDL_Renderer *shapeRed;
	SDL_Renderer *shapeGreen;
	SDL_Renderer *shapeGrey;
};


/////////////////////////////////////////////////////////////////


typedef struct _Ship Ship;
typedef struct _Bull Bull;
typedef struct _Head Head;
typedef struct _Tail Tail;

struct _Control control;
struct _App app;

Ship *player;
Head head;
Tail tail;


/////////////////////////////////////////////////////////////////


#endif