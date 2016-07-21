#pragma once
#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <SDL_mixer.h>
#include <iostream>
#include "ResourceManager.h"
using namespace std;

class AudioManager
{
public:
	static AudioManager* m_instance;
	static AudioManager* instance();
	Mix_Chunk* steps;
	void PlayAmbientAudio();
	void PlayWalkingGrass();
	void PlayShoot();
	//can add other audio functions for different sound effects.


private:
	AudioManager();
	~AudioManager();
};

#endif