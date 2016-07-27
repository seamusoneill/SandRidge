#include "Thumbnail.h"

Thumbnail::Thumbnail(){}

Thumbnail::Thumbnail(SDL_Texture* texture)
{
	mTexture = texture;
}

Thumbnail::~Thumbnail(){}

bool Thumbnail::initialise()
{
	bool success = true;
	return success;
}