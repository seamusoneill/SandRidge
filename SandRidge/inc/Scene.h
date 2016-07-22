#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

class Scene
{
public:
	Scene();
	~Scene();
	
	enum SceneType
	{
		SCENE_MAIN_MENU,
		SCENE_GAME
	};

	virtual bool update(float dt);
	void render();

	SceneType getSceneType();

	virtual bool createScene() = 0;
	virtual bool disposeScene() = 0;
protected:
	SceneType mSceneType;
};

#endif //!_SCENE_H_