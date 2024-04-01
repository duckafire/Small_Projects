#define SCREEN_WIDTH  1080
#define SCREEN_HEIGHT 640

void initSDL(void);
void updateScene(void);
void drawScene(void);
void doInput(void);
SDL_Texture *loadImage(char *file);
void draw(SDL_Texture *img, int x, int y);