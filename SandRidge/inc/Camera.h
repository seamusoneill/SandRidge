#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <SDL.h>

#include "CONSTANTS.h"
#include "SceneManager.h"

class Camera{
public:
	static Camera* m_instance;
	static Camera* instance();

	void update();
	void render(SDL_Texture* texture, int x, int y, int width, int height, double angle = 0.0f, SDL_Point* centre = NULL, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	Camera();

	SDL_Rect CameraBounds;
	int mPosX, mPosY;
};

#endif