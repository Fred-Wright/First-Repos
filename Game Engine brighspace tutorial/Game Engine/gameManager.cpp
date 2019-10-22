#include "gameManager.h"
#include "SDL.h"
#include <cstdio>
#include "SDL_render.h"
#include <string>

class Bitmap;
const int fps = 60;
const int frameDelay = 1000 / fps;
Uint32 frameStart;
int frameTime;

Game::Game() {

	frameStart = SDL_GetTicks();
	g_window = nullptr;
	g_renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);

	g_window = SDL_CreateWindow(
		"Game Launcher",
		250,
		50,
		1600,
		890,
		0
	);

	g_renderer = SDL_CreateRenderer(
		g_window,
		-1,
		0
	);

	if (g_renderer) {
		int i_Renderer = SDL_SetRenderDrawColor(
			g_renderer,
			255,
			0,
			0,
			255
		);

	}

	frameTime = SDL_GetTicks() - frameStart;

	if (frameDelay > frameTime)
	{
		SDL_Delay(frameDelay - frameTime);
	}

	if (!g_window) {
		printf(R"(Failiure)", SDL_GetError());
	}

	if (!g_renderer) {
		printf(R"(Failiure)", SDL_GetError());
	}
};

void Game::Update(void) 
{
	SDL_RenderClear(g_renderer);

	

	SDL_RenderPresent(g_renderer);

}
/*
void Game::loadSprite(std::string file) {

	
	g_Surface = SDL_GetWindowSurface(g_window);
	
	g_Image = SDL_LoadBMP("Untitled.bmp");
	SDL_BlitSurface(g_Image, NULL, g_Surface, NULL);
	SDL_FillRect(g_Surface, NULL, SDL_MapRGB(g_Surface->format, 255, 0, 0));
	

}

*/

Game::~Game() {


	if (g_renderer) {
		SDL_DestroyRenderer(g_renderer);
	}

	if (g_window) {
		SDL_DestroyWindow(g_window);
	}

	//SDL_FreeSurface(g_Image);

}


void Game::setDispColor(int x, int y)
{
	if (g_renderer) {
		int i_Renderer = SDL_SetRenderDrawColor(
			g_renderer,
			x,
			y,
			0,
			255
		);

		SDL_RenderClear(g_renderer);

		SDL_RenderPresent(g_renderer);

	}

}

SDL_Surface* s_Surface;
SDL_Surface* s_Image;


