#include "SceneManager.h"

SceneManager* SceneManager::m_instance = 0;

SceneManager::SceneManager()
{
	bool success;


	//Initialize PNG loading //TODO move this to resourceManager
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! \nSDL_image Error: %s\n", IMG_GetError());
		success = false;
	}

	//TODO Remove this, put it in AudioManager. Also remove it from Main.
	//Initialise SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! \nSDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not intitialize! \nSDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}

	gameScene = new Game();
	currentScene = gameScene;
}

SceneManager* SceneManager::instance()
{
	if (m_instance == 0)
		m_instance = new SceneManager();
	return m_instance;
}

void SceneManager::update(float dt)
{
	currentScene->update(dt);
}
void SceneManager::close()
{
	//Quit SDL subsystems
	Mix_Quit();//TODO Move to AudioManager
	IMG_Quit();//TODO Move to ResourceManager
	TTF_Quit();
}

void SceneManager::setScene(Scene* scene)
{
	if (currentScene->disposeScene())
	{
		if (scene->createScene())
		{
			currentScene = scene;
			currentSceneType = scene->getSceneType();
		}
		else
			printf("Failed to create " + scene->getSceneType());
	}
	else
		printf("Failed to dispose of " + currentSceneType);
}

void SceneManager::setScene(Scene::SceneType sceneType)
{
	switch (sceneType)
	{
	case Scene::SCENE_MAIN_MENU:
		setScene(menuScene);
		break;
	case Scene::SCENE_GAME:
		setScene(gameScene);
		break;
	}
}