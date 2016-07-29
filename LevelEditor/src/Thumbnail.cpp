#include "Thumbnail.h"

Thumbnail::Thumbnail(){}

Thumbnail::Thumbnail(SDL_Texture* texture, std::string id)
{
	mTexture = texture;
	//Create font texture using Id
}

Thumbnail::~Thumbnail(){}

bool Thumbnail::initialise(SDL_Rect* window)
{
	bool success = true;
	mWindow = window;
	return success;
}

void Thumbnail::render(Camera* cam)
{
	cam->render(mTexture, mWindow->x, mWindow->y, mWindow->w, mWindow->h);
}