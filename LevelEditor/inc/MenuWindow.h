#pragma once 
#ifndef _MENU_WINDOW_H_
#define _MENU_WINDOW_H_

#include <SDL.h>
#include "Renderer.h"

class MenuWindow{
public :
	MenuWindow();
	MenuWindow(SDL_Rect* windowRect)
		:mWindowRect(windowRect){}
	~MenuWindow();
	bool update();
	void render();
private:
	SDL_Rect* mWindowRect;
};
#endif //!_MENU_WINDOW_H_