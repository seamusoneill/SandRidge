#pragma once
#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdio.h>

#include "CONSTANTS.h"
#include "Scene.h"

class SceneManager
{
public :
	static SceneManager* m_instance;
	static SceneManager* instance();

	enum SceneType
	{
		CURRENT_SCENE,
		MAIN_MENU_SCENE,
		GAME_SCENE
	};

	Scene* currentScene;

	SDL_Window* window;
	SDL_Renderer* renderer;

#define SceneRenderer (SceneManager::instance()->renderer)

	void update(float dt);

	void close();
private:
	SceneManager();
};

#endif //!_SCENE_MANAGER_H_