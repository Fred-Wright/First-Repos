#pragma once
#include "SDL.h"
#include <cstdio>
#include <string>

class Game {

public:
	Game();
	~Game();

	void Update(void);
	void setDispColor(int x, int y);
	SDL_Window * g_window;
	SDL_Renderer* g_renderer;



	

};