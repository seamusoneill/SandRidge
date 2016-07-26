#include "MenuWindow.h"

MenuWindow::MenuWindow()
{
}

MenuWindow::MenuWindow(SDL_Rect* windowRect)
	:mWindowRect(windowRect)
{
	initialise(windowRect);
}
bool MenuWindow::initialise(SDL_Rect* windowRect)
{
	bool success = true;

	mWindowRect = windowRect;
	mCamera = new Camera();
	mCamera->initialise(mWindowRect);
	
	return success;
}
MenuWindow::~MenuWindow()
{
}

bool MenuWindow::update()
{
	return false;
}
void MenuWindow::render()
{
}