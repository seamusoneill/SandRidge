#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "SceneManager.h"
#include "InputManager.h"
#include "Player.h"
#include "Tree.h"
#include <vector>
#include <ctime>

class Game : Scene{
public:
	Game();
	~Game();

	bool createScene();
	bool disposeScene();

	bool update(float dt);

private:
	std::vector<BaseObject*> gameObject;

	Player* mPlayer;
	std::vector<Tree*> mTrees;
};
#endif //!_GAME_H_