#pragma once 
#ifndef _MENU_WINDOW_H_
#define _MENU_WINDOW_H_

#include <SDL.h>
#include "Camera.h"
#include "GameObject.h"
class MenuWindow{
public :
	MenuWindow();
	MenuWindow(SDL_Rect* windowRect);
	~MenuWindow();
	bool initialise(SDL_Rect* windowRect);
	bool update();
	void render();
private:
	SDL_Rect* mWindowRect;
	Camera* mCamera;
};
#endif //!_MENU_WINDOW_H_