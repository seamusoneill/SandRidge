#include "Renderer.h"

Renderer* Renderer::m_instance = 0;

Renderer* Renderer::instance()
{
	if (m_instance == 0)
		m_instance = new Renderer();
	return m_instance;
}

Renderer::Renderer()
{
	bool success;

	//Create window
	mWindow = SDL_CreateWindow("Level Editor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (mWindow == NULL)
	{
		printf("SDL Could not initialize! \nSDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create vsynced renderer for window
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (mRenderer == NULL)
		{
			printf("Rendererer could not be created %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize renderer colour
			SDL_SetRenderDrawColor(mRenderer, 0x11, 0xAF, 0xFF, 0xFF);
		}
	}
}

Renderer::~Renderer()
{
	close();
}

void Renderer::close()
{
	//Destroy window
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;
	mRenderer = NULL;
}
SDL_Renderer* Renderer::getRenderer()
{
	return mRenderer;
}