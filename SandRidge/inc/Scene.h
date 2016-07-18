#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

class Scene
{
public:
	Scene();
	~Scene();

	virtual bool update(float dt);
	void render();

protected:

};

#endif //!_SCENE_H_