#ifndef __STRUCT
#define __STRUCT


/////////////////////////////////////////////////////////////////


// for all entities
struct Entity{
	SDL_Texture *spt;
	float x, y, spd;
	unsigned int dim, cooldown; // dim = width and height; shoot cooldown
	unsigned short isEnemy, hp, maxHp;
	SDL_Rect lifebar;
	struct Entity *next; // chain of entities (one to bullets and one to ships)
};


/////////////////////////////////////////////////////////////////


// for player control
typedef struct{
	unsigned short top;
	unsigned short bel;
	unsigned short lef;
	unsigned short rig;
	unsigned short sht; // SHooT
} Control;


/////////////////////////////////////////////////////////////////


// for general control of program
typedef struct{
	// about window
	SDL_Renderer *renderer; // pointer to "back buffer"
	SDL_Window   *window;   // poniter to the own window
	
	// to load entities (match.c)
	void (*update)(void);
	void (*draw)(void);
	
	// entities control (HEAD is the beinning and TAIL is the final)
	struct Entity shipHead, *shipTail; // player and enemies
	struct Entity projHead, *projTail; // bullets of player and enemies
	
	// draw shapes (colors)
	SDL_Renderer *shapeRed;
	SDL_Renderer *shapeGreen;
	SDL_Renderer *shapeGrey;
} App;


/////////////////////////////////////////////////////////////////


// global
struct Entity *player;
Control control;
App app;


/////////////////////////////////////////////////////////////////


#endif