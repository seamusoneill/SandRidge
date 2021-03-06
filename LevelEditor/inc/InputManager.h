#pragma once
#ifndef _INPUT_MANAGER_H_
#define	_INPUT_MANAGER_H_

#include <SDL.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <map>

#include "Command.h"

//Struct containing the command that was called and bool to say if it's being executed or undone.
struct InputCommand
{
	Command* command = NULL;
	bool executing = NULL;
};

class InputManager{
public:
	static InputManager* m_instance;
	static InputManager* instance();

	InputCommand HandleInput(SDL_Event* e);
private:
	InputManager();
	enum key { W, A, S, D };
	bool isKeyDown(key);

	//current keystate
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
};

#endif