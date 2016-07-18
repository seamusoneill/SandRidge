#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "SceneManager.h"
#include "InputManager.h"

class Game : Scene{
public:
	Game();
	~Game();

	bool update(float dt);

private:
};
#endif //!_GAME_H_