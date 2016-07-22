#pragma once
#ifndef _AUDIOOBSERVER_H_
#define _AUDIOOBSERVER_H_

#include "Observer.h"
#include <SDL_dev\SDL2_mixer-2.0.0\include\SDL_mixer.h>
#include "ResourceManager.h"
class AudioObserver : public Observer
{
public:
	AudioObserver();//default contructors
	~AudioObserver();
	void onNotify(int val);//updates what audio file to play.
	void attachSubject(Subject* sub);//attaches subject to the observer
};

#endif// !_SOUNDOBSERVER_H_
