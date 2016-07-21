#include "AudioManager.h"


AudioManager* AudioManager::m_instance = 0;
AudioManager::AudioManager() {}

AudioManager* AudioManager::instance() {
	if (m_instance == 0)
		m_instance = new AudioManager();
	return m_instance;
}

void AudioManager::PlayAmbientAudio(){
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(ResourceManager::instance()->getMusic("ambient"), -1); //-1 continuously loops.
	}
}

void AudioManager::PlayWalkingGrass(){
	Mix_PlayChannel(-1, ResourceManager::instance()->getSfx("steps"), 0);
}

void AudioManager::PlayShoot(){
	Mix_PlayChannel(-1, ResourceManager::instance()->getSfx("high"), 0);
}

AudioManager::~AudioManager()
{
}
