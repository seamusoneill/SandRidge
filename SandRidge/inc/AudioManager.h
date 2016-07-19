#pragma once
#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <SDL_mixer.h>
#include <iostream>
using namespace std;

class AudioManager
{
public:
	static AudioManager* m_instance;
	static AudioManager* instance();
	Mix_Music* ambient;
	Mix_Chunk* steps;
	void LoadAudio();//can change how this is set up. can pass the sdl mixer if we have resource loader
	void PlayAmbientAudio();
	void PlayWalkingGrass();
	//can add other audio functions for different sound effects.


private:
	AudioManager();
	~AudioManager();
};

#endif