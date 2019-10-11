#pragma once
#include "SDL.h"
#include <cstdio>
#include <string>

struct SDL_Window;
struct SDL_Renderer;



class Game {

private:
	

	
public:
	
	Game();
	~Game();
	SDL_Window* g_window;
	SDL_Renderer* g_renderer;
	//SDL_Surface* g_Surface;
	//SDL_Surface* g_Image;


	void Update(void);

	void setDispColor(int x, int y);
	//void loadSprite(std::string file);
};