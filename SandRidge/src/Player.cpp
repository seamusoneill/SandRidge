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
	loadFromFile("res/img/dot.png"); //TODO, should not reload this file on every init.
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
	mPosX += mVelX * dt;
	mPosY += mVelY * dt;
}

void Player::shoot()
{
	AudioManager::instance()->PlayShoot();
}

void Player::walk(Direction direction)
{
	switch (direction)
	{
	case DIRECTION_RIGHT:
		mVelX = mMovementSpeed;
		break;
	case DIRECTION_LEFT:
		mVelX = -mMovementSpeed;
		break;
	case DIRECTION_UP:
		mVelY = -mMovementSpeed;
		break;
	case DIRECTION_DOWN:
		mVelY = mMovementSpeed;
		break;
	default:
		break;
	}
}

void Player::stopWalk(Direction direction)
{
	switch (direction)
	{
	case DIRECTION_RIGHT:
		if (mVelX > 0)
			mVelX = 0;
		break;
	case DIRECTION_LEFT:
		if (mVelX < 0)
			mVelX = -0;
		break;
	case DIRECTION_UP:
		if (mVelY < 0)
			mVelY = 0;
		break;
	case DIRECTION_DOWN:
		if (mVelY > 0)
			mVelY = 0;
		break;
	default:
		break;
	}
}
void Player::punch()
{}