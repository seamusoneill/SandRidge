#include "SelectionWindow.h"

SelectionWindow::SelectionWindow()
{
}

bool SelectionWindow::initialise(SDL_Rect* windowRect, std::vector < GameObject > gameObjects)
{
	bool success = true;

	for (int i = 0; i < gameObjects.size(); ++i)
	{
		thumbnails.push_back(Thumbnail(gameObjects[i].mTexture));
	}

	for (int i = 0; i < thumbnails.size(); ++i)
	{
		//Position thumbnails int the window 2 across by N down;
		//Write the name of the object under the thumbnail as well. (Thumbnails should maybe have a fonttexture.
	}

	return success;
}