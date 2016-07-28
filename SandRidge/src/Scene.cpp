#include "Scene.h"

Scene::Scene(){

}


Scene::~Scene()
{

}

Scene::SceneType Scene::update(float dt)
{
	return SCENE_GAME;
}

void Scene::render()
{}


Scene::SceneType Scene::getSceneType()
{
	return mSceneType;

}