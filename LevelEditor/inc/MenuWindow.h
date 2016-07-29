#pragma once 
#ifndef _MENU_WINDOW_H_
#define _MENU_WINDOW_H_

#include <SDL.h>
#include "Camera.h"

class MenuWindow{
public :
	MenuWindow();
	MenuWindow(SDL_Rect* windowRect);
	~MenuWindow();
	bool initialise(SDL_Rect* windowRect);
	bool update();
	void render(SDL_Texture* texture, int x, int y, int width, int height);
protected:
	SDL_Rect* mWindowRect;
	Camera* mCamera;
};
#endif //!_MENU_WINDOW_H_