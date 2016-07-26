#pragma once
#ifndef _COMMAND_H_
#define _COMMAND_H_

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() {}
	virtual void undo(){}
protected:
	Command() {}
};
#endif //!_COMMAND_H_