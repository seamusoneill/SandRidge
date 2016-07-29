#pragma once
#ifndef _SELECTION_WINDOW_H_
#define _SELECTION_WINDOW_H_

#include "MenuWindow.h"
#include <vector>
#include "Thumbnail.h"
#include <SDL_image.h> //TODO remove this when moving texture loading location
#include "SandRidge\inc\ObjectType.h"
#include "SandRidge\inc\CreateObjectTypes.h"

class SelectionWindow : public MenuWindow
{
public:
	SelectionWindow();
	bool initialise(SDL_Rect* windowRect);
	bool update();
private:
	std::vector<Thumbnail> thumbnails;
};
#endif //!_SELECTION_WINDOW_H_