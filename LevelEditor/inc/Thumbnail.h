#pragma once
#ifndef _THUMBNAIL_H_
#define _THUMBNAIL_H_

#include <SDL.h>
#include <GameObject.h>

class Thumbnail
{
public:
	Thumbnail();
	Thumbnail(SDL_Texture* texture);
	Thumbnail(GameObject obj);
	~Thumbnail();
	bool initialise();

private:
	SDL_Rect* mWindow;
	SDL_Texture* mTexture;
};

#endif //!_THUMBNAIL_H_