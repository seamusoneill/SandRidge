#pragma once
#ifndef _THUMBNAIL_H_
#define _THUMBNAIL_H_

class Thumbnail
{
public:
	Thumbnail();
	~Thumbnail();
	bool initialise();

private:
	SDL_Rect* mWindow;
	SDL_Texture* mTexture;
};

#endif //!_THUMBNAIL_H_