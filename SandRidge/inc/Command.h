#pragma once
#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "GameActor.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() {}
	virtual void execute(GameActor& actor) {}
protected:
	Command() {}
};

class ShootCommand : public Command
{
public:
	virtual void execute(GameActor& actor)
	{
		actor.shoot();
	}
};
#endif //!_COMMAND_H_