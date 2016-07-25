#pragma once
#ifndef _GAME_ACTOR_COMMANDS_H_
#define _GAME_ACTOR_COMMANDS_H_
/*Commands for GameActor object.*/

#include "Command.h"

class ShootCommand : public Command
{
public:
	virtual void execute(GameActor& actor)
	{
		actor.shoot();
	}
};

class WalkCommand : public Command
{
public:
	WalkCommand(Direction direction)
		: mDirection(direction){}
	virtual void execute(GameActor& actor)
	{
		actor.walk(mDirection);
	}
	virtual void undo(GameActor & actor)
	{
		actor.stopWalk(mDirection);
	}
private:
	Direction mDirection;
};
#endif //!_GAME_ACTOR_COMMANDS_H_