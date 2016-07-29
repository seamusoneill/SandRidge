#pragma once
#ifndef _THUMBNAIL_H_
#define _THUMBNAIL_H_

#include <SDL.h>
#include <string>
#include "Camera.h" //TODO
class Thumbnail
{
public:
	Thumbnail();
	Thumbnail(SDL_Texture* texture, std::string id);
	~Thumbnail();
	bool initialise(SDL_Rect* window);
	void render(Camera* cam);
private:
	SDL_Rect* mWindow;
	SDL_Texture* mTexture;
};

#endif //!_THUMBNAIL_H_