#include "SDL.h"
#include <cstdio>
#include "gameManager.h"
#include <iostream>

/*
	surface = SDL_GetWindowSurface(window);

	image = SDL_LoadBMP("Untitled.bmp");

	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 0, 0));
	SDL_BlitSurface(image, NULL, surface, NULL);
	
}
*/

SDL_Surface* g_Surface;
SDL_Surface* g_Image;
Game* game = new Game();

void Image() {
	g_Surface = NULL;
		g_Image = NULL;
		g_Image = SDL_LoadBMP("assets/Untitled.bmp");
		g_Surface = SDL_GetWindowSurface(game->g_window);
		//SDL_FillRect(g_Surface, NULL, SDL_MapRGB(g_Surface->format, 255, 0, 0));
		SDL_BlitSurface(g_Image, NULL, g_Surface, NULL);
	

}

int main(int argc, char* argv[])
{
	

		
	
	bool quit = false;

	while (!quit) 
	{
		SDL_UpdateWindowSurface(game->g_window);
		SDL_RenderClear(game->g_renderer);
		SDL_Event s_Event;
		
		Image();


		while (SDL_PollEvent(&s_Event)) 
		{
			if (s_Event.type == SDL_KEYDOWN) 
			{
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

				game->setDispColor(x, y);
			}

		}
	}

	SDL_FreeSurface(g_Image);
	delete game;
	game = nullptr;
	return 0;
}