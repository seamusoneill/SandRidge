#pragma once
#ifndef _AUDIOOBSERVER_H_
#define _AUDIOOBSERVER_H_

#include "Observer.h"
#include <SDL_mixer.h>
#include "ResourceManager.h"
class AudioObserver : public Observer
{
public:
	AudioObserver();//default contructors
	~AudioObserver();
	void onNotify(int val);//updates what audio file to play.
	void attachToSubject(Subject* sub);//attaches subject to the observer
};

#endif// !_AUDIOOBSERVER_H_