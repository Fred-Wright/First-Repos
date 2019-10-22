#pragma once
#include "gameManager.h"

class GameObject 
{

public:
	GameObject(const char* textSheet, int x, int y, float multiplier);

	void Update();
	void Render();


private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

};