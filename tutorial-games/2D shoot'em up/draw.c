void prepareScene(void){
	// background color (RGBA)
	SDL_SetRenderDrawColor(app.renderer, 50, 50, 50, 255);

	// clear "scene"
	SDL_RenderClear(app.renderer);
}

void presentScene(void){
	// draw new frame
	SDL_RenderPresent(app.renderer);
}