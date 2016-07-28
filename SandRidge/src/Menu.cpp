#include "Menu.h"


Menu::Menu()
{
	createScene();
}


Menu::~Menu()
{
	disposeScene();
}

bool Menu::createScene()
{
	bool success = true;

	mButton.push_back(new Button());
	mButton.push_back(new Button());
	mButton[0]->initialise(NULL, 50, 50, 50, 50);
	mButton[1]->initialise(NULL, 100, 100, 50, 50);//TODO sort out how many buttons and for loop for this
	mSceneType = SCENE_MAIN_MENU;

	return success;
}

bool Menu::disposeScene()
{
	bool success = true;



	return success;
}

Scene::SceneType Menu::update(float dt)
{
	SDL_Event e; //Event handler
	int i = 0;
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
		if (mButton.at(0)->IsClicked()){//play button
			return SCENE_GAME;
		}
		else if (mButton.at(1)->IsClicked())
		{
			return SCENE_QUIT;
		}
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			return SCENE_QUIT;
		}
	}
	for (size_t i = 0; i < mButton.size(); i++)
		mButton[i]->update(&e);
	//Clear screen
	SDL_SetRenderDrawColor(SceneRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(SceneRenderer);
	for (size_t i = 0; i < mButton.size(); i++)
		mButton[i]->render();
	//Update screen
	SDL_RenderPresent(SceneRenderer);

	return SCENE_MAIN_MENU;
}
void Menu::HandleMain(SDL_Event* e){//TODO if we have more menus this will be needed to sort out
	if (mButton.at(0)->IsClicked()){//play button
		//menuState = PLAYING;
	}
}

void Menu::ChangeScene(){//change this

}