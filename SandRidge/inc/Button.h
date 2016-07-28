#pragma once
#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "BaseObject.h"
class Button : public BaseObject
{
public:
	Button();
	~Button();

	bool initialise(SDL_Texture* texture = NULL, int posX = 0, int posY = 0, int width = 0, int height = 0,
		float angle = 0.0f, SDL_Point* centrePoint = NULL, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void update(float dt);
	void update(SDL_Event* e);
	bool IsClicked();
private: 
	
	bool clicked;
};

#endif //!_BUTTON_H_