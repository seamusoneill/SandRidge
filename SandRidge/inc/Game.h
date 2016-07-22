#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "Scene.h"
#include "InputManager.h"
//#include "AudioManager.h" //TODO not this
#include "Player.h"
#include <vector>

class Game : public Scene{
public:
	Game();
	~Game();

	bool createScene();
	bool disposeScene();

	bool update(float dt);

private:
	std::vector<BaseObject*> gameObject;

	Player* mPlayer;
};
#endif //!_GAME_H_