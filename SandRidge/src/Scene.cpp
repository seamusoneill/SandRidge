#include "Scene.h"

Scene::Scene()
{
	myval = -1;
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

bool Scene::AddObserver(Observer* obs){
	for (size_t i = 0; i < m_observerList.size(); i++){
		if (obs == m_observerList[i]){
			return false;
		}
	}
	m_observerList.push_back(obs);
	obs->update(myval);
	return true;
}

void Scene::SetPlayValue(int val){
	myval = val;
	for (size_t i = 0; i < m_observerList.size(); i++)
		m_observerList[i]->update(myval);
}