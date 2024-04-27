#ifndef __STRUCT
#define __STRUCT

#include <SDL_ttf.h>

/////////////////////////////////////////////////////////////////


// entities
struct _Ship{
	SDL_Texture *spt;
	float x, y, spd;
	unsigned int dim, cooldown;
	short isEnemy, hp, maxHp;
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

struct _Star{
	float x, y, spd;
	Uint8 color;
};

struct _Expl{
	float x, y, sx, sy;
	unsigned int dim;
	int r, g, b, a;
	struct _Expl *next;
};

struct _Debr{
	float x, y, sx, sy, alpha;
	short dim;
	SDL_Rect rect;
	SDL_Texture *spt;
	struct _Debr *next;
};


/////////////////////////////////////////////////////////////////


// entities chain
struct _Head{
	struct _Ship ship;
	struct _Bull bull;
	struct _Expl expl;
	struct _Debr debr;
};

struct _Tail{
	struct _Ship *ship;
	struct _Bull *bull;
	struct _Expl *expl;
	struct _Debr *debr;
};


/////////////////////////////////////////////////////////////////


// input and output
struct _App{
	// about window
	SDL_Renderer *renderer;
	SDL_Window   *window;
	
	// about graphics
	SDL_Surface  *textSurface;
	TTF_Font     *normalFont;
	SDL_Color     textColor;
};

struct _Control{
	unsigned short top;
	unsigned short bel;
	unsigned short lef;
	unsigned short rig;
	unsigned short sht; // SHooT
};


/////////////////////////////////////////////////////////////////


typedef struct _Ship Ship;
typedef struct _Bull Bull;
typedef struct _Head Head;
typedef struct _Tail Tail;
typedef struct _Star Star;
typedef struct _Expl Expl;
typedef struct _Debr Debr;

struct _Control control;
struct _App app;

Ship *player;
Head head;
Tail tail;


/////////////////////////////////////////////////////////////////


#endif