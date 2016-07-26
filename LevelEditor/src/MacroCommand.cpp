#include "MacroCommand.h"

void MacroCommand::add(Command *c) {
	mCommands.push_back(c);
}
void MacroCommand::remove(Command *c){
	std::remove(mCommands.begin(), mCommands.end(), c);
}

void MacroCommand::execute()
{
	for (int i = 0; i < mCommands.size(); i++)
	{
		
		mCommands[i]->execute();
	}
}