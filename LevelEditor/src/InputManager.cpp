#include "InputManager.h"
#include "Command.h"

InputManager* InputManager::m_instance = 0;
InputManager::InputManager() {}

InputManager* InputManager::instance() {
	if (m_instance == 0)
		m_instance = new InputManager();
	return m_instance;
}

InputCommand InputManager::HandleInput(SDL_Event* e)
{
	InputCommand inputCommand;
	switch (e->type)
	{	
	case SDL_BUTTON_LEFT:
		//Left mouse click
		break;
		//If a key was pressed
	case SDL_KEYDOWN:
		inputCommand.executing = true;
		if (e->key.repeat == 0)
		{
			switch (e->key.keysym.sym)
			{
			case SDLK_SPACE:
				inputCommand.command = NULL;
				break;
			case SDLK_LEFT:
				inputCommand.command = NULL;
				break;
			case SDLK_RIGHT:
				inputCommand.command = NULL;
				break;
			case SDLK_UP:
				inputCommand.command = NULL;
				break;
			case SDLK_DOWN:
				inputCommand.command = NULL;
			}
		}
		break;
		//If a key was released
	case SDL_KEYUP:
		inputCommand.executing = false;
		if (e->key.repeat == 0)
		{
			switch (e->key.keysym.sym)
			{
			case SDLK_LEFT:
				inputCommand.command = NULL;
				break;
			case SDLK_RIGHT:
				inputCommand.command = NULL;
				break;
			case SDLK_UP:
				inputCommand.command = NULL;
				break;
			case SDLK_DOWN:
				inputCommand.command = NULL;
				break;
			}
		}
		break;
	default:
		break;
	}
	return inputCommand;
}