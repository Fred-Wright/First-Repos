#pragma once
#include "SDL.h"
#include <cstdio>
#include <string>

class Game {

public:
	Game();
	Game~();

	void init(const car* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	bool Running();

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer* renderer;

};