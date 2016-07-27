#pragma once
#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

/*Singleton class responsible for initialising and updating the windows and handling input between them.*/

#include "MenuWindow.h"
#include <vector>
#include "InputManager.h"

class WindowManager
{
public:
	static WindowManager* instance();
	bool update();
private:
	WindowManager();
	~WindowManager();
	static WindowManager* m_instance;
	MenuWindow* mCurrentWindow; //Window which the mouse is over
	std::vector<MenuWindow*> mWindows;
};
#endif //!_WINDOW_MANAGER_H_