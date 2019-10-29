#include "gameManager.h"
#include "SDL.h"
#include "SDL_render.h"
#include "TextureManager.h"
#include <iostream>
#include "GameObject.h"
#include "Tilemap.h"
#include "Componenets.h"
#include "ECS.h"

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;
Manager manager;
auto& newPlayer(manager.addEntity());



Game::Game()
{

}

Game::~Game()
{

}



void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
	{
		std::cout << "initialised!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window) 
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		
		isRunning = true;

	}
	
	player = new GameObject("assets/Player.png", 0, 0, 0.5);
	enemy = new GameObject("assets/enemy.png", 100, 100, 0.5);
	map = new Map();

	newPlayer.addComponent<PositionComponent>();
	newPlayer.getComponent<PositionComponent>().setPos(500, 500);

}

void Game::HandleEvents()
{

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type){
		case SDL_QUIT:
			isRunning = false;
			break;

	default:
		break;
	}

}

void Game::Render()
{

	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Render();
	enemy->Render();
	

	SDL_RenderPresent(renderer);

}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned" << std::endl;
}

void Game::Update()
{

	player->Update();
	enemy->Update();

	manager.update();
	std::cout << newPlayer.getComponent<PositionComponent>().x() << ", " << newPlayer.getComponent<PositionComponent>().y() << std::endl;
}




bool Game::Running()
{
	return true;
}





