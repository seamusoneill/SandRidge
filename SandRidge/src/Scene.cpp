#include "Scene.h"

Scene::Scene(){

}


Scene::~Scene()
{

}

bool Scene::update(float dt)
{
	return false;
}

void Scene::render()
{}


Scene::SceneType Scene::getSceneType()
{
	return mSceneType;

}