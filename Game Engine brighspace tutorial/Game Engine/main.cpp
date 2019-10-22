#include "SDL.h"
#include <cstdio>
#include "gameManager.h"
#include <iostream>

SDL_Surface* g_Surface;
SDL_Surface* g_Image;
Game* game = new Game();

void Image() {
	g_Surface = NULL;
		g_Image = NULL;
		g_Image = SDL_LoadBMP("assets/Untitled.bmp");
		g_Surface = SDL_GetWindowSurface(game->g_window);
		SDL_FillRect(g_Surface, NULL, SDL_MapRGBA(g_Surface->format, 0,0,0,255));
		SDL_BlitSurface(g_Image, NULL, g_Surface, NULL);
}

int main(int argc, char* argv[])
{
	
	Image();


	bool quit = false;

	while (!quit) 
	{
		
		SDL_RenderClear(game->g_renderer);
		SDL_Event s_Event;
		
		
		

		while (SDL_PollEvent(&s_Event)) 
		{
			if (s_Event.type == SDL_KEYDOWN) 
			{
				if (s_Event.key.keysym.sym == SDLK_s) 
				{

				}

				if (s_Event.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}

			if (s_Event.type == SDL_MOUSEMOTION) 
			{
				int x, y;
				int red, green;
				SDL_GetMouseState(&x, &y);
				std::cout << x << " " << y << std::endl;
				red = x;
				green = y;

				//game->setDispColor(x, y);

				//g_Surface = SDL_GetWindowSurface(game->g_window);
				SDL_FillRect(g_Surface, NULL, SDL_MapRGBA(g_Surface->format, x, y, 0, 255));
				SDL_BlitSurface(g_Image, NULL, g_Surface, NULL);
			}

		}
		SDL_UpdateWindowSurface(game->g_window);
	}

	SDL_FreeSurface(g_Image);
	delete game;
	game = nullptr;
	return 0;
}