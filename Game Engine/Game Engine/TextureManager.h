#pragma once
#include "gameManager.h"
#include "SDL.h"

class TextureManager 
{
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest);


	int h;
	int w;

};