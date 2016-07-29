#include "WindowManager.h"

WindowManager* WindowManager::m_instance = 0;

WindowManager* WindowManager::instance()
{
	if (m_instance == 0)
		m_instance = new WindowManager();
	return m_instance;
}
WindowManager::WindowManager()
{
	s = SelectionWindow();
	s.initialise(new SDL_Rect());
}

WindowManager::~WindowManager()
{
}

bool WindowManager::update()
{
	SDL_Event e;//Event Handler
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			return true;
		}
		else

			InputManager::instance()->HandleInput(&e);
	}
	s.update();
	//If mouse is over windowX make windowX the current window.
	//If a mouse click is called then call the command on the correct window.

	return false;
}