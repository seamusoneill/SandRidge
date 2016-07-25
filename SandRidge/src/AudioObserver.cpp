#include "AudioObserver.h"


AudioObserver::AudioObserver()
{
}


AudioObserver::~AudioObserver()
{
}

void AudioObserver::onNotify(int val){//Updates what the AudioObserver should play.
	if (val ==1)
	{
		Mix_PlayMusic(ResourceManager::instance()->getMusic("ambient"), -1); //-1 continuously loops.
	}
}
void AudioObserver::attachToSubject(Subject* sub){
	sub->Attach(this);
}