#include "SceneManager.h"

SceneManager* SceneManager::m_instance = 0;

SceneManager::SceneManager()
{
	bool success;


	
	menuScene = new Menu();
	currentScene = menuScene;
}

SceneManager* SceneManager::instance()
{
	if (m_instance == 0)
		m_instance = new SceneManager();
	return m_instance;
}

Scene::SceneType SceneManager::update(float dt)
{
	Scene::SceneType returnedScene = currentScene->update(dt);
	if (returnedScene != currentSceneType)
	{
		if (returnedScene != Scene::SCENE_QUIT)
		{
			setScene(returnedScene);/// gotta test this
		}
		else
			return returnedScene;
	}
	
	return returnedScene;
	
}
void SceneManager::close()
{
	
}

void SceneManager::setScene(Scene* scene)
{
	if (currentScene->disposeScene())
	{
		if (scene->createScene())
		{
			currentScene = scene;
			currentSceneType = scene->getSceneType();
		}
		else
			printf("Failed to create " + scene->getSceneType());
	}
	else
		printf("Failed to dispose of " + currentSceneType);
}

void SceneManager::setScene(Scene::SceneType sceneType)
{
	switch (sceneType)
	{
	case Scene::SCENE_MAIN_MENU:
		if (menuScene == NULL)
			menuScene = new Menu();
		setScene(menuScene);
		gameScene = NULL;
		break;
	case Scene::SCENE_GAME:
		if (gameScene == NULL)
			gameScene = new Game();
		setScene(gameScene);
		menuScene = NULL;// TODO if this isnt what we want need to setup so it works with the above if()
		break;
	}
}