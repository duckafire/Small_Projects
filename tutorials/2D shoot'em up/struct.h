typedef struct{
	SDL_Renderer *renderer;
	SDL_Window   *window;
} App;

typedef struct{
	int x, y;
	SDL_Texture *sprite;
} Entity;

App app;
Entity player;