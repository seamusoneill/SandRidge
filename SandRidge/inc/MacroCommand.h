#pragma once
#ifndef _MACRO_COMMAND_H_
#define _MACRO_COMMAND_H_

#include "Command.h"
#include <vector>
#include <algorithm>

class MacroCommand : Command
{
public:
	MacroCommand(){}
	virtual ~MacroCommand(){}
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void execute();
	virtual void execute(GameActor& actor);
private:
	std::vector<Command*> mCommands;
};

#endif