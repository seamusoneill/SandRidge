#pragma once
#ifndef _MENU_H_
#define _MENU_H_
#include "Scene.h"
#include "Button.h"
class Menu : public Scene
{
public:
	Menu();
	~Menu();

	bool createScene();
	bool disposeScene();

	Scene::SceneType update(float dt);

	void ChangeScene();
private:
	std::vector<Button*> mButton;
	void HandleMain(SDL_Event* e);

};
#endif _MENU_H_
