//Abstract class for characters in the game: Player, enemies, NPCs. Provides Animations and commands.
#pragma once
#ifndef _GAME_ACTOR_H_
#define _GAME_ACTOR_H_

#include "BaseObject.h"

enum Direction {
	DIRECTION_RIGHT,
	DIRECTION_LEFT,
	DIRECTION_UP,
	DIRECTION_DOWN
};

class GameActor : public BaseObject
{
public:
	GameActor();
	~GameActor();

	virtual void walk(Direction direction)
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
	virtual void stopWalk(Direction direction)
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
	virtual void shoot() = 0;

protected:
	int mMovementSpeed;
};

#endif //!_GAME_ACTOR_H_