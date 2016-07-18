#include "BaseObject.h"

BaseObject::BaseObject()
{
	//Initialise
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	mPosX = 0;
	mPosY = 0;
	mAngle = 0.0;
	mCentrePoint = NULL;
	mClip = NULL;
	mFlip = SDL_FLIP_NONE;
}

BaseObject::~BaseObject()
{
	//Deallocate
	free();
}

bool BaseObject::loadFromFile(std::string path)
{
	//Get rid of preexisting texture
	free();
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! \nSDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image. Removes cyan
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(SceneRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! \nSDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void BaseObject::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
		mPosX = 0;
		mPosY = 0;
		mAngle = 0.0;
		mCentrePoint = NULL;
		mClip = NULL;
		mFlip = SDL_FLIP_NONE;
	}
}

void BaseObject::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void BaseObject::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void BaseObject::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void BaseObject::render()
{
	Camera::instance()->render(mTexture, mPosX, mPosY, mWidth, mHeight);
}

SDL_Texture* BaseObject::getTexture()
{
	return mTexture;
}

int BaseObject::getWidth()
{
	return mWidth;
}

int BaseObject::getHeight()
{
	return mHeight;
}

int BaseObject::getX()
{
	return mPosX;
}

int BaseObject::getY()
{
	return mPosY;
}

float BaseObject::getAngle()
{
	return mAngle;
}

SDL_Point* BaseObject::getCentre()
{
	return mCentrePoint;
}

SDL_Rect* BaseObject::getClip()
{
	return mClip;
}
SDL_RendererFlip BaseObject::getFlip()
{
	return mFlip;
}

BaseObject* BaseObject::getThis()
{
	return this;
}