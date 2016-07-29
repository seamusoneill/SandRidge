#pragma once
#ifndef _BASE_OBJECT_H_
#define _BASE_OBJECT_H_

#include <string>
#include <SDL_image.h>

#include "Camera.h"
#include "ObjectType.h"
#include "ResourceManager.h" //Renderer is included in resource manager and camera //todo
class BaseObject 
{
public:
	BaseObject();
	~BaseObject();

	//Initialise methods
	virtual bool initialise(SDL_Texture* texture = NULL, int posX = 0, int posY = 0, int width = 0, int height = 0,
		float angle = 0.0f, SDL_Point* centrePoint = NULL, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE) {
		return true;
	};
	
	bool initialise(ObjectType* type, int posX, int posY)
	{
		bool success = true;
		mTexture = ResourceManager::instance()->getTexture(type->getTextureId());
		mPosX = posX;
		mPosY = posY;
		return success;
	}

	//Update method
	virtual void update(float dt) {};

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
	//Type Object, contains texture and id
	ObjectType mType;

	//Texture
	SDL_Texture* mTexture;

	//The X and Y offsets of the texture
	float mPosX, mPosY;

	//Image dimensions
	int mWidth;
	int mHeight;

	//The X and Y velocity of the object
	int mVelX, mVelY;

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