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

private:
	bool isRunning;
	SDL_Window* window;
	int counter = 0;

};