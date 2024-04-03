#define SCREEN_WIDTH  1080
#define SCREEN_HEIGHT 640

// draw.c
void updateScene(void);
void drawScene(void);
SDL_Texture *loadImage(char *file);
void sprite(SDL_Texture *img, int x, int y, int scale);

// init.c and input.c
void initSDL(void);
void doInput(void);