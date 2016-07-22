#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include "Subject.h"
#include <vector>
class Scene
{
public:
	Scene();
	~Scene();
	Subject mSceneSubject;
	bool AddObserver(Observer* obs);
	virtual bool update(float dt);
	void render();

	void SetPlayValue(int val);
private:
	std::vector<Observer*> m_observerList;
	int myval;
protected:
	virtual bool createScene();
	virtual bool disposeScene();
};

#endif //!_SCENE_H_