#include "AudioManager.h"


AudioManager* AudioManager::m_instance = 0;
AudioManager::AudioManager() {}

AudioManager* AudioManager::instance() {
	if (m_instance == 0)
		m_instance = new AudioManager();
	return m_instance;
}

void AudioManager::LoadAudio(){
	ambient = Mix_LoadMUS("res/snd/mus/ambient.wav");
	steps = Mix_LoadWAV("res/snd/fx/steps.wav");//example sounds
	if (ambient == NULL || steps == NULL)
	{
		cout << "Failed to load some Audio files" << endl;
	}
}
void AudioManager::PlayAmbientAudio(){
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(ambient, -1); //-1 continuously loops.
	}
}
void AudioManager::PlayWalkingGrass(){
	Mix_PlayChannel(-1, steps, 0);
}

AudioManager::~AudioManager()
{
}
