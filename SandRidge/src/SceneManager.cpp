#include "SceneManager.h"

SceneManager* SceneManager::m_instance = 0;

SceneManager::SceneManager()
{
	bool success;

	//Create window
	window = SDL_CreateWindow("Sand Ridge", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, CONSTANTS::SCREEN_WIDTH, CONSTANTS::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("SDL Could not initialize! \nSDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create vsynced renderer for window
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == NULL)
		{
			printf("Rendererer could not be created %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize renderer colour
			SDL_SetRenderDrawColor(renderer, 0x11, 0xAF, 0xFF, 0xFF);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! \nSDL_image Error: %s\n", IMG_GetError());
				success = false;
			}

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
		}
	}
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
	//Destroy window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
}