#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

#include "CONSTANTS.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "FontTexture.h"
#include "InputManager.h"
#include "Timer.h"
#include "Game.h"
#include "AudioManager.h"

#include "AudioObserver.h"//for testing

using namespace std;

bool init();
bool loadMedia();
void close();

SDL_Joystick* gameController = NULL;
SDL_Haptic* controllerHaptic = NULL;
Game* game;
Scene* scene;

bool init(){
	bool success = true; //Initalization flag

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC) < 0)
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

		//Check for joysticks
		if (SDL_NumJoysticks() < 1)
		{
			printf("Warning: No joysticks connected!\n");
		}
		else
		{
			//Load joystick
			gameController = SDL_JoystickOpen(0);
			if (gameController == NULL)
			{
				printf("Warning unable to open game controller! \nSDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Get controller haptic device
				controllerHaptic = SDL_HapticOpenFromJoystick(gameController);
				if (controllerHaptic == NULL)
				{
					printf("Warning: Controller does not support haptics! \nSDL Error: %s\n", SDL_GetError());
				}
				else
				{
					//Get initialise rumble
					if (SDL_HapticRumbleInit(controllerHaptic) < 0)
					{
						printf("Warning: Unable to initialise rumble! \nSDL Error: %s\n", SDL_GetError());
					}
				}
			}
		}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
			printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		}

		//Initialise ResourceManager. Warning: Must be done before AudioManager
		ResourceManager::instance()->loadAllMedia();
		//Initialise AudioManager
		AudioManager::instance();
		//Initialise SceneManager
		SceneManager::instance();
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
	else
	{

		if (!loadMedia())
			printf("Failed to load media!\n");
		else
		{
			game = new Game();
			AudioObserver obs;
			//for testing
			scene = new Scene();
			obs.attachSubject(&scene->mSceneSubject);
			//attach subject to observer
			scene->mSceneSubject.Notify(1);
			//obs.onNotify(1);///does the same as line above
			
		}
	}

	bool quit = false; //Main loop flag

	int countedFrames = 0;

	//While applcation is running
	while (!quit)
	{

		if (game->update(countedFrames - SDL_GetTicks()))
		{
			quit = true;
		}

		++countedFrames;
	}

	close();
	return 0;
}


void close()
{
	//Close game controller
	SDL_HapticClose(controllerHaptic);
	SDL_JoystickClose(gameController);
	gameController = NULL;
	controllerHaptic = NULL;

	SceneManager::instance()->close();

	//Quit SDL
	SDL_Quit();
}