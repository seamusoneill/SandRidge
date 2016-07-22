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
#include "Game.h"
#include "AudioManager.h"

class SceneManager
{
	friend class Scene;
public :
	static SceneManager* m_instance;
	static SceneManager* instance();

	Scene::SceneType currentSceneType;
	Scene* currentScene;

	void update(float dt);

	void close();

	void setScene(Scene* scene);
	void setScene(Scene::SceneType sceneType);
private:
	SceneManager();

	//Scenes
	Game* gameScene;
	Scene* menuScene;
};

#endif //!_SCENE_MANAGER_H_