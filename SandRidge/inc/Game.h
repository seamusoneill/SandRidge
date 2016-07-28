#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "Scene.h"

#include "Player.h"
#include "MacroCommand.h"
#include <vector>

class Game : public Scene{
public:
	Game();
	~Game();

	bool createScene();
	bool disposeScene();

	Scene::SceneType update(float dt);

private:
	std::vector<BaseObject*> gameObject;

	Player* mPlayer;

	MacroCommand mCommandLog;
};
#endif //!_GAME_H_