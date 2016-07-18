#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
}

bool Game::update(float dt)
{
	SDL_Event e; //Event handler

	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			return true;
		}

	}

	//Clear screen
	SDL_SetRenderDrawColor(SceneRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(SceneRenderer);

	//Render objects
	

	//Update screen
	SDL_RenderPresent(SceneRenderer);

	return false;
}