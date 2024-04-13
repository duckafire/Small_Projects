#ifndef ___COLOR_PICKER___
#define ___COLOR_PICKER___

#define SCREEN_DIM 350 // 350 x 350

extern SDL_Renderer *renderer;
extern SDL_Window   *window;
extern SDL_DisplayMode desktop;

// white
extern unsigned short wRed;
extern unsigned short wGreen;
extern unsigned short wBlue;
// black
extern unsigned short bRed;
extern unsigned short bGreen;
extern unsigned short bBlue;
// current
extern unsigned short cRed;
extern unsigned short cGreen;
extern unsigned short cBlue;

int main(int argc, char *argv[]);
void square(float red, float green, float blue);
void bar(void);
void boards(short x1, short y1, short w1, short h1, short x2, short y2, short w2, short h2);

#endif