#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "GameActor.h"
#include "InputManager.h"
#include "AudioManager.h" //TODO observer pattern

class Player : public GameActor
{
public:
	Player();
	~Player();

	bool initialise(SDL_Texture* texture = NULL, int posX = 0, int posY = 0, int width = 0, int height = 0,
		float angle = 0.0f, SDL_Point* centrePoint = NULL, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void update(float dt);
	
	void handleEvent(SDL_Event e);
private:
	//Movement velocity
	int mVelX, mVelY;

	void walk();
	void shoot();
	void punch();
};

#endif //!_GAME_ACTOR_H_