#define SCREEN_WIDTH  1080
#define SCREEN_HEIGHT 640

void initSDL(void);
void updateScene(void);
void drawScene(void);
void doInput(void);

typedef struct{
	SDL_Renderer *renderer;
	SDL_Window   *window;
} App;

App app;