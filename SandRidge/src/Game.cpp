#include "Game.h"

Game::Game()
{
	//createScene();
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
	mCommandLog = MacroCommand();
	//AudioManager::instance()->PlayAmbientAudio();

	mSceneType = SCENE_GAME;

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

Scene::SceneType Game::update(float dt)
{
	SDL_Event e; //Event handler

	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			return SCENE_QUIT;
		}
		if (e.key.keysym.sym == SDLK_ESCAPE)//change this to input manager
		{
			return SCENE_MAIN_MENU;
		}
		else
		{
			InputCommand inputCommand = InputManager::instance()->HandleInput(&e);
			if (inputCommand.command)
			{
				if (inputCommand.executing == true)
					inputCommand.command->execute(*mPlayer);
				else
					inputCommand.command->undo(*mPlayer);
				
				mCommandLog.add(inputCommand.command);
			}
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

	return SCENE_GAME;
}