#pragma once
#ifndef _OBSERVER_H_
#define _OBSERVER_H_
//#include <SDL_dev\SDL2_mixer-2.0.0\include\SDL_mixer.h>
//#include "ResourceManager.h"
class Observer//including here doesnt work.
{
public:
	virtual void onNotify(int val) = 0;
};
#endif// !_OBSERVER_H_
