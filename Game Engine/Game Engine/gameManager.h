#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <cstdio>
#include <string>

class Game {

public:
	
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	bool Running();
	static SDL_Renderer* renderer;
	static SDL_Event event;
	SDL_Texture* texture;
	SDL_Window* window;

private:
	bool isRunning;
	
	int counter = 0;

};