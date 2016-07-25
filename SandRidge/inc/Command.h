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
	virtual void undo(){}
	virtual void undo(GameActor& actor){}
protected:
	Command() {}
};
#endif //!_COMMAND_H_