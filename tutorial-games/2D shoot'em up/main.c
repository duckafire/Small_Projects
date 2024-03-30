#include <SDL.h>

int main(int argc, char *argv[]){
	// clear trash in "app"
	memset(&app, 0, sizeof(App));
	
	initSDL();
	
	atexit(cleanup);
	
	while(1){
		prepareScene();
		doInput();
		presentScene();
		
		// less fps to ~62
		SDL_Delay(16);
	}
	
	return 0;
}