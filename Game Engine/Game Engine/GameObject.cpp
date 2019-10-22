#include "GameObject.h"
#include "TextureManager.h"

int h;
int w;
float z;

GameObject::GameObject(const char* textSheet, int x, int y, float multipier)
{
	objTexture = TextureManager::LoadTexture(textSheet);
	xpos = x;
	ypos = y;
	z = multipier;
	SDL_Surface* tempSurface = IMG_Load(textSheet);
	h = tempSurface->h;
	w = tempSurface->w;
	SDL_FreeSurface(tempSurface);

}

void GameObject::Update() 
{
	

	xpos++;
	ypos++;

	srcRect.h = h;
	srcRect.w = w;
	srcRect.x = 0;
	srcRect.y = 0;


	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * z;
	destRect.h = srcRect.h * z;



}

void GameObject::Render()
{
	
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
