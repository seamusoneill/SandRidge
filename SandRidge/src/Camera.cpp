#include "Camera.h"

Camera* Camera::m_instance = 0;

Camera* Camera::instance()
{
	if (m_instance == 0)
		m_instance = new Camera();
	return m_instance;
}

Camera::Camera()
{
	mPosX = 0;
	mPosY = 0;
	CameraBounds.x = 0;
	CameraBounds.y = 0;
	//CameraBounds.h = CONSTANTS::LEVEL_HEIGHT;
	//CameraBounds.w = CONSTANTS::LEVEL_WIDTH;
}

void Camera::update()
{
#pragma region Lock To Player
	

#pragma endregion
	/* Commented out until we have a level width
#pragma region Check Bounds
	{	
		if (mPosX < CameraBounds.x)
		{
			//The camera is going too far left
			mPosX = CameraBounds.x;
		}
		if (mPosX + CONSTANTS::SCREEN_WIDTH > CameraBounds.x + CameraBounds.w)
		{
			//The camera is going too far right
			mPosX = CameraBounds.x + CameraBounds.w - CONSTANTS::SCREEN_WIDTH;
		}
		if (mPosY < CameraBounds.y)
		{
			//The camera is too far up
			mPosY = CameraBounds.y;
		}
		if (mPosY + CONSTANTS::SCREEN_HEIGHT > CameraBounds.y + CameraBounds.h)
		{
			//The camera is too low
			mPosY = CameraBounds.y + CameraBounds.h - CONSTANTS::SCREEN_HEIGHT;
		}
	}
	//!Check Bounds
	*/
#pragma endregion 
}

void Camera::render(SDL_Texture* texture, int x, int y, int width, int height, SDL_Rect* clip, double angle, SDL_Point* centre, SDL_RendererFlip flip)
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