#include "InputManager.h"

InputManager* InputManager::m_instance = 0;
InputManager::InputManager() {}

InputManager* InputManager::instance() {
	if (m_instance == 0)
		m_instance = new InputManager();
	return m_instance;
}

void InputManager::HandleInput(SDL_Event* e)
{
	switch (e->type)
	{
	case SDL_KEYDOWN:
		if (e->key.keysym.sym == SDLK_SPACE)
		{
			currentKeyStates = SDL_GetKeyboardState(NULL);
		}
		break;
	case SDL_KEYUP:
		break;
	default:
		break;
	}
}