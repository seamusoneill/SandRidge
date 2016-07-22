#include "ConcreteAObserver.h"


ConcreteAObserver::ConcreteAObserver()
{
}


ConcreteAObserver::~ConcreteAObserver()
{
}

void ConcreteAObserver::update(int val){
	if (val ==1)
	{
		Mix_PlayMusic(ResourceManager::instance()->getMusic("ambient"), -1); //-1 continuously loops.
	}
}