#include "Player.h"

Player::Player()
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
	mVelX = 0;
	mVelY = 0;
}

Player::~Player()
{

}

bool Player::initialise(SDL_Texture* texture, int posX, int posY, int width, int height,
	float angle, SDL_Point* centrePoint, SDL_Rect* clip, SDL_RendererFlip flip)
{
	bool success = true;

	mTexture = texture;
	loadFromFile("res/img/dot.png");
	mPosX = posX;
	mPosY = posY; 
	mWidth = width;
	mHeight = height;
	mAngle = angle;
	mCentrePoint = centrePoint;
	mClip = clip;
	mFlip = flip;

	return success;
}

void Player::update(float dt)
{
	walk();
}

void Player::handleEvent(SDL_Event e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
			//TODO replace with command pattern, remove magic numbers
		case SDLK_UP: mVelY -= 10; break;
		case SDLK_DOWN: mVelY += 10; break;
		case SDLK_LEFT: mVelX -= 10; break;
		case SDLK_RIGHT: mVelX += 10; break;
		}
	}

	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += 10; break;
		case SDLK_DOWN: mVelY -= 10; break;
		case SDLK_LEFT: mVelX += 10; break;
		case SDLK_RIGHT: mVelX -= 10; break;
		}
	}
}

void Player::walk()
{
	mPosX += mVelX;
	mPosY += mVelY;
}

void Player::shoot()
{
	AudioManager::instance()->PlayShoot();
}

void Player::punch()
{}