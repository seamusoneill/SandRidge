#pragma once
#include <vector>
#include "Observer.h"
#include <algorithm>

class Subject
{
public:
	Subject();
	~Subject();
	std::vector<Observer*> m_observers;//observers
	void Attach(Observer* o);
	void Detach(Observer* o);
	void Notify(int num);
};
