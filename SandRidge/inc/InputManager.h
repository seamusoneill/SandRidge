#pragma once
#ifndef _INPUT_MANAGER_H_
#define	_INPUT_MANAGER_H_

#include <SDL.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <map>

#include "Command.h"

class InputManager{
public:
	static InputManager* m_instance;
	static InputManager* instance();

	Command* HandleInput(SDL_Event* e);
private:
	InputManager();
	enum key { W, A, S, D };
	bool isKeyDown(key);

	Command* mSpacebar = new ShootCommand();

	//current keystate
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
};

#endif