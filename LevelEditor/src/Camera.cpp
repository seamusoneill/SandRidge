#include "Camera.h"

Camera::Camera()
{
	mPosX = 0;
	mPosY = 0;
}

Camera::~Camera() {}

bool Camera::initialise(SDL_Rect* cameraWindow)
{
	bool success = true;
	mCameraBounds = cameraWindow;
	mPosX = cameraWindow->x;
	mPosY = cameraWindow->y;
	return success;
}

void Camera::update()
{
}

void Camera::render(SDL_Texture* texture, int x, int y, int width, int height, double angle, SDL_Point* centre, SDL_Rect* clip, SDL_RendererFlip flip)
{	
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x - mPosX, y - mPosY, width, height };
	
	//Set clip rendering dimesions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(SceneRenderer, texture, clip, &renderQuad, angle, centre, flip);
}