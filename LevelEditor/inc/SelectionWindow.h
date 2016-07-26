#pragma once
#ifndef _SELECTION_WINDOW_H_
#define _SELECTION_WINDOW_H_

#include "MenuWindow.h"
#include <vector>
#include "Thumbnail.h"

class SelectionWindow : public MenuWindow
{
public:
	SelectionWindow();
private:
	std::vector<Thumbnail> thumbnails;
};
#endif //!_SELECTION_WINDOW_H_