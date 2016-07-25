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
		//If a key was pressed
	case SDL_KEYDOWN:
		inputCommand.executing = true;
		if (e->key.repeat == 0)
		{
			switch (e->key.keysym.sym)
			{
			case SDLK_SPACE:
				inputCommand.command = mSpacebar;
				break;
			case SDLK_LEFT:
				inputCommand.command = mLeftArrow;
				break;
			case SDLK_RIGHT:
				inputCommand.command = mRightArrow;
				break;
			case SDLK_UP:
				inputCommand.command = mUpArrow;
				break;
			case SDLK_DOWN:
				inputCommand.command = mDownArrow;
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
				inputCommand.command = mLeftArrow;
				break;
			case SDLK_RIGHT:
				inputCommand.command = mRightArrow;
				break;
			case SDLK_UP:
				inputCommand.command = mUpArrow;
				break;
			case SDLK_DOWN:
				inputCommand.command = mDownArrow;
				break;
			}
		}
		break;
	default:
		break;
	}
	return inputCommand;
}