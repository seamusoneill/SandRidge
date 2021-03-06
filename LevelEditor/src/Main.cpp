#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "WindowManager.h"

using namespace std;

bool init();
void close();

bool init(){
	bool success = true; //Initalization flag

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL Could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!\n");
		}
		else
		{
			//Initialise Renderer
			Renderer::instance();
			//Initialise WindowManager
			WindowManager::instance();
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true; //Loading success flag

	return success;
}



int main(int argc, char* args[])
{
	if (!init())
		printf("Failed to initilaize!\n");

	bool quit = false; //Main loop flag

	//While applcation is running
	while (!quit)
	{
		if (WindowManager::instance()->update())
			quit = true;
	}

	close();
	return 0;
}


void close()
{
	Renderer::instance()->close();

	//Quit SDL
	SDL_Quit();
}