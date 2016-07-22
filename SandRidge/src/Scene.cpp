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

bool Scene::AddObserver(Observer* obs){
	for (size_t i = 0; i < m_observerList.size(); i++){
		if (obs == m_observerList[i]){
			return false;
		}
	}
	m_observerList.push_back(obs);
	return true;
}

void Scene::SetPlayValue(int val){
	myval = val;
	for (size_t i = 0; i < m_observerList.size(); i++)
		m_observerList[i]->onNotify(myval);
}