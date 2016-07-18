#pragma once
#ifndef _BASE_OBJECT_H_
#define _BASE_OBJECT_H_

#include <string>
#include <SDL_image.h>

#include "Camera.h"

class BaseObject 
{
public:
	BaseObject();
	~BaseObject();
	
	//Update method
	virtual void update(float dt) = 0;

	//Load image at specified path and set texture
	bool loadFromFile(std::string path);

	//Deallocates texture
	void free();

	//Set colour modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Render texture at given point
	void render();

	//Gets texture
	SDL_Texture* getTexture();

	//Gets image dimensions
	int getWidth();
	int getHeight();

	//Get position
	int getX();
	int getY();

	float getAngle();

	SDL_Point* getCentre();

	SDL_Rect* getClip();

	SDL_RendererFlip getFlip();

	//Return pointer to this game object
	BaseObject* getThis();

protected:

	//Texture
	SDL_Texture* mTexture;

	//The X and Y offsets of the texture
	int mPosX, mPosY;

	//Image dimensions
	int mWidth;
	int mHeight;

	//Image angle
	float mAngle;

	//Object centre
	SDL_Point* mCentrePoint;

	//Portion of src rectangle to be rendered
	SDL_Rect* mClip;

	//Image flip
	SDL_RendererFlip mFlip;
};

#endif //!_BASE_OBJECT_H_