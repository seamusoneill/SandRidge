#include "Game.h"

Game::Game()
{
	createScene();
}

Game::~Game()
{
	disposeScene();
}

bool Game::createScene()
{
	bool success = true;

	mPlayer = new Player();
	mPlayer->initialise(NULL,100,100,32,32);

	gameObject.push_back(mPlayer);


	AudioManager::instance()->PlayAmbientAudio();

	return success;
}

bool Game::disposeScene()
{
	bool success = true;

	for (int i = 0; i < gameObject.size(); i++)
	{
		gameObject[i]->~BaseObject();
		//TODO remove from vector
	}

	return success;
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
		else
		{
			Command* command = InputManager::instance()->HandleInput(&e);
			if (command)
				command->execute(*mPlayer);
			else mPlayer->handleEvent(e); //TODO Remove this function from player and replace everything  with commands
		}
		
	}

	//Update objects
	for (int i = 0; i < gameObject.size(); i++)
	{
		gameObject[i]->update(dt);
	}

	//Clear screen
	SDL_SetRenderDrawColor(SceneRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(SceneRenderer);

	//Render objects
	for (int i = 0; i < gameObject.size(); i++)
	{
		gameObject[i]->render();
	}

	//Update screen
	SDL_RenderPresent(SceneRenderer);

	return false;
}