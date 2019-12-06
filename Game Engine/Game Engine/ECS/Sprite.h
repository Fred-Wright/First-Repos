#pragma once
#include "Components.h"
#include "SDL.h"
#include "..\TextureManager.h"


class SpriteComponent : public Component
{

private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;

public:


	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTexture(path);
		SDL_Surface* tempSurface = IMG_Load(path);
		srcRect.h = tempSurface->h;
		srcRect.w = tempSurface->w;
		SDL_FreeSurface(tempSurface);
	}


	SpriteComponent(const char* path, int mFrames, int mSpeed)
	{
		animated = true;
		frames = mFrames;
		speed = mSpeed;
		setTexture(path);
		SDL_Surface* tempSurface = IMG_Load(path);
		srcRect.h = tempSurface->h;
		srcRect.w = tempSurface->w;
		SDL_FreeSurface(tempSurface);
	}
	
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}
	

	void setTexture(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}


	void init() override
	{

		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;

	}




	void update() override
	{
		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}


		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;


	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}


};