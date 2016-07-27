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

#ifndef _SELECT_COMMAND_H_
#define _SELECT_COMMAND_H_

class SelectCommand : Command
{

};

#endif // !_SELECT_COMMAND_H_

#ifndef _PLACE_COMMAND_H_
#define _PLACE_COMMAND_H_

class PlaceCommand : Command
{

};

#endif // !_PLACE_COMMAND_H_
