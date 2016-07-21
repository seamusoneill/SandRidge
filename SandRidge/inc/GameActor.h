//Abstract class for characters in the game: Player, enemies, NPCs. Provides Animations and commands.
#pragma once
#ifndef _GAME_ACTOR_H_
#define _GAME_ACTOR_H_

#include "BaseObject.h"

class GameActor : public BaseObject
{
public:
	GameActor();
	~GameActor();

	virtual void walk() = 0;
	virtual void shoot() = 0;

protected:

};

#endif //!_GAME_ACTOR_H_