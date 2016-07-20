#pragma once
#ifndef	TREE_H
#define TREE_H

#include "BaseObject.h"

class Tree : public BaseObject{
public:
	Tree();
	~Tree();
	bool initialise(SDL_Texture* texture = NULL, int posX = 0, int posY = 0, int width = 0, int height = 0,
		float angle = 0.0f, SDL_Point* centrePoint = NULL, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void update(float dt);
};
#endif