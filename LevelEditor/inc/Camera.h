#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <SDL.h>

#include "Renderer.h"

class Camera{
public:
	Camera();
	~Camera();
	bool initialise(SDL_Rect* cameraWindow);
	
	void update();
	void render(SDL_Texture* texture, int x, int y, int width, int height, double angle = 0.0f, SDL_Point* centre = NULL, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
	SDL_Rect* mCameraBounds;
	int mPosX, mPosY;
};

#endif