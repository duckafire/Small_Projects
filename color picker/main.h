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

#endif