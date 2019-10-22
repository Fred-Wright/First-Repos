#include "TextureManager.h"


SDL_Texture* TextureManager::LoadTexture(const char* textrue)
{

	SDL_Surface* tempSurface = IMG_Load(textrue);
	int h = tempSurface->h;
	int w = tempSurface->w;
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;


}

void TextureManager::Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest)
{

	SDL_RenderCopy(Game::renderer, text, &src, &dest);

}
